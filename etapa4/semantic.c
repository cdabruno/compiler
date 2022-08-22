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
                    fprintf(stderr, "Semantic error, variable %s already declared.\n", ast->children[1]->hashReference->name);
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
                    fprintf(stderr, "Semantic error, variable %s already declared.\n", ast->children[1]->hashReference->name);
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
                for(int i = 0; i < MAX_SONS; i++){
                        setDeclaration(ast->children[i]);
                }
                break;
            case AST_FUNC_DEC:
                if(checkDeclared(ast->children[1]->hashReference->name)){
                    fprintf(stderr, "Semantic error, variable %s already declared.\n", ast->children[1]->hashReference->name);
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
                fprintf(stderr, "Semantic error, variable %s undeclared.\n", ast->hashReference->name);
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
                fprintf(stderr, "Semantic error, incompatible types for SUM operator.\n");
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
                fprintf(stderr, "Semantic error, incompatible types for SUB operator.\n");
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
                fprintf(stderr, "Semantic error, incompatible types for MULT operator.\n");
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
                fprintf(stderr, "Semantic error, incompatible types for DIV operator.\n");
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
                fprintf(stderr, "Semantic error, incompatible types for COMPARISON operator.\n");
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
                fprintf(stderr, "Semantic error, incompatible types for AND operator.\n");
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
                fprintf(stderr, "Semantic error, incompatible types for OR operator.\n");
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
                fprintf(stderr, "Semantic error, incompatible types for NOT operator.\n");
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
    if((isIntValue(expA) && isIntValue(expB)) || (expA == expB) ){
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
                    printf("Semantic error, incorrect use of identifier %s.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_EXPR_FUNC_CALL:
                if(ast->children[0]->hashReference->type != SYMBOL_FUNC){
                    printf("Semantic error, incorrect use of identifier %s.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_EXPR_IDENTIFIER:
                if(ast->children[0]->hashReference->type != SYMBOL_VAR){
                    printf("Semantic error, incorrect use of identifier %s.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_ASSIGN:
                if(ast->children[0]->hashReference->type != SYMBOL_VAR){
                    printf("Semantic error, incorrect use of identifier %s.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_ASSIGN_ARR:
                if(ast->children[0]->hashReference->type != SYMBOL_ARR){
                    printf("Semantic error, incorrect use of identifier %s.\n", ast->children[0]->hashReference->name);
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
                if(!compatibleTypes(getExpressionDatatype(ast->children[0]), getExpressionDatatype(ast->children[1]))){
                    printf("Semantic error, incompatible types for assignment of variable %s.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_ASSIGN_ARR:
                if(!compatibleTypes(getExpressionDatatype(ast->children[0]), getExpressionDatatype(ast->children[1]))){
                    printf("Semantic error, incompatible types for assignment of variable %s.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                if(!isIntValue(getExpressionDatatype(ast->children[1]))){
                    printf("Semantic error, array index must be an integer value.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_IF:
                if(getExpressionDatatype(ast->children[0]) != DATATYPE_BOOL){
                    printf("Semantic error, IF expects boolean.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_IFE:
                if(getExpressionDatatype(ast->children[0]) != DATATYPE_BOOL){
                    printf("Semantic error, IF expects boolean.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_WHILE:
                if(getExpressionDatatype(ast->children[0]) != DATATYPE_BOOL){
                    printf("Semantic error, while expects boolean.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_READ:
                if(ast->children[0]->hashReference->type != SYMBOL_VAR){
                    printf("Semantic error, incorrect use of identifier.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
            case AST_READ_ARR:
                if(ast->children[0]->hashReference->type != SYMBOL_ARR){
                    printf("Semantic error, incorrect use of identifier.\n", ast->children[0]->hashReference->name);
                    semanticErrors++;
                }
                break;
        }
    }
}

