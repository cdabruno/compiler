#include "hash.h"
#include "ast.h"
#include "lex.yy.h"
#include "semantic.h"
#include "y.tab.h"

extern int getLineNumber(void);

int semanticErrors = 0;

void setDeclaration(Ast *ast){
    if(ast != NULL){
        switch(ast->type){
            case AST_VAR_DEC:
                if(checkDeclared(ast->children[1]->hashReference->name)){
                    fprintf(stderr, "Semantic error at line %d, variable %s already declared.\n", ast->line, ast->children[1]->hashReference->name);
                    semanticErrors++;
                }
                else{
                    ast->children[1]->hashReference->type = SYMBOL_VAR;
                    if(ast->children[0]->type == AST_KW_CHAR){
                        ast->children[1]->hashReference->datatype = DATATYPE_CHAR;
                    }
                    else if(ast->children[0]->type == AST_KW_INT){
                        ast->children[1]->hashReference->datatype = DATATYPE_INT;
                    }
                    else if(ast->children[0]->type == AST_KW_FLOAT){
                        ast->children[1]->hashReference->datatype = DATATYPE_FLOAT;
                    }
                }
                for(int i = 0; i < MAX_SONS; i++){
                        setDeclaration(ast->children[i]);
                }
                break;
            case AST_ARR_DEC:
                if(checkDeclared(ast->children[1]->hashReference->name)){
                    fprintf(stderr, "Semantic error at line %d, variable %s already declared.\n", ast->line, ast->children[1]->hashReference->name);
                    semanticErrors++;
                }
                else{
                    ast->children[1]->hashReference->type = SYMBOL_ARR;
                    if(ast->children[0]->type == AST_KW_CHAR){
                        ast->children[1]->hashReference->datatype = DATATYPE_CHAR;
                    }
                    else if(ast->children[0]->type == AST_KW_INT){
                        ast->children[1]->hashReference->datatype = DATATYPE_INT;
                    }
                    else if(ast->children[0]->type == AST_KW_FLOAT){
                        ast->children[1]->hashReference->datatype = DATATYPE_FLOAT;
                    }
                }
                int arr_type = ast->children[1]->hashReference->datatype;
                if(ast->children[3] != NULL){
                    switch (checkCorrectArrDeclaration(arr_type, atoi(ast->children[2]->hashReference->name), 0, ast->children[3])){
                        case TOO_MANY_ARGS:
                            printf("Semantic error at line %d, too many values for array %s size.\n", ast->line, ast->children[1]->hashReference->name);
                            semanticErrors++;
                            break;
                        case MISSING_ARGS:
                            printf("Semantic error at line %d, missing values for array %s size.\n", ast->line, ast->children[1]->hashReference->name);
                            semanticErrors++;
                            break;
                        case INCORRECT_TYPE_ASSGN:
                            printf("Semantic error at line %d, incorrect value type for array %s.\n", ast->line, ast->children[1]->hashReference->name);
                            semanticErrors++;
                            break;
                        default:
                            break;
                    }
                }
                for(int i = 0; i < MAX_SONS; i++){
                        setDeclaration(ast->children[i]);
                }
                break;
            case AST_FUNC_DEC:
                if(checkDeclared(ast->children[1]->hashReference->name)){
                    fprintf(stderr, "Semantic error at line %d, variable %s already declared.\n", ast->children[0]->line, ast->children[1]->hashReference->name);
                    semanticErrors++;
                }
                else{
                    ast->children[1]->hashReference->type = SYMBOL_FUNC;
                    if(ast->children[0]->type == AST_KW_CHAR){
                        ast->children[1]->hashReference->datatype = DATATYPE_CHAR;
                    }
                    else if(ast->children[0]->type == AST_KW_INT){
                        ast->children[1]->hashReference->datatype = DATATYPE_INT;
                    }
                    else if(ast->children[0]->type == AST_KW_FLOAT){
                        ast->children[1]->hashReference->datatype = DATATYPE_FLOAT;
                    }
                }
                for(int i = 0; i < MAX_SONS; i++){
                        setDeclaration(ast->children[i]);
                }
                break;
                case AST_PARAM:
                if(checkDeclared(ast->children[1]->hashReference->name)){
                    fprintf(stderr, "Semantic error at line %d, variable %s already declared.\n", ast->line, ast->children[1]->hashReference->name);
                    semanticErrors++;
                }
                else{
                    ast->children[1]->hashReference->type = SYMBOL_VAR;
                    if(ast->children[0]->type == AST_KW_CHAR){
                        ast->children[1]->hashReference->datatype = DATATYPE_CHAR;
                    }
                    else if(ast->children[0]->type == AST_KW_INT){
                        ast->children[1]->hashReference->datatype = DATATYPE_INT;
                    }
                    else if(ast->children[0]->type == AST_KW_FLOAT){
                        ast->children[1]->hashReference->datatype = DATATYPE_FLOAT;
                    }
                }
                for(int i = 0; i < MAX_SONS; i++){
                        setDeclaration(ast->children[i]);
                }
                break;
            default:
                for(int i = 0; i < MAX_SONS; i++){
                    setDeclaration(ast->children[i]);
                }
        }
    }
}

