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

// #define SYN_DEBUG_MODE

extern int yylex();
extern int yylex_destroy();
extern FILE* yyin;
extern int yydestroy();
extern int current_line;
extern int previous_col;
extern int symbol_table_scope;
int has_syntax_error = 0;

int yyerror(const char*);
static void print_grammar_rule(char*);
%}

%union {
  char* terminal_string;
  struct node* node;
}

%type<node> program
%type<node> declaration-list
%type<node> declaration
%type<node> var-declaration
%type<node> data-type
%type<node> func-declaration
%type<node> params-list
%type<node> params
%type<node> param
%type<node> block-statement
%type<node> statement-or-declaration-list
%type<node> statement
%type<node> expression-statement
%type<node> conditional-statement
%type<node> iteration-statement
%type<node> return-statement
%type<node> input-statement
%type<node> output-statement
%type<node> write-call
%type<node> expression
%type<node> simple-expression
%type<node> relational-operator
%type<node> binary-logical-operator
%type<node> list-expression
%type<node> math-expression
%type<node> add-sub-operator
%type<node> term
%type<node> mul-div-operator
%type<node> factor
%type<node> func-call
%type<node> args-list
%type<node> args
%type<node> list-constructor
%type<node> list-constructor-expression
%type<node> list-func
%type<node> list-func-expression
%type<node> list-func-operator
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
%token<terminal_string> ID

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
  }
;

