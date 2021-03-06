%defines "lib/syn.tab.h"
%define lr.type canonical-lr;
%define parse.error verbose
%define parse.trace
%locations
%{
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"
#include "syntax_tree.h"
#include "semantic_utils.h"

// #define SYN_DEBUG_MODE

extern int yylex();
extern int yylex_destroy();
extern FILE* yyin;
extern int yydestroy();
extern int current_line;
extern int previous_col;
extern int last_id_line;
extern int last_id_col;
extern int symbol_table_scope;
extern symbol_table_t* last_child;
char* INT_TYPE_STR = "int\0";
char* FLOAT_TYPE_STR = "float\0";
char* LIST_TYPE_STR = "NIL\0";
char* INT_LIST_TYPE_STR = "int list\0";
char* FLOAT_LIST_TYPE_STR = "float list\0";
char* INT_TO_FLOAT_STR = "convert_int_to_float\0";
char* FLOAT_TO_INT_STR = "convert_float_to_int\0";
char* STRING_LITERAL = "string\0";
int has_syntax_error = 0;

int yyerror(const char*);
static void print_grammar_rule(char*);
%}

%union {
  char* terminal_string;
  struct {
    char* terminal_string;
    int line;
    int col;
  } terminal_id;
  struct node* node;
}

%type<node> program
%type<node> declaration-list
%type<node> declaration
%type<node> var-declaration
%type<node> data-type
%type<node> func-declaration
%type<node> func-definition
%type<node> params-list
%type<node> params
%type<node> param
%type<node> block-statement
%type<node> statement-list
%type<node> statement
%type<node> expression-statement
%type<node> conditional-statement
%type<node> iteration-statement
%type<node> expression-or-empty
%type<node> return-statement
%type<node> input-statement
%type<node> output-statement
%type<node> write-call
%type<node> expression
%type<node> simple-expression
%type<node> logical-expression
%type<node> relational-expression
%type<node> relational-operator
%type<node> list-expression
%type<node> binary-list-operator
%type<node> binary-logical-operator
%type<node> math-expression
%type<node> add-sub-operator
%type<node> term
%type<node> mul-div-operator
%type<node> unary-sign-expression
%type<node> unary-operator
%type<node> factor
%type<node> func-call
%type<node> args-list
%type<node> args
%type<node> numeric-const
%type<node> output-arg

/* Token declarations */
%token<terminal_string> INT_TYPE
%token<terminal_string> FLOAT_TYPE
%token<terminal_string> INT_LIST_TYPE
%token<terminal_string> FLOAT_LIST_TYPE
%token<terminal_id> INT_CONST
%token<terminal_id> FLOAT_CONST
%token<terminal_id> LIST_CONST
%token<terminal_id> STRING_CONST
%token<terminal_id> ADD_OP
%token<terminal_id> SUB_OP
%token<terminal_id> MULT_OP
%token<terminal_id> DIV_OP
%token<terminal_id> NOT_OR_TAIL_OP
%token<terminal_id> OR_OP
%token<terminal_id> AND_OP
%token<terminal_id> LIST_HEAD_OP
%token<terminal_id> LIST_TAIL_OP
%token<terminal_id> LIST_CONSTRUCTOR_OP
%token<terminal_id> LIST_MAP_OP
%token<terminal_id> LIST_FILTER_OP
%token<terminal_id> LESSTHAN_OP
%token<terminal_id> LESSEQUAL_OP
%token<terminal_id> GREATERTHAN_OP
%token<terminal_id> GREATEREQUAL_OP
%token<terminal_id> NOTEQUAL_OP
%token<terminal_id> EQUAL_OP
%token<terminal_string> LBRACE
%token<terminal_string> RBRACE
%token<terminal_string> LPARENTHESES
%token<terminal_string> RPARENTHESES
%token<terminal_string> SEMICOLON
%token<terminal_id> ASSIGNMENT
%token<terminal_string> COMMA
%token<terminal_string> FOR_KW
%token<terminal_string> IF_KW
%token<terminal_string> ELSE_KW
%token<terminal_id> RETURN_KW
%token<terminal_string> READ_KW
%token<terminal_string> WRITE_KW
%token<terminal_string> WRITELN_KW
%token<terminal_id> ID