int checkDeclared(char* symbolName){
    Hash *temp = hashFind(symbolName);
    if(temp->type == TK_IDENTIFIER){
        return 0;
    }
    else{
        return 1;
    }
}

void verifyDeclaration(Ast *ast){
    if(ast != NULL){
        if(ast->hashReference != NULL){
            if(ast->hashReference->type == TK_IDENTIFIER){
                fprintf(stderr, "Semantic error at line %d, variable %s undeclared.\n", ast->line, ast->hashReference->name);
                semanticErrors++;
            }
        }
        for(int i = 0; i < MAX_SONS; i++){
            verifyDeclaration(ast->children[i]);
        }
    }
}

int getExpressionDatatype(Ast *ast){

    int typeA;
    int typeB;

    switch(ast->type){
        case AST_IDENTIFIER:
            return ast->hashReference->datatype;
        case AST_EXPR_PAR:
            return getExpressionDatatype(ast->children[0]);
            break;
        case AST_EXPR_IDENTIFIER:
            return getExpressionDatatype(ast->children[0]);
            break;
        case AST_EXPR_ARR:
            return getExpressionDatatype(ast->children[0]);
            break;
        case AST_CHAR:
            return DATATYPE_CHAR;
            break;
        case AST_FLOAT:
            return DATATYPE_FLOAT;
            break;
        case AST_INT:
            return DATATYPE_INT;
            break;
        case AST_STRING:
            return DATATYPE_STRING;
            break;
        case AST_EXPR_SUM:
            typeA = getExpressionDatatype(ast->children[0]);
            typeB = getExpressionDatatype(ast->children[1]);
            if(compatibleExpressionsNum(typeA, typeB)){
                return typeA;
            }
            else if (typeA != 0 && typeB != 0){
                fprintf(stderr, "Semantic error at line %d, incompatible types for SUM operator.\n", ast->line);
                semanticErrors++;
            }
            return 0;
            break;
        case AST_EXPR_SUB:
            typeA = getExpressionDatatype(ast->children[0]);
            typeB = getExpressionDatatype(ast->children[1]);
            if(compatibleExpressionsNum(typeA, typeB)){
                return typeA;
            }
            else if (typeA != 0 && typeB != 0){
                fprintf(stderr, "Semantic error at line %d, incompatible types for SUB operator.\n", ast->line);
                semanticErrors++;
            }
            return 0;
            break;
        case AST_EXPR_MULT:
            typeA = getExpressionDatatype(ast->children[0]);
            typeB = getExpressionDatatype(ast->children[1]);
            if(compatibleExpressionsNum(typeA, typeB)){
                return typeA;
            }
            else if (typeA != 0 && typeB != 0){
                fprintf(stderr, "Semantic error at line %d, incompatible types for MULT operator.\n", ast->line);
                semanticErrors++;
            }
            return 0;
            break;
        case AST_EXPR_DIV:
            typeA = getExpressionDatatype(ast->children[0]);
            typeB = getExpressionDatatype(ast->children[1]);
            if(compatibleExpressionsNum(typeA, typeB)){
                return typeA;
            }
            else if (typeA != 0 && typeB != 0){
                fprintf(stderr, "Semantic error at line %d, incompatible types for DIV operator.\n", ast->line);
                semanticErrors++;
            }
            return 0;
            break;
        case AST_EXPR_LT:
        case AST_EXPR_GT:
        case AST_EXPR_LE:
        case AST_EXPR_GE:
        case AST_EXPR_EQ:
        case AST_EXPR_DIFF:
            typeA = getExpressionDatatype(ast->children[0]);
            typeB = getExpressionDatatype(ast->children[1]);
            if(compatibleExpressionsNum(typeA, typeB)){
                return DATATYPE_BOOL;
            }
            else if (typeA != 0 && typeB != 0){
                fprintf(stderr, "Semantic error at line %d, incompatible types for COMPARISON operator.\n", ast->line);
                semanticErrors++;
            }
            return 0;
            break;
        case AST_EXPR_AND:
            typeA = getExpressionDatatype(ast->children[0]);
            typeB = getExpressionDatatype(ast->children[1]);
            if(typeA == DATATYPE_BOOL && typeB == DATATYPE_BOOL){
                return DATATYPE_BOOL;
            }
            else if (typeA != 0 && typeB != 0){
                fprintf(stderr, "Semantic error at line %d, incompatible types for AND operator.\n", ast->line);
                semanticErrors++;
            }
            return 0;
            break;
        case AST_EXPR_OR:
            typeA = getExpressionDatatype(ast->children[0]);
            typeB = getExpressionDatatype(ast->children[1]);
            if(typeA == DATATYPE_BOOL && typeB == DATATYPE_BOOL){
                return DATATYPE_BOOL;
            }
            else if (typeA != 0 && typeB != 0){
                fprintf(stderr, "Semantic error at line %d, incompatible types for OR operator.\n", ast->line);
                semanticErrors++;
            }
            return 0;
            break;
        case AST_EXPR_NOT:
            typeA = getExpressionDatatype(ast->children[0]);
            if(typeA == DATATYPE_BOOL){
                return DATATYPE_BOOL;
            }
            else if(typeA != 0){
                fprintf(stderr, "Semantic error at line %d, incompatible types for NOT operator.\n", ast->line);
                semanticErrors++;
            }
            return 0;
            break;
        case AST_EXPR_FUNC_CALL:
            return getExpressionDatatype(ast->children[0]);
        default: 
            return -1;
    }
}

