/* A Bison parser, made by GNU Bison 3.7.5.  */

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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

    int yyerror();

    Ast *ast;
    

#line 78 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    KW_CHAR = 258,                 /* KW_CHAR  */
    KW_INT = 259,                  /* KW_INT  */
    KW_FLOAT = 260,                /* KW_FLOAT  */
    KW_IF = 261,                   /* KW_IF  */
    KW_ELSE = 262,                 /* KW_ELSE  */
    KW_WHILE = 263,                /* KW_WHILE  */
    KW_READ = 264,                 /* KW_READ  */
    KW_PRINT = 265,                /* KW_PRINT  */
    KW_RETURN = 266,               /* KW_RETURN  */
    ASSIGNMENT = 267,              /* ASSIGNMENT  */
    OPERATOR_LE = 268,             /* OPERATOR_LE  */
    OPERATOR_GE = 269,             /* OPERATOR_GE  */
    OPERATOR_EQ = 270,             /* OPERATOR_EQ  */
    OPERATOR_DIF = 271,            /* OPERATOR_DIF  */
    TK_IDENTIFIER = 272,           /* TK_IDENTIFIER  */
    LIT_INTEGER = 273,             /* LIT_INTEGER  */
    LIT_FLOAT = 274,               /* LIT_FLOAT  */
    LIT_CHAR = 275,                /* LIT_CHAR  */
    LIT_STRING = 276,              /* LIT_STRING  */
    TOKEN_ERROR = 277              /* TOKEN_ERROR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define KW_CHAR 258
#define KW_INT 259
#define KW_FLOAT 260
#define KW_IF 261
#define KW_ELSE 262
#define KW_WHILE 263
#define KW_READ 264
#define KW_PRINT 265
#define KW_RETURN 266
#define ASSIGNMENT 267
#define OPERATOR_LE 268
#define OPERATOR_GE 269
#define OPERATOR_EQ 270
#define OPERATOR_DIF 271
#define TK_IDENTIFIER 272
#define LIT_INTEGER 273
#define LIT_FLOAT 274
#define LIT_CHAR 275
#define LIT_STRING 276
#define TOKEN_ERROR 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "parser.y"

    Hash *symbol;
    Ast *ast;

#line 180 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_CHAR = 3,                    /* KW_CHAR  */
  YYSYMBOL_KW_INT = 4,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 5,                   /* KW_FLOAT  */
  YYSYMBOL_KW_IF = 6,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 7,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 8,                   /* KW_WHILE  */
  YYSYMBOL_KW_READ = 9,                    /* KW_READ  */
  YYSYMBOL_KW_PRINT = 10,                  /* KW_PRINT  */
  YYSYMBOL_KW_RETURN = 11,                 /* KW_RETURN  */
  YYSYMBOL_ASSIGNMENT = 12,                /* ASSIGNMENT  */
  YYSYMBOL_OPERATOR_LE = 13,               /* OPERATOR_LE  */
  YYSYMBOL_OPERATOR_GE = 14,               /* OPERATOR_GE  */
  YYSYMBOL_OPERATOR_EQ = 15,               /* OPERATOR_EQ  */
  YYSYMBOL_OPERATOR_DIF = 16,              /* OPERATOR_DIF  */
  YYSYMBOL_TK_IDENTIFIER = 17,             /* TK_IDENTIFIER  */
  YYSYMBOL_LIT_INTEGER = 18,               /* LIT_INTEGER  */
  YYSYMBOL_LIT_FLOAT = 19,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_CHAR = 20,                  /* LIT_CHAR  */
  YYSYMBOL_LIT_STRING = 21,                /* LIT_STRING  */
  YYSYMBOL_TOKEN_ERROR = 22,               /* TOKEN_ERROR  */
  YYSYMBOL_23_ = 23,                       /* '&'  */
  YYSYMBOL_24_ = 24,                       /* '|'  */
  YYSYMBOL_25_ = 25,                       /* '<'  */
  YYSYMBOL_26_ = 26,                       /* '>'  */
  YYSYMBOL_27_ = 27,                       /* '+'  */
  YYSYMBOL_28_ = 28,                       /* '-'  */
  YYSYMBOL_29_ = 29,                       /* '.'  */
  YYSYMBOL_30_ = 30,                       /* '/'  */
  YYSYMBOL_31_ = 31,                       /* '~'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '['  */
  YYSYMBOL_36_ = 36,                       /* ']'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_declaration_lst = 41,           /* declaration_lst  */
  YYSYMBOL_declaration = 42,               /* declaration  */
  YYSYMBOL_literal = 43,                   /* literal  */
  YYSYMBOL_type_kw = 44,                   /* type_kw  */
  YYSYMBOL_literals_lst = 45,              /* literals_lst  */
  YYSYMBOL_parameters_lst = 46,            /* parameters_lst  */
  YYSYMBOL_parameters = 47,                /* parameters  */
  YYSYMBOL_command = 48,                   /* command  */
  YYSYMBOL_command_lst = 49,               /* command_lst  */
  YYSYMBOL_assign = 50,                    /* assign  */
  YYSYMBOL_expr = 51,                      /* expr  */
  YYSYMBOL_expr_lst = 52,                  /* expr_lst  */
  YYSYMBOL_if = 53,                        /* if  */
  YYSYMBOL_ife = 54,                       /* ife  */
  YYSYMBOL_while = 55,                     /* while  */
  YYSYMBOL_read = 56,                      /* read  */
  YYSYMBOL_print = 57,                     /* print  */
  YYSYMBOL_print_lst = 58,                 /* print_lst  */
  YYSYMBOL_print_expr = 59,                /* print_expr  */
  YYSYMBOL_return = 60                     /* return  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,     2,     2,     2,     2,     2,    23,     2,
      32,    33,     2,    27,     2,    28,    29,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      25,     2,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,    24,    38,    31,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    71,    71,    74,    75,    78,    79,    81,    83,    86,
      87,    88,    91,    92,    93,    96,    97,   100,   101,   104,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   118,
     119,   122,   123,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   146,   147,   150,   153,   156,   159,   160,   163,   166,
     167,   170,   171,   174
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_CHAR", "KW_INT",
  "KW_FLOAT", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_READ", "KW_PRINT",
  "KW_RETURN", "ASSIGNMENT", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_DIF", "TK_IDENTIFIER", "LIT_INTEGER", "LIT_FLOAT", "LIT_CHAR",
  "LIT_STRING", "TOKEN_ERROR", "'&'", "'|'", "'<'", "'>'", "'+'", "'-'",
  "'.'", "'/'", "'~'", "'('", "')'", "';'", "'['", "']'", "'{'", "'}'",
  "$accept", "program", "declaration_lst", "declaration", "literal",
  "type_kw", "literals_lst", "parameters_lst", "parameters", "command",
  "command_lst", "assign", "expr", "expr_lst", "if", "ife", "while",
  "read", "print", "print_lst", "print_expr", "return", YY_NULLPTR
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
     275,   276,   277,    38,   124,    60,    62,    43,    45,    46,
      47,   126,    40,    41,    59,    91,    93,   123,   125
};
#endif

#define YYPACT_NINF (-82)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,   -82,   -82,   -82,   -82,     7,   -82,    18,    -6,   -82,
     -82,    25,   230,    19,   -82,   -82,   -82,   -20,    33,    28,
      74,    35,    62,   -82,    61,   -82,    96,   -82,    -5,    96,
      65,    80,    85,   109,   220,   225,   -10,    -5,    93,    97,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   225,
     225,    98,    27,   -82,   225,   225,   -82,   178,   -82,   220,
     178,   225,   225,    99,    -5,   -82,    95,   116,   225,   225,
     225,   -82,   137,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   -82,   178,    40,   -82,   -82,
      -5,    -5,    59,   158,   101,    77,   -82,     1,     1,     1,
       1,   196,   202,     1,     1,   -12,   -12,   -82,   -82,   124,
     131,   -82,   -82,   -82,   -82,   -82,   225,    -5,   178,   -82
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    12,    13,    14,     8,     0,     2,     4,     0,     1,
       3,     0,    18,     0,    10,    11,     9,     0,     0,     0,
      18,     0,     0,    19,     0,    17,    16,     5,    28,    16,
       0,     0,     0,     0,    60,     0,     0,    28,    30,     0,
      21,    22,    23,    24,    25,    26,    27,    15,     6,     0,
       0,    56,    34,    61,     0,     0,    36,    62,    58,    60,
      63,     0,     0,     0,    28,     7,     0,     0,     0,    52,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    59,    31,     0,    20,    29,
      28,    28,     0,    52,     0,     0,    33,    43,    44,    45,
      46,    47,    48,    41,    42,    37,    38,    39,    40,     0,
      53,    55,    57,    51,    50,    35,     0,    28,    32,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   140,   -82,    68,    -4,   119,   134,   -82,   -81,
     -13,   -82,   -35,    63,   -82,   -82,   -82,   -82,   -82,   100,
     -82,   -82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    56,     8,    30,    19,    20,    38,
      39,    40,    57,    94,    41,    42,    43,    44,    45,    58,
      59,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      60,    31,    61,    32,    33,    34,    35,     9,    18,   110,
     111,    11,    36,    22,    66,    67,    18,    83,    84,    71,
      72,     1,     2,     3,    63,    62,    86,    87,    81,    82,
      83,    84,    37,    92,    93,    95,   119,    21,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      23,    89,     4,    73,    74,    75,    76,    12,    93,    69,
      13,    24,    70,    77,    78,    79,    80,    81,    82,    83,
      84,    26,    73,    74,    75,    76,   109,     1,     2,     3,
      17,   118,    77,    78,    79,    80,    81,    82,    83,    84,
      73,    74,    75,    76,    29,   112,    27,    29,    28,    48,
      77,    78,    79,    80,    81,    82,    83,    84,    73,    74,
      75,    76,    49,   115,    14,    15,    16,    50,    77,    78,
      79,    80,    81,    82,    83,    84,    51,    64,    90,    73,
      74,    75,    76,    68,   114,    65,   116,    88,   117,    77,
      78,    79,    80,    81,    82,    83,    84,    10,    47,    91,
      73,    74,    75,    76,    25,     0,   113,     0,     0,    85,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
      96,    73,    74,    75,    76,    52,    14,    15,    16,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    54,
      55,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    73,
      74,    75,    76,     0,     0,    73,    74,    75,    76,     0,
      78,    79,    80,    81,    82,    83,    84,    79,    80,    81,
      82,    83,    84,     1,     2,     3,     0,    52,    14,    15,
      16,    53,    52,    14,    15,    16,     0,     0,    14,    15,
      16,    54,    55,     0,     0,     0,    54,    55
};

static const yytype_int8 yycheck[] =
{
      35,     6,    12,     8,     9,    10,    11,     0,    12,    90,
      91,    17,    17,    33,    49,    50,    20,    29,    30,    54,
      55,     3,     4,     5,    37,    35,    61,    62,    27,    28,
      29,    30,    37,    68,    69,    70,   117,    18,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      17,    64,    34,    13,    14,    15,    16,    32,    93,    32,
      35,    33,    35,    23,    24,    25,    26,    27,    28,    29,
      30,    36,    13,    14,    15,    16,    36,     3,     4,     5,
      12,   116,    23,    24,    25,    26,    27,    28,    29,    30,
      13,    14,    15,    16,    26,    36,    34,    29,    37,    34,
      23,    24,    25,    26,    27,    28,    29,    30,    13,    14,
      15,    16,    32,    36,    18,    19,    20,    32,    23,    24,
      25,    26,    27,    28,    29,    30,    17,    34,    33,    13,
      14,    15,    16,    35,    33,    38,    12,    38,     7,    23,
      24,    25,    26,    27,    28,    29,    30,     7,    29,    33,
      13,    14,    15,    16,    20,    -1,    93,    -1,    -1,    59,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      33,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,    13,
      14,    15,    16,    -1,    -1,    13,    14,    15,    16,    -1,
      24,    25,    26,    27,    28,    29,    30,    25,    26,    27,
      28,    29,    30,     3,     4,     5,    -1,    17,    18,    19,
      20,    21,    17,    18,    19,    20,    -1,    -1,    18,    19,
      20,    31,    32,    -1,    -1,    -1,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    34,    40,    41,    42,    44,     0,
      41,    17,    32,    35,    18,    19,    20,    43,    44,    46,
      47,    18,    33,    17,    33,    46,    36,    34,    37,    43,
      45,     6,     8,     9,    10,    11,    17,    37,    48,    49,
      50,    53,    54,    55,    56,    57,    60,    45,    34,    32,
      32,    17,    17,    21,    31,    32,    43,    51,    58,    59,
      51,    12,    35,    49,    34,    38,    51,    51,    35,    32,
      35,    51,    51,    13,    14,    15,    16,    23,    24,    25,
      26,    27,    28,    29,    30,    58,    51,    51,    38,    49,
      33,    33,    51,    51,    52,    51,    33,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    36,
      48,    48,    36,    52,    33,    36,    12,     7,    51,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    42,    43,
      43,    43,    44,    44,    44,    45,    45,    46,    46,    47,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    53,    54,    55,    56,    56,    57,    58,
      58,    59,    59,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     6,     7,     8,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     2,     0,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       1,     3,     6,     3,     1,     4,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       4,     2,     0,     5,     7,     5,     2,     5,     2,     2,
       0,     1,     1,     2
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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_lst  */
#line 71 "parser.y"
                         { ast = (yyvsp[0].ast); }