%destructor {
  free($$.terminal_string);
} ID INT_CONST FLOAT_CONST STRING_CONST

// Solve ambiguity conflict
%right RPARENTHESES ELSE_KW

%%
// 1
program:
  declaration-list {
    print_grammar_rule("program\0");
    node_t* declaration_list = $1;
    syntax_tree = declaration_list;
  }
;

// 2
declaration-list:
  declaration-list declaration {
    print_grammar_rule("declaration-list multiple\0");
    $$ = initialize_node("declaration-list", -1, -1);
    node_t* declaration_list = $$;
    node_t* recursive_declaration_list = $1;
    node_t* declaration = $2;
    add_node(declaration_list, recursive_declaration_list);
    add_node(declaration_list, declaration);
  }
  | declaration {
    print_grammar_rule("declaration-list single\0");
    $$ = $1;
  }
;

// 3
declaration:
  var-declaration {
    print_grammar_rule("declaration var-declaration\0");
    $$ = $1;
  }
  | func-declaration {
    $$ = $1;
    print_grammar_rule("declaration func-declaration\0");
  }
  | error {
    has_syntax_error = 1;
    $$ = initialize_node("error", -1, -1);
  }
;

// 4
var-declaration:
  data-type ID SEMICOLON {
    print_grammar_rule("var-declaration\0");
    $$ = initialize_node("var-declaration", -1, -1);
    node_t* var_declaration = $$;
    node_t* data_type = $1;
    node_t* id = initialize_node($2.terminal_string, $2.line, $2.col);
    add_node(var_declaration, data_type);
    add_node(var_declaration, id);

    // Semantic
    check_redeclared_id(current_symbol_table, id);
    /* 
      This is probably not a good solution but whenever the parser tries to find a match for a variable declaration it always looks ahead.
      In case the lookahead symbol is either a '{' or a '}' the symbol table context will be changed by the lexer for the parent or the last child, respectively.
      What I do here is simply guarantee that the symbol table entry is being correctly placed by checking the lookahead symbol first.
      https://www.gnu.org/software/bison/manual/html_node/Lookahead.html
    */
    if (yychar == LBRACE) {
      add_symbol_table_entry(current_symbol_table->parent, id->name, data_type->name, 0, -1);
    } else if (yychar == RBRACE) {
      add_symbol_table_entry(last_child, id->name, data_type->name, 0, -1);
    }
    else {
      add_symbol_table_entry(current_symbol_table, id->name, data_type->name, 0, -1);
    }

    free($2.terminal_string);
  }
;

// 5
data-type:
  INT_TYPE {
    print_grammar_rule("data-type INT_TYPE\0");
    $$ = initialize_node("int", -1, -1);
  }
  | FLOAT_TYPE {
    print_grammar_rule("data-type FLOAT_TYPE\0");
    $$ = initialize_node("float",  -1, -1);
  }
  | INT_LIST_TYPE {
    print_grammar_rule("data-type INT_LIST_TYPE\0");
    $$ = initialize_node("int list", -1, -1);
  }
  | FLOAT_LIST_TYPE {
    print_grammar_rule("data-type FLOAT_LIST_TYPE\0");
    $$ = initialize_node("float list", -1, -1);
  }
;

// 6
func-declaration:
  func-definition block-statement {
    print_grammar_rule("func-declaration\0");
    $$ = initialize_node("func-declaration", -1, -1);
    node_t* func_declaration = $$;
    node_t* func_definition = $1;
    node_t* block_statement = $2;
    add_node(func_declaration, func_definition);
    add_node(func_declaration, block_statement);
  }
;