int isIntValue(int type){
    if(type == DATATYPE_INT || type == DATATYPE_CHAR){
        return 1;
    }
    else{
        return 0;
    }
}

int compatibleExpressionsNum(int expA, int expB){
    if((isIntValue(expA) && isIntValue(expB)) || (expA == DATATYPE_FLOAT && expB == DATATYPE_FLOAT)){
        return 1;
    }
    else{
        return 0;
    }
}

int compatibleTypes(int expA, int expB){
    if((isIntValue(expA) && isIntValue(expB)) || (expA == expB && expA != DATATYPE_STRING) ){
        return 1;
    }
    else{
        return 0;
    }
}

void checkIdentifierUsage(Ast *ast){
    if(ast != NULL){
        switch(ast->type){
            case AST_EXPR_ARR:
                if(ast->children[0]->hashReference->type != SYMBOL_ARR){
                    printf("Semantic error at line %d, incorrect use of identifier %s.\n", ast->line, ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_EXPR_FUNC_CALL:
                if(ast->children[0]->hashReference->type != SYMBOL_FUNC){
                    printf("Semantic error at line %d, incorrect use of identifier %s.\n", ast->line, ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_EXPR_IDENTIFIER:
                if(ast->children[0]->hashReference->type != SYMBOL_VAR){
                    printf("Semantic error at line %d, incorrect use of identifier %s.\n", ast->line, ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_ASSIGN:
                if(ast->children[0]->hashReference->type != SYMBOL_VAR){
                    printf("Semantic error at line %d, incorrect use of identifier %s.\n", ast->line, ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_ASSIGN_ARR:
                if(ast->children[0]->hashReference->type != SYMBOL_ARR){
                    printf("Semantic error at line %d, incorrect use of identifier %s.\n", ast->line, ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
        }
        for(int i = 0; i < MAX_SONS; i++){
            checkIdentifierUsage(ast->children[i]);
        }
    }
}

void checkCommandTypesMatch(Ast *ast){
    if(ast != NULL){
        switch(ast->type){
            case AST_ASSIGN:
                //printf("%s, %d, %d\n", ast->children[0]->hashReference->name, getExpressionDatatype(ast->children[0]), getExpressionDatatype(ast->children[1]));
                if(!compatibleTypes(getExpressionDatatype(ast->children[0]), getExpressionDatatype(ast->children[1]))){
                    printf("Semantic error at line %d, incompatible types for assignment of variable %s.\n", ast->line, ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_ASSIGN_ARR:
                if(!compatibleTypes(getExpressionDatatype(ast->children[0]), getExpressionDatatype(ast->children[1]))){
                    printf("Semantic error at line %d, incompatible types for assignment of variable %s.\n", ast->line, ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                if(!isIntValue(getExpressionDatatype(ast->children[1]))){
                    printf("Semantic error at line %d, array index must be an integer value.\n", ast->line);
                    semanticErrors++;
                }
                break;
            case AST_IF:
                if(getExpressionDatatype(ast->children[0]) != DATATYPE_BOOL){
                    printf("Semantic error at line %d, IF expects boolean.\n", ast->children[0]->line);
                    semanticErrors++;
                }
                break;
            case AST_IFE:
                if(getExpressionDatatype(ast->children[0]) != DATATYPE_BOOL){
                    printf("Semantic error at line %d, IF expects boolean.\n", ast->children[0]->line);
                    semanticErrors++;
                }
                break;
            case AST_WHILE:
                if(getExpressionDatatype(ast->children[0]) != DATATYPE_BOOL){
                    printf("Semantic error at line %d, while expects boolean.\n", ast->children[0]->line);
                    semanticErrors++;
                }
                break;
            case AST_READ:
                if(ast->children[0]->hashReference->type != SYMBOL_VAR){
                    printf("Semantic error at line %d, incorrect use of identifier %s.\n", ast->line, ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_READ_ARR:
                if(ast->children[0]->hashReference->type != SYMBOL_ARR){
                    printf("Semantic error at line %d, incorrect use of identifier %s.\n", ast->line, ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
        }
        for(int i = 0; i < MAX_SONS; i++){
            checkCommandTypesMatch(ast->children[i]);
        }
    }
}

int checkCorrectArrDeclaration(int datatype, int size, int countingSize, Ast *literalLst){
    if(literalLst == NULL){
        if(size < countingSize){
            return TOO_MANY_ARGS;
        }
        else if(size > countingSize){
            return MISSING_ARGS;
        }
        else{
            return ARR_DECLR_OK;
        }
    }
    else{
        if(compatibleTypes(getExpressionDatatype(literalLst->children[0]), datatype)){
            countingSize++;
            return checkCorrectArrDeclaration(datatype, size, countingSize, literalLst->children[1]);
        }
        else{
            return INCORRECT_TYPE_ASSGN;
        }
    }
}

void checkUseOfFunctions(Ast *consumedAst, Ast *fullAst){

    if(consumedAst != NULL){
        if(consumedAst->type == AST_EXPR_FUNC_CALL){
            Ast *functionDeclaration = findFunctionDeclaration(consumedAst->children[0]->hashReference->name, fullAst);           
            if(functionDeclaration != NULL){
                switch(isCorrectUseOfFunction(functionDeclaration->children[2], consumedAst->children[1])){
                    case TOO_MANY_ARGS:
                        printf("Semantic error at line %d, too many arguments for function %s.\n", consumedAst->children[0]->line, consumedAst->children[0]->hashReference->name);
                        semanticErrors++;
                        break;
                    case MISSING_ARGS:
                        printf("Semantic error at line %d, missing arguments for function %s.\n", consumedAst->children[0]->line, consumedAst->children[0]->hashReference->name);
                        semanticErrors++;
                        break;
                    case INCORRECT_TYPE_ARGUMENT:
                        printf("Semantic error at line %d, incorrect type arguments for function %s.\n", consumedAst->children[0]->line, consumedAst->children[0]->hashReference->name);
                        semanticErrors++;
                        break;
                }
            }
        }
        for(int i = 0; i < MAX_SONS; i++){
            checkUseOfFunctions(consumedAst->children[i], fullAst);
        }
    }
}

Ast* findFunctionDeclaration(char* functionName, Ast *ast){
    if(ast != NULL){
        if(ast->children[0]->type == AST_FUNC_DEC){
            if(strcmp(ast->children[0]->children[1]->hashReference->name, functionName) == 0){
                return ast->children[0];
            }
            else{
                return findFunctionDeclaration(functionName, ast->children[1]);
            }
        }
        else{
            return findFunctionDeclaration(functionName, ast->children[1]);
        }
    }
    else{
        return NULL;
    }
}

int isCorrectUseOfFunction(Ast *parameterList, Ast *argumentList){
    if(parameterList == NULL && argumentList == NULL){
        return FUNC_CALL_OK;
    }
    else if(parameterList == NULL && argumentList != NULL){
         return TOO_MANY_ARGS;
    }
    else if(parameterList != NULL && argumentList == NULL){
         return MISSING_ARGS;
    }
    else if(compatibleTypes(castKWtoDatatype(parameterList->children[0]->children[0]->type), getExpressionDatatype(argumentList->children[0]))){
        return isCorrectUseOfFunction(parameterList->children[1], argumentList->children[1]);
    }
    else{
        printf("%d, %d\n", parameterList->children[0]->children[0]->type, getExpressionDatatype(argumentList->children[0]));
        return INCORRECT_TYPE_ARGUMENT;
    }
}

int castKWtoDatatype(int keyword){
    switch(keyword){
        case AST_KW_CHAR:
            return DATATYPE_CHAR;
            break;
        case AST_KW_INT:
            return DATATYPE_INT;
            break;
        case AST_KW_FLOAT:
            return DATATYPE_FLOAT;
            break;
    }
}

void checkReturnType(Ast *ast){
    if(ast != NULL){
        if(ast->type == AST_FUNC_DEC){
            int datatype = castKWtoDatatype(ast->children[0]->type);
            checkFunctionReturns(ast->children[3], datatype);
        }
        for(int i = 0; i < MAX_SONS; i++){
            checkReturnType(ast->children[i]);
        }
    }
}

void checkFunctionReturns(Ast *commandList, int datatype){
    if(commandList != NULL){
        if(commandList->type == AST_RETURN){
            if(!compatibleTypes(getExpressionDatatype(commandList->children[0]), datatype)){
                printf("Semantic error at line %d, return type does not match function type declared.\n", commandList->children[0]->line);
                semanticErrors++;
            }
        }
        for(int i = 0; i < MAX_SONS; i++){
            checkFunctionReturns(commandList->children[i], datatype);
        }
    }
}

void semanticAnalysis(Ast *ast){
    setDeclaration(ast);
    verifyDeclaration(ast);
    checkIdentifierUsage(ast);
    checkCommandTypesMatch(ast);
    checkUseOfFunctions(ast, ast);
    checkReturnType(ast);
}