#line 1328 "y.tab.c"
    break;

  case 3: /* declaration_lst: declaration declaration_lst  */
#line 74 "parser.y"
                                             { (yyval.ast) = createAstNode(AST_DECL, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1334 "y.tab.c"
    break;

  case 4: /* declaration_lst: %empty  */
#line 75 "parser.y"
      { (yyval.ast) = 0; }
#line 1340 "y.tab.c"
    break;

  case 5: /* declaration: type_kw TK_IDENTIFIER '(' literal ')' ';'  */
#line 78 "parser.y"
                                                       { (yyval.ast) = createAstNode(AST_VAR_DEC, 0, (yyvsp[-5].ast), createAstNode(AST_IDENTIFIER, (yyvsp[-4].symbol), 0, 0, 0, 0), (yyvsp[-2].ast), 0); }
#line 1346 "y.tab.c"
    break;

  case 6: /* declaration: type_kw TK_IDENTIFIER '[' LIT_INTEGER ']' literals_lst ';'  */
#line 79 "parser.y"
                                                                 { (yyval.ast) = createAstNode(AST_ARR_DEC, 0, (yyvsp[-6].ast), createAstNode(AST_IDENTIFIER, (yyvsp[-5].symbol), 0, 0, 0, 0), 
                                                                    createAstNode(AST_INT, (yyvsp[-3].symbol), 0, 0, 0, 0), (yyvsp[-1].ast)); }
#line 1353 "y.tab.c"
    break;

  case 7: /* declaration: type_kw TK_IDENTIFIER '(' parameters_lst ')' '{' command_lst '}'  */
#line 81 "parser.y"
                                                                       { (yyval.ast) = createAstNode(AST_FUNC_DEC, 0, (yyvsp[-7].ast), createAstNode(AST_IDENTIFIER, (yyvsp[-6].symbol), 0, 0, 0, 0),
                                                                            (yyvsp[-4].ast), (yyvsp[-1].ast)); }
#line 1360 "y.tab.c"
    break;

  case 8: /* declaration: ';'  */
#line 83 "parser.y"
          { (yyval.ast) = 0; }
#line 1366 "y.tab.c"
    break;

  case 9: /* literal: LIT_CHAR  */
#line 86 "parser.y"
                  { (yyval.ast) = createAstNode(AST_CHAR, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1372 "y.tab.c"
    break;

  case 10: /* literal: LIT_INTEGER  */
#line 87 "parser.y"
                  { (yyval.ast) = createAstNode(AST_INT, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1378 "y.tab.c"
    break;

  case 11: /* literal: LIT_FLOAT  */
#line 88 "parser.y"
                { (yyval.ast) = createAstNode(AST_FLOAT, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1384 "y.tab.c"
    break;

  case 12: /* type_kw: KW_CHAR  */
#line 91 "parser.y"
                 { (yyval.ast) = createAstNode(AST_KW_CHAR, 0, 0, 0, 0, 0); }
#line 1390 "y.tab.c"
    break;

  case 13: /* type_kw: KW_INT  */
#line 92 "parser.y"
             { (yyval.ast) = createAstNode(AST_KW_INT, 0, 0, 0, 0, 0); }
#line 1396 "y.tab.c"
    break;

  case 14: /* type_kw: KW_FLOAT  */
#line 93 "parser.y"
               { (yyval.ast) = createAstNode(AST_KW_FLOAT, 0, 0, 0, 0, 0); }
#line 1402 "y.tab.c"
    break;

  case 15: /* literals_lst: literal literals_lst  */
#line 96 "parser.y"
                                   { (yyval.ast) = createAstNode(AST_LIT_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1408 "y.tab.c"
    break;

  case 16: /* literals_lst: %empty  */
#line 97 "parser.y"
      { (yyval.ast) = 0; }
#line 1414 "y.tab.c"
    break;

  case 17: /* parameters_lst: parameters parameters_lst  */
#line 100 "parser.y"
                                          { (yyval.ast) = createAstNode(AST_PARAM_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1420 "y.tab.c"
    break;

  case 18: /* parameters_lst: %empty  */
#line 101 "parser.y"
      { (yyval.ast) = 0; }
#line 1426 "y.tab.c"
    break;

  case 19: /* parameters: type_kw TK_IDENTIFIER  */
#line 104 "parser.y"
                                  { (yyval.ast) = createAstNode(AST_PARAM, 0, (yyvsp[-1].ast), createAstNode(AST_IDENTIFIER, (yyvsp[0].symbol), 0, 0, 0, 0), 0, 0); }
#line 1432 "y.tab.c"
    break;

  case 20: /* command: '{' command_lst '}'  */
#line 107 "parser.y"
                             { (yyval.ast) = createAstNode(AST_COMMAND_BLOCK, 0, (yyvsp[-1].ast), 0, 0, 0); }
#line 1438 "y.tab.c"
    break;

  case 21: /* command: assign  */
#line 108 "parser.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1444 "y.tab.c"
    break;

  case 22: /* command: if  */
#line 109 "parser.y"
         { (yyval.ast) = (yyvsp[0].ast); }
#line 1450 "y.tab.c"
    break;

  case 23: /* command: ife  */
#line 110 "parser.y"
          { (yyval.ast)  = (yyvsp[0].ast); }
#line 1456 "y.tab.c"
    break;

  case 24: /* command: while  */
#line 111 "parser.y"
            { (yyval.ast) = (yyvsp[0].ast); }
#line 1462 "y.tab.c"
    break;

  case 25: /* command: read  */
#line 112 "parser.y"
           { (yyval.ast) = (yyvsp[0].ast); }
#line 1468 "y.tab.c"
    break;

  case 26: /* command: print  */
#line 113 "parser.y"
            { (yyval.ast) = (yyvsp[0].ast); }
#line 1474 "y.tab.c"
    break;

  case 27: /* command: return  */
#line 114 "parser.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1480 "y.tab.c"
    break;

  case 28: /* command: %empty  */
#line 115 "parser.y"
      { (yyval.ast) = 0; }
#line 1486 "y.tab.c"
    break;

  case 29: /* command_lst: command ';' command_lst  */
#line 118 "parser.y"
                                     { (yyval.ast) = createAstNode(AST_COMMAND_LIST, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1492 "y.tab.c"
    break;

  case 30: /* command_lst: command  */
#line 119 "parser.y"
              { (yyval.ast) = (yyvsp[0].ast); }
#line 1498 "y.tab.c"
    break;

  case 31: /* assign: TK_IDENTIFIER ASSIGNMENT expr  */
#line 122 "parser.y"
                                      { (yyval.ast) = createAstNode(AST_ASSIGN, 0, createAstNode(AST_IDENTIFIER, (yyvsp[-2].symbol), 0, 0, 0, 0), (yyvsp[0].ast), 0, 0); }
#line 1504 "y.tab.c"
    break;

  case 32: /* assign: TK_IDENTIFIER '[' expr ']' ASSIGNMENT expr  */
#line 123 "parser.y"
                                                 { (yyval.ast) = createAstNode(AST_ASSIGN_ARR, 0, createAstNode(AST_IDENTIFIER, (yyvsp[-5].symbol), 0, 0, 0, 0), (yyvsp[-3].ast), (yyvsp[0].ast), 0); }
#line 1510 "y.tab.c"
    break;

  case 33: /* expr: '(' expr ')'  */
#line 126 "parser.y"
                   { (yyval.ast) = createAstNode(AST_EXPR_PAR, 0, (yyvsp[-1].ast), 0, 0, 0); }
#line 1516 "y.tab.c"
    break;

  case 34: /* expr: TK_IDENTIFIER  */
#line 127 "parser.y"
                    { (yyval.ast) = createAstNode(AST_IDENTIFIER, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1522 "y.tab.c"
    break;

  case 35: /* expr: TK_IDENTIFIER '[' expr ']'  */
#line 128 "parser.y"
                                 { (yyval.ast) = createAstNode(AST_EXPR_ARR, 0, createAstNode(AST_IDENTIFIER, (yyvsp[-3].symbol), 0, 0, 0, 0), (yyvsp[-1].ast), 0, 0); }
#line 1528 "y.tab.c"
    break;

  case 36: /* expr: literal  */
#line 129 "parser.y"
              { (yyval.ast) = (yyvsp[0].ast); }
#line 1534 "y.tab.c"
    break;

  case 37: /* expr: expr '+' expr  */
#line 130 "parser.y"
                    { (yyval.ast) = createAstNode(AST_EXPR_SUM, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1540 "y.tab.c"
    break;

  case 38: /* expr: expr '-' expr  */
#line 131 "parser.y"
                    { (yyval.ast) = createAstNode(AST_EXPR_SUB, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1546 "y.tab.c"
    break;

  case 39: /* expr: expr '.' expr  */
#line 132 "parser.y"
                    { (yyval.ast) = createAstNode(AST_EXPR_MULT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1552 "y.tab.c"
    break;

  case 40: /* expr: expr '/' expr  */
#line 133 "parser.y"
                    { (yyval.ast) = createAstNode(AST_EXPR_DIV, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1558 "y.tab.c"
    break;

  case 41: /* expr: expr '<' expr  */
#line 134 "parser.y"
                    { (yyval.ast) = createAstNode(AST_EXPR_LT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1564 "y.tab.c"
    break;

  case 42: /* expr: expr '>' expr  */
#line 135 "parser.y"
                    { (yyval.ast) = createAstNode(AST_EXPR_GT, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1570 "y.tab.c"
    break;

  case 43: /* expr: expr OPERATOR_LE expr  */
#line 136 "parser.y"
                            { (yyval.ast) = createAstNode(AST_EXPR_LE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1576 "y.tab.c"
    break;

  case 44: /* expr: expr OPERATOR_GE expr  */
#line 137 "parser.y"
                            { (yyval.ast) = createAstNode(AST_EXPR_GE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1582 "y.tab.c"
    break;

  case 45: /* expr: expr OPERATOR_EQ expr  */
#line 138 "parser.y"
                            { (yyval.ast) = createAstNode(AST_EXPR_EQ, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1588 "y.tab.c"
    break;

  case 46: /* expr: expr OPERATOR_DIF expr  */
#line 139 "parser.y"
                             { (yyval.ast) = createAstNode(AST_EXPR_DIFF, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1594 "y.tab.c"
    break;

  case 47: /* expr: expr '&' expr  */
#line 140 "parser.y"
                    { (yyval.ast) = createAstNode(AST_EXPR_AND, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1600 "y.tab.c"
    break;

  case 48: /* expr: expr '|' expr  */
#line 141 "parser.y"
                    { (yyval.ast) = createAstNode(AST_EXPR_OR, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1606 "y.tab.c"
    break;

  case 49: /* expr: '~' expr  */
#line 142 "parser.y"
               { (yyval.ast) = createAstNode(AST_EXPR_NOT, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1612 "y.tab.c"
    break;

  case 50: /* expr: TK_IDENTIFIER '(' expr_lst ')'  */
#line 143 "parser.y"
                                     { (yyval.ast) = createAstNode(AST_EXPR_FUNC_CALL, 0, createAstNode(AST_IDENTIFIER, (yyvsp[-3].symbol), 0, 0, 0, 0), (yyvsp[-1].ast), 0, 0); }
#line 1618 "y.tab.c"
    break;

  case 51: /* expr_lst: expr expr_lst  */
#line 146 "parser.y"
                        { (yyval.ast) = createAstNode(AST_EXPR_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1624 "y.tab.c"
    break;

  case 52: /* expr_lst: %empty  */
#line 147 "parser.y"
      { (yyval.ast) = 0; }
#line 1630 "y.tab.c"
    break;

  case 53: /* if: KW_IF '(' expr ')' command  */
#line 150 "parser.y"
                               { (yyval.ast) = createAstNode(AST_IF, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1636 "y.tab.c"
    break;

  case 54: /* ife: KW_IF '(' expr ')' command KW_ELSE command  */
#line 153 "parser.y"
                                                { (yyval.ast) = createAstNode(AST_IFE, 0, (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast), 0); }
#line 1642 "y.tab.c"
    break;

  case 55: /* while: KW_WHILE '(' expr ')' command  */
#line 156 "parser.y"
                                     { (yyval.ast) = createAstNode(AST_WHILE, 0, (yyvsp[-2].ast), (yyvsp[0].ast), 0, 0); }
#line 1648 "y.tab.c"
    break;

  case 56: /* read: KW_READ TK_IDENTIFIER  */
#line 159 "parser.y"
                            { (yyval.ast) = createAstNode(AST_READ, 0, createAstNode(AST_IDENTIFIER, (yyvsp[0].symbol), 0, 0, 0, 0), 0, 0, 0); }
#line 1654 "y.tab.c"
    break;

  case 57: /* read: KW_READ TK_IDENTIFIER '[' expr ']'  */
#line 160 "parser.y"
                                         { (yyval.ast) = createAstNode(AST_READ_ARR, 0, createAstNode(AST_IDENTIFIER, (yyvsp[-3].symbol), 0, 0, 0, 0), (yyvsp[-1].ast), 0, 0); }
#line 1660 "y.tab.c"
    break;

  case 58: /* print: KW_PRINT print_lst  */
#line 163 "parser.y"
                          { (yyval.ast) = createAstNode(AST_PRINT, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1666 "y.tab.c"
    break;

  case 59: /* print_lst: print_expr print_lst  */
#line 166 "parser.y"
                                { (yyval.ast) = createAstNode(AST_PRINT_LIST, 0, (yyvsp[-1].ast), (yyvsp[0].ast), 0, 0); }
#line 1672 "y.tab.c"
    break;

  case 60: /* print_lst: %empty  */
#line 167 "parser.y"
      { (yyval.ast) = 0; }
#line 1678 "y.tab.c"
    break;

  case 61: /* print_expr: LIT_STRING  */
#line 170 "parser.y"
                       { (yyval.ast) = createAstNode(AST_STRING, (yyvsp[0].symbol), 0, 0, 0, 0); }
#line 1684 "y.tab.c"
    break;

  case 62: /* print_expr: expr  */
#line 171 "parser.y"
           { (yyval.ast) = (yyvsp[0].ast); }
#line 1690 "y.tab.c"
    break;

  case 63: /* return: KW_RETURN expr  */
#line 174 "parser.y"
                       { (yyval.ast) = createAstNode(AST_RETURN, 0, (yyvsp[0].ast), 0, 0, 0); }
#line 1696 "y.tab.c"
    break;


#line 1700 "y.tab.c"

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
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 177 "parser.y"


int yyerror(){
    fprintf(stderr, "Syntax error at line %d\n", getLineNumber());
    exit(3);
}
