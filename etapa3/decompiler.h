/* Made by Bruno Correa and Alexadre Crestani */


#ifndef DECOMPILER_H
#define DECOMPILER_H

#include <stdio.h>
#include "ast.h"

void decompile(Ast *ast, FILE *file);
void decompile_AST_IDENTIFIER(Ast *ast, FILE *file);
void decompile_AST_INT(Ast *ast, FILE *file);
void decompile_AST_FLOAT(Ast *ast, FILE *file);
void decompile_AST_CHAR(Ast *ast, FILE *file);
void decompile_AST_STRING(Ast *ast, FILE *file);
void decompile_AST_DECL(Ast *ast, FILE *file);
void decompile_AST_FUNC_DEC(Ast *ast, FILE *file);
void decompile_AST_VAR_DEC(Ast *ast, FILE *file);
void decompile_AST_ARR_DEC(Ast *ast, FILE *file);
void decompile_AST_KW_INT(Ast *ast, FILE *file);
void decompile_AST_KW_FLOAT(Ast *ast, FILE *file);
void decompile_AST_KW_CHAR(Ast *ast, FILE *file);
void decompile_AST_LIT_LIST(Ast *ast, FILE *file);
void decompile_AST_PARAM_LIST(Ast *ast, FILE *file);
void decompile_AST_PARAM(Ast *ast, FILE *file);
void decompile_AST_COMMAND_BLOCK(Ast *ast, FILE *file);
void decompile_AST_COMMAND_LIST(Ast *ast, FILE *file);
void decompile_AST_ASSIGN(Ast *ast, FILE *file);
void decompile_AST_ASSIGN_ARR(Ast *ast, FILE *file);
void decompile_AST_EXPR_PAR(Ast *ast, FILE *file);
void decompile_AST_EXPR_LIST(Ast *ast, FILE *file);
void decompile_AST_EXPR_ARR(Ast *ast, FILE *file);
void decompile_AST_EXPR_SUM(Ast *ast, FILE *file);
void decompile_AST_EXPR_SUB(Ast *ast, FILE *file);
void decompile_AST_EXPR_MULT(Ast *ast, FILE *file);
void decompile_AST_EXPR_DIV(Ast *ast, FILE *file);
void decompile_AST_EXPR_LT(Ast *ast, FILE *file);
void decompile_AST_EXPR_GT(Ast *ast, FILE *file);
void decompile_AST_EXPR_LE(Ast *ast, FILE *file);
void decompile_AST_EXPR_GE(Ast *ast, FILE *file);
void decompile_AST_EXPR_EQ(Ast *ast, FILE *file);
void decompile_AST_EXPR_DIFF(Ast *ast, FILE *file);
void decompile_AST_EXPR_AND(Ast *ast, FILE *file);
void decompile_AST_EXPR_OR(Ast *ast, FILE *file);
void decompile_AST_EXPR_NOT(Ast *ast, FILE *file);
void decompile_AST_EXPR_FUNC_CALL(Ast *ast, FILE *file);
void decompile_AST_IF(Ast *ast, FILE *file);
void decompile_AST_IFE(Ast *ast, FILE *file);
void decompile_AST_WHILE(Ast *ast, FILE *file);
void decompile_AST_READ(Ast *ast, FILE *file);
void decompile_AST_READ_ARR(Ast *ast, FILE *file);
void decompile_AST_PRINT(Ast *ast, FILE *file);
void decompile_AST_PRINT_LIST(Ast *ast, FILE *file);
void decompile_AST_RETURN(Ast *ast, FILE *file);

#endif