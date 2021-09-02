/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "src/syn.y"

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
int has_syntax_error = 0;

int yyerror(const char*);
static void print_grammar_rule(char*);

#line 91 "src/syn.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "syn.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_TYPE = 3,                   /* INT_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 4,                 /* FLOAT_TYPE  */
  YYSYMBOL_INT_LIST_TYPE = 5,              /* INT_LIST_TYPE  */
  YYSYMBOL_FLOAT_LIST_TYPE = 6,            /* FLOAT_LIST_TYPE  */
  YYSYMBOL_INT_CONST = 7,                  /* INT_CONST  */
  YYSYMBOL_FLOAT_CONST = 8,                /* FLOAT_CONST  */
  YYSYMBOL_LIST_CONST = 9,                 /* LIST_CONST  */
  YYSYMBOL_STRING_CONST = 10,              /* STRING_CONST  */
  YYSYMBOL_ADD_OP = 11,                    /* ADD_OP  */
  YYSYMBOL_SUB_OP = 12,                    /* SUB_OP  */
  YYSYMBOL_MULT_OP = 13,                   /* MULT_OP  */
  YYSYMBOL_DIV_OP = 14,                    /* DIV_OP  */
  YYSYMBOL_NOT_OR_TAIL_OP = 15,            /* NOT_OR_TAIL_OP  */
  YYSYMBOL_OR_OP = 16,                     /* OR_OP  */
  YYSYMBOL_AND_OP = 17,                    /* AND_OP  */
  YYSYMBOL_LIST_HEAD_OP = 18,              /* LIST_HEAD_OP  */
  YYSYMBOL_LIST_TAIL_OP = 19,              /* LIST_TAIL_OP  */
  YYSYMBOL_LIST_CONSTRUCTOR_OP = 20,       /* LIST_CONSTRUCTOR_OP  */
  YYSYMBOL_LIST_MAP_OP = 21,               /* LIST_MAP_OP  */
  YYSYMBOL_LIST_FILTER_OP = 22,            /* LIST_FILTER_OP  */
  YYSYMBOL_LESSTHAN_OP = 23,               /* LESSTHAN_OP  */
  YYSYMBOL_LESSEQUAL_OP = 24,              /* LESSEQUAL_OP  */
  YYSYMBOL_GREATERTHAN_OP = 25,            /* GREATERTHAN_OP  */
  YYSYMBOL_GREATEREQUAL_OP = 26,           /* GREATEREQUAL_OP  */
  YYSYMBOL_NOTEQUAL_OP = 27,               /* NOTEQUAL_OP  */
  YYSYMBOL_EQUAL_OP = 28,                  /* EQUAL_OP  */
  YYSYMBOL_LBRACE = 29,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 30,                    /* RBRACE  */
  YYSYMBOL_LPARENTHESES = 31,              /* LPARENTHESES  */
  YYSYMBOL_RPARENTHESES = 32,              /* RPARENTHESES  */
  YYSYMBOL_SEMICOLON = 33,                 /* SEMICOLON  */
  YYSYMBOL_ASSIGNMENT = 34,                /* ASSIGNMENT  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_FOR_KW = 36,                    /* FOR_KW  */
  YYSYMBOL_IF_KW = 37,                     /* IF_KW  */
  YYSYMBOL_ELSE_KW = 38,                   /* ELSE_KW  */
  YYSYMBOL_RETURN_KW = 39,                 /* RETURN_KW  */
  YYSYMBOL_READ_KW = 40,                   /* READ_KW  */
  YYSYMBOL_WRITE_KW = 41,                  /* WRITE_KW  */
  YYSYMBOL_WRITELN_KW = 42,                /* WRITELN_KW  */
  YYSYMBOL_ID = 43,                        /* ID  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_46_declaration_list = 46,       /* declaration-list  */
  YYSYMBOL_declaration = 47,               /* declaration  */
  YYSYMBOL_48_var_declaration = 48,        /* var-declaration  */
  YYSYMBOL_49_data_type = 49,              /* data-type  */
  YYSYMBOL_50_func_declaration = 50,       /* func-declaration  */
  YYSYMBOL_51_params_list = 51,            /* params-list  */
  YYSYMBOL_params = 52,                    /* params  */
  YYSYMBOL_param = 53,                     /* param  */
  YYSYMBOL_54_block_statement = 54,        /* block-statement  */
  YYSYMBOL_55_statement_or_declaration_list = 55, /* statement-or-declaration-list  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_57_expression_statement = 57,   /* expression-statement  */
  YYSYMBOL_58_conditional_statement = 58,  /* conditional-statement  */
  YYSYMBOL_59_iteration_statement = 59,    /* iteration-statement  */
  YYSYMBOL_60_return_statement = 60,       /* return-statement  */
  YYSYMBOL_61_input_statement = 61,        /* input-statement  */
  YYSYMBOL_62_output_statement = 62,       /* output-statement  */
  YYSYMBOL_63_write_call = 63,             /* write-call  */
  YYSYMBOL_expression = 64,                /* expression  */
  YYSYMBOL_65_simple_expression = 65,      /* simple-expression  */
  YYSYMBOL_66_relational_operator = 66,    /* relational-operator  */
  YYSYMBOL_67_binary_logical_operator = 67, /* binary-logical-operator  */
  YYSYMBOL_68_list_expression = 68,        /* list-expression  */
  YYSYMBOL_69_math_expression = 69,        /* math-expression  */
  YYSYMBOL_70_add_sub_operator = 70,       /* add-sub-operator  */
  YYSYMBOL_term = 71,                      /* term  */
  YYSYMBOL_72_mul_div_operator = 72,       /* mul-div-operator  */
  YYSYMBOL_factor = 73,                    /* factor  */
  YYSYMBOL_74_func_call = 74,              /* func-call  */
  YYSYMBOL_75_args_list = 75,              /* args-list  */
  YYSYMBOL_args = 76,                      /* args  */
  YYSYMBOL_77_list_constructor = 77,       /* list-constructor  */
  YYSYMBOL_78_list_constructor_expression = 78, /* list-constructor-expression  */
  YYSYMBOL_79_list_func = 79,              /* list-func  */
  YYSYMBOL_80_list_func_expression = 80,   /* list-func-expression  */
  YYSYMBOL_81_list_func_operator = 81,     /* list-func-operator  */
  YYSYMBOL_82_numeric_const = 82,          /* numeric-const  */
  YYSYMBOL_83_output_arg = 83              /* output-arg  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4493

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  373

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   120,   120,   129,   138,   146,   150,   154,   161,   176,
     180,   184,   188,   196,   211,   214,   221,   224,   231,   239,
     246,   249,   252,   259,   262,   265,   268,   271,   274,   277,
     284,   287,   294,   297,   304,   311,   314,   321,   329,   336,
     339,   346,   350,   357,   360,   363,   366,   369,   376,   379,
     382,   385,   388,   391,   398,   401,   408,   411,   414,   421,
     424,   431,   434,   441,   444,   451,   454,   461,   464,   467,
     470,   474,   478,   485,   493,   496,   503,   506,   513,   521,
     524,   531,   539,   543,   551,   554,   561,   564,   567,   570,
     577,   580
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_TYPE",
  "FLOAT_TYPE", "INT_LIST_TYPE", "FLOAT_LIST_TYPE", "INT_CONST",
  "FLOAT_CONST", "LIST_CONST", "STRING_CONST", "ADD_OP", "SUB_OP",
  "MULT_OP", "DIV_OP", "NOT_OR_TAIL_OP", "OR_OP", "AND_OP", "LIST_HEAD_OP",
  "LIST_TAIL_OP", "LIST_CONSTRUCTOR_OP", "LIST_MAP_OP", "LIST_FILTER_OP",
  "LESSTHAN_OP", "LESSEQUAL_OP", "GREATERTHAN_OP", "GREATEREQUAL_OP",
  "NOTEQUAL_OP", "EQUAL_OP", "LBRACE", "RBRACE", "LPARENTHESES",
  "RPARENTHESES", "SEMICOLON", "ASSIGNMENT", "COMMA", "FOR_KW", "IF_KW",
  "ELSE_KW", "RETURN_KW", "READ_KW", "WRITE_KW", "WRITELN_KW", "ID",
  "$accept", "program", "declaration-list", "declaration",
  "var-declaration", "data-type", "func-declaration", "params-list",
  "params", "param", "block-statement", "statement-or-declaration-list",
  "statement", "expression-statement", "conditional-statement",
  "iteration-statement", "return-statement", "input-statement",
  "output-statement", "write-call", "expression", "simple-expression",
  "relational-operator", "binary-logical-operator", "list-expression",
  "math-expression", "add-sub-operator", "term", "mul-div-operator",
  "factor", "func-call", "args-list", "args", "list-constructor",
  "list-constructor-expression", "list-func", "list-func-expression",
  "list-func-operator", "numeric-const", "output-arg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
#endif

#define YYPACT_NINF (-160)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-92)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     380,   474,   -34,   -27,   -19,   -12,    35,  1918,  1959,  2000,
       3,  2041,  -160,  2082,    52,    74,  2123,    15,    33,     7,
       9,    16,    42,   705,  2226,  2164,    24,  2267,  3727,  3745,
    3763,   304,   332,   593,    32,   593,  2205,   393,  2308,    56,
      58,    14,    62,    82,    84,  3656,  2349,    77,  2390,  2431,
    2472,  2513,  2554,  2595,  2636,  2677,   120,    68,    94,   112,
     203,   336,  3781,  3799,  3817,   156,   173,   174,   338,  3835,
     542,    57,  3853,   111,   180,   482,   393,  2718,   184,   181,
     128,   482,   199,   442,  2759,   673,   733,   779,   847,   890,
     970,  1088,  1117,   593,   593,  1144,  3871,  3889,  1235,  1280,
    1144,  1376,   196,   198,   204,  3907,   221,   233,  2800,   243,
     126,   262,   132,   284,   273,  4015,   287,   291,   185,   248,
    3925,  3943,   723,   114,    97,   482,    55,   317,  3961,   550,
     320,   329,   499,  2841,   146,  2882,   393,  1432,   342,  2923,
    1432,  2964,  2226,   839,   849,  1020,   339,   393,   360,  1225,
    1331,  1446,  1472,  4059,  4081,  4103,  1469,   345,  1469,   393,
    3680,   377,   381,  4363,   364,  4125,  4147,  4169,   383,   406,
     395,   338,  4191,  1495,  1521,   128,   593,  3284,  3309,  3334,
    1548,   376,  1548,   393,  3234,   211,   226,  3631,   387,  3359,
    3384,  3409,   257,   411,   272,   338,  3434,  3005,  3704,   572,
     629,   926,   389,   393,   391,   980,  1055,  1187,  1385,   128,
     128,  3142,  2226,   796,   404,   412,   161,   413,  1566,  1610,
    1652,  1693,  1734,  1775,  1816,   414,   397,  3046,  1503,   405,
    1534,  3219,   593,   142,  1109,  3184,   415,   393,  3170,   245,
     399,  4385,  4389,  4393,  4397,  4213,   252,   416,   393,  1469,
    1469,  3168,  4235,  4257,  3168,  3182,   419,   423,  3979,   316,
     344,   644,   424,   393,   171,    -5,   410,   683,   757,   941,
    1007,  3459,    70,   427,   128,   550,  1548,  1548,  3196,  3484,
    3509,  3196,  3210,   425,  1622,   438,  1664,  1705,  3142,   439,
     449,   452,  1746,  3087,   482,   393,  1857,   459,   466,   442,
    1898,  3128,  3984,  3988,  4401,   463,   128,  1469,  4423,  4427,
    1469,  4279,   480,   276,   289,  4037,  4301,  4323,  4002,   288,
    3992,  1048,   487,   128,  1548,  1249,  1319,  1548,  3534,   489,
     303,    96,   130,  3259,  3559,  3584,   302,   178,  1787,  1828,
    4345,  1869,  1939,   491,   494,  1980,   501,   514,  4431,   515,
    4435,  4439,  1324,   516,  1336,  1389,  3609,   482,    55,   527,
     530,  4461,  1397,   531,  2021,  2062,  2103,   393,    55,   534,
    2144,    55,  2185
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -160,  -160,  -160,   560,     5,   109,  -160,  -160,  -160,   433,
     -22,  -140,  -123,  -118,  -116,   -92,   -88,   -86,   -72,   -65,
     -26,   929,  -159,  -150,  1011,   934,   115,   748,  -129,   340,
     451,  -157,  -160,  1066,  1143,  1245,  1287,  -152,   637,   271
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,    46,    47,    11,    18,    19,    20,
      48,    27,    49,    50,    51,    52,    53,    54,    55,    56,
     110,    58,    93,    94,    59,    60,    61,    62,   100,    63,
      64,   111,   112,    65,    66,    67,    68,   104,    69,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    57,   227,   132,   249,     9,   173,   174,   219,    -9,
     220,    74,     9,   250,   139,    78,   -10,   141,   257,   256,
     232,    28,    29,    30,   -11,    31,    32,   -45,   276,    33,
     -45,   -12,    34,    35,   221,    12,   254,   277,   222,   -14,
     223,   -17,    23,   283,   -17,    37,    14,    77,   -18,   106,
     107,   -18,   289,   290,   224,   113,   -16,    45,    21,   -16,
     281,   225,    28,    29,    30,    22,    31,    32,   173,   174,
      33,    24,   293,    34,    35,    72,   288,     2,     3,     4,
       5,   173,   174,    15,   212,    16,    37,    75,   213,    76,
     -45,   214,   215,    79,   216,   217,    43,    44,    45,   131,
     226,    84,   -58,   134,   218,   -58,   -15,   173,   174,    10,
     138,    57,   310,   -39,    57,   -40,    10,   329,   -82,   -82,
      82,   229,   173,   174,    17,   173,   174,   -42,   -43,   232,
     -81,   -43,    17,   247,   -79,   177,   178,   179,   327,    31,
      32,   173,   174,   180,   -58,   -47,   181,   182,   148,   349,
     148,    83,   164,   -89,   -89,   -89,   -89,   273,   -77,   183,
     -75,   -77,   -44,   288,   -74,   -44,   353,   129,    28,    29,
      30,   184,    31,    32,   -89,    95,    33,   285,   -76,    34,
      35,   -76,   -71,   -71,   -71,   -71,   176,   254,   176,   -56,
     297,   164,    37,   101,   296,   188,   173,   174,   164,   -82,
     -82,    57,   323,   -71,    45,   281,   -71,   -57,   148,   148,
     -81,   305,   105,   -81,   173,   174,   204,   108,   -43,    85,
      86,   310,   312,   -80,   109,   327,    87,    88,    89,    90,
      91,    92,   197,   176,   176,   364,   -46,   322,   211,   -84,
     219,   -85,   220,   -42,   188,   370,   -42,   124,   372,   330,
     219,   164,   220,   219,   125,   220,   173,   174,   -47,   173,
     174,   -47,   164,   173,   174,   126,   221,    57,   343,   344,
     222,   240,   223,   240,   164,   127,   221,   -45,   251,   221,
     222,   -44,   223,   222,   -58,   223,   224,   173,   174,   -56,
     188,   148,   -56,   225,   128,   266,   224,   266,   164,   224,
     173,   174,   278,   225,   -57,   -91,   225,   -57,   -43,   -82,
     -82,   -61,   -61,   -71,   -71,   -71,   -71,   -41,   164,   -90,
     -81,   -44,   -71,   130,   188,   188,   204,   -89,   -89,   -89,
     -89,   363,   226,   210,   -78,   -41,   218,   -78,   -41,   -62,
     -62,   369,   226,    96,    97,   226,   218,   148,   -89,   218,
     133,   -89,   164,   135,   307,   -88,   -88,   -88,   -88,   102,
     103,   307,   136,   164,   240,   240,   164,   230,   231,   164,
     204,   252,   253,   150,   140,   150,   -88,   166,   164,   -88,
     324,     1,   228,     2,     3,     4,     5,   324,   245,   188,
     188,   266,   266,   188,   279,   280,   188,   204,   286,   287,
     153,   154,   155,   204,    31,    32,   308,   309,   156,   -42,
     164,   157,   158,   -47,   164,   -56,   166,   325,   326,   271,
     190,   188,   240,   166,   159,   240,   255,   -57,   307,   307,
     300,   282,   284,   150,   150,   294,   160,   302,   188,   266,
     121,   206,   266,   295,   298,   299,   324,   324,   311,   153,
     154,   155,   114,    31,    32,   320,    26,   156,   304,   328,
     157,   158,   319,   -71,   -71,   -71,   -71,   321,   337,   190,
     338,   340,   -71,   159,    -7,    -7,   166,    -7,    -7,    -7,
      -7,   341,   164,   210,   151,   115,   151,   166,   167,    28,
      29,    30,   345,    31,    32,   348,   242,    33,   242,   166,
      34,    35,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   346,
     -32,   -32,   -41,    37,   -32,   190,   150,   -32,   -32,   352,
     268,   356,   268,   166,   357,    45,   358,   167,   -32,   -32,
     -32,   191,   -32,   359,   167,   -32,   -32,   137,   -32,   -32,
     -32,   -32,   -32,   166,   151,   151,   360,   361,   362,   190,
     190,   206,   207,   -71,   -71,   -71,   -71,   177,   178,   179,
     365,    31,    32,   366,   367,   180,   371,    13,   181,   182,
     347,     0,   303,   175,     0,   -71,     0,   166,     0,     0,
     191,   183,     0,   -89,   -89,   -89,   -89,   167,   166,   242,
     242,   166,   -89,   184,   317,   206,     0,     0,   167,     0,
     143,   144,   145,   166,    31,    32,     0,   243,     0,   243,
     167,   146,     0,     0,   190,   190,   268,   268,   190,     0,
       0,   335,   206,     0,   147,     0,   191,   151,   339,     0,
       0,   269,     0,   269,   167,   166,    70,     0,     0,   166,
     -88,   -88,   -88,   -88,     0,     0,   190,   242,     0,   -88,
     351,     0,     0,     0,   167,   -72,   -72,   -72,   -72,     0,
     191,   191,   207,   190,   268,     0,     0,   355,     0,     0,
     152,     0,   152,     0,   172,     0,   -72,     0,     0,   -72,
     -55,   -55,   -55,   151,   -55,   -55,     0,     0,   167,     0,
       0,   -55,     0,     0,   -60,   -60,    98,    99,     0,   167,
     243,   243,   167,     0,   -55,   167,   207,   166,     2,     3,
       4,     5,     0,   172,   167,   -60,   -55,   196,   -60,     0,
     172,     0,     0,     0,     0,   191,   191,   269,   269,   191,
     152,   152,   191,   207,   -71,   -71,   -71,   -71,   208,   207,
     -54,   -54,   -54,   -71,   -54,   -54,   167,     0,     0,     0,
     167,   -54,     0,     0,   210,     0,   -78,   191,   243,     0,
       0,   243,     0,     0,   -54,     0,   196,     0,   -64,   -64,
     -64,   -64,     0,   172,   191,   269,   -54,     0,   269,     0,
       0,   149,     0,   149,   172,   165,   -48,   -48,   -48,   -64,
     -48,   -48,   -64,   244,     0,   244,   172,   -48,     0,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,     0,
     -48,   -31,   196,   152,   -31,   -31,     0,   270,   167,   270,
     172,     0,   -48,     0,   165,   -31,   -31,   -31,   189,   -31,
       0,   165,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     172,   149,   149,   120,     0,     0,   196,   196,   208,   205,
     -89,   -89,   -89,   -89,   -49,   -49,   -49,     0,   -49,   -49,
     -88,   -88,   -88,   -88,     0,   -49,     0,     0,     0,   152,
       0,     0,   -89,     0,   172,     0,     0,   189,   -49,     0,
       0,     0,   -88,     0,   165,   172,   244,   244,   172,     0,
     -49,   172,   208,     0,     0,   165,     0,   -50,   -50,   -50,
     172,   -50,   -50,     0,   241,     0,   241,   165,   -50,     0,
       0,   196,   196,   270,   270,   196,     0,     0,   196,   208,
       0,   -50,     0,   189,   258,   208,     0,     0,   267,     0,
     267,   165,   172,   -50,     0,     0,   172,   -72,   -72,   -72,
     -72,     0,     0,   196,   244,     0,   -72,   244,     0,     0,
       0,   165,   -68,   -68,   -68,   -68,     0,   189,   189,   292,
     196,   270,     0,     0,   270,     0,   161,    71,     0,    73,
       0,   163,     0,   -68,     0,     0,   -68,   -51,   -51,   -51,
       0,   -51,   -51,     0,     0,   165,     0,     0,   -51,     0,
       0,   -60,   -60,    98,    99,     0,   165,   241,   241,   316,
     -60,   -51,     0,   205,   172,   161,     0,     0,     0,   185,
     163,   165,   116,   -51,   187,     0,     0,   163,   -69,   -69,
     -69,   -69,   189,   189,   267,   267,   334,   118,   119,     0,
     205,   -72,   -72,   -72,   -72,   123,     0,     0,     0,   -69,
       0,     0,   -69,   165,     0,     0,     0,   165,   162,     0,
       0,     0,     0,   -72,   189,   350,     0,     0,   185,   -70,
     -70,   -70,   -70,   187,     0,   161,   -64,   -64,   -64,   -64,
     163,   189,   354,     0,     0,   -64,   161,     0,     0,     0,
     -70,   163,     0,   -70,     0,     0,     0,   162,   161,     0,
     239,   186,   246,   163,   162,   -52,   -52,   -52,     0,   -52,
     -52,     0,     0,   168,   185,     0,   -52,     0,     0,   187,
       0,     0,   161,     0,   265,   165,   272,   163,     0,   -52,
     -88,   -88,   -88,   -88,   -53,   -53,   -53,     0,   -53,   -53,
       0,   -52,   161,     0,     0,   -53,     0,   163,   185,   185,
     186,   -88,   168,   187,   187,     0,   192,   162,   -53,   168,
       0,    28,    29,    30,     0,    31,    32,     0,   162,     0,
     -53,     0,    34,     0,     0,     0,   161,     0,     0,     0,
     162,   163,     0,     0,     0,    37,     0,   161,     0,     0,
     169,     0,   163,   313,   314,     0,   186,   198,     0,   123,
       0,     0,   161,     0,   162,   192,     0,   163,   -68,   -68,
     -68,   -68,   168,   185,   185,     0,     0,   -68,   187,   187,
     331,   332,     0,   168,   162,     0,   123,     0,     0,   169,
     186,   186,     0,   193,   161,   168,   169,     0,   116,   163,
       0,     0,     0,   163,     0,   185,   -60,   -60,    98,    99,
     187,   192,   -65,   -65,   -65,     0,   -65,   -65,   162,   168,
       0,     0,   185,   -65,     0,     0,     0,   187,   -60,   162,
     -87,   -87,   -87,   -87,     0,     0,   -65,     0,     0,   168,
       0,     0,   193,     0,   162,   192,   192,     0,   -65,   169,
       0,   -87,   170,     0,   -87,   186,   186,   -66,   -66,   -66,
     169,   -66,   -66,     0,     0,     0,   161,     0,   -66,     0,
       0,   163,   169,   168,     0,     0,   162,     0,     0,     0,
     162,   -66,     0,     0,   168,     0,     0,   186,   193,     0,
       0,   170,     0,   -66,   171,   194,   169,     0,   170,   168,
     -86,   -86,   -86,   -86,   186,   -67,   -67,   -67,   -67,     0,
     192,   192,   -64,   -64,   -64,   -64,   169,   -59,   -59,    98,
      99,   -86,   193,   193,   -86,     0,   -67,     0,     0,   -67,
       0,   168,     0,   171,   -64,   168,     0,   195,   -59,     0,
     171,   -59,   192,     0,   194,     0,     0,     0,   162,     0,
     169,   170,     0,   199,   200,   201,     0,    31,    32,   192,
       0,   169,   170,     0,   202,     0,   -69,   -69,   -69,   -69,
     -63,   -63,   -63,   -63,   170,   -69,   169,   203,   -73,   -73,
     -73,   -73,     0,     0,     0,     0,   195,   193,   193,   122,
     194,   -63,     0,   171,   -63,     0,     0,     0,   170,   -73,
       0,     0,   -73,   168,   171,     0,     0,     0,   169,    28,
      29,    30,   169,    31,    32,     0,   171,    33,   170,   193,
      34,    35,     0,     0,   194,   194,     0,   -68,   -68,   -68,
     -68,   142,   195,    37,     0,    38,   193,     0,    39,    40,
     171,    41,    42,    43,    44,    45,   233,   234,   235,   -68,
      31,    32,   170,   -69,   -69,   -69,   -69,   236,     0,     0,
     171,     0,     0,   170,     0,     0,   195,   195,     0,     0,
     237,     0,   -61,   -61,   -61,   -69,   -61,   -61,   170,     0,
     169,     0,   238,   -61,   -70,   -70,   -70,   -70,     0,   194,
     194,     0,     0,     0,   171,     0,   -61,     0,   -62,   -62,
     -62,     0,   -62,   -62,     0,   171,   -70,     0,   -61,   -62,
     170,     0,     0,     0,   170,   -87,   -87,   -87,   -87,     0,
     171,   194,   -62,     0,     0,   259,   260,   261,     0,    31,
      32,   195,   195,     0,   -62,     0,   262,   -87,   194,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,   -24,   263,
       0,   -24,   171,     0,   -24,   -24,   171,     0,     0,     0,
       0,   264,     0,   195,     0,   -24,   -24,   -24,     0,   -24,
       0,     0,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     195,     0,   170,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
       0,   -23,   -23,     0,     0,   -23,     0,     0,   -23,   -23,
       0,     0,     0,   -70,   -70,   -70,   -70,     0,     0,   -23,
     -23,   -23,   -70,   -23,     0,     0,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   171,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,     0,   -25,   -25,     0,     0,   -25,     0,     0,
     -25,   -25,     0,     0,     0,   -87,   -87,   -87,   -87,     0,
       0,   -25,   -25,   -25,   -87,   -25,     0,     0,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,     0,   -26,   -26,     0,     0,   -26,     0,
       0,   -26,   -26,     0,     0,     0,   -86,   -86,   -86,   -86,
       0,     0,   -26,   -26,   -26,   -86,   -26,     0,     0,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,     0,   -27,   -27,     0,     0,   -27,
       0,     0,   -27,   -27,     0,     0,     0,   -59,   -59,    98,
      99,     0,     0,   -27,   -27,   -27,   -59,   -27,     0,     0,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,     0,     0,
     -28,     0,     0,   -28,   -28,     0,     0,     0,   -67,   -67,
     -67,   -67,     0,     0,   -28,   -28,   -28,   -67,   -28,     0,
       0,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,     0,
       0,   -29,     0,     0,   -29,   -29,     0,     0,     0,   -63,
     -63,   -63,   -63,     0,     0,   -29,   -29,   -29,   -63,   -29,
       0,     0,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -35,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,   -35,
       0,     0,   -35,     0,     0,   -35,   -35,     0,     0,     0,
     -73,   -73,   -73,   -73,     0,     0,   -35,   -35,   -35,   -73,
     -35,     0,     0,   -35,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -30,   -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,
     -30,     0,     0,   -30,     0,     0,   -30,   -30,    -2,     1,
       0,     2,     3,     4,     5,     0,     0,   -30,   -30,   -30,
       0,   -30,     0,     0,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -19,   -19,   -19,   -19,   -19,   -19,   -19,     0,
     -19,   -19,     0,     0,   -19,     0,     0,   -19,   -19,    -4,
      -4,     0,    -4,    -4,    -4,    -4,     0,     0,   -19,   -19,
     -19,     0,   -19,     0,     0,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
       0,   -36,   -36,     0,     0,   -36,     0,     0,   -36,   -36,
      -5,    -5,     0,    -5,    -5,    -5,    -5,     0,     0,   -36,
     -36,   -36,     0,   -36,     0,     0,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,     0,   -32,   -32,     0,     0,   -32,     0,     0,   -32,
     -32,    -6,    -6,     0,    -6,    -6,    -6,    -6,     0,     0,
     -32,   -32,   -32,     0,   -32,     0,     0,   -32,   -32,   368,
     -32,   -32,   -32,   -32,   -32,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,     0,   -37,   -37,     0,     0,   -37,     0,     0,
     -37,   -37,    -3,    -3,     0,    -3,    -3,    -3,    -3,     0,
       0,   -37,   -37,   -37,     0,   -37,     0,     0,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,     0,   -38,   -38,     0,     0,   -38,     0,
       0,   -38,   -38,    -8,    -8,     0,    -8,    -8,    -8,    -8,
       0,     0,   -38,   -38,   -38,     0,   -38,     0,     0,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,     0,   -33,   -33,     0,     0,   -33,
       0,     0,   -33,   -33,   -13,   -13,     0,   -13,   -13,   -13,
     -13,     0,     0,   -33,   -33,   -33,     0,   -33,     0,     0,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -34,   -34,
     -34,   -34,   -34,   -34,   -34,     0,   -34,   -34,     0,     0,
     -34,     0,     0,   -34,   -34,   -19,   -19,     0,   -19,   -19,
     -19,   -19,     0,     0,   -34,   -34,   -34,     0,   -34,     0,
       0,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -34,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,     0,   -22,   -22,     0,
       0,   -22,     0,     0,   -22,   -22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -22,   -22,   -22,     0,   -22,
       0,     0,   -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,
       2,     3,     4,     5,    28,    29,    30,     0,    31,    32,
       0,     0,    33,     0,     0,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,    36,    37,     0,
      38,     0,     0,    39,    40,     0,    41,    42,    43,    44,
      45,   -31,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,
     -31,     0,     0,   -31,     0,     0,   -31,   -31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -31,   -31,   -31,
       0,   -31,     0,     0,   -31,   -31,     0,   -31,   -31,   -31,
     -31,   -31,   -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,
     -21,   -21,     0,     0,   -21,     0,     0,   -21,   -21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -21,   -21,
     -21,     0,   -21,     0,     0,   -21,   -21,     0,   -21,   -21,
     -21,   -21,   -21,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
       0,   -24,   -24,     0,     0,   -24,     0,     0,   -24,   -24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -24,
     -24,   -24,     0,   -24,     0,     0,   -24,   -24,     0,   -24,
     -24,   -24,   -24,   -24,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,     0,   -20,   -20,     0,     0,   -20,     0,     0,   -20,
     -20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -20,   -20,   -20,     0,   -20,     0,     0,   -20,   -20,     0,
     -20,   -20,   -20,   -20,   -20,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,     0,   -23,   -23,     0,     0,   -23,     0,     0,
     -23,   -23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -23,   -23,   -23,     0,   -23,     0,     0,   -23,   -23,
       0,   -23,   -23,   -23,   -23,   -23,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,     0,   -25,   -25,     0,     0,   -25,     0,
       0,   -25,   -25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -25,   -25,   -25,     0,   -25,     0,     0,   -25,
     -25,     0,   -25,   -25,   -25,   -25,   -25,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,     0,   -26,   -26,     0,     0,   -26,
       0,     0,   -26,   -26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -26,   -26,   -26,     0,   -26,     0,     0,
     -26,   -26,     0,   -26,   -26,   -26,   -26,   -26,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,     0,     0,
     -27,     0,     0,   -27,   -27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -27,   -27,   -27,     0,   -27,     0,
       0,   -27,   -27,     0,   -27,   -27,   -27,   -27,   -27,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,     0,
       0,   -28,     0,     0,   -28,   -28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -28,   -28,   -28,     0,   -28,
       0,     0,   -28,   -28,     0,   -28,   -28,   -28,   -28,   -28,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,
       0,     0,   -29,     0,     0,   -29,   -29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -29,   -29,   -29,     0,
     -29,     0,     0,   -29,   -29,     0,   -29,   -29,   -29,   -29,
     -29,   -35,   -35,   -35,   -35,   -35,   -35,   -35,     0,   -35,
     -35,     0,     0,   -35,     0,     0,   -35,   -35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -35,   -35,   -35,
       0,   -35,     0,     0,   -35,   -35,     0,   -35,   -35,   -35,
     -35,   -35,   -30,   -30,   -30,   -30,   -30,   -30,   -30,     0,
     -30,   -30,     0,     0,   -30,     0,     0,   -30,   -30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -30,   -30,
     -30,     0,   -30,     0,     0,   -30,   -30,     0,   -30,   -30,
     -30,   -30,   -30,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
       0,   -36,   -36,     0,     0,   -36,     0,     0,   -36,   -36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -36,
     -36,   -36,     0,   -36,     0,     0,   -36,   -36,     0,   -36,
     -36,   -36,   -36,   -36,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,     0,   -37,   -37,     0,     0,   -37,     0,     0,   -37,
     -37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -37,   -37,   -37,     0,   -37,     0,     0,   -37,   -37,     0,
     -37,   -37,   -37,   -37,   -37,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,     0,   -38,   -38,     0,     0,   -38,     0,     0,
     -38,   -38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -38,   -38,   -38,     0,   -38,     0,     0,   -38,   -38,
       0,   -38,   -38,   -38,   -38,   -38,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,     0,   -33,   -33,     0,     0,   -33,     0,
       0,   -33,   -33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -33,   -33,   -33,     0,   -33,     0,     0,   -33,
     -33,     0,   -33,   -33,   -33,   -33,   -33,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,     0,   -34,   -34,     0,     0,   -34,
       0,     0,   -34,   -34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -34,   -34,   -34,     0,   -34,     0,     0,
     -34,   -34,     0,   -34,   -34,   -34,   -34,   -34,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,     0,    -8,    -8,     0,     0,
      -8,     0,     0,    -8,    -8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -8,    -8,    -8,     0,    -8,     0,
       0,    -8,    -8,     0,    -8,    -8,    -8,    -8,    -8,     2,
       3,     4,     5,    28,    29,    30,     0,    31,    32,     0,
       0,    33,     0,     0,    34,    35,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   301,    37,     0,    38,
       0,     0,    39,    40,     0,    41,    42,    43,    44,    45,
       2,     3,     4,     5,    28,    29,    30,     0,    31,    32,
       0,     0,    33,     0,     0,    34,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   342,    37,     0,
      38,     0,     0,    39,    40,     0,    41,    42,    43,    44,
      45,   -19,   -19,   -19,   -19,   -19,   -19,   -19,     0,   -19,
     -19,     0,     0,   -19,     0,     0,   -19,   -19,     0,   199,
     200,   201,     0,    31,    32,     0,     0,   -19,   -19,   -19,
     202,   -19,     0,     0,   -19,   -19,     0,   -19,   -19,   -19,
     -19,   -19,     0,   203,     0,   153,   154,   155,     0,    31,
      32,   -71,   -71,   -71,   -71,   291,   157,     0,     0,   199,
     200,   201,     0,    31,    32,   -72,   -72,   -72,   -72,   159,
     202,   306,   -71,   177,   178,   179,     0,    31,    32,     0,
       0,   315,     0,   203,   181,     0,   -72,   199,   200,   201,
       0,    31,    32,     0,     0,   318,     0,   183,   202,     0,
     -86,   -86,   -86,   -86,     0,     0,     0,     0,     0,   333,
       0,   203,     0,     0,     0,   -71,   -71,   -71,   -71,     0,
     -71,   -71,   -86,   336,   -71,   -83,   -83,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,   274,   -71,     0,   275,   -71,
     -71,   -71,   -71,   -71,     0,   -71,   -71,     0,     0,   -71,
       0,     0,   -71,   -71,   -71,   -71,   -71,   -71,     0,     0,
     274,   -71,     0,     0,   -71,   -89,   -89,   -89,   -89,     0,
     -89,   -89,     0,     0,   -89,     0,     0,   -89,   -89,   -89,
     -89,   -89,   -89,     0,     0,     0,   -89,     0,     0,   -89,
     -88,   -88,   -88,   -88,     0,   -88,   -88,     0,     0,   -88,
       0,     0,   -88,   -88,   -88,   -88,   -88,   -88,     0,     0,
       0,   -88,     0,     0,   -88,   -72,   -72,   -72,   -72,     0,
     -72,   -72,     0,     0,   -72,     0,     0,   -72,   -72,   -72,
     -72,   -72,   -72,     0,     0,     0,   -72,     0,     0,   -72,
     -60,   -60,    98,    99,     0,   -60,   -60,     0,     0,   -60,
       0,     0,   -60,   -60,   -60,   -60,   -60,   -60,     0,     0,
       0,   -60,     0,     0,   -60,   -64,   -64,   -64,   -64,     0,
     -64,   -64,     0,     0,   -64,     0,     0,   -64,   -64,   -64,
     -64,   -64,   -64,     0,     0,     0,   -64,     0,     0,   -64,
     -68,   -68,   -68,   -68,     0,   -68,   -68,     0,     0,   -68,
       0,     0,   -68,   -68,   -68,   -68,   -68,   -68,     0,     0,
       0,   -68,     0,     0,   -68,   -69,   -69,   -69,   -69,     0,
     -69,   -69,     0,     0,   -69,     0,     0,   -69,   -69,   -69,
     -69,   -69,   -69,     0,     0,     0,   -69,     0,     0,   -69,
     -70,   -70,   -70,   -70,     0,   -70,   -70,     0,     0,   -70,
       0,     0,   -70,   -70,   -70,   -70,   -70,   -70,     0,     0,
       0,   -70,     0,     0,   -70,   -87,   -87,   -87,   -87,     0,
     -87,   -87,     0,     0,   -87,     0,     0,   -87,   -87,   -87,
     -87,   -87,   -87,     0,     0,     0,   -87,     0,     0,   -87,
     -86,   -86,   -86,   -86,     0,   -86,   -86,     0,     0,   -86,
       0,     0,   -86,   -86,   -86,   -86,   -86,   -86,     0,     0,
       0,   -86,     0,     0,   -86,   -67,   -67,   -67,   -67,     0,
     -67,   -67,     0,     0,   -67,     0,     0,   -67,   -67,   -67,
     -67,   -67,   -67,     0,     0,     0,   -67,     0,     0,   -67,
     -59,   -59,    98,    99,     0,   -59,   -59,     0,     0,   -59,
       0,     0,   -59,   -59,   -59,   -59,   -59,   -59,     0,     0,
       0,   -59,     0,     0,   -59,   -63,   -63,   -63,   -63,     0,
     -63,   -63,     0,     0,   -63,     0,     0,   -63,   -63,   -63,
     -63,   -63,   -63,     0,     0,     0,   -63,     0,     0,   -63,
     -73,   -73,   -73,   -73,     0,   -73,   -73,     0,     0,   -73,
       0,     0,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,
       0,   -73,   173,   174,   -73,     0,     0,    85,    86,     0,
       0,   -80,     0,     0,    87,    88,    89,    90,    91,    92,
       0,     0,     0,   -46,     0,     0,   -46,   -71,   -71,   -71,
     -71,     0,   -71,   -71,     0,     0,   -71,   -83,   -83,   -71,
     -71,   -71,   -71,   -71,   -71,     0,     0,    80,     0,   -71,
      81,   -71,   -71,   -71,   -71,     0,   -71,   -71,     0,     0,
     -71,   -83,   -83,   -71,   -71,   -71,   -71,   -71,   -71,     0,
       0,   209,   -71,     0,   248,   -71,   -71,   -71,   -71,     0,
     -71,   -71,     0,     0,   -71,     0,     0,   -71,   -71,   -71,
     -71,   -71,   -71,     0,     0,    80,     0,   -71,   -89,   -89,
     -89,   -89,     0,   -89,   -89,     0,     0,   -89,     0,     0,
     -89,   -89,   -89,   -89,   -89,   -89,   -88,   -88,   -88,   -88,
     -89,   -88,   -88,     0,     0,   -88,     0,     0,   -88,   -88,
     -88,   -88,   -88,   -88,   -72,   -72,   -72,   -72,   -88,   -72,
     -72,     0,     0,   -72,     0,     0,   -72,   -72,   -72,   -72,
     -72,   -72,   -60,   -60,    98,    99,   -72,   -60,   -60,     0,
       0,   -60,     0,     0,   -60,   -60,   -60,   -60,   -60,   -60,
     -64,   -64,   -64,   -64,   -60,   -64,   -64,     0,     0,   -64,
       0,     0,   -64,   -64,   -64,   -64,   -64,   -64,   -68,   -68,
     -68,   -68,   -64,   -68,   -68,     0,     0,   -68,     0,     0,
     -68,   -68,   -68,   -68,   -68,   -68,   -69,   -69,   -69,   -69,
     -68,   -69,   -69,     0,     0,   -69,     0,     0,   -69,   -69,
     -69,   -69,   -69,   -69,   -70,   -70,   -70,   -70,   -69,   -70,
     -70,     0,     0,   -70,     0,     0,   -70,   -70,   -70,   -70,
     -70,   -70,   -87,   -87,   -87,   -87,   -70,   -87,   -87,     0,
       0,   -87,     0,     0,   -87,   -87,   -87,   -87,   -87,   -87,
     -86,   -86,   -86,   -86,   -87,   -86,   -86,     0,     0,   -86,
       0,     0,   -86,   -86,   -86,   -86,   -86,   -86,   -67,   -67,
     -67,   -67,   -86,   -67,   -67,     0,     0,   -67,     0,     0,
     -67,   -67,   -67,   -67,   -67,   -67,   -59,   -59,    98,    99,
     -67,   -59,   -59,     0,     0,   -59,     0,     0,   -59,   -59,
     -59,   -59,   -59,   -59,   -63,   -63,   -63,   -63,   -59,   -63,
     -63,     0,     0,   -63,     0,     0,   -63,   -63,   -63,   -63,
     -63,   -63,   -73,   -73,   -73,   -73,   -63,   -73,   -73,     0,
       0,   -73,     0,     0,   -73,   -73,   -73,   -73,   -73,   -73,
     -59,   -59,    98,    99,   -73,   -67,   -67,   -67,   -67,   -63,
     -63,   -63,   -63,   -73,   -73,   -73,   -73,     0,     0,     0,
       0,     0,   -59,   -71,   -71,   -71,   -71,   -67,     0,     0,
       0,   -63,   -71,     0,     0,   -73,   -71,   -71,   -71,   -71,
       0,   -71,   -71,   210,   -78,   -71,   -83,   -83,   -71,   -71,
     -71,   -71,   -71,   -71,     0,     0,   209,   -71,   -71,   -71,
     -71,   -71,     0,   -71,   -71,     0,     0,   -71,     0,     0,
     -71,   -71,   -71,   -71,   -71,   -71,     0,     0,   209,   -71,
     -89,   -89,   -89,   -89,     0,   -89,   -89,     0,     0,   -89,
       0,     0,   -89,   -89,   -89,   -89,   -89,   -89,     0,     0,
       0,   -89,   -88,   -88,   -88,   -88,     0,   -88,   -88,     0,
       0,   -88,     0,     0,   -88,   -88,   -88,   -88,   -88,   -88,
       0,     0,     0,   -88,   -72,   -72,   -72,   -72,     0,   -72,
     -72,     0,     0,   -72,     0,     0,   -72,   -72,   -72,   -72,
     -72,   -72,     0,     0,     0,   -72,   -60,   -60,    98,    99,
       0,   -60,   -60,     0,     0,   -60,     0,     0,   -60,   -60,
     -60,   -60,   -60,   -60,     0,     0,     0,   -60,   -64,   -64,
     -64,   -64,     0,   -64,   -64,     0,     0,   -64,     0,     0,
     -64,   -64,   -64,   -64,   -64,   -64,     0,     0,     0,   -64,
     -68,   -68,   -68,   -68,     0,   -68,   -68,     0,     0,   -68,
       0,     0,   -68,   -68,   -68,   -68,   -68,   -68,     0,     0,
       0,   -68,   -69,   -69,   -69,   -69,     0,   -69,   -69,     0,
       0,   -69,     0,     0,   -69,   -69,   -69,   -69,   -69,   -69,
       0,     0,     0,   -69,   -70,   -70,   -70,   -70,     0,   -70,
     -70,     0,     0,   -70,     0,     0,   -70,   -70,   -70,   -70,
     -70,   -70,     0,     0,     0,   -70,   -87,   -87,   -87,   -87,
       0,   -87,   -87,     0,     0,   -87,     0,     0,   -87,   -87,
     -87,   -87,   -87,   -87,     0,     0,     0,   -87,   -86,   -86,
     -86,   -86,     0,   -86,   -86,     0,     0,   -86,     0,     0,
     -86,   -86,   -86,   -86,   -86,   -86,     0,     0,     0,   -86,
     -67,   -67,   -67,   -67,     0,   -67,   -67,     0,     0,   -67,
       0,     0,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,
       0,   -67,   -59,   -59,    98,    99,     0,   -59,   -59,     0,
       0,   -59,     0,     0,   -59,   -59,   -59,   -59,   -59,   -59,
       0,     0,     0,   -59,   -63,   -63,   -63,   -63,     0,   -63,
     -63,     0,     0,   -63,     0,     0,   -63,   -63,   -63,   -63,
     -63,   -63,     0,     0,     0,   -63,   -73,   -73,   -73,   -73,
       0,   -73,   -73,     0,     0,   -73,     0,     0,   -73,   -73,
     -73,   -73,   -73,   -73,   173,   174,     0,   -73,     0,    85,
      86,     0,     0,   -80,     0,     0,    87,    88,    89,    90,
      91,    92,     0,     0,     0,   -46,   -60,   -60,    98,    99,
     -64,   -64,   -64,   -64,   -68,   -68,   -68,   -68,   -69,   -69,
     -69,   -69,   -70,   -70,   -70,   -70,     0,   -60,     0,     0,
       0,   -64,     0,     0,     0,   -68,     0,     0,     0,   -69,
       0,     0,     0,   -70,   -87,   -87,   -87,   -87,   -86,   -86,
     -86,   -86,   -67,   -67,   -67,   -67,   -59,   -59,    98,    99,
     -63,   -63,   -63,   -63,     0,   -87,     0,     0,     0,   -86,
       0,     0,     0,   -67,     0,     0,     0,   -59,     0,     0,
       0,   -63,   -73,   -73,   -73,   -73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -73
};

static const yytype_int16 yycheck[] =
{
      22,    27,   142,   126,   163,     0,    11,    12,   126,    43,
     126,    37,     7,   163,   137,    41,    43,   140,   175,   171,
     149,     7,     8,     9,    43,    11,    12,    32,   187,    15,
      35,    43,    18,    19,   126,     0,   165,   187,   126,    32,
     126,    32,    35,   195,    35,    31,    43,    33,    32,    75,
      76,    35,   209,   210,   126,    81,    32,    43,    43,    35,
     189,   126,     7,     8,     9,    32,    11,    12,    11,    12,
      15,    29,   212,    18,    19,    43,   205,     3,     4,     5,
       6,    11,    12,    31,    29,    33,    31,    31,    33,    31,
      33,    36,    37,    31,    39,    40,    41,    42,    43,   125,
     126,    33,    32,   129,   126,    35,    32,    11,    12,     0,
     136,   137,   241,    31,   140,    31,     7,   274,    21,    22,
      43,   147,    11,    12,    15,    11,    12,    33,    32,   258,
      33,    35,    23,   159,    20,     7,     8,     9,   267,    11,
      12,    11,    12,    15,    33,    33,    18,    19,    33,   306,
      35,    31,    37,    11,    12,    13,    14,   183,    32,    31,
      32,    35,    32,   292,    32,    35,   323,    35,     7,     8,
       9,    43,    11,    12,    32,    60,    15,   203,    32,    18,
      19,    35,    11,    12,    13,    14,    71,   316,    73,    33,
     216,    76,    31,    20,    33,    80,    11,    12,    83,    21,
      22,   227,    31,    32,    43,   334,    35,    33,    93,    94,
      32,   237,    32,    35,    11,    12,   101,    33,    33,    16,
      17,   350,   248,    20,    43,   354,    23,    24,    25,    26,
      27,    28,    33,   118,   119,   358,    33,   263,   123,    43,
     358,    43,   358,    32,   129,   368,    35,    43,   371,   275,
     368,   136,   368,   371,    33,   371,    11,    12,    32,    11,
      12,    35,   147,    11,    12,    32,   358,   293,   294,   295,
     358,   156,   358,   158,   159,    32,   368,    32,   163,   371,
     368,    33,   368,   371,    32,   371,   358,    11,    12,    32,
     175,   176,    35,   358,    32,   180,   368,   182,   183,   371,
      11,    12,   187,   368,    32,    32,   371,    35,    32,    21,
      22,     7,     8,    11,    12,    13,    14,    33,   203,    32,
      32,    32,    20,    32,   209,   210,   211,    11,    12,    13,
      14,   357,   358,    31,    32,    32,   358,    35,    35,     7,
       8,   367,   368,     7,     8,   371,   368,   232,    32,   371,
      33,    35,   237,    33,   239,    11,    12,    13,    14,    21,
      22,   246,    33,   248,   249,   250,   251,     7,     8,   254,
     255,     7,     8,    33,    32,    35,    32,    37,   263,    35,
     265,     1,    43,     3,     4,     5,     6,   272,    43,   274,
     275,   276,   277,   278,     7,     8,   281,   282,     7,     8,
       7,     8,     9,   288,    11,    12,     7,     8,    15,    32,
     295,    18,    19,    32,   299,    32,    76,     7,     8,    43,
      80,   306,   307,    83,    31,   310,    20,    32,   313,   314,
      33,    20,    43,    93,    94,    31,    43,    32,   323,   324,
     100,   101,   327,    31,    31,    31,   331,   332,    32,     7,
       8,     9,    10,    11,    12,    32,    23,    15,    43,    32,
      18,    19,    43,    11,    12,    13,    14,    43,    43,   129,
      32,    32,    20,    31,     0,     1,   136,     3,     4,     5,
       6,    32,   367,    31,    33,    43,    35,   147,    37,     7,
       8,     9,    33,    11,    12,    32,   156,    15,   158,   159,
      18,    19,     3,     4,     5,     6,     7,     8,     9,    43,
      11,    12,    32,    31,    15,   175,   176,    18,    19,    32,
     180,    32,   182,   183,    33,    43,    32,    76,    29,    30,
      31,    80,    33,    32,    83,    36,    37,    38,    39,    40,
      41,    42,    43,   203,    93,    94,    32,    32,    32,   209,
     210,   211,   101,    11,    12,    13,    14,     7,     8,     9,
      33,    11,    12,    33,    33,    15,    32,     7,    18,    19,
     299,    -1,   232,    31,    -1,    33,    -1,   237,    -1,    -1,
     129,    31,    -1,    11,    12,    13,    14,   136,   248,   249,
     250,   251,    20,    43,   254,   255,    -1,    -1,   147,    -1,
       7,     8,     9,   263,    11,    12,    -1,   156,    -1,   158,
     159,    18,    -1,    -1,   274,   275,   276,   277,   278,    -1,
      -1,   281,   282,    -1,    31,    -1,   175,   176,   288,    -1,
      -1,   180,    -1,   182,   183,   295,    43,    -1,    -1,   299,
      11,    12,    13,    14,    -1,    -1,   306,   307,    -1,    20,
     310,    -1,    -1,    -1,   203,    11,    12,    13,    14,    -1,
     209,   210,   211,   323,   324,    -1,    -1,   327,    -1,    -1,
      33,    -1,    35,    -1,    37,    -1,    32,    -1,    -1,    35,
       7,     8,     9,   232,    11,    12,    -1,    -1,   237,    -1,
      -1,    18,    -1,    -1,    11,    12,    13,    14,    -1,   248,
     249,   250,   251,    -1,    31,   254,   255,   367,     3,     4,
       5,     6,    -1,    76,   263,    32,    43,    80,    35,    -1,
      83,    -1,    -1,    -1,    -1,   274,   275,   276,   277,   278,
      93,    94,   281,   282,    11,    12,    13,    14,   101,   288,
       7,     8,     9,    20,    11,    12,   295,    -1,    -1,    -1,
     299,    18,    -1,    -1,    31,    -1,    33,   306,   307,    -1,
      -1,   310,    -1,    -1,    31,    -1,   129,    -1,    11,    12,
      13,    14,    -1,   136,   323,   324,    43,    -1,   327,    -1,
      -1,    33,    -1,    35,   147,    37,     7,     8,     9,    32,
      11,    12,    35,   156,    -1,   158,   159,    18,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      31,    15,   175,   176,    18,    19,    -1,   180,   367,   182,
     183,    -1,    43,    -1,    76,    29,    30,    31,    80,    33,
      -1,    83,    36,    37,    38,    39,    40,    41,    42,    43,
     203,    93,    94,    95,    -1,    -1,   209,   210,   211,   101,
      11,    12,    13,    14,     7,     8,     9,    -1,    11,    12,
      11,    12,    13,    14,    -1,    18,    -1,    -1,    -1,   232,
      -1,    -1,    33,    -1,   237,    -1,    -1,   129,    31,    -1,
      -1,    -1,    33,    -1,   136,   248,   249,   250,   251,    -1,
      43,   254,   255,    -1,    -1,   147,    -1,     7,     8,     9,
     263,    11,    12,    -1,   156,    -1,   158,   159,    18,    -1,
      -1,   274,   275,   276,   277,   278,    -1,    -1,   281,   282,
      -1,    31,    -1,   175,   176,   288,    -1,    -1,   180,    -1,
     182,   183,   295,    43,    -1,    -1,   299,    11,    12,    13,
      14,    -1,    -1,   306,   307,    -1,    20,   310,    -1,    -1,
      -1,   203,    11,    12,    13,    14,    -1,   209,   210,   211,
     323,   324,    -1,    -1,   327,    -1,    37,    33,    -1,    35,
      -1,    37,    -1,    32,    -1,    -1,    35,     7,     8,     9,
      -1,    11,    12,    -1,    -1,   237,    -1,    -1,    18,    -1,
      -1,    11,    12,    13,    14,    -1,   248,   249,   250,   251,
      20,    31,    -1,   255,   367,    76,    -1,    -1,    -1,    80,
      76,   263,    83,    43,    80,    -1,    -1,    83,    11,    12,
      13,    14,   274,   275,   276,   277,   278,    93,    94,    -1,
     282,    11,    12,    13,    14,   101,    -1,    -1,    -1,    32,
      -1,    -1,    35,   295,    -1,    -1,    -1,   299,    37,    -1,
      -1,    -1,    -1,    33,   306,   307,    -1,    -1,   129,    11,
      12,    13,    14,   129,    -1,   136,    11,    12,    13,    14,
     136,   323,   324,    -1,    -1,    20,   147,    -1,    -1,    -1,
      32,   147,    -1,    35,    -1,    -1,    -1,    76,   159,    -1,
     156,    80,   158,   159,    83,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    37,   175,    -1,    18,    -1,    -1,   175,
      -1,    -1,   183,    -1,   180,   367,   182,   183,    -1,    31,
      11,    12,    13,    14,     7,     8,     9,    -1,    11,    12,
      -1,    43,   203,    -1,    -1,    18,    -1,   203,   209,   210,
     129,    32,    76,   209,   210,    -1,    80,   136,    31,    83,
      -1,     7,     8,     9,    -1,    11,    12,    -1,   147,    -1,
      43,    -1,    18,    -1,    -1,    -1,   237,    -1,    -1,    -1,
     159,   237,    -1,    -1,    -1,    31,    -1,   248,    -1,    -1,
      37,    -1,   248,   249,   250,    -1,   175,    43,    -1,   255,
      -1,    -1,   263,    -1,   183,   129,    -1,   263,    11,    12,
      13,    14,   136,   274,   275,    -1,    -1,    20,   274,   275,
     276,   277,    -1,   147,   203,    -1,   282,    -1,    -1,    76,
     209,   210,    -1,    80,   295,   159,    83,    -1,   299,   295,
      -1,    -1,    -1,   299,    -1,   306,    11,    12,    13,    14,
     306,   175,     7,     8,     9,    -1,    11,    12,   237,   183,
      -1,    -1,   323,    18,    -1,    -1,    -1,   323,    33,   248,
      11,    12,    13,    14,    -1,    -1,    31,    -1,    -1,   203,
      -1,    -1,   129,    -1,   263,   209,   210,    -1,    43,   136,
      -1,    32,    37,    -1,    35,   274,   275,     7,     8,     9,
     147,    11,    12,    -1,    -1,    -1,   367,    -1,    18,    -1,
      -1,   367,   159,   237,    -1,    -1,   295,    -1,    -1,    -1,
     299,    31,    -1,    -1,   248,    -1,    -1,   306,   175,    -1,
      -1,    76,    -1,    43,    37,    80,   183,    -1,    83,   263,
      11,    12,    13,    14,   323,    11,    12,    13,    14,    -1,
     274,   275,    11,    12,    13,    14,   203,    11,    12,    13,
      14,    32,   209,   210,    35,    -1,    32,    -1,    -1,    35,
      -1,   295,    -1,    76,    33,   299,    -1,    80,    32,    -1,
      83,    35,   306,    -1,   129,    -1,    -1,    -1,   367,    -1,
     237,   136,    -1,     7,     8,     9,    -1,    11,    12,   323,
      -1,   248,   147,    -1,    18,    -1,    11,    12,    13,    14,
      11,    12,    13,    14,   159,    20,   263,    31,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,   129,   274,   275,    43,
     175,    32,    -1,   136,    35,    -1,    -1,    -1,   183,    32,
      -1,    -1,    35,   367,   147,    -1,    -1,    -1,   295,     7,
       8,     9,   299,    11,    12,    -1,   159,    15,   203,   306,
      18,    19,    -1,    -1,   209,   210,    -1,    11,    12,    13,
      14,    29,   175,    31,    -1,    33,   323,    -1,    36,    37,
     183,    39,    40,    41,    42,    43,     7,     8,     9,    33,
      11,    12,   237,    11,    12,    13,    14,    18,    -1,    -1,
     203,    -1,    -1,   248,    -1,    -1,   209,   210,    -1,    -1,
      31,    -1,     7,     8,     9,    33,    11,    12,   263,    -1,
     367,    -1,    43,    18,    11,    12,    13,    14,    -1,   274,
     275,    -1,    -1,    -1,   237,    -1,    31,    -1,     7,     8,
       9,    -1,    11,    12,    -1,   248,    33,    -1,    43,    18,
     295,    -1,    -1,    -1,   299,    11,    12,    13,    14,    -1,
     263,   306,    31,    -1,    -1,     7,     8,     9,    -1,    11,
      12,   274,   275,    -1,    43,    -1,    18,    33,   323,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    31,
      -1,    15,   295,    -1,    18,    19,   299,    -1,    -1,    -1,
      -1,    43,    -1,   306,    -1,    29,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
     323,    -1,   367,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      -1,    -1,    -1,    11,    12,    13,    14,    -1,    -1,    29,
      30,    31,    20,    33,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,   367,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    15,    -1,    -1,
      18,    19,    -1,    -1,    -1,    11,    12,    13,    14,    -1,
      -1,    29,    30,    31,    20,    33,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    15,    -1,
      -1,    18,    19,    -1,    -1,    -1,    11,    12,    13,    14,
      -1,    -1,    29,    30,    31,    20,    33,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    15,
      -1,    -1,    18,    19,    -1,    -1,    -1,    11,    12,    13,
      14,    -1,    -1,    29,    30,    31,    20,    33,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    -1,    -1,    -1,    11,    12,
      13,    14,    -1,    -1,    29,    30,    31,    20,    33,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,    11,
      12,    13,    14,    -1,    -1,    29,    30,    31,    20,    33,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,
      11,    12,    13,    14,    -1,    -1,    29,    30,    31,    20,
      33,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    15,    -1,    -1,    18,    19,     0,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,     0,
       1,    -1,     3,     4,     5,     6,    -1,    -1,    29,    30,
      31,    -1,    33,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
       0,     1,    -1,     3,     4,     5,     6,    -1,    -1,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    15,    -1,    -1,    18,
      19,     0,     1,    -1,     3,     4,     5,     6,    -1,    -1,
      29,    30,    31,    -1,    33,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    15,    -1,    -1,
      18,    19,     0,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    15,    -1,
      -1,    18,    19,     0,     1,    -1,     3,     4,     5,     6,
      -1,    -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    15,
      -1,    -1,    18,    19,     0,     1,    -1,     3,     4,     5,
       6,    -1,    -1,    29,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,     0,     1,    -1,     3,     4,
       5,     6,    -1,    -1,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    -1,    39,    40,    41,    42,    43,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      33,    -1,    -1,    36,    37,    -1,    39,    40,    41,    42,
      43,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    15,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    39,    40,    41,
      42,    43,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    33,    -1,    -1,    36,    37,    -1,    39,    40,
      41,    42,    43,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,    39,
      40,    41,    42,    43,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    15,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,
      39,    40,    41,    42,    43,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    15,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      -1,    39,    40,    41,    42,    43,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    15,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    -1,    39,    40,    41,    42,    43,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    15,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    -1,    39,    40,    41,    42,    43,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    -1,    39,    40,    41,    42,    43,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    -1,    39,    40,    41,    42,    43,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      33,    -1,    -1,    36,    37,    -1,    39,    40,    41,    42,
      43,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    15,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      -1,    33,    -1,    -1,    36,    37,    -1,    39,    40,    41,
      42,    43,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    33,    -1,    -1,    36,    37,    -1,    39,    40,
      41,    42,    43,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,    39,
      40,    41,    42,    43,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    15,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    -1,    33,    -1,    -1,    36,    37,    -1,
      39,    40,    41,    42,    43,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    15,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,    37,
      -1,    39,    40,    41,    42,    43,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    -1,    15,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    33,    -1,    -1,    36,
      37,    -1,    39,    40,    41,    42,    43,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    15,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,    -1,
      36,    37,    -1,    39,    40,    41,    42,    43,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      15,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,
      -1,    36,    37,    -1,    39,    40,    41,    42,    43,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,    33,
      -1,    -1,    36,    37,    -1,    39,    40,    41,    42,    43,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      33,    -1,    -1,    36,    37,    -1,    39,    40,    41,    42,
      43,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    15,    -1,    -1,    18,    19,    -1,     7,
       8,     9,    -1,    11,    12,    -1,    -1,    29,    30,    31,
      18,    33,    -1,    -1,    36,    37,    -1,    39,    40,    41,
      42,    43,    -1,    31,    -1,     7,     8,     9,    -1,    11,
      12,    11,    12,    13,    14,    43,    18,    -1,    -1,     7,
       8,     9,    -1,    11,    12,    11,    12,    13,    14,    31,
      18,    31,    32,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    43,    -1,    31,    18,    -1,    32,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    43,    -1,    31,    18,    -1,
      11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    31,    -1,    -1,    -1,    11,    12,    13,    14,    -1,
      16,    17,    33,    43,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    32,    -1,    34,    35,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    32,    -1,    -1,    35,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,    35,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    35,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,    35,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    35,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,    35,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    35,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,    35,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    35,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,    35,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    35,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,    35,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    -1,    -1,    35,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,    35,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    11,    12,    35,    -1,    -1,    16,    17,    -1,
      -1,    20,    -1,    -1,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    -1,    -1,    35,    11,    12,    13,
      14,    -1,    16,    17,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    31,    -1,    33,
      34,    11,    12,    13,    14,    -1,    16,    17,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    31,    32,    -1,    34,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    31,    -1,    33,    11,    12,
      13,    14,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,
      23,    24,    25,    26,    27,    28,    11,    12,    13,    14,
      33,    16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,
      25,    26,    27,    28,    11,    12,    13,    14,    33,    16,
      17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    11,    12,    13,    14,    33,    16,    17,    -1,
      -1,    20,    -1,    -1,    23,    24,    25,    26,    27,    28,
      11,    12,    13,    14,    33,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    11,    12,
      13,    14,    33,    16,    17,    -1,    -1,    20,    -1,    -1,
      23,    24,    25,    26,    27,    28,    11,    12,    13,    14,
      33,    16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,
      25,    26,    27,    28,    11,    12,    13,    14,    33,    16,
      17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    11,    12,    13,    14,    33,    16,    17,    -1,
      -1,    20,    -1,    -1,    23,    24,    25,    26,    27,    28,
      11,    12,    13,    14,    33,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    11,    12,
      13,    14,    33,    16,    17,    -1,    -1,    20,    -1,    -1,
      23,    24,    25,    26,    27,    28,    11,    12,    13,    14,
      33,    16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,
      25,    26,    27,    28,    11,    12,    13,    14,    33,    16,
      17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    11,    12,    13,    14,    33,    16,    17,    -1,
      -1,    20,    -1,    -1,    23,    24,    25,    26,    27,    28,
      11,    12,    13,    14,    33,    11,    12,    13,    14,    11,
      12,    13,    14,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    33,    11,    12,    13,    14,    33,    -1,    -1,
      -1,    33,    20,    -1,    -1,    33,    11,    12,    13,    14,
      -1,    16,    17,    31,    32,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    31,    32,    11,    12,
      13,    14,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,
      23,    24,    25,    26,    27,    28,    -1,    -1,    31,    32,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    11,    12,    13,    14,    -1,    16,    17,    -1,
      -1,    20,    -1,    -1,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    11,    12,    13,    14,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    32,    11,    12,    13,    14,
      -1,    16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    32,    11,    12,
      13,    14,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    32,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    11,    12,    13,    14,    -1,    16,    17,    -1,
      -1,    20,    -1,    -1,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    11,    12,    13,    14,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    32,    11,    12,    13,    14,
      -1,    16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    32,    11,    12,
      13,    14,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    32,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    32,    11,    12,    13,    14,    -1,    16,    17,    -1,
      -1,    20,    -1,    -1,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    32,    11,    12,    13,    14,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    32,    11,    12,    13,    14,
      -1,    16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,
      25,    26,    27,    28,    11,    12,    -1,    32,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    32,    11,    12,    13,    14,
      11,    12,    13,    14,    11,    12,    13,    14,    11,    12,
      13,    14,    11,    12,    13,    14,    -1,    32,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    32,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    32,    11,    12,    13,    14,    11,    12,
      13,    14,    11,    12,    13,    14,    11,    12,    13,    14,
      11,    12,    13,    14,    -1,    32,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    32,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,    45,    46,    47,    48,
      49,    50,     0,    47,    43,    31,    33,    49,    51,    52,
      53,    43,    32,    35,    29,    54,    53,    55,     7,     8,
       9,    11,    12,    15,    18,    19,    30,    31,    33,    36,
      37,    39,    40,    41,    42,    43,    48,    49,    54,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    68,
      69,    70,    71,    73,    74,    77,    78,    79,    80,    82,
      43,    69,    43,    69,    64,    31,    31,    33,    64,    31,
      31,    34,    43,    31,    33,    16,    17,    23,    24,    25,
      26,    27,    28,    66,    67,    70,     7,     8,    13,    14,
      72,    20,    21,    22,    81,    32,    64,    64,    33,    43,
      64,    75,    76,    64,    10,    43,    65,    83,    69,    69,
      71,    73,    43,    69,    43,    33,    32,    32,    32,    35,
      32,    64,    56,    33,    64,    33,    33,    38,    64,    56,
      32,    56,    29,     7,     8,     9,    18,    31,    70,    71,
      73,    74,    82,     7,     8,     9,    15,    18,    19,    31,
      43,    65,    68,    69,    70,    71,    73,    74,    77,    78,
      79,    80,    82,    11,    12,    31,    70,     7,     8,     9,
      15,    18,    19,    31,    43,    65,    68,    69,    70,    71,
      73,    74,    77,    78,    79,    80,    82,    33,    43,     7,
       8,     9,    18,    31,    70,    71,    73,    74,    82,    31,
      31,    70,    29,    33,    36,    37,    39,    40,    54,    57,
      58,    59,    60,    61,    62,    63,    64,    55,    43,    64,
       7,     8,    72,     7,     8,     9,    18,    31,    43,    69,
      70,    71,    73,    74,    82,    43,    69,    64,    34,    66,
      67,    70,     7,     8,    72,    20,    81,    75,    71,     7,
       8,     9,    18,    31,    43,    69,    70,    71,    73,    74,
      82,    43,    69,    64,    31,    34,    66,    67,    70,     7,
       8,    72,    20,    81,    43,    64,     7,     8,    72,    75,
      75,    43,    71,    55,    31,    31,    33,    64,    31,    31,
      33,    30,    32,    73,    43,    64,    31,    70,     7,     8,
      72,    32,    64,    69,    69,    43,    71,    73,    43,    43,
      32,    43,    64,    31,    70,     7,     8,    72,    32,    75,
      64,    69,    69,    43,    71,    73,    43,    43,    32,    73,
      32,    32,    30,    64,    64,    33,    43,    83,    32,    75,
      71,    73,    32,    75,    71,    73,    32,    33,    32,    32,
      32,    32,    32,    64,    56,    33,    33,    33,    38,    64,
      56,    32,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    48,    49,
      49,    49,    49,    50,    51,    51,    52,    52,    53,    54,
      55,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    59,    60,    60,    61,    62,    63,
      63,    64,    64,    65,    65,    65,    65,    65,    66,    66,
      66,    66,    66,    66,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    75,    75,    76,    76,    77,    78,
      78,    79,    80,    80,    81,    81,    82,    82,    82,    82,
      83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     6,     1,     0,     3,     1,     2,     3,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     5,     7,     9,     2,     3,     5,     5,     1,
       1,     3,     1,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       2,     1,     1,     4,     1,     0,     3,     1,     3,     3,
       1,     3,     3,     1,     1,     1,     2,     2,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration-list  */