// 7
func-definition:
  data-type ID LPARENTHESES params-list RPARENTHESES {
    print_grammar_rule("func-definition\0");
    $$ = initialize_node("func-declaration", -1, -1);
    node_t* func_definition = $$;
    node_t* data_type = $1;
    node_t* id = initialize_node($2.terminal_string, $2.line, $2.col);
    node_t* params_list = $4;
    add_node(func_definition, data_type);
    add_node(func_definition, id);
    // Checks for empty params list
    if (params_list != NULL) {
      add_node(func_definition, params_list);
    }

    // Semantic
    check_redeclared_id(symbol_table, id);
    add_symbol_table_entry(symbol_table, id->name, data_type->name, 1, func_params_count);
    func_params_count = 0;

    free($2.terminal_string);
  }
;

// 8
params-list:
  params {
    print_grammar_rule("params-list params\0");
    $$ = $1;
  }
  | %empty {
    print_grammar_rule("params-list empty\0");
    $$ = NULL;
  }
;

// 9
params: 
  params COMMA param {
    print_grammar_rule("params multiple params\0");
    $$ = initialize_node("params", -1, -1);
    node_t* params = $$;
    node_t* recursive_params = $1;
    node_t* param = $3;
    add_node(params, recursive_params);
    add_node(params, param);
  }
  | param {
    print_grammar_rule("params single param\0");
    $$ = $1;
  }
;

// 10
param:
  data-type ID {
    print_grammar_rule("param\0");
    $$ = initialize_node("param", -1, -1);
    node_t* param = $$;
    node_t* data_type = $1;
    node_t* id = initialize_node($2.terminal_string, $2.line, $2.col);
    add_node(param, data_type);
    add_node(param, id);
    // Semantic
    check_redeclared_param(id);
    save_func_param(id->name, data_type->name);
    free($2.terminal_string);
  }
;

// 11
block-statement:
  LBRACE statement-list RBRACE {
    print_grammar_rule("block-statement\0");
    $$ = $2;
  }
  | LBRACE RBRACE {
    print_grammar_rule("block-statement empty\0");
    $$ = initialize_node("empty-block-statement", -1, -1);
  }
;

// 12
statement-list:
  statement-list statement {
    print_grammar_rule("statement-list recursive\0");
    $$ = initialize_node("statement-list", -1, -1);
    node_t* statement_list = $$;
    node_t* recursive_statement_list = $1;
    node_t* statement = $2;
    if (recursive_statement_list != NULL) {
      add_node(statement_list, recursive_statement_list);
    }
    add_node(statement_list, statement);
  }
  | statement {
    print_grammar_rule("statement-list statement\0");
    $$ = $1;
  }
;

// 13
statement:
  expression-statement {
    print_grammar_rule("statement expression-statement\0");
    $$ = $1;
  }
  | block-statement {
    print_grammar_rule("statement block-statement\0");
    $$ = $1;
  }
  | conditional-statement {
    print_grammar_rule("statement conditional-statement\0");
    $$ = $1;
  }
  | iteration-statement {
    print_grammar_rule("statement iteration-statement\0");
    $$ = $1;
  }
  | return-statement {
    print_grammar_rule("statement return-statement\0");
    $$ = $1;
  }
  | input-statement {
    print_grammar_rule("statement input-statement\0");
    $$ = $1;
  }
  | output-statement {
    print_grammar_rule("statement output-statement\0");
    $$ = $1;
  }
  | var-declaration {
    print_grammar_rule("statement var-declaration\0");
    $$ = $1;
  }
  | error {
    has_syntax_error = 1;
    $$ = initialize_node("error", -1, -1);
  }
;

// 14
expression-statement:
  expression SEMICOLON {
    print_grammar_rule("expression-statement expression\0");
    $$ = $1;
  }
  | SEMICOLON {
    print_grammar_rule("expression-statement semicolon\0");
    $$ = initialize_node("empty-expression-statement", -1, -1);
  }
;

