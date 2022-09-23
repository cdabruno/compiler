/* Made by Bruno Correa and Alexadre Crestani */

#ifndef TAC_H
#define TAC_H

#include "hash.h"
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

#define TAC_SYMBOL 1
#define TAC_SUM 2
#define TAC_SUB 3
#define TAC_MULT 4
#define TAC_DIV 5
#define TAC_LE 6
#define TAC_GE 7
#define TAC_EQ 8
#define TAC_DIFF 9
#define TAC_COPY 10
#define TAC_JUMP_FALSE 11
#define TAC_LABEL 12
#define TAC_JUMP 13
#define TAC_GT 14
#define TAC_LT 15
#define TAC_AND 16
#define TAC_OR 17
#define TAC_NOT 18
#define TAC_COPY_ARR 19
#define TAC_FUNC_CALL 20
#define TAC_FUNC_PARAMS 21
#define TAC_READ 22
#define TAC_PRINT_LIST 23
#define TAC_EXPR_ARR 24
#define TAC_RETURN 25
#define TAC_FUNC_BEGIN 26
#define TAC_FUNC_END 27
#define TAC_READ_ARR 28

typedef struct TAC_STRUCT {
    int type;
    Hash* result;
    Hash* op1;
    Hash* op2;
    struct TAC_STRUCT* prev;
    struct TAC_STRUCT* next;
} Tac;


Tac *tacCreate(int type, Hash *result, Hash *op1, Hash *op2);
void tacPrint(Tac* tac);
Tac *tacJoin(Tac *l1, Tac *l2);
void tacPrintBackwards(Tac* tac);
Tac *generateCode(Ast *node);

#endif