#line 120 "src/syn.y"
                   {
    print_grammar_rule("program\0");
    node_t* declaration_list = (yyvsp[0].node);
    syntax_tree = declaration_list;
  }
#line 2595 "src/syn.tab.c"
    break;

  case 3: /* declaration-list: declaration-list declaration  */
#line 129 "src/syn.y"
                               {
    print_grammar_rule("declaration-list multiple\0");
    (yyval.node) = initialize_node("declaration-list");
    node_t* declaration_list = (yyval.node);
    node_t* recursive_declaration_list = (yyvsp[-1].node);
    node_t* declaration = (yyvsp[0].node);
    add_node(declaration_list, recursive_declaration_list);
    add_node(declaration_list, declaration);
  }
#line 2609 "src/syn.tab.c"
    break;

  case 4: /* declaration-list: declaration  */
#line 138 "src/syn.y"
                {
    print_grammar_rule("declaration-list single\0");
    (yyval.node) = (yyvsp[0].node);
  }
#line 2618 "src/syn.tab.c"
    break;

  case 5: /* declaration: var-declaration  */
#line 146 "src/syn.y"
                  {
    print_grammar_rule("declaration var-declaration\0");
    (yyval.node) = (yyvsp[0].node);
  }
#line 2627 "src/syn.tab.c"
    break;

  case 6: /* declaration: func-declaration  */
