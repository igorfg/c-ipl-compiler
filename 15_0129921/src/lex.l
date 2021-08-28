/* Options to generate the output file without the need of extra declarations */
%option noinput
%option nounput
%option noyywrap
%{
#define DEBUG_MODE

/* Declarations */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../lib/syn.tab.h"

int current_line = 1;
int current_col = 1;
int previous_col;
int comment_block_line_begin;

static void update_position(int);
static void print_token(char*, char*);
%}

/* Directives for comment block or comment lines */
%x COMMENT_LINE
%x COMMENT_BLOCK

/* REGEX declarations to increase code readability */
DELIM        [ \t\n]
WHITESPACE   {DELIM}+
DIGIT        [0-9]
LETTER       [a-zA-Z]
ID           ({LETTER}|"_")+({LETTER}|{DIGIT}|"_")*
INT_CONST    [+-]?{DIGIT}+
FLOAT_CONST  [+-]?{DIGIT}*(\.{DIGIT}+)
LIST_CONST   NIL
STRING_CONST ["]([^"\\\n]|\\(.|\n))*["]
UNIFINISHED_STRING_CONST ["]([^"\\\n]|\\(.|\n))*

%%
  /*Ignore whitespaces*/
{WHITESPACE}                { update_position(0); }

  /* Multiline Comments */
"/*"                        { 
                              comment_block_line_begin = current_line;
                              update_position(0);
                              BEGIN(COMMENT_BLOCK);
                            }
<COMMENT_BLOCK>"*/"         { update_position(0); BEGIN(INITIAL); }
<COMMENT_BLOCK>\n           { update_position(0); }
<COMMENT_BLOCK>.            { update_position(0); }
  /*
  If it reaches EOF while still in a comment block it notifies a special error
  https://westes.github.io/flex/manual/EOF.html
  https://stackoverflow.com/questions/29991073/checking-unfinished-comments-in-flex
   */
<COMMENT_BLOCK><<EOF>>      { 
                              printf("/* never ending comment block at line %d\n", comment_block_line_begin);
                              yyterminate();
                            }

  /* Single line comments */
"//"                        { update_position(0); BEGIN(COMMENT_LINE); }
<COMMENT_LINE>\n            { update_position(0); BEGIN(INITIAL); }
<COMMENT_LINE>.             { update_position(0); }

  /* Data types are int, float elem and set */
"int"                       { update_position(1); print_token("INT_TYPE\0", yytext); return INT_TYPE; }
"float"                     { update_position(1); print_token("FLOAT_TYPE\0", yytext); return FLOAT_TYPE; }
"int list"                  { update_position(1); print_token("INT_LIST_TYPE\0", yytext); return INT_LIST_TYPE; }
"float list"                { update_position(1); print_token("FLOAT_LIST_TYPE\0", yytext); return FLOAT_LIST_TYPE; }

  /* Char os string constant with single or double quotes */

  /* Constants */
{INT_CONST}                 { update_position(1); print_token("INT_CONST\0", yytext); return INT_CONST; }
{FLOAT_CONST}               { update_position(1); print_token("FLOAT_CONST\0", yytext); return FLOAT_CONST; }
{LIST_CONST}                { update_position(1); print_token("LIST_CONST\0", yytext); return LIST_CONST; }
{STRING_CONST}              { update_position(1); print_token("STRING_CONST\0", yytext); return STRING_CONST; }
{UNIFINISHED_STRING_CONST}  { 
                              printf("Error: \" at line %d, column %d does not have a closing \"\n", current_line, current_col);
                              update_position(0);
                            }


  /* Definition of operators */
"+"                         { update_position(1); print_token("ADD_OP\0", yytext); return ADD_OP; }
"-"                         { update_position(1); print_token("SUB_OP\0", yytext); return SUB_OP; }
"*"                         { update_position(1); print_token("MULT_OP\0", yytext); return MULT_OP; }
"/"                         { update_position(1); print_token("DIV_OP\0", yytext); return DIV_OP; }

  /* Logical operators */