// 15
conditional-statement:
  IF_KW LPARENTHESES expression RPARENTHESES statement {
    print_grammar_rule("conditional-statement IF\0");
    $$ = initialize_node("if", -1, -1);
    node_t* conditional_statement = $$;
    node_t* expression = $3;
    node_t* statement = $5;
    add_node(conditional_statement, expression);
    add_node(conditional_statement, statement);
  }
  | IF_KW LPARENTHESES expression RPARENTHESES statement ELSE_KW statement {
    print_grammar_rule("conditional-statement IF ELSE\0");
    $$ = initialize_node("if-else", -1, -1);
    node_t* conditional_statement = $$;
    node_t* expression = $3;
    node_t* if_statement = $5;
    node_t* else_statement = $7;
    add_node(conditional_statement, expression);
    add_node(conditional_statement, if_statement);
    add_node(conditional_statement, else_statement);
  }
;

// 16
iteration-statement:
  FOR_KW LPARENTHESES expression-or-empty SEMICOLON expression-or-empty SEMICOLON expression-or-empty RPARENTHESES statement {
    print_grammar_rule("iteration-statement\0");
    $$ = initialize_node("for", -1, -1);
    node_t* iteration_statement = $$;
    node_t* first_expression = $3;
    node_t* second_expression = $5;
    node_t* third_expression = $7;
    node_t* statement = $9;
    add_node(iteration_statement, first_expression);
    add_node(iteration_statement, second_expression);
    add_node(iteration_statement, third_expression);
    add_node(iteration_statement, statement);
  }
;

// 17
expression-or-empty:
  expression {
    print_grammar_rule("expression-or-empty expression\0");
    $$ = $1;
  }
  | %empty {
    print_grammar_rule("expression-or-empty empty\0");
    $$ = initialize_node("empty-expression", -1, -1);
  }
;

// 18
return-statement: 
  RETURN_KW expression SEMICOLON {
    print_grammar_rule("return-statement expression\0");
    $$ = initialize_node("return", $1.line, $1.col);
    node_t* return_statement = $$;
    node_t* expression = $2;
    add_node(return_statement, expression);

    //Semantic
    check_return_type(return_statement, expression);
  }
;

// 19
input-statement: 
  READ_KW LPARENTHESES ID RPARENTHESES SEMICOLON {
    print_grammar_rule("input-statement\0");
    $$ = initialize_node("read", -1, -1);
    node_t* input_statement = $$;
    node_t* id = initialize_node($3.terminal_string, $3.line, $3.col);
    add_node(input_statement, id);

    // Semantic
    if (check_entry_in_symbol_table(current_symbol_table, id)) {
      check_read_type(id);
    }
    free($3.terminal_string);
  }
;

// 20
output-statement:
  write-call LPARENTHESES output-arg RPARENTHESES SEMICOLON {
    print_grammar_rule("output-statement simple-expression\0");
    $$ = $1;
    node_t* output_statement = $$;
    node_t* output_arg = $3;
    add_node(output_statement, output_arg);
    check_write_type(output_arg);
  }
;

// 21
write-call:
  WRITE_KW {
    print_grammar_rule("write-call write\0");
    $$ = initialize_node("write", -1, -1);
  }
  | WRITELN_KW {
    print_grammar_rule("write-call writeln\0");
    $$ = initialize_node("writeln", -1, -1);
  }
;

// 22
expression:
  ID ASSIGNMENT expression {
    print_grammar_rule("expression assigment\0");
    $$ = initialize_node("=", $2.line, $2.col);
    node_t* expression = $$;
    node_t* id = initialize_node($1.terminal_string, $1.line, $1.col);
    node_t* recursive_expression = $3;
    add_node(expression, id);
    add_node(expression, recursive_expression);
    
    // Semantic
    if (check_entry_in_symbol_table(current_symbol_table, id)) {
      check_binary_operation_type($$);
    }
    free($1.terminal_string);
  }
  | simple-expression {
    print_grammar_rule("expression simple-expression\0");
    $$ = $1;
  }