#line 150 "src/syn.y"
                     {
    (yyval.node) = (yyvsp[0].node);
    print_grammar_rule("declaration func-declaration\0");
  }
#line 2636 "src/syn.tab.c"
    break;

  case 7: /* declaration: error  */
#line 154 "src/syn.y"
          {
    has_syntax_error = 1;
  }
#line 2644 "src/syn.tab.c"
    break;

  case 8: /* var-declaration: data-type ID SEMICOLON  */
#line 161 "src/syn.y"
                         {
    print_grammar_rule("var-declaration\0");
    (yyval.node) = initialize_node("var-declaration");
    node_t* var_declaration = (yyval.node);
    node_t* data_type = (yyvsp[-2].node);
    node_t* id = initialize_node((yyvsp[-1].terminal_string));
    add_node(var_declaration, data_type);
    add_node(var_declaration, id);
    add_symbol_table_entry(current_symbol_table, id->name, data_type->name);
    free((yyvsp[-1].terminal_string));
  }
#line 2660 "src/syn.tab.c"
    break;

  case 9: /* data-type: INT_TYPE  */
#line 176 "src/syn.y"
           {
    print_grammar_rule("data-type INT_TYPE\0");
    (yyval.node) = initialize_node("int");
  }
#line 2669 "src/syn.tab.c"
    break;

  case 10: /* data-type: FLOAT_TYPE  */
