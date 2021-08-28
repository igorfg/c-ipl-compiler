%defines "lib/syn.tab.h"
%define parse.error verbose
%debug
%locations
%{
#include <stdio.h>
#include <string.h>

extern int yylex();
extern FILE * yyin;
extern int yydestroy();
int yyerror(const char * e);
%}

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
%token GREATEREQUAl_OP
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

%%
program: declaration-list { printf("program\n"); };

declaration-list: declaration-list declaration | declaration { printf("declaration-list\n"); };

declaration: var-declaration { printf("declaration\n"); };

var-declaration: data-type ID SEMICOLON { printf("var-declaration\n"); };

data-type: INT_TYPE { printf("data-type INT_TYPE\n"); }
    | FLOAT_TYPE { printf("data-type FLOAT_TYPE\n"); }
    | INT_LIST_TYPE { printf("data-type INT_LIST_TYPE\n"); }
    | FLOAT_LIST_TYPE { printf("data-type FLOAT_LIST_TYPE\n"); };

%%

int yyerror(const char * e) {
  printf("%s", e);
  return 0;
}

int main() {
  yyparse();
  return 0;
}