;

// 23
simple-expression:
  logical-expression {
    print_grammar_rule("simple-expression logic-expression\0");
    $$ = $1;
  }
;

// 24
logical-expression:
  logical-expression binary-logical-operator relational-expression {
    print_grammar_rule("logical-expression recursive\0");
    $$ = $2;
    node_t* logical_expression = $$;
    node_t* recursive_logical_expression = $1;
    node_t* relational_expression = $3;
    add_node(logical_expression, recursive_logical_expression);
    add_node(logical_expression, relational_expression);

    // Semantic
    check_binary_operation_type($$);
  }
  | relational-expression {
    print_grammar_rule("logical-expression relational-expression\0");
    $$ = $1;
  }
;

// 25
binary-logical-operator:
  AND_OP { 
    print_grammar_rule("binary-logical-operator AND\0");
    $$ = initialize_node("&&", $1.line, $1.col);
  }
  | OR_OP { 
    print_grammar_rule("binary-logical-operator OR\0");
    $$ = initialize_node("||", $1.line, $1.col);
  }
;

// 26
relational-expression:
  relational-expression relational-operator list-expression {
    print_grammar_rule("relational-expression recursive\0");
    $$ = $2;
    node_t* relational_expression = $$;
    node_t* recursive_relational_expression = $1;
    node_t* list_expression = $3;
    add_node(relational_expression, recursive_relational_expression);
    add_node(relational_expression, list_expression);

    // Semantic
    check_binary_operation_type($$);
  }
  | list-expression {
    print_grammar_rule("relational-expression list-expression\0");
    $$ = $1;
  }
;

// 27
relational-operator:
  LESSTHAN_OP {
    print_grammar_rule("relational-operator LESSTHAN\0");
    $$ = initialize_node("<", $1.line, $1.col);
  }
  | LESSEQUAL_OP {
    print_grammar_rule("relational-operator LESSEQUAL\0");
    $$ = initialize_node("<=", $1.line, $1.col);
  }
  | GREATERTHAN_OP {
    print_grammar_rule("relational-operator GREATERTHAN\0");
    $$ = initialize_node(">", $1.line, $1.col);
  }
  | GREATEREQUAL_OP {
    print_grammar_rule("relational-operator GREATEREQUAL\0");
    $$ = initialize_node(">=", $1.line, $1.col);
  }
  | NOTEQUAL_OP {
    print_grammar_rule("relational-operator NOTEQUAL\0");
    $$ = initialize_node("!=", $1.line, $1.col);
  }
  | EQUAL_OP {
    print_grammar_rule("relational-operator EQUAL\0");
    $$ = initialize_node("==", $1.line, $1.col);
  }
;

// 28
list-expression:
  math-expression binary-list-operator list-expression {
    print_grammar_rule("list-expression list constructor\0");
    $$ = $2;
    node_t* list_expression = $$;
    node_t* math_expression = $1;
    node_t* recursive_list_expression = $3;
    add_node(list_expression, math_expression);
    add_node(list_expression, recursive_list_expression);

    // Semantic
    check_binary_operation_type($$);
  }
  | math-expression {
    $$ = $1;
  }
;

// 29
binary-list-operator:
  LIST_CONSTRUCTOR_OP {
    print_grammar_rule("binary-list-operator LIST_CONSTRUCTOR_OP\0");
    $$ = initialize_node(":", $1.line, $1.col);
  }
  | LIST_FILTER_OP {
    print_grammar_rule("relational-operator LIST_FILTER_OP\0");
    $$ = initialize_node("<<", $1.line, $1.col);
  }
  | LIST_MAP_OP {
    print_grammar_rule("relational-operator LIST_MAP_OP\0");
    $$ = initialize_node(">>", $1.line, $1.col);
  }
;