#line 180 "src/syn.y"
               {
    print_grammar_rule("data-type FLOAT_TYPE\0");
    (yyval.node) = initialize_node("float");
  }
#line 2678 "src/syn.tab.c"
    break;

  case 11: /* data-type: INT_LIST_TYPE  */
#line 184 "src/syn.y"
                  {
    print_grammar_rule("data-type INT_LIST_TYPE\0");
    (yyval.node) = initialize_node("int list");
  }
#line 2687 "src/syn.tab.c"
    break;

  case 12: /* data-type: FLOAT_LIST_TYPE  */
#line 188 "src/syn.y"
                    {
    print_grammar_rule("data-type FLOAT_LIST_TYPE\0");
    (yyval.node) = initialize_node("float list");
  }
#line 2696 "src/syn.tab.c"
    break;

  case 13: /* func-declaration: data-type ID LPARENTHESES params-list RPARENTHESES block-statement  */
#line 196 "src/syn.y"
                                                                     {
    print_grammar_rule("func-declaration\0");
    (yyval.node) = initialize_node("func-declaration");
    node_t* func_declaration = (yyval.node);
    node_t* data_type = (yyvsp[-5].node);
    node_t* id = initialize_node((yyvsp[-4].terminal_string));
    add_node(func_declaration, data_type);
    add_node(func_declaration, id);
    add_symbol_table_entry(current_symbol_table, id->name, "function");
    free((yyvsp[-4].terminal_string));
  }