// 4
var-declaration:
  data-type ID SEMICOLON {
    print_grammar_rule("var-declaration\0");
    $$ = initialize_node("var-declaration");
    node_t* var_declaration = $$;
    node_t* data_type = $1;
    node_t* id = initialize_node($2);
    add_node(var_declaration, data_type);
    add_node(var_declaration, id);
    add_symbol_table_entry(current_symbol_table, id->name, data_type->name, 0);
    free($2);
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
  data-type ID LPARENTHESES params-list RPARENTHESES block-statement {
    print_grammar_rule("func-declaration\0");
    $$ = initialize_node("func-declaration");
    node_t* func_declaration = $$;
    node_t* data_type = $1;
    node_t* id = initialize_node($2);
    node_t* params_list = $4;
    node_t* block_statement = $6;
    add_node(func_declaration, data_type);
    add_node(func_declaration, id);
    // Checks for empty params list
    if (params_list != NULL) {
      add_node(func_declaration, params_list);
    }
    add_node(func_declaration, block_statement);
    add_symbol_table_entry(current_symbol_table, id->name, data_type->name, 1);
    free($2);
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
    node_t* id = initialize_node($2);
    add_node(param, data_type);
    add_node(param, id);
    save_func_param(id->name, data_type->name);
    free($2);
  }
;

// 10
block-statement:
  LBRACE statement-or-declaration-list RBRACE {
    print_grammar_rule("block-statement\0");
    $$ = $2;
  }
;

// 11
statement-or-declaration-list:
  statement-or-declaration-list statement {
    print_grammar_rule("statement-or-declaration-list statement\0");
    $$ = initialize_node("statement-or-declaration-list");
    node_t* statement_or_declaration_list = $$;
    node_t* recursive_statement_or_declaration = $1;
    node_t* statement = $2;
    if (recursive_statement_or_declaration != NULL) {
      add_node(statement_or_declaration_list, recursive_statement_or_declaration);
    }
    add_node(statement_or_declaration_list, statement);
  }
  | statement-or-declaration-list var-declaration {
    print_grammar_rule("statement-or-declaration-list var-declaration\0");
    $$ = initialize_node("statement-or-declaration-list");
    node_t* statement_or_declaration_list = $$;
    node_t* recursive_statement_or_declaration = $1;
    node_t* var_declaration = $2;
    // This checks if the last read symbol was %empty
    if (recursive_statement_or_declaration != NULL) {
      add_node(statement_or_declaration_list, recursive_statement_or_declaration);
    }
    add_node(statement_or_declaration_list, var_declaration);
  }
  | %empty {
    print_grammar_rule("statement-or-declaration-list empty\0");
    $$ = NULL;
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
  FOR_KW LPARENTHESES expression SEMICOLON expression SEMICOLON expression RPARENTHESES statement {
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

// 17
input-statement: 
  READ_KW LPARENTHESES ID RPARENTHESES SEMICOLON {
    print_grammar_rule("input-statement\0");
    $$ = initialize_node("read");
    node_t* input_statement = $$;
    node_t* id = initialize_node($3);
    add_node(input_statement, id);
    free($3);
  }
;

// 18
output-statement:
  write-call LPARENTHESES output-arg RPARENTHESES SEMICOLON {
    print_grammar_rule("output-statement simple-expression\0");
    $$ = $1;
    node_t* output_statement = $$;
    node_t* output_arg = $3;
    add_node(output_statement, output_arg);
  }
;

// 19
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

// 20
expression:
  ID ASSIGNMENT expression {
    print_grammar_rule("expression assigment\0");
    $$ = initialize_node("=");
    node_t* expression = $$;
    node_t* id = initialize_node($1);
    node_t* recursive_expression = $3;
    add_node(expression, id);
    add_node(expression, recursive_expression);
    free($1);
  }
  | simple-expression {
    print_grammar_rule("expression simple-expression\0");
    $$ = $1;
  }
;

// 21
simple-expression:
  math-expression relational-operator math-expression {
    print_grammar_rule("simple-expression relational-operator\0");
    $$ = $2;
    node_t* simple_expression = $$;
    node_t* first_math_expression = $1;
    node_t* second_math_expression = $3;
    add_node(simple_expression, first_math_expression);
    add_node(simple_expression, second_math_expression);
  }
  | math-expression binary-logical-operator math-expression {
    print_grammar_rule("simple-expression binary-logical-operator\0");
    $$ = initialize_node("simple-expression");
    node_t* simple_expression = $$;
    node_t* first_math_expression = $1;
    node_t* binary_logical_operator = $2;
    node_t* second_math_expression = $3;
    add_node(simple_expression, first_math_expression);
    add_node(simple_expression, binary_logical_operator);
    add_node(simple_expression, second_math_expression);
  }
  | NOT_OR_TAIL_OP math-expression {
    print_grammar_rule("simple-expression not or tail op\0");
    $$ = initialize_node("not");
    node_t* simple_expression = $$;
    node_t* math_expression = $2;
    add_node(simple_expression, math_expression);
  }
  | math-expression {
    print_grammar_rule("simple-expression math-expression\0");
    $$ = $1;
  }
  | list-expression {
    print_grammar_rule("simple-expression list-expression");
    $$ = $1;
  }
;

// 22
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

// 23
binary-logical-operator:
  AND_OP { 
    print_grammar_rule("binary-logical-operator AND\0");
    $$ = initialize_node($1);
  }
  | OR_OP { 
    print_grammar_rule("binary-logical-operator OR\0");
    $$ = initialize_node($1);
  }
;

// 24
list-expression:
  list-constructor {
    print_grammar_rule("list-expression list constructor\0");
    $$ = $1;
  }
  | list-func {
    print_grammar_rule("list-expression list func");
    $$ = $1;
  }
  | LIST_TAIL_OP ID {
    print_grammar_rule("list-expression list tail\0");
    $$ = initialize_node("%");
    node_t* list_expression = $$;
    node_t* id = initialize_node($2);
    add_node(list_expression, id);
  }
;

// 25
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

// 26
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

// 27
term:
  term mul-div-operator factor {
    print_grammar_rule("term mul-div\0");
    $$ = initialize_node("term");
    node_t* term = $$;
    node_t* recursive_term = $1;
    node_t* mul_div_operator = $2;
    node_t* factor = $3;
    add_node(term, recursive_term);
    add_node(term, mul_div_operator);
    add_node(term, factor);
  }
  | factor {
    print_grammar_rule("term factor\0");
    $$ = $1;
  }
;

// 28
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

// 29
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
  | LIST_HEAD_OP ID {
    print_grammar_rule("factor list head\0");
    $$ = initialize_node("?");
    node_t* factor = $$;
    node_t* id = initialize_node($2);
    add_node(factor, id);
    free($2);
  }
  | ID {
    print_grammar_rule("factor id\0");
    $$ = initialize_node($1);
    free($1);
  }
  | LIST_CONST {
    print_grammar_rule("factor list const\0");
    $$ = initialize_node("NIL");
  }
;

// 30
func-call:
  ID LPARENTHESES args-list RPARENTHESES {
    print_grammar_rule("func-call\0");
    $$ = initialize_node("func-call");
    node_t* func_call = $$;
    node_t* id = initialize_node($1);
    node_t* args_list = $3;
    add_node(func_call, id);
    add_node(func_call, args_list);
    free($1);
  }
;

// 31
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

// 32
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

// 33
list-constructor:
  list-constructor-expression LIST_CONSTRUCTOR_OP ID {
    print_grammar_rule("list-constructor\0");
    $$ = initialize_node(":");
    node_t* list_constructor = $$;
    node_t* list_constructor_expression = $1;
    node_t* id = initialize_node($3);
    add_node(list_constructor, list_constructor_expression);
    add_node(list_constructor, id);
    free($3);
  }
;

// 34
list-constructor-expression:
  list-constructor-expression LIST_CONSTRUCTOR_OP math-expression {
    print_grammar_rule("list-constructor-expression adding expression\0");
    $$ = initialize_node(":");
    node_t* list_constructor_expression = $$;
    node_t* recursive_list_constructor_expression = $1;
    node_t* math_expression = $3;
    add_node(list_constructor_expression, recursive_list_constructor_expression);
    add_node(list_constructor_expression, math_expression);
  }
  | math-expression {
    print_grammar_rule("list-constructor-expression finished\0");
    $$ = $1;
  }
;

// 35
list-func:
  list-func-expression list-func-operator ID {
    print_grammar_rule("list-func\0");
    $$ = $2;
    node_t* list_func = $$;
    node_t* list_func_expression = $1;
    node_t* id = initialize_node($3);
    add_node(list_func, list_func_expression);
    add_node(list_func, id);
    free($3);
  }
;

// 36
list-func-expression:
  list-func-expression list-func-operator ID {
    print_grammar_rule("list-func-expression multiple");
    $$ = $2;
    node_t* list_func_expression = $$;
    node_t* recursive_list_func_expression = $1;
    node_t* id = initialize_node($3);
    add_node(list_func_expression, recursive_list_func_expression);
    add_node(list_func_expression, id);
    free($3);
  }
  | ID {
    print_grammar_rule("list-func-expression single id");
    $$ = initialize_node($1);
    free($1);
  }
;

// 37
list-func-operator:
  LIST_MAP_OP {
    print_grammar_rule("list-func-operator map");
    $$ = initialize_node(">>");
  }
  | LIST_FILTER_OP {
    print_grammar_rule("list-func-operator filter");
    $$ = initialize_node("<<");
  }
;

// 38
numeric-const:
  add-sub-operator FLOAT_CONST {
    print_grammar_rule("numeric-const signed float const\0");
    $$ = $1;
    node_t* numeric_const = $$;
    node_t* float_const = initialize_node($2);
    add_node(numeric_const, float_const);
    free($2);
  }
  | add-sub-operator INT_CONST {
    print_grammar_rule("numeric-const signed int const\0");
    $$ = $1;
    node_t* numeric_const = $$;
    node_t* float_const = initialize_node($2);
    add_node(numeric_const, float_const);
    free($2);
  }
  | FLOAT_CONST {
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

// 39
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

static void print_grammar_rule(char* grammar_rule) {
#if defined SYN_DEBUG_MODE
  printf("Syn %s\n", grammar_rule);
#endif
}

int main() {
  func_params_list = NULL;
  // The root symbol table is the only one without a parent
  symbol_table = initialize_symbol_table(symbol_table_scope);
  // At first our current symbol table is the root symbol table
  current_symbol_table = symbol_table;
  yyparse();
  if (!has_syntax_error) {
    print_symbol_table(symbol_table, 0);
    printf("Syntax Tree\n");
    print_syntax_tree(syntax_tree, 0);
    free_symbol_table(symbol_table);
    free_syntax_tree(syntax_tree);
  } else{
    printf("Symbol table and syntax tree are not shown when a syntax error occurs\n");
  }
  yylex_destroy();
  return 0;
}