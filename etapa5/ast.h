/* Made by Bruno Correa and Alexadre Crestani */

#ifndef AST_H
#define AST_H

#define MAX_SONS 4

#define AST_IDENTIFIER 1
#define AST_INT 2
#define AST_FLOAT 3
#define AST_CHAR 4
#define AST_STRING 5
#define AST_DECL 6
#define AST_FUNC_DEC 7
#define AST_VAR_DEC 8
#define AST_ARR_DEC 9
#define AST_KW_INT 10
#define AST_KW_FLOAT 11
#define AST_KW_CHAR 12
#define AST_LIT_LIST 13
#define AST_PARAM_LIST 14
#define AST_PARAM 15
#define AST_COMMAND_BLOCK 16
#define AST_COMMAND_LIST 17
#define AST_ASSIGN 18
#define AST_ASSIGN_ARR 19
#define AST_EXPR_PAR 20
#define AST_EXPR_LIST 21
#define AST_EXPR_ARR 22
#define AST_EXPR_SUM 23
#define AST_EXPR_SUB 24
#define AST_EXPR_MULT 25
#define AST_EXPR_DIV 26
#define AST_EXPR_LT 27
#define AST_EXPR_GT 28
#define AST_EXPR_LE 29
#define AST_EXPR_GE 30
#define AST_EXPR_EQ 31
#define AST_EXPR_DIFF 32
#define AST_EXPR_AND 33
#define AST_EXPR_OR 34
#define AST_EXPR_NOT 35
#define AST_EXPR_FUNC_CALL 36
#define AST_IF 37
#define AST_IFE 38
#define AST_WHILE 39
#define AST_READ 40
#define AST_READ_ARR 41
#define AST_PRINT 42
#define AST_PRINT_LIST 43
#define AST_RETURN 44
#define AST_EXPR_IDENTIFIER 45


#include "hash.h"

typedef struct AST_STRUCT {
    int type;
    Hash *hashReference;
    int line;
    struct AST_STRUCT *children[MAX_SONS];
} Ast;

Ast *createAstNode(int type, Hash *hashReference, Ast *child1, Ast *child2, Ast *child3, Ast *child4, int line);

void printAst(Ast *node, int level);

#endif