#line 2712 "src/syn.tab.c"
    break;

  case 14: /* params-list: params  */
#line 211 "src/syn.y"
         {
    print_grammar_rule("params-list params\0");
  }
#line 2720 "src/syn.tab.c"
    break;

  case 15: /* params-list: %empty  */
#line 214 "src/syn.y"
           {
    print_grammar_rule("params-list empty\0");
  }
#line 2728 "src/syn.tab.c"
    break;

  case 16: /* params: params COMMA param  */
#line 221 "src/syn.y"
                     {
    print_grammar_rule("params multiple params\0");
  }
#line 2736 "src/syn.tab.c"
    break;

  case 17: /* params: param  */
#line 224 "src/syn.y"
          {
    print_grammar_rule("params single param\0");
  }
#line 2744 "src/syn.tab.c"
    break;

  case 18: /* param: data-type ID  */
#line 231 "src/syn.y"
               {
    print_grammar_rule("param\0");
    free((yyvsp[0].terminal_string));
  }
#line 2753 "src/syn.tab.c"
    break;

  case 19: /* block-statement: LBRACE statement-or-declaration-list RBRACE  */
#line 239 "src/syn.y"
                                              {
    print_grammar_rule("block-statement\0");
  }
#line 2761 "src/syn.tab.c"
    break;

  case 20: /* statement-or-declaration-list: statement-or-declaration-list statement  */
