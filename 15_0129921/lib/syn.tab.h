/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LIB_SYN_TAB_H_INCLUDED
# define YY_YY_LIB_SYN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_TYPE = 258,                /* INT_TYPE  */
    FLOAT_TYPE = 259,              /* FLOAT_TYPE  */
    INT_LIST_TYPE = 260,           /* INT_LIST_TYPE  */
    FLOAT_LIST_TYPE = 261,         /* FLOAT_LIST_TYPE  */
    INT_CONST = 262,               /* INT_CONST  */
    FLOAT_CONST = 263,             /* FLOAT_CONST  */
    LIST_CONST = 264,              /* LIST_CONST  */
    STRING_CONST = 265,            /* STRING_CONST  */
    ADD_OP = 266,                  /* ADD_OP  */
    SUB_OP = 267,                  /* SUB_OP  */
    MULT_OP = 268,                 /* MULT_OP  */
    DIV_OP = 269,                  /* DIV_OP  */
    NOT_OR_TAIL_OP = 270,          /* NOT_OR_TAIL_OP  */
    OR_OP = 271,                   /* OR_OP  */
    AND_OP = 272,                  /* AND_OP  */
    LIST_HEAD_OP = 273,            /* LIST_HEAD_OP  */
    LIST_TAIL_OP = 274,            /* LIST_TAIL_OP  */
    LIST_CONSTRUCTOR_OP = 275,     /* LIST_CONSTRUCTOR_OP  */
    LIST_MAP_OP = 276,             /* LIST_MAP_OP  */
    LIST_FILTER_OP = 277,          /* LIST_FILTER_OP  */
    LESSTHAN_OP = 278,             /* LESSTHAN_OP  */
    LESSEQUAL_OP = 279,            /* LESSEQUAL_OP  */
    GREATERTHAN_OP = 280,          /* GREATERTHAN_OP  */
    GREATEREQUAL_OP = 281,         /* GREATEREQUAL_OP  */
    NOTEQUAL_OP = 282,             /* NOTEQUAL_OP  */
    EQUAL_OP = 283,                /* EQUAL_OP  */
    LBRACE = 284,                  /* LBRACE  */
    RBRACE = 285,                  /* RBRACE  */
    LPARENTHESES = 286,            /* LPARENTHESES  */
    RPARENTHESES = 287,            /* RPARENTHESES  */
    SEMICOLON = 288,               /* SEMICOLON  */
    ASSIGNMENT = 289,              /* ASSIGNMENT  */
    COMMA = 290,                   /* COMMA  */
    FOR_KW = 291,                  /* FOR_KW  */
    IF_KW = 292,                   /* IF_KW  */
    ELSE_KW = 293,                 /* ELSE_KW  */
    RETURN_KW = 294,               /* RETURN_KW  */
    READ_KW = 295,                 /* READ_KW  */
    WRITE_KW = 296,                /* WRITE_KW  */
    WRITELN_KW = 297,              /* WRITELN_KW  */
    ID = 298                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "src/syn.y"

  char* terminal_string;
  struct node* node;

#line 112 "lib/syn.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_LIB_SYN_TAB_H_INCLUDED  */
