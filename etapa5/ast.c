/* Made by Bruno Correa and Alexadre Crestani */

#include "ast.h"
#include "semantic.h"

Ast *createAstNode(int type, Hash *hashReference, Ast *child1, Ast *child2, Ast *child3, Ast *child4, int line){
    Ast *newNode = (Ast *) calloc(1, sizeof(Ast));
    newNode->type = type;
    newNode->hashReference = hashReference;
    newNode->children[0] = child1;
    newNode->children[1] = child2;
    newNode->children[2] = child3;
    newNode->children[3] = child4;
    newNode->line = line;

    return newNode;
}

void printAst(Ast *node, int level){
    if(node != NULL){
        for(int i = 0; i < level; i++){
            printf("  ");
        }
        
        switch(node->type){
            case AST_IDENTIFIER: printf("AST_IDENTIFIER"); break;
            case AST_INT: printf("AST_INT"); break;
            case AST_FLOAT: printf("AST_FLOAT"); break;
            case AST_CHAR: printf("AST_CHAR"); break;
            case AST_STRING: printf("AST_STRING"); break;
            case AST_DECL: printf("AST_DECL"); break;
            case AST_FUNC_DEC: printf("AST_FUNC_DEC"); break;
            case AST_VAR_DEC: printf("AST_VAR_DEC"); break;
            case AST_ARR_DEC: printf("AST_ARR_DEC"); break;
            case AST_KW_INT: printf("AST_KW_INT"); break;
            case AST_KW_FLOAT: printf("AST_KW_FLOAT"); break;
            case AST_KW_CHAR: printf("AST_KW_CHAR"); break;
            case AST_LIT_LIST: printf("AST_LIT_LIST"); break;
            case AST_PARAM_LIST: printf("AST_PARAM_LIST"); break;
            case AST_PARAM: printf("AST_PARAM"); break;
            case AST_COMMAND_BLOCK: printf("AST_COMMAND_BLOCK"); break;
            case AST_COMMAND_LIST: printf("AST_COMMAND_LIST"); break;
            case AST_ASSIGN: printf("AST_ASSIGN"); break;
            case AST_ASSIGN_ARR: printf("AST_ASSIGN_ARR"); break;
            case AST_EXPR_PAR: printf("AST_EXPR_PAR"); break;
            case AST_EXPR_LIST: printf("AST_EXPR_LIST"); break;
            case AST_EXPR_ARR: printf("AST_EXPR_ARR"); break;
            case AST_EXPR_SUM: printf("AST_EXPR_SUM"); break;
            case AST_EXPR_SUB: printf("AST_EXPR_SUB"); break;
            case AST_EXPR_MULT: printf("AST_EXPR_MULT"); break;
            case AST_EXPR_DIV: printf("AST_EXPR_DIV"); break;
            case AST_EXPR_LT: printf("AST_EXPR_LT"); break;
            case AST_EXPR_GT: printf("AST_EXPR_GT"); break;
            case AST_EXPR_LE: printf("AST_EXPR_LE"); break;
            case AST_EXPR_GE: printf("AST_EXPR_GE"); break;
            case AST_EXPR_EQ: printf("AST_EXPR_EQ"); break;
            case AST_EXPR_DIFF: printf("AST_EXPR_DIFF"); break;
            case AST_EXPR_AND: printf("AST_EXPR_AND"); break;
            case AST_EXPR_OR: printf("AST_EXPR_OR"); break;
            case AST_EXPR_NOT: printf("AST_EXPR_NOT"); break;
            case AST_EXPR_FUNC_CALL: printf("AST_EXPR_FUNC_CALL"); break;
            case AST_IF: printf("AST_IF"); break;
            case AST_IFE: printf("AST_IFE"); break;
            case AST_WHILE: printf("AST_WHILE"); break;
            case AST_READ: printf("AST_READ"); break;
            case AST_READ_ARR: printf("AST_READ_ARR"); break;
            case AST_PRINT: printf("AST_PRINT"); break;
            case AST_PRINT_LIST: printf("AST_PRINT_LIST"); break;
            case AST_RETURN: printf("AST_RETURN"); break;
            case AST_EXPR_IDENTIFIER: printf("AST_EXPR_IDENTIFIER"); break;
        }

        if(node->hashReference != NULL){
            printf(" %s", node->hashReference->name);
            printf(" %d", node->hashReference->type);
        }

        printf(" %d", getExpressionDatatype(node));
        

        printf("\n");
        

        for(int i = 0; i < MAX_SONS; i++){
            printAst(node->children[i], level + 1);
        }
    }
}