#line 246 "src/syn.y"
                                          {
    print_grammar_rule("statement-or-declaration-list statement\0");
  }
#line 2769 "src/syn.tab.c"
    break;

  case 21: /* statement-or-declaration-list: statement-or-declaration-list var-declaration  */
#line 249 "src/syn.y"
                                                  {
    print_grammar_rule("statement-or-declaration-list var-declaration\0");
  }
#line 2777 "src/syn.tab.c"
    break;

  case 22: /* statement-or-declaration-list: %empty  */
#line 252 "src/syn.y"
           {
    print_grammar_rule("statement-or-declaration-list empty\0");
  }
#line 2785 "src/syn.tab.c"
    break;

  case 23: /* statement: expression-statement  */
#line 259 "src/syn.y"
                       {
    print_grammar_rule("statement expression-statement\0");
  }
#line 2793 "src/syn.tab.c"
    break;

  case 24: /* statement: block-statement  */
#line 262 "src/syn.y"
                    {
    print_grammar_rule("statement block-statement\0");
  }
#line 2801 "src/syn.tab.c"
    break;

  case 25: /* statement: conditional-statement  */
#line 265 "src/syn.y"
                          {
    print_grammar_rule("statement conditional-statement\0");
  }
#line 2809 "src/syn.tab.c"
    break;

  case 26: /* statement: iteration-statement  */
