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
int has_syntax_error = 0;

int yyerror(const char*);
void semantic_error(int, int, char*);
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
%type<node> not-expression
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
%token<terminal_string> INT_CONST
%token<terminal_string> FLOAT_CONST
%token<terminal_string> LIST_CONST
%token<terminal_string> STRING_CONST
%token<terminal_string> ADD_OP
%token<terminal_string> SUB_OP
%token<terminal_string> MULT_OP
%token<terminal_string> DIV_OP
%token<terminal_string> NOT_OR_TAIL_OP
%token<terminal_string> OR_OP
%token<terminal_string> AND_OP
%token<terminal_string> LIST_HEAD_OP
%token<terminal_string> LIST_TAIL_OP
%token<terminal_string> LIST_CONSTRUCTOR_OP
%token<terminal_string> LIST_MAP_OP
%token<terminal_string> LIST_FILTER_OP
%token<terminal_string> LESSTHAN_OP
%token<terminal_string> LESSEQUAL_OP
%token<terminal_string> GREATERTHAN_OP
%token<terminal_string> GREATEREQUAL_OP
%token<terminal_string> NOTEQUAL_OP
%token<terminal_string> EQUAL_OP
%token<terminal_string> LBRACE
%token<terminal_string> RBRACE
%token<terminal_string> LPARENTHESES
%token<terminal_string> RPARENTHESES
%token<terminal_string> SEMICOLON
%token<terminal_string> ASSIGNMENT
%token<terminal_string> COMMA
%token<terminal_string> FOR_KW
%token<terminal_string> IF_KW
%token<terminal_string> ELSE_KW
%token<terminal_string> RETURN_KW
%token<terminal_string> READ_KW
%token<terminal_string> WRITE_KW
%token<terminal_string> WRITELN_KW
%token<terminal_id> ID

%destructor {
  free($$);
} INT_CONST FLOAT_CONST STRING_CONST

%destructor {
  free($$.terminal_string);
} ID

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
    $$ = initialize_node("declaration-list");
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
    $$ = initialize_node("error");
  }
;

