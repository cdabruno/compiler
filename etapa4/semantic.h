#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"

void setDeclaration(Ast *ast);
int checkDeclared(char* symbolName);
void verifyDeclaration(Ast *ast);
int getExpressionDatatype(Ast *ast);
int isIntValue(int type);
int compatibleExpressionsNum(int expA, int expB);
int compatibleTypes(int expA, int expB);
void checkAssignments(Ast *ast);
void checkIdentifierUsage();

#endif