#line 268 "src/syn.y"
                        {
    print_grammar_rule("statement iteration-statement\0");
  }
#line 2817 "src/syn.tab.c"
    break;

  case 27: /* statement: return-statement  */
#line 271 "src/syn.y"
                     {
    print_grammar_rule("statement return-statement\0");
  }
#line 2825 "src/syn.tab.c"
    break;

  case 28: /* statement: input-statement  */
#line 274 "src/syn.y"
                    {
    print_grammar_rule("statement input-statement\0");
  }
#line 2833 "src/syn.tab.c"
    break;

  case 29: /* statement: output-statement  */
#line 277 "src/syn.y"
                     {
    print_grammar_rule("statement output-statement\0");
  }
#line 2841 "src/syn.tab.c"
    break;

  case 30: /* expression-statement: expression SEMICOLON  */
#line 284 "src/syn.y"
                       {
    print_grammar_rule("expression-statement expression\0");
  }
#line 2849 "src/syn.tab.c"
    break;

  case 31: /* expression-statement: SEMICOLON  */
#line 287 "src/syn.y"
              {
    print_grammar_rule("expression-statement semicolon\0");
  }
#line 2857 "src/syn.tab.c"
    break;

  case 32: /* conditional-statement: IF_KW LPARENTHESES expression RPARENTHESES statement  */
#line 294 "src/syn.y"
                                                       {
    print_grammar_rule("conditional-statement IF\0");
  }
#line 2865 "src/syn.tab.c"
    break;

  case 33: /* conditional-statement: IF_KW LPARENTHESES expression RPARENTHESES statement ELSE_KW statement  */
#line 297 "src/syn.y"
                                                                           {
    print_grammar_rule("conditional-statement IF ELSE\0");
  }
#line 2873 "src/syn.tab.c"
    break;

  case 34: /* iteration-statement: FOR_KW LPARENTHESES expression SEMICOLON expression SEMICOLON expression RPARENTHESES statement  */
#line 304 "src/syn.y"
                                                                                                  {
    print_grammar_rule("iteration-statement\0");
  }
#line 2881 "src/syn.tab.c"
    break;

  case 35: /* return-statement: RETURN_KW SEMICOLON  */
#line 311 "src/syn.y"
                      {
    print_grammar_rule("return-statement void\0");
  }
#line 2889 "src/syn.tab.c"
    break;

  case 36: /* return-statement: RETURN_KW expression SEMICOLON  */
#line 314 "src/syn.y"
                                   {
    print_grammar_rule("return-statement expression\0");
  }
#line 2897 "src/syn.tab.c"
    break;

  case 37: /* input-statement: READ_KW LPARENTHESES ID RPARENTHESES SEMICOLON  */
#line 321 "src/syn.y"
                                                 {
    print_grammar_rule("input-statement\0");
    free((yyvsp[-2].terminal_string));
  }
#line 2906 "src/syn.tab.c"
    break;

  case 38: /* output-statement: write-call LPARENTHESES output-arg RPARENTHESES SEMICOLON  */
#line 329 "src/syn.y"
                                                            {
    print_grammar_rule("output-statement simple-expression\0");
  }
#line 2914 "src/syn.tab.c"
    break;

  case 39: /* write-call: WRITE_KW  */
#line 336 "src/syn.y"
           {
    print_grammar_rule("write-call write\0");
  }
#line 2922 "src/syn.tab.c"
    break;

  case 40: /* write-call: WRITELN_KW  */
#line 339 "src/syn.y"
               {
    print_grammar_rule("write-call writeln\0");
  }
#line 2930 "src/syn.tab.c"
    break;

  case 41: /* expression: ID ASSIGNMENT expression  */
#line 346 "src/syn.y"
                           {
    print_grammar_rule("expression assigment\0");
    free((yyvsp[-2].terminal_string));
  }
