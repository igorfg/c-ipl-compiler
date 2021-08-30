%defines "lib/syn.tab.h"
%define lr.type canonical-lr;
%define parse.error verbose
%define parse.trace
%locations
%{
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"

#define SYN_DEBUG_MODE

extern int yylex();
extern FILE * yyin;
extern int yydestroy();
extern int current_line;
extern int current_col;
int yyerror(const char * e);
static void print_grammar_rule(char*);
%}

/* Token declarations */
%token INT_TYPE
%token FLOAT_TYPE
%token INT_LIST_TYPE
%token FLOAT_LIST_TYPE
%token INT_CONST
%token FLOAT_CONST
%token LIST_CONST
%token STRING_CONST
%token ADD_OP
%token SUB_OP
%token MULT_OP
%token DIV_OP
%token NOT_OR_TAIL_OP
%token OR_OP
%token AND_OP
%token LIST_HEAD_OP
%token LIST_TAIL_OP
%token LIST_CONSTRUCTOR_OP
%token LIST_MAP_OP
%token LIST_FILTER_OP
%token LESSTHAN_OP
%token LESSEQUAL_OP
%token GREATERTHAN_OP
%token GREATEREQUAL_OP
%token NOTEQUAL_OP
%token EQUAL_OP
%token LBRACE
%token RBRACE
%token LPARENTHESES
%token RPARENTHESES
%token SEMICOLON
%token ASSIGNMENT
%token COMMA
%token FOR_KW
%token IF_KW
%token ELSE_KW
%token RETURN_KW
%token READ_KW
%token WRITE_KW
%token WRITELN_KW
%token ID

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
var-declaration: data-type ID SEMICOLON { print_grammar_rule("var-declaration\0"); };
// 5
data-type: INT_TYPE { print_grammar_rule("data-type INT_TYPE\0"); }
         | FLOAT_TYPE { print_grammar_rule("data-type FLOAT_TYPE\0"); }
         | INT_LIST_TYPE { print_grammar_rule("data-type INT_LIST_TYPE\0"); }
         | FLOAT_LIST_TYPE { print_grammar_rule("data-type FLOAT_LIST_TYPE\0"); };
// 6
func-declaration: data-type ID LPARENTHESES params-list RPARENTHESES block-statement { print_grammar_rule("func-declaration\0"); };
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

int main() {
  symbol_table = initialize_symbol_table("global");
  // At first our current symbol table is the root symbol table
  current_symbol_table = symbol_table;
  yyparse();
  return 0;
}