/* Options to generate the output file without the need of extra declarations */
%option noinput nounput
%option noyywrap
%{
/* Declarations */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int current_line = 1;
int current_col = 1;
int previous_col;
int comment_block_line_begin;

static void update_position(int);
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
"int"                       { update_position(1); printf("<INT_TYPE,%s>\n", yytext); }
"float"                     { update_position(1); printf("<FLOAT_TYPE,%s>\n", yytext); }
"int list"                  { update_position(1); printf("<INT_LIST_TYPE,%s>\n", yytext); }
"float list"                { update_position(1); printf("<FLOAT_LIST_TYPE,%s>\n", yytext); }

  /* Char os string constant with single or double quotes */

  /* Constants */
{INT_CONST}                 { update_position(1); printf("<INT_CONST,%s>\n", yytext); }
{FLOAT_CONST}               { update_position(1); printf("<FLOAT_CONST,%s>\n", yytext); }
{LIST_CONST}                { update_position(1); printf("<LIST_CONST,%s>\n", yytext); }
{STRING_CONST}              { update_position(1); printf("<STRING_CONST,%s>\n", yytext); }
{UNIFINISHED_STRING_CONST}  { 
                              printf("Error: \" at line %d, column %d does not have a closing \"\n", current_line, current_col);
                              update_position(0);
                            }


  /* Definition of operators */
"+"                         { update_position(1); printf("<ADD_OP,%s>\n", yytext); }
"-"                         { update_position(1); printf("<SUB_OP,%s>\n", yytext); }
"*"                         { update_position(1); printf("<MULT_OP,%s>\n", yytext); }
"/"                         { update_position(1); printf("<DIV_OP,%s>\n", yytext); }

  /* Logical operators */
"!"                         { update_position(1); printf("<NOT_OR_LIST_TAIL_OP,%s>\n", yytext); }
"||"                        { update_position(1); printf("<OR_OP,%s>\n", yytext); }
"&&"                        { update_position(1); printf("<AND_OP,%s>\n", yytext); }

  /* List type operators - List tail operator is the same as logic negation at the moment */
"?"                         { update_position(1); printf("<LIST_HEAD_OP,%s>\n", yytext); }
"%"                         { update_position(1); printf("<LIST_TAIL_OP,%s>\n", yytext); }
":"                         { update_position(1); printf("<LIST_CONSTRUCTOR_OP,%s>\n", yytext); }
">>"                        { update_position(1); printf("<LIST_MAP_OP,%s>\n", yytext); }
"<<"                        { update_position(1); printf("<LIST_FILTER_OP,%s>\n", yytext); }

  /* Relational operators */
"<"                         { update_position(1); printf("<LESSTHAN_OP,%s>\n", yytext); }
"<="                        { update_position(1); printf("<LESSEQUAL_OP,%s>\n", yytext); }
">"                         { update_position(1); printf("<GREATERTHAN_OP,%s>\n", yytext); }
">="                        { update_position(1); printf("<GREATEREQUAl_OP,%s>\n", yytext); }
"!="                        { update_position(1); printf("<NOTEQUAL_OP,%s>\n", yytext); }
"=="                        { update_position(1); printf("<COMPARISON_OP,%s>\n", yytext); }

  /* Delimiters, assignments and block symbols */
"{"                         { update_position(1); printf("<LBRACE,%s>\n", yytext); }
"}"                         { update_position(1); printf("<RBRACE,%s>\n", yytext); }
"("                         { update_position(1);printf("<LPARENTHESIS,%s>\n", yytext); }
")"                         { update_position(1); printf("<RPARENTHESIS,%s>\n", yytext); }
";"                         { update_position(1); printf("<SEMICOLON,%s>\n", yytext); }
"="                         { update_position(1); printf("<ASSIGNMENT,%s>\n", yytext); }
","                         { update_position(1); printf("<COMMA,%s>\n", yytext); }

  /* Flow control */
"for"                       { update_position(1); printf("<FOR_KW,%s>\n", yytext); }
"if"                        { update_position(1); printf("<IF_KW,%s>\n", yytext); }
"else"                      { update_position(1); printf("<ELSE_KW,%s>\n", yytext); }
"return"                    { update_position(1); printf("<RETURN_KW,%s>\n", yytext); }

  /* Input and Output */
"read"                      { update_position(1); printf("<READ_KW,%s>\n", yytext); }
"write"                     { update_position(1); printf("<WRITE_KW,%s>\n", yytext); }
"writeln"                   { update_position(1); printf("<WRITELN_KW,%s>\n", yytext); }
  
  /* ID Definition */
{ID}                        {
                              update_position(1);
                              printf("<ID,%s>\n", yytext);
                            }

  /* Error handling */
.                           {
                              update_position(0);
                              printf("Token not recognized: \"%s\". Line: %d, Column: %d\n", yytext, current_line, current_col);
                            }

%%

/* Updates line in case of newline and updates column otherwise */
static void update_position(int should_print_line_number) {
  if (should_print_line_number) {
    printf("%d: ", current_line);
  }
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

int main() {
  yylex();
  return 0;
}