#line 2939 "src/syn.tab.c"
    break;

  case 42: /* expression: simple-expression  */
#line 350 "src/syn.y"
                      {
    print_grammar_rule("expression simple-expression\0");
  }
#line 2947 "src/syn.tab.c"
    break;

  case 43: /* simple-expression: math-expression relational-operator math-expression  */
#line 357 "src/syn.y"
                                                      {
    print_grammar_rule("simple-expression relational-operator\0");
  }
#line 2955 "src/syn.tab.c"
    break;

  case 44: /* simple-expression: math-expression binary-logical-operator math-expression  */
#line 360 "src/syn.y"
                                                            {
    print_grammar_rule("simple-expression binary-logical-operator\0");
  }
#line 2963 "src/syn.tab.c"
    break;

  case 45: /* simple-expression: NOT_OR_TAIL_OP math-expression  */
#line 363 "src/syn.y"
                                   {
    print_grammar_rule("simple-expression not or tail op\0");
  }
#line 2971 "src/syn.tab.c"
    break;

  case 46: /* simple-expression: math-expression  */
#line 366 "src/syn.y"
                    {
    print_grammar_rule("simple-expression math-expression\0");
  }
#line 2979 "src/syn.tab.c"
    break;

  case 47: /* simple-expression: list-expression  */
#line 369 "src/syn.y"
                    {
    print_grammar_rule("simple-expression list-expression");
  }
#line 2987 "src/syn.tab.c"
    break;

  case 48: /* relational-operator: LESSTHAN_OP  */
#line 376 "src/syn.y"
              {
    print_grammar_rule("relational-operator LESSTHAN\0");
  }
#line 2995 "src/syn.tab.c"
    break;

  case 49: /* relational-operator: LESSEQUAL_OP  */
#line 379 "src/syn.y"
                 {
    print_grammar_rule("relational-operator LESSEQUAL\0");
  }
#line 3003 "src/syn.tab.c"
    break;

  case 50: /* relational-operator: GREATERTHAN_OP  */
#line 382 "src/syn.y"
                   {
    print_grammar_rule("relational-operator GREATERTHAN\0");
  }
#line 3011 "src/syn.tab.c"
    break;

  case 51: /* relational-operator: GREATEREQUAL_OP  */
#line 385 "src/syn.y"
                    {
    print_grammar_rule("relational-operator GREATEREQUAL\0");
  }
#line 3019 "src/syn.tab.c"
    break;

  case 52: /* relational-operator: NOTEQUAL_OP  */
#line 388 "src/syn.y"
                {
    print_grammar_rule("relational-operator NOTEQUAL\0");
  }
#line 3027 "src/syn.tab.c"
    break;

  case 53: /* relational-operator: EQUAL_OP  */
#line 391 "src/syn.y"
             {
    print_grammar_rule("relational-operator EQUAL\0");
  }
#line 3035 "src/syn.tab.c"
    break;

  case 54: /* binary-logical-operator: AND_OP  */
#line 398 "src/syn.y"
         { 
    print_grammar_rule("binary-logical-operator AND\0");
  }
#line 3043 "src/syn.tab.c"
    break;

  case 55: /* binary-logical-operator: OR_OP  */
#line 401 "src/syn.y"
          { 
    print_grammar_rule("binary-logical-operator OR\0");
  }
#line 3051 "src/syn.tab.c"
    break;

  case 56: /* list-expression: list-constructor  */
#line 408 "src/syn.y"
                   {
    print_grammar_rule("list-expression list constructor\0");
  }
#line 3059 "src/syn.tab.c"
    break;

  case 57: /* list-expression: list-func  */
#line 411 "src/syn.y"
              {
    print_grammar_rule("list-expression list func");
  }
#line 3067 "src/syn.tab.c"
    break;

  case 58: /* list-expression: LIST_TAIL_OP math-expression  */
#line 414 "src/syn.y"
                                 {
    print_grammar_rule("list-expression list tail\0");
  }
#line 3075 "src/syn.tab.c"
    break;

  case 59: /* math-expression: math-expression add-sub-operator term  */
#line 421 "src/syn.y"
                                        {
    print_grammar_rule("math-expression add-sub\0");
  }
#line 3083 "src/syn.tab.c"
    break;

  case 60: /* math-expression: term  */
#line 424 "src/syn.y"
         {
    print_grammar_rule("math-expression term\0");
  }
#line 3091 "src/syn.tab.c"
    break;

  case 61: /* add-sub-operator: ADD_OP  */
#line 431 "src/syn.y"
         {
    print_grammar_rule("add-sub-operator ADD_OP\0");
  }
#line 3099 "src/syn.tab.c"
    break;

  case 62: /* add-sub-operator: SUB_OP  */
#line 434 "src/syn.y"
           {
    print_grammar_rule("add-sub-operator SUB_OP\0");
  }
#line 3107 "src/syn.tab.c"
    break;

  case 63: /* term: term mul-div-operator factor  */
#line 441 "src/syn.y"
                               {
    print_grammar_rule("term mul-div\0");
  }
#line 3115 "src/syn.tab.c"
    break;

  case 64: /* term: factor  */
#line 444 "src/syn.y"
           {
    print_grammar_rule("term factor\0");
  }
#line 3123 "src/syn.tab.c"
    break;

  case 65: /* mul-div-operator: MULT_OP  */
#line 451 "src/syn.y"
          {
    print_grammar_rule("mul-div-operator mult\0");
  }
#line 3131 "src/syn.tab.c"
    break;

  case 66: /* mul-div-operator: DIV_OP  */
#line 454 "src/syn.y"
           {
    print_grammar_rule("mul-div-operator div\0");
  }
#line 3139 "src/syn.tab.c"
    break;

  case 67: /* factor: LPARENTHESES expression RPARENTHESES  */
#line 461 "src/syn.y"
                                       {
    print_grammar_rule("factor expression\0");
  }
#line 3147 "src/syn.tab.c"
    break;

  case 68: /* factor: func-call  */
#line 464 "src/syn.y"
              {
    print_grammar_rule("factor func-call\0");
  }
#line 3155 "src/syn.tab.c"
    break;

  case 69: /* factor: numeric-const  */
#line 467 "src/syn.y"
                  {
    print_grammar_rule("factor numeric-const\0");
  }
#line 3163 "src/syn.tab.c"
    break;

  case 70: /* factor: LIST_HEAD_OP ID  */
#line 470 "src/syn.y"
                    {
    print_grammar_rule("factor list head\0");
    free((yyvsp[0].terminal_string));
  }
#line 3172 "src/syn.tab.c"
    break;

  case 71: /* factor: ID  */
#line 474 "src/syn.y"
       {
    print_grammar_rule("factor id\0");
    free((yyvsp[0].terminal_string));
  }
#line 3181 "src/syn.tab.c"
    break;

  case 72: /* factor: LIST_CONST  */
#line 478 "src/syn.y"
               {
    print_grammar_rule("factor list const\0");
  }
#line 3189 "src/syn.tab.c"
    break;

  case 73: /* func-call: ID LPARENTHESES args-list RPARENTHESES  */
#line 485 "src/syn.y"
                                         {
    print_grammar_rule("func-call\0");
    free((yyvsp[-3].terminal_string));
  }
#line 3198 "src/syn.tab.c"
    break;

  case 74: /* args-list: args  */
#line 493 "src/syn.y"
       {
    print_grammar_rule("args-list args\0");
  }
#line 3206 "src/syn.tab.c"
    break;

  case 75: /* args-list: %empty  */
#line 496 "src/syn.y"
           {
    print_grammar_rule("args-list empty\0");
  }
#line 3214 "src/syn.tab.c"
    break;

  case 76: /* args: args COMMA expression  */
#line 503 "src/syn.y"
                        {
    print_grammar_rule("args multiple args\0");
  }
#line 3222 "src/syn.tab.c"
    break;

  case 77: /* args: expression  */
#line 506 "src/syn.y"
               {
    print_grammar_rule("args expression\0");
  }
#line 3230 "src/syn.tab.c"
    break;

  case 78: /* list-constructor: list-constructor-expression LIST_CONSTRUCTOR_OP ID  */
#line 513 "src/syn.y"
                                                     {
    print_grammar_rule("list-constructor\0");
    free((yyvsp[0].terminal_string));
  }
#line 3239 "src/syn.tab.c"
    break;

  case 79: /* list-constructor-expression: list-constructor-expression LIST_CONSTRUCTOR_OP math-expression  */
#line 521 "src/syn.y"
                                                                  {
    print_grammar_rule("list-constructor-expression adding expression\0");
  }
#line 3247 "src/syn.tab.c"
    break;

  case 80: /* list-constructor-expression: math-expression  */
#line 524 "src/syn.y"
                    {
    print_grammar_rule("list-constructor-expression finished\0");
  }
#line 3255 "src/syn.tab.c"
    break;

  case 81: /* list-func: list-func-expression list-func-operator ID  */
#line 531 "src/syn.y"
                                             {
    print_grammar_rule("list-func\0");
    free((yyvsp[0].terminal_string));
  }
#line 3264 "src/syn.tab.c"
    break;

  case 82: /* list-func-expression: list-func-expression list-func-operator ID  */
#line 539 "src/syn.y"
                                             {
    print_grammar_rule("list-func-expression multiple");
    free((yyvsp[0].terminal_string));
  }
#line 3273 "src/syn.tab.c"
    break;

  case 83: /* list-func-expression: ID  */
#line 543 "src/syn.y"
       {
    print_grammar_rule("list-func-expression single id");
    free((yyvsp[0].terminal_string));
  }
#line 3282 "src/syn.tab.c"
    break;

  case 84: /* list-func-operator: LIST_MAP_OP  */
#line 551 "src/syn.y"
              {
    print_grammar_rule("list-func-operator map");
  }
#line 3290 "src/syn.tab.c"
    break;

  case 85: /* list-func-operator: LIST_FILTER_OP  */
#line 554 "src/syn.y"
                   {
    print_grammar_rule("list-func-operator filter");
  }
#line 3298 "src/syn.tab.c"
    break;

  case 86: /* numeric-const: add-sub-operator FLOAT_CONST  */
#line 561 "src/syn.y"
                               {
    print_grammar_rule("numeric-const signed float const\0");
  }
#line 3306 "src/syn.tab.c"
    break;

  case 87: /* numeric-const: add-sub-operator INT_CONST  */
#line 564 "src/syn.y"
                               {
    print_grammar_rule("numeric-const signed int const\0");
  }
#line 3314 "src/syn.tab.c"
    break;

  case 88: /* numeric-const: FLOAT_CONST  */
#line 567 "src/syn.y"
                {
    print_grammar_rule("numeric-const unsgigned float const\0");
  }
#line 3322 "src/syn.tab.c"
    break;

  case 89: /* numeric-const: INT_CONST  */
#line 570 "src/syn.y"
              {
    print_grammar_rule("numeric-const unsigned int const\0");
  }
#line 3330 "src/syn.tab.c"
    break;

  case 90: /* output-arg: simple-expression  */
#line 577 "src/syn.y"
                    {
    print_grammar_rule("output-arg simple-expression");
  }
#line 3338 "src/syn.tab.c"
    break;

  case 91: /* output-arg: STRING_CONST  */
#line 580 "src/syn.y"
                 {
    print_grammar_rule("output-arg string const");
  }
#line 3346 "src/syn.tab.c"
    break;


#line 3350 "src/syn.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 585 "src/syn.y"

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
  // The root symbol table is the only one without a parent
  symbol_table = initialize_symbol_table("global");
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
