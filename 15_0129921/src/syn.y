%defines "lib/syn.tab.h"
%define lr.type canonical-lr;
%define parse.error verbose
%define parse.trace
%locations
%{
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"

// #define SYN_DEBUG_MODE

typedef struct node node_t;

// Syntax abstract tree
struct node {
  node_t* first_node; 
  node_t* second_node;
  node_t* third_node; 
  node_t* fourth_node;
  char* name;             
  char* first_symbol;          
  char* second_symbol;
  char* third_symbol;          
};

extern int yylex();
extern FILE* yyin;
extern int yydestroy();
extern int current_line;
extern int current_col;

int yyerror(const char* e);
static void print_grammar_rule(char*);
node_t* add_node(node_t*, node_t*, node_t*, node_t*, char*, char*, char*, char*);
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
program: declaration-list { print_grammar_rule("program\0"); };
// 2
declaration-list: declaration-list declaration | declaration { print_grammar_rule("declaration-list\0"); };
// 3
declaration: var-declaration { print_grammar_rule("declaration var-declaration\0"); }
           | func-declaration { print_grammar_rule("declaration func-declaration\0"); };
// 4
var-declaration: data-type ID SEMICOLON {
                                          print_grammar_rule("var-declaration\0");
                                          $$ = add_node($1, NULL, NULL, NULL, "var-declaration", $2, NULL, NULL);
                                          // printf("%s %s\n", $2, $1->first_symbol);
                                          char* id = $2;
                                          char* data_type = $1->first_symbol;
                                          add_symbol_table_entry(current_symbol_table, id, data_type);
                                        };
// 5
data-type:
  INT_TYPE          {
                      print_grammar_rule("data-type INT_TYPE\0");
                      $$ = add_node(NULL, NULL, NULL, NULL, "data-type", $1, NULL, NULL);
                    }
  | FLOAT_TYPE      {
                      print_grammar_rule("data-type FLOAT_TYPE\0");
                      $$ = add_node(NULL, NULL, NULL, NULL, "data-type", $1, NULL, NULL);
                    }
  | INT_LIST_TYPE   {
                      print_grammar_rule("data-type INT_LIST_TYPE\0");
                      $$ = add_node(NULL, NULL, NULL, NULL, "data-type", $1, NULL, NULL);
                    }
  | FLOAT_LIST_TYPE {
                      print_grammar_rule("data-type FLOAT_LIST_TYPE\0");
                      $$ = add_node(NULL, NULL, NULL, NULL, "data-type", $1, NULL, NULL);
                    }
;
// 6
func-declaration:
  data-type ID LPARENTHESES params-list RPARENTHESES block-statement {
    print_grammar_rule("func-declaration\0");
    $$ = add_node($1, NULL, NULL, NULL, "func-declaration", $2, NULL, NULL);
    char* id = $2;
    char* data_type = "function";
    add_symbol_table_entry(current_symbol_table, id, data_type);
  }
;
// 7
params-list: params { print_grammar_rule("params-list params\0"); }
           | %empty { print_grammar_rule("params-list empty\0"); };
// 8
params: params COMMA param { print_grammar_rule("params multiple params\0"); }
      | param { print_grammar_rule("params single param\0"); }
// 9
param: data-type ID { print_grammar_rule("param\0"); };
// 10
block-statement: LBRACE statement-or-declaration-list RBRACE { print_grammar_rule("block-statement\0"); };
// 11
statement-or-declaration-list: statement-or-declaration-list statement { print_grammar_rule("statement-or-declaration-list statement\0"); }
                             | statement-or-declaration-list var-declaration { print_grammar_rule("statement-or-declaration-list var-declaration\0"); }
                             | %empty { print_grammar_rule("statement-or-declaration-list empty\0"); };
// 12
statement: expression-statement { print_grammar_rule("statement expression-statement\0"); }
         | block-statement { print_grammar_rule("statement block-statement\0"); }
         | conditional-statement { print_grammar_rule("statement conditional-statement\0"); }
         | iteration-statement { print_grammar_rule("statement iteration-statement\0"); }
         | return-statement { print_grammar_rule("statement return-statement\0"); }
         | input-statement { print_grammar_rule("statement input-statement\0"); }
         | output-statement { print_grammar_rule("statement output-statement\0"); };
// 13
expression-statement: expression SEMICOLON | SEMICOLON { print_grammar_rule("expression-statement\0"); };
// 14
conditional-statement: IF_KW LPARENTHESES expression RPARENTHESES statement { print_grammar_rule("conditional-statement IF\0"); }
                     | IF_KW LPARENTHESES expression RPARENTHESES statement ELSE_KW statement { print_grammar_rule("conditional-statement IF ELSE\0"); };
// 15
iteration-statement: FOR_KW LPARENTHESES expression SEMICOLON expression SEMICOLON expression RPARENTHESES statement { print_grammar_rule("iteration-statement\0"); };
// 16
return-statement: RETURN_KW SEMICOLON { print_grammar_rule("return-statement void\0"); }
                | RETURN_KW expression SEMICOLON { print_grammar_rule("return-statement expression\0"); };
// 17
input-statement: READ_KW LPARENTHESES ID RPARENTHESES SEMICOLON { print_grammar_rule("input-statement\0"); };
// 18
output-statement: write-call LPARENTHESES output-arg RPARENTHESES SEMICOLON { print_grammar_rule("output-statement simple-expression\0"); };
// 19
write-call: WRITE_KW { print_grammar_rule("write-call write\0"); }
          | WRITELN_KW { print_grammar_rule("write-call writeln\0"); };
// 20
expression: ID ASSIGNMENT expression { print_grammar_rule("expression assigment\0"); }
          | simple-expression { print_grammar_rule("expression simple-expression\0"); };
// 21
simple-expression: math-expression relational-operator math-expression { print_grammar_rule("simple-expression relational-operator\0"); }
                 | math-expression binary-logical-operator math-expression { print_grammar_rule("simple-expression binary-logical-operator\0"); }
                 | NOT_OR_TAIL_OP math-expression { print_grammar_rule("simple-expression not or tail op\0"); }
                 | math-expression { print_grammar_rule("simple-expression math-expression\0"); }
                 | list-expression { print_grammar_rule("simple-expression list-expression"); };
// 22
relational-operator: LESSTHAN_OP { print_grammar_rule("relational-operator LESSTHAN\0"); }
                   | LESSEQUAL_OP { print_grammar_rule("relational-operator LESSEQUAL\0"); }
                   | GREATERTHAN_OP { print_grammar_rule("relational-operator GREATERTHAN\0"); }
                   | GREATEREQUAL_OP { print_grammar_rule("relational-operator GREATEREQUAL\0"); }
                   | NOTEQUAL_OP { print_grammar_rule("relational-operator NOTEQUAL\0"); }
                   | EQUAL_OP { print_grammar_rule("relational-operator EQUAL\0"); };
// 23
binary-logical-operator: AND_OP { print_grammar_rule("binary-logical-operator AND\0"); }
                       | OR_OP { print_grammar_rule("binary-logical-operator OR\0"); };
// 24
list-expression: list-constructor { print_grammar_rule("list-expression list constructor\0"); }
               | list-func { print_grammar_rule("list-expression list func"); }
               | LIST_TAIL_OP math-expression { print_grammar_rule("list-expression list tail\0"); };
// 25
math-expression: math-expression add-sub-operator term { print_grammar_rule("math-expression add-sub\0"); }
               | term { print_grammar_rule("math-expression term\0"); };
// 26
add-sub-operator: ADD_OP { print_grammar_rule("add-sub-operator ADD_OP\0"); }
                | SUB_OP { print_grammar_rule("add-sub-operator SUB_OP\0"); };
// 27
term: term mul-div-operator factor { print_grammar_rule("term mul-div\0"); }
    | factor { print_grammar_rule("term factor\0"); };
// 28
mul-div-operator: MULT_OP { print_grammar_rule("mul-div-operator mult\0"); }
                | DIV_OP { print_grammar_rule("mul-div-operator div\0"); };
// 29
factor: LPARENTHESES expression RPARENTHESES { print_grammar_rule("factor expression\0"); }
      | func-call { print_grammar_rule("factor func-call\0"); }
      | numeric-const { print_grammar_rule("factor numeric-const\0"); }
      | LIST_HEAD_OP ID { print_grammar_rule("factor list head\0"); }
      | ID { print_grammar_rule("factor id\0"); }
      | LIST_CONST { print_grammar_rule("factor list const\0"); };
// 30
func-call: ID LPARENTHESES args-list RPARENTHESES { print_grammar_rule("func-call\0"); };
// 31
args-list: args { print_grammar_rule("args-list args\0"); }
         | %empty { print_grammar_rule("args-list empty\0"); };
// 32
args: args COMMA expression { print_grammar_rule("args multiple args\0"); }
    | expression { print_grammar_rule("args expression\0"); };
// 33
list-constructor: list-constructor-expression LIST_CONSTRUCTOR_OP ID  { print_grammar_rule("list-constructor\0"); };
// 34
list-constructor-expression: list-constructor-expression LIST_CONSTRUCTOR_OP math-expression { print_grammar_rule("list-constructor-expression adding expression\0"); }
                           | math-expression { print_grammar_rule("list-constructor-expression finished\0"); };
// 35
list-func: list-func-expression list-func-operator ID { print_grammar_rule("list-func\0"); };
// 36
list-func-expression: list-func-expression list-func-operator ID { print_grammar_rule("list-func-expression multiple"); }
                        | ID { print_grammar_rule("list-func-expression single id"); };
// 37
list-func-operator: LIST_MAP_OP { print_grammar_rule("list-func-operator map"); }
                      | LIST_FILTER_OP { print_grammar_rule("list-func-operator filter"); };
// 38
numeric-const: add-sub-operator FLOAT_CONST { print_grammar_rule("numeric-const signed float const\0"); }
             | add-sub-operator INT_CONST { print_grammar_rule("numeric-const signed int const\0"); }
             | FLOAT_CONST { print_grammar_rule("numeric-const unsgigned float const\0"); }
             | INT_CONST { print_grammar_rule("numeric-const unsigned int const\0"); };
// 39
output-arg: simple-expression { print_grammar_rule("output-arg simple-expression"); }
          | STRING_CONST { print_grammar_rule("output-arg string const"); };
%%
int yyerror(const char * e) {
  printf("%s at line %d col %d\n", e, current_line-1, current_col);
  return 0;
}

static void print_grammar_rule(char* grammar_rule) {
#if defined SYN_DEBUG_MODE
  printf("Syn %s\n", grammar_rule);
#endif
}

node_t* add_node(
  node_t* first_node, node_t* second_node, node_t* third_node,
  node_t* fourth_node, char* name, char* first_symbol, char* second_symbol, char* third_symbol
) {
  node_t* node = (node_t*)malloc(sizeof(node_t));
  node->first_node = first_node;
  node->second_node = second_node;
  node->third_node = third_node;
  node->fourth_node = fourth_node;
  node->name = name;
  node->first_symbol = first_symbol;
  node->second_symbol = second_symbol;
  node->third_symbol = third_symbol;

  return node;
}

int main() {
  symbol_table = initialize_symbol_table("global");
  // At first our current symbol table is the root symbol table
  current_symbol_table = symbol_table;
  yyparse();
  print_symbol_table(symbol_table, 0);
  return 0;
}