// 4
var-declaration:
  data-type ID SEMICOLON {
    print_grammar_rule("var-declaration\0");
    $$ = initialize_node("var-declaration");
    node_t* var_declaration = $$;
    node_t* data_type = $1;
    node_t* id = initialize_node($2.terminal_string);
    add_node(var_declaration, data_type);
    add_node(var_declaration, id);

    // Semantic
    if (check_redeclared_id(current_symbol_table, id->name)) {
      char error[10000];
      sprintf(error, "variable id \"%s\" was declared previously", id->name);
      semantic_error($2.line, $2.col, error);
    }

    /* 
      This is probably not a good solution but whenever the parser tries to find a match to a variable declaration is always looks ahead.
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
    $$ = initialize_node("int");
  }
  | FLOAT_TYPE {
    print_grammar_rule("data-type FLOAT_TYPE\0");
    $$ = initialize_node("float");
  }
  | INT_LIST_TYPE {
    print_grammar_rule("data-type INT_LIST_TYPE\0");
    $$ = initialize_node("int list");
  }
  | FLOAT_LIST_TYPE {
    print_grammar_rule("data-type FLOAT_LIST_TYPE\0");
    $$ = initialize_node("float list");
  }
;

// 6
func-declaration:
  func-definition block-statement {
    print_grammar_rule("func-declaration\0");
    $$ = initialize_node("func-declaration");
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
    $$ = initialize_node("func-declaration");
    node_t* func_definition = $$;
    node_t* data_type = $1;
    node_t* id = initialize_node($2.terminal_string);
    node_t* params_list = $4;
    add_node(func_definition, data_type);
    add_node(func_definition, id);
    // Checks for empty params list
    if (params_list != NULL) {
      add_node(func_definition, params_list);
    }

    // Semantic
    if (check_redeclared_id(current_symbol_table, id->name)) {
      char error[10000];
      sprintf(error, "function id \"%s\" was declared previously", id->name);
      semantic_error($2.line, $2.col, error);
    }
    add_symbol_table_entry(symbol_table, id->name, data_type->name, 1, func_params_count);
    func_params_count = 0;

    free($2.terminal_string);
  }
;

// 7
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

// 8
params: 
  params COMMA param {
    print_grammar_rule("params multiple params\0");
    $$ = initialize_node("params");
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

// 9
param:
  data-type ID {
    print_grammar_rule("param\0");
    $$ = initialize_node("param");
    node_t* param = $$;
    node_t* data_type = $1;
    node_t* id = initialize_node($2.terminal_string);
    add_node(param, data_type);
    add_node(param, id);
    // Semantic
    if (check_redeclared_param(id->name)) {
      char error[10000];
      sprintf(error, "param id \"%s\" was declared previously", id->name);
      semantic_error($2.line, $2.col, error);
    }
    save_func_param(id->name, data_type->name);
    free($2.terminal_string);
  }
;

// 10
block-statement:
  LBRACE statement-list RBRACE {
    print_grammar_rule("block-statement\0");
    $$ = $2;
  }
  | LBRACE RBRACE {
    print_grammar_rule("block-statement empty\0");
    $$ = initialize_node("empty-block-statement");
  }
;

// 11
statement-list:
  statement-list statement {
    print_grammar_rule("statement-list recursive\0");
    $$ = initialize_node("statement-list");
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

// 12
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
    $$ = initialize_node("error");
  }
;

// 13
expression-statement:
  expression SEMICOLON {
    print_grammar_rule("expression-statement expression\0");
    $$ = $1;
  }
  | SEMICOLON {
    print_grammar_rule("expression-statement semicolon\0");
    $$ = initialize_node("empty-expression-statement");
  }
;

// 14
conditional-statement:
  IF_KW LPARENTHESES expression RPARENTHESES statement {
    print_grammar_rule("conditional-statement IF\0");
    $$ = initialize_node("if");
    node_t* conditional_statement = $$;
    node_t* expression = $3;
    node_t* statement = $5;
    add_node(conditional_statement, expression);
    add_node(conditional_statement, statement);
  }
  | IF_KW LPARENTHESES expression RPARENTHESES statement ELSE_KW statement {
    print_grammar_rule("conditional-statement IF ELSE\0");
    $$ = initialize_node("if-else");
    node_t* conditional_statement = $$;
    node_t* expression = $3;
    node_t* if_statement = $5;
    node_t* else_statement = $7;
    add_node(conditional_statement, expression);
    add_node(conditional_statement, if_statement);
    add_node(conditional_statement, else_statement);
  }
;

// 15
iteration-statement:
  FOR_KW LPARENTHESES expression-or-empty SEMICOLON expression-or-empty SEMICOLON expression-or-empty RPARENTHESES statement {
    print_grammar_rule("iteration-statement\0");
    $$ = initialize_node("for");
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

// 16
expression-or-empty:
  expression {
    print_grammar_rule("expression-or-empty expression\0");
    $$ = $1;
  }
  | %empty {
    print_grammar_rule("expression-or-empty empty\0");
    $$ = initialize_node("empty-expression");
  }
;

// 17
return-statement: 
  RETURN_KW SEMICOLON {
    print_grammar_rule("return-statement void\0");
    $$ = initialize_node("void-return");
  }
  | RETURN_KW expression SEMICOLON {
    print_grammar_rule("return-statement expression\0");
    $$ = initialize_node("return");
    node_t* return_statement = $$;
    node_t* expression = $2;
    add_node(return_statement, expression);
  }
;

// 18
input-statement: 
  READ_KW LPARENTHESES ID RPARENTHESES SEMICOLON {
    print_grammar_rule("input-statement\0");
    $$ = initialize_node("read");
    node_t* input_statement = $$;
    node_t* id = initialize_node($3.terminal_string);
    add_node(input_statement, id);

    // Semantic
    if (!find_entry_in_symbol_table(current_symbol_table, id->name)) {
      char error[10000];
      sprintf(error, "id \"%s\" was not declared", id->name);
      semantic_error($3.line, $3.col, error);
    }
    free($3.terminal_string);
  }
;

// 19
output-statement:
  write-call LPARENTHESES output-arg RPARENTHESES SEMICOLON {
    print_grammar_rule("output-statement simple-expression\0");
    $$ = $1;
    node_t* output_statement = $$;
    node_t* output_arg = $3;
    add_node(output_statement, output_arg);
  }
;

// 20
write-call:
  WRITE_KW {
    print_grammar_rule("write-call write\0");
    $$ = initialize_node("write");
  }
  | WRITELN_KW {
    print_grammar_rule("write-call writeln\0");
    $$ = initialize_node("writeln");
  }
;

// 21
expression:
  ID ASSIGNMENT expression {
    print_grammar_rule("expression assigment\0");
    $$ = initialize_node("=");
    node_t* expression = $$;
    node_t* id = initialize_node($1.terminal_string);
    node_t* recursive_expression = $3;
    add_node(expression, id);
    add_node(expression, recursive_expression);
    
    // Semantic
    if (!find_entry_in_symbol_table(current_symbol_table, id->name)) {
      char error[10000];
      sprintf(error, "id \"%s\" was not declared", id->name);
      semantic_error($1.line, $1.col, error);
    }
    free($1.terminal_string);
  }
  | simple-expression {
    print_grammar_rule("expression simple-expression\0");
    $$ = $1;
  }
;

// 22
simple-expression:
  logical-expression {
    print_grammar_rule("simple-expression logic-expression\0");
    $$ = $1;
  }
;

// 23
logical-expression:
  logical-expression binary-logical-operator relational-expression {
    print_grammar_rule("logical-expression recursive\0");
    $$ = $2;
    node_t* logical_expression = $$;
    node_t* recursive_logical_expression = $1;
    node_t* relational_expression = $3;
    add_node(logical_expression, recursive_logical_expression);
    add_node(logical_expression, relational_expression);
  }
  | relational-expression {
    print_grammar_rule("logical-expression relational-expression\0");
    $$ = $1;
  }
;

// 24
binary-logical-operator:
  AND_OP { 
    print_grammar_rule("binary-logical-operator AND\0");
    $$ = initialize_node("&&");
  }
  | OR_OP { 
    print_grammar_rule("binary-logical-operator OR\0");
    $$ = initialize_node("||");
  }
;

// 25
relational-expression:
  relational-expression relational-operator list-expression {
    print_grammar_rule("relational-expression recursive\0");
    $$ = $2;
    node_t* relational_expression = $$;
    node_t* recursive_relational_expression = $1;
    node_t* list_expression = $3;
    add_node(relational_expression, recursive_relational_expression);
    add_node(relational_expression, list_expression);
  }
  | list-expression {
    print_grammar_rule("relational-expression list-expression\0");
    $$ = $1;
  }
;

// 26
relational-operator:
  LESSTHAN_OP {
    print_grammar_rule("relational-operator LESSTHAN\0");
    $$ = initialize_node("<");
  }
  | LESSEQUAL_OP {
    print_grammar_rule("relational-operator LESSEQUAL\0");
    $$ = initialize_node("<=");
  }
  | GREATERTHAN_OP {
    print_grammar_rule("relational-operator GREATERTHAN\0");
    $$ = initialize_node(">");
  }
  | GREATEREQUAL_OP {
    print_grammar_rule("relational-operator GREATEREQUAL\0");
    $$ = initialize_node(">=");
  }
  | NOTEQUAL_OP {
    print_grammar_rule("relational-operator NOTEQUAL\0");
    $$ = initialize_node("!=");
  }
  | EQUAL_OP {
    print_grammar_rule("relational-operator EQUAL\0");
    $$ = initialize_node("==");
  }
;

// 27
list-expression:
  list-expression binary-list-operator math-expression {
    print_grammar_rule("list-expression list constructor\0");
    $$ = $2;
    node_t* list_expression = $$;
    node_t* recursive_list_expression = $1;
    node_t* math_expression = $3;
    add_node(list_expression, recursive_list_expression);
    add_node(list_expression, math_expression);
  }
  | math-expression {
    $$ = $1;
  }
;

// 28
binary-list-operator:
  LIST_CONSTRUCTOR_OP {
    print_grammar_rule("binary-list-operator LIST_CONSTRUCTOR_OP\0");
    $$ = initialize_node(":");
  }
  | LIST_FILTER_OP {
    print_grammar_rule("relational-operator LIST_FILTER_OP\0");
    $$ = initialize_node("<<");
  }
  | LIST_MAP_OP {
    print_grammar_rule("relational-operator LIST_MAP_OP\0");
    $$ = initialize_node(">>");
  }
;

// 28
math-expression:
  math-expression add-sub-operator term {
    print_grammar_rule("math-expression add-sub\0");
    $$ = $2;
    node_t* math_expression = $$;
    node_t* recursive_math_expression = $1;
    node_t* term = $3;
    add_node(math_expression, recursive_math_expression);
    add_node(math_expression, term);
  }
  | term {
    print_grammar_rule("math-expression term\0");
    $$ = $1;
  }
;

// 29
add-sub-operator:
  ADD_OP {
    print_grammar_rule("add-sub-operator ADD_OP\0");
    $$ = initialize_node("+");
  }
  | SUB_OP {
    print_grammar_rule("add-sub-operator SUB_OP\0");
    $$ = initialize_node("-");
  }
;

// 30
term:
  term mul-div-operator not-expression {
    print_grammar_rule("term mul-div\0");
    $$ = $2;
    node_t* term = $$;
    node_t* recursive_term = $1;
    node_t* not_expression = $3;
    add_node(term, recursive_term);
    add_node(term, not_expression);
  }
  | not-expression {
    print_grammar_rule("term factor\0");
    $$ = $1;
  }
;

// 31
mul-div-operator:
  MULT_OP {
    print_grammar_rule("mul-div-operator mult\0");
    $$ = initialize_node("*");
  }
  | DIV_OP {
    print_grammar_rule("mul-div-operator div\0");
    $$ = initialize_node("/");
  }
;

// 32
not-expression:
  NOT_OR_TAIL_OP not-expression {
    print_grammar_rule("not-expression recursive\0");
    $$ = initialize_node("!");
    node_t* not_expression = $$;
    node_t* recursive_not_expression = $2;
    add_node(not_expression, recursive_not_expression);
  }
  | unary-sign-expression {
    print_grammar_rule("not-expressional unary-sign-expression");
    $$ = $1;
  };
;

// 33
unary-sign-expression:
  unary-operator unary-sign-expression {
    print_grammar_rule("unary-sign-expression recursive\0");
    $$ = $1;
    node_t* unary_sign_expression = $$;
    node_t* recursive_unary_sign_expression = $2;
    add_node(unary_sign_expression, recursive_unary_sign_expression);
  }
  | factor {
    print_grammar_rule("unary-sign-expression factor\0");
    $$ = $1;
  }
;

unary-operator:
  add-sub-operator {
    print_grammar_rule("unary-operator add-sub-operator\0");
    $$ = $1;
  }
  | LIST_HEAD_OP {
    print_grammar_rule("unary-operator LIST_HEAD_OP\0");
    $$ = initialize_node("?");
  }
  | LIST_TAIL_OP {
    print_grammar_rule("unary-operator LIST_TAIL_OP\0");
    $$ = initialize_node("%");
  }
;

// 34
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
    $$ = initialize_node($1.terminal_string);

    // Semantic
    if (!find_entry_in_symbol_table(current_symbol_table, $1.terminal_string)) {
      char error[10000];
      sprintf(error, "id \"%s\" was not declared", $1.terminal_string);
      semantic_error($1.line, $1.col, error);
    }

    free($1.terminal_string);
  }
  | LIST_CONST {
    print_grammar_rule("factor list const\0");
    $$ = initialize_node("NIL");
  }
;

// 35
func-call:
  ID LPARENTHESES args-list RPARENTHESES {
    print_grammar_rule("func-call\0");
    $$ = initialize_node("func-call");
    node_t* func_call = $$;
    node_t* id = initialize_node($1.terminal_string);
    node_t* args_list = $3;
    add_node(func_call, id);
    add_node(func_call, args_list);

    // printf("**********\n");
    // print_symbol_table(symbol_table, 0);
    // printf("**********\n");

    // Semantic
    if (!find_entry_in_symbol_table(current_symbol_table, id->name)) {
      char error[10000];
      sprintf(error, "id \"%s\" was not declared", id->name);
      semantic_error($1.line, $1.col, error);
    } else if(!check_number_of_arguments(symbol_table, id->name, args_list)) {
      char error[10000];
      sprintf(error, "function call \"%s\" has the wrong number of arguments", id->name);
      semantic_error($1.line, $1.col, error);
    }

    free($1.terminal_string);
  }
;

// 36
args-list:
  args {
    print_grammar_rule("args-list args\0");
    $$ = $1;
  }
  | %empty {
    print_grammar_rule("args-list empty\0");
    $$ = initialize_node("empty-args-list");
  }
;

// 37
args:
  args COMMA expression {
    print_grammar_rule("args multiple args\0");
    $$ = initialize_node("args");
    node_t* args = $$;
    node_t* recursive_args = $1;
    node_t* expression = $3;
    add_node(args, recursive_args);
    add_node(args, expression);
  }
  | expression {
    print_grammar_rule("args expression\0");
    $$ = initialize_node("args");
    node_t* args = $$;
    node_t* expression = $1;
    add_node(args, expression);
  }
;

// 43
numeric-const:
  FLOAT_CONST {
    print_grammar_rule("numeric-const unsgigned float const\0");
    $$ = initialize_node($1);
    free($1);
  }
  | INT_CONST {
    print_grammar_rule("numeric-const unsigned int const\0");
    $$ = initialize_node($1);
    free($1);
  }
;

// 44
output-arg:
  simple-expression {
    print_grammar_rule("output-arg simple-expression");
    $$ = $1;
  }
  | STRING_CONST {
    print_grammar_rule("output-arg string const");
    $$ = initialize_node($1);
    free($1);
  }
;

%%
int yyerror(const char * e) {
  printf("%s at line %d col %d\n", e, current_line, previous_col);
  return 0;
}

void semantic_error(int line, int col, char* msg) {
  printf("semantic error at line %d col %d: %s\n", line, col, msg);
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