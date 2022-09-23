#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "ast.h"

#define MISSING_ARGS 1
#define TOO_MANY_ARGS 2
#define INCORRECT_TYPE_ASSGN 3
#define ARR_DECLR_OK 4
#define INCORRECT_TYPE_ARGUMENT 5
#define FUNC_CALL_OK 6

void setDeclaration(Ast *ast);
int checkDeclared(char* symbolName);
void verifyDeclaration(Ast *ast);
int getExpressionDatatype(Ast *ast);
int isIntValue(int type);
int compatibleExpressionsNum(int expA, int expB);
int compatibleTypes(int expA, int expB);
void checkCommandTypesMatch(Ast *ast);
void checkIdentifierUsage();
int checkCorrectArrDeclaration(int datatype, int size, int countingSize, Ast *literalLst);
void checkUseOfFunctions(Ast *consumedAst, Ast *fullAst);
Ast* findFunctionDeclaration(char* functionName, Ast *ast);
int isCorrectUseOfFunction(Ast *parameterList, Ast *argumentList);
int castKWtoDatatype(int keyword);
void checkReturnType(Ast *ast);
void checkFunctionReturns(Ast *commandList, int datatype);

void semanticAnalysis(Ast *ast);

#endif