// 30
math-expression:
  math-expression add-sub-operator term {
    print_grammar_rule("math-expression add-sub\0");
    $$ = $2;
    node_t* math_expression = $$;
    node_t* recursive_math_expression = $1;
    node_t* term = $3;
    add_node(math_expression, recursive_math_expression);
    add_node(math_expression, term);

    // Semantic
    check_binary_operation_type($$);
  }
  | term {
    print_grammar_rule("math-expression term\0");
    $$ = $1;
  }
;

// 31
add-sub-operator:
  ADD_OP {
    print_grammar_rule("add-sub-operator ADD_OP\0");
    $$ = initialize_node("+", $1.line, $1.col);
  }
  | SUB_OP {
    print_grammar_rule("add-sub-operator SUB_OP\0");
    $$ = initialize_node("-", $1.line, $1.col);
  }
;

// 32
term:
  term mul-div-operator unary-sign-expression {
    print_grammar_rule("term mul-div\0");
    $$ = $2;
    node_t* term = $$;
    node_t* recursive_term = $1;
    node_t* not_expression = $3;
    add_node(term, recursive_term);
    add_node(term, not_expression);
    
    // Semantic
    check_binary_operation_type($$);
  }
  | unary-sign-expression {
    print_grammar_rule("term factor\0");
    $$ = $1;
  }
;

// 33
mul-div-operator:
  MULT_OP {
    print_grammar_rule("mul-div-operator mult\0");
    $$ = initialize_node("*", $1.line, $1.col);
  }
  | DIV_OP {
    print_grammar_rule("mul-div-operator div\0");
    $$ = initialize_node("/", $1.line, $1.col);
  }
;

// 34
unary-sign-expression:
  unary-operator unary-sign-expression {
    print_grammar_rule("unary-sign-expression recursive\0");
    $$ = $1;
    node_t* unary_sign_expression = $$;
    node_t* recursive_unary_sign_expression = $2;
    add_node(unary_sign_expression, recursive_unary_sign_expression);
    check_unary_operation_type($$);
  }
  | factor {
    print_grammar_rule("unary-sign-expression factor\0");
    $$ = $1;
  }
;

// 35
unary-operator:
  add-sub-operator {
    print_grammar_rule("unary-operator add-sub-operator\0");
    $$ = $1;
  }
  | LIST_HEAD_OP {
    print_grammar_rule("unary-operator LIST_HEAD_OP\0");
    $$ = initialize_node("?", $1.line, $1.col);
  }
  | LIST_TAIL_OP {
    print_grammar_rule("unary-operator LIST_TAIL_OP\0");
    $$ = initialize_node("%", $1.line, $1.col);
  }
  | NOT_OR_TAIL_OP {
    print_grammar_rule("unary-operator NOT_OR_TAIL_OP\0");
    $$ = initialize_node("!", $1.line, $1.col);
  }
;

// 36
factor: 
  LPARENTHESES expression RPARENTHESES {
    print_grammar_rule("factor expression\0");
    $$ = $2;
  }
  | func-call {
    print_grammar_rule("factor func-call\0");
    $$ = $1;
  }
  | numeric-const {
    print_grammar_rule("factor numeric-const\0");
    $$ = $1;
  }
  | ID {
    print_grammar_rule("factor id\0");
    node_t* id = initialize_node($1.terminal_string, $1.line, $1.col);
    $$ = id;

    // Semantic
    check_entry_in_symbol_table(current_symbol_table, id);
    free($1.terminal_string);
  }
  | LIST_CONST {
    print_grammar_rule("factor list const\0");
    node_t * nil = initialize_node("NIL", $1.line, $1.col);
    nil->type = LIST_TYPE_STR;
    nil->is_function = 0;
    $$ = nil;
  }
;