"!"                         { update_position(1); print_token("NOT_OR_TAIL_OP\0", yytext); return NOT_OR_TAIL_OP; }
"||"                        { update_position(1); print_token("OR_OP\0", yytext); return OR_OP; }
"&&"                        { update_position(1); print_token("AND_OP\0", yytext); return AND_OP; }

  /* List type operators - List tail operator is the same as logic negation at the moment */
"?"                         { update_position(1); print_token("LIST_HEAD_OP\0", yytext); return LIST_HEAD_OP; }
"%"                         { update_position(1); print_token("LIST_TAIL_OP\0", yytext); return LIST_TAIL_OP; }
":"                         { update_position(1); print_token("LIST_CONSTRUCTOR_OP\0", yytext); return LIST_CONSTRUCTOR_OP; }
">>"                        { update_position(1); print_token("LIST_MAP_OP\0", yytext); return LIST_MAP_OP; }
"<<"                        { update_position(1); print_token("LIST_FILTER_OP\0", yytext); return LIST_FILTER_OP; }

  /* Relational operators */
"<"                         { update_position(1); print_token("LESSTHAN_OP\0", yytext); return LESSTHAN_OP; }
"<="                        { update_position(1); print_token("LESSEQUAL_OP\0", yytext); return LESSEQUAL_OP; }
">"                         { update_position(1); print_token("GREATERTHAN_OP\0", yytext); return GREATERTHAN_OP; }
">="                        { update_position(1); print_token("GREATEREQUAl_OP\0", yytext); return GREATEREQUAl_OP; }
"!="                        { update_position(1); print_token("NOTEQUAL_OP\0", yytext); return NOTEQUAL_OP; }
"=="                        { update_position(1); print_token("EQUAL_OP\0", yytext); return EQUAL_OP; }

  /* Delimiters, assignments and block symbols */
"{"                         { update_position(1); print_token("LBRACE\0", yytext); return LBRACE; }
"}"                         { update_position(1); print_token("RBRACE\0", yytext); return RBRACE; }
"("                         { update_position(1); print_token("LPARENTHESES\0", yytext); return LPARENTHESES; }
")"                         { update_position(1); print_token("RPARENTHESES\0", yytext); return RPARENTHESES; }
";"                         { update_position(1); print_token("SEMICOLON\0", yytext); return SEMICOLON; }
"="                         { update_position(1); print_token("ASSIGNMENT\0", yytext); return ASSIGNMENT; }
","                         { update_position(1); print_token("COMMA\0", yytext); return COMMA; }

  /* Flow control */
"for"                       { update_position(1); print_token("FOR_KW\0", yytext); return FOR_KW; }
"if"                        { update_position(1); print_token("IF_KW\0", yytext); return IF_KW; }
"else"                      { update_position(1); print_token("ELSE_KW\0", yytext); return ELSE_KW; }
"return"                    { update_position(1); print_token("RETURN_KW\0", yytext); return RETURN_KW; }

  /* Input and Output */
"read"                      { update_position(1); print_token("READ_KW\0", yytext); return READ_KW; }
"write"                     { update_position(1); print_token("WRITE_KW\0", yytext); return WRITE_KW; }
"writeln"                   { update_position(1); print_token("WRITELN_KW\0", yytext); return WRITELN_KW; }
  
  /* ID Definition */
{ID}                        { update_position(1); print_token("ID\0", yytext); return ID; }

  /* Error handling */
.                           {
                              update_position(0);
                              printf("Token not recognized: \"%s\". Line: %d, Column: %d\n", yytext, current_line, current_col);
                            }

%%

/* Updates line in case of newline and updates column otherwise */
static void update_position(int should_print_line_number) {
#ifdef DEBUG_MODE
  if (should_print_line_number) {
    printf("Lex %d: ", current_line);
  }
#endif
  previous_col = current_col;
  for (int nsymbol = 0; nsymbol < yyleng; ++nsymbol) {
    if (yytext[nsymbol] == '\n') {
      current_col = 1;
      previous_col = 1;
      current_line++;
    } else {
      current_col++;
    }
  }
}

static void print_token(char* token_name, char* yytext) {
#if defined DEBUG_MODE
  printf("<%s,%s>\n", token_name, yytext);
#endif
}