// 37
func-call:
  ID LPARENTHESES args-list RPARENTHESES {
    print_grammar_rule("func-call\0");
    $$ = initialize_node("func-call", -1, -1);
    node_t* func_call = $$;
    node_t* id = initialize_node($1.terminal_string, $1.line, $1.col);
    node_t* args_list = $3;
    add_node(func_call, id);
    add_node(func_call, args_list);

    // printf("**********\n");
    // print_symbol_table(symbol_table, 0);
    // printf("**********\n");

    // Semantic
    if (check_entry_in_symbol_table(current_symbol_table, id)) {
      if(check_number_of_arguments(id, args_list)) {
        check_param_types(id, args_list);
      }
    } 
    
    // Function calls should be treated as var type
    func_call->is_function = 0;
    func_call->type = id->type;
    free($1.terminal_string);
  }
;

// 38
args-list:
  args {
    print_grammar_rule("args-list args\0");
    $$ = $1;
  }
  | %empty {
    print_grammar_rule("args-list empty\0");
    $$ = initialize_node("empty-args-list", -1, -1);
  }
;

// 39
args:
  args COMMA expression {
    print_grammar_rule("args multiple args\0");
    $$ = initialize_node("args", -1, -1);
    node_t* args = $$;
    node_t* recursive_args = $1;
    node_t* expression = $3;
    add_node(args, recursive_args);
    add_node(args, expression);
  }
  | expression {
    print_grammar_rule("args expression\0");
    $$ = initialize_node("args", -1, -1);
    node_t* args = $$;
    node_t* dummy_args = initialize_node("args", -1, -1);
    node_t* expression = $1;
    add_node(args, dummy_args);
    add_node(args, expression);
  }
;

// 40
numeric-const:
  FLOAT_CONST {
    print_grammar_rule("numeric-const unsigned float const\0");
    node_t* numeric_const = initialize_node($1.terminal_string, $1.line, $1.col);
    numeric_const->type = FLOAT_TYPE_STR;
    numeric_const->is_function = 0;
    $$ = numeric_const;
    free($1.terminal_string);
  }
  | INT_CONST {
    print_grammar_rule("numeric-const unsigned int const\0");
    node_t* numeric_const = initialize_node($1.terminal_string, $1.line, $1.col);
    numeric_const->type = INT_TYPE_STR;
    numeric_const->is_function = 0;
    $$ = numeric_const;
    free($1.terminal_string);
  }
;

// 41
output-arg:
  simple-expression {
    print_grammar_rule("output-arg simple-expression");
    $$ = $1;
  }
  | STRING_CONST {
    print_grammar_rule("output-arg string const");
    $$ = initialize_node($1.terminal_string, $1.line, $1.col);
    $$->type = STRING_LITERAL;
    $$->is_function = 0;
    free($1.terminal_string);
  }
;

%%
int yyerror(const char * e) {
  printf("%s at line %d col %d\n", e, current_line, previous_col);
  return 0;
}

static void print_grammar_rule(char* grammar_rule) {
#if defined SYN_DEBUG_MODE
  printf("Syn %s\n", grammar_rule);
#endif
}

int main() {
  /*
    This is a temporary list to store function params in order to pass them whenever a new symbol table/scope is introduced
    We also count the amount of parameters in the function declaration ir order to check it during function calls later
  */
  func_params_list = NULL;
  func_params_count = 0;

  /*
    We save a list of pointer to our AST nodes because when a syntax error occurs the
    tree might not include all nodes and thus we lose some node references resulting in memory leaks
  */
  error_recovery_node_list = NULL;

  // The root symbol table is the only one without a parent
  symbol_table = initialize_symbol_table(symbol_table_scope);

  // At first our current symbol table is the root symbol table
  current_symbol_table = symbol_table;

  // Initialize parsing
  yyparse();
  // Check if main was declared
  check_main_declaration();
  print_symbol_table(symbol_table, 0);
  if (!has_syntax_error) {
    printf("Syntax Tree\n");
    print_syntax_tree(syntax_tree, 0);
  } else{
    printf("Syntax tree is not shown when a syntax error occurs\n");
  }


  // Free Symbol Table
  free_symbol_table(symbol_table);

  // Free AST
  free_error_recovery_list();
  yylex_destroy();
  return 0;
}