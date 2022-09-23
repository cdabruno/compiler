/* Made by Bruno Correa and Alexadre Crestani */

#include "tac.h"

static char lastParameter[200] = "";

Tac* tacCreate(int type, Hash *result, Hash *op1, Hash *op2) {
    Tac *newTac = 0;
    newTac = (Tac*) calloc(1, sizeof(Tac));
    newTac->type = type;
    newTac->result = result;
    newTac->op1 = op1;
    newTac->op2 = op2;
    newTac->prev = 0;
    newTac->next = 0;
    return newTac;
  
}

Tac* tacCreateBinOp(int tac, Tac *code0, Tac *code1) {
  Tac *result = 0;
  result = tacCreate(tac, makeTemp(), code0 ? code0->result : 0, code1 ? code1->result : 0);
  return tacJoin(tacJoin(code0, code1), result);
}

Tac* tacCreateIf(Tac *code0, Tac *code1)
{
    Tac *jumpTac = 0;
    Tac *labelTac = 0;
    Hash *newLabel = 0;
    newLabel = makeLabel();

    jumpTac = tacCreate(TAC_JUMP_FALSE, newLabel, code0 ? code0->result: 0, 0);
    jumpTac->prev = code0;

    labelTac = tacCreate(TAC_LABEL, newLabel, 0, 0);
    labelTac->prev = code1;

    return tacJoin(jumpTac, labelTac);
}

Tac* tacCreateIfElse(Tac* code0, Tac* code1, Tac* code2)
{
    Tac *jumpFalseTac = 0;
    Tac *jumpTac = 0;
    Tac *label1 = 0;
    Tac *label2 = 0;

    Hash *hashLabel1 = 0;
    hashLabel1 = makeLabel();
    Hash *hashLabel2 = 0;
    hashLabel2 = makeLabel();
    
    jumpFalseTac = tacCreate(TAC_JUMP_FALSE, hashLabel1, code0 ? code0->result: 0, 0);
    jumpFalseTac->prev = code0;

    jumpTac = tacCreate(TAC_JUMP, hashLabel2, 0, 0);
    jumpTac->prev = code1;

    label1 = tacCreate(TAC_LABEL, hashLabel1, 0, 0);
    
    label2 = tacCreate(TAC_LABEL, hashLabel2, 0, 0);

    return tacJoin(jumpFalseTac, tacJoin(jumpTac, tacJoin(label1 , tacJoin(code2, label2))));
}

Tac* tacCreateWhile(Tac* code0, Tac* code1)
{
    Tac *jumpFalseTac = 0;
    Tac *jumpTac = 0;
    Tac *label1 = 0;
    Tac *label2 = 0;


    Hash *hashLabel1 = 0;
    hashLabel1 = makeLabel();
    Hash *hashLabel2 = 0;
    hashLabel2 = makeLabel();
    

    jumpFalseTac = tacCreate(TAC_JUMP_FALSE, hashLabel2, code0 ? code0->result: 0, 0);
    jumpFalseTac->prev = code0;

    jumpTac = tacCreate(TAC_JUMP, hashLabel1, 0, 0);
    jumpTac->prev = code1;

    label1 = tacCreate(TAC_LABEL, hashLabel1, 0, 0);
    label2 = tacCreate(TAC_LABEL, hashLabel2, 0, 0);

    return tacJoin(label1, tacJoin(jumpFalseTac, tacJoin(jumpTac , label2)));
}

Tac *tacCreateFuncDec(Tac *code0, Tac *code1, Tac *code2, Tac *code3)
{
    Tac *tacFuncBegin = 0;
    Tac *tacFuncEnd = 0;

    tacFuncBegin = tacCreate(TAC_FUNC_BEGIN, code1 ? code1->result : 0, 0, 0);
    tacFuncEnd = tacCreate(TAC_FUNC_END, code1 ? code1->result : 0, 0, 0);

    return tacJoin(code0, tacJoin(code1, tacJoin(code2, tacJoin(tacFuncBegin, tacJoin(code3, tacFuncEnd)))));
}




void tacPrint(Tac* tac) {
    if (!tac) return;
    if (tac->type == TAC_SYMBOL) return;

    fprintf(stderr, "TAC(");

    switch (tac->type)
    {
        case TAC_SYMBOL :  fprintf(stderr, "TAC_SYMBOL");  break;
        case TAC_SUM : fprintf(stderr, "TAC_SUM"); break;
        case TAC_SUB : fprintf(stderr, "TAC_SUB"); break;
        case TAC_MULT : fprintf(stderr, "TAC_MULT"); break;
        case TAC_DIV : fprintf(stderr, "TAC_DIV"); break;
        case TAC_LE : fprintf(stderr, "TAC_LE"); break;
        case TAC_GE : fprintf(stderr, "TAC_GE"); break;
        case TAC_EQ : fprintf(stderr, "TAC_EQ"); break;
        case TAC_DIFF : fprintf(stderr, "TAC_DIFF"); break;
        case TAC_COPY : fprintf(stderr, "TAC_COPY"); break;
        case TAC_JUMP_FALSE : fprintf(stderr, "TAC_JUMP_FALSE"); break;
        case TAC_LABEL : fprintf(stderr, "TAC_LABEL"); break;
        case TAC_JUMP : fprintf(stderr, "TAC_JUMP"); break;
        case TAC_GT : fprintf(stderr, "TAC_GT"); break;
        case TAC_LT : fprintf(stderr, "TAC_LT"); break;
        case TAC_AND : fprintf(stderr, "TAC_AND"); break;
        case TAC_OR : fprintf(stderr, "TAC_OR"); break;
        case TAC_NOT : fprintf(stderr, "TAC_NOT"); break;
        case TAC_COPY_ARR : fprintf(stderr, "TAC_COPY_ARR"); break;
        case TAC_FUNC_CALL : fprintf(stderr, "TAC_FUNC_CALL"); break;
        case TAC_FUNC_PARAMS : fprintf(stderr, "TAC_FUNC_PARAMS"); break;
        case TAC_READ : fprintf(stderr, "TAC_READ"); break;
        case TAC_PRINT_LIST : fprintf(stderr, "TAC_PRINT"); break;
        case TAC_EXPR_ARR : fprintf(stderr, "TAC_EXPR_ARR"); break;
        case TAC_RETURN : fprintf(stderr, "TAC_RETURN"); break;
        case TAC_FUNC_BEGIN : fprintf(stderr, "TAC_FUNC_BEGIN"); break;
        case TAC_FUNC_END : fprintf(stderr, "TAC_FUNC_END"); break;
        case TAC_READ_ARR: fprintf(stderr, "TAC_READ_ARR"); break;
        case TAC_FUNC_ARG: fprintf(stderr, "TAC_FUNC_ARG"); break;
        default:          fprintf(stderr, "TAC_UNKNOWN"); break;
        
    }

    fprintf(stderr, ",%s", (tac->result) ? tac->result->name : "0");
    fprintf(stderr, ",%s", (tac->op1) ? tac->op1->name : "0");
    fprintf(stderr, ",%s", (tac->op2) ? tac->op2->name : "0");
    fprintf(stderr, ");\n");

}

void tacPrintBackwards(Tac* tac) {
    if(!tac)
        return;
    else{
        tacPrintBackwards(tac->prev);
        tacPrint(tac);
    }
}

Tac *tacJoin(Tac *l1, Tac *l2)
{
    Tac *point;
    if(!l1) return l2;
    if (!l2) return l1;
    
    for(point = l2; point->prev != 0; point = point->prev)
        ;

    point->prev = l1;
    return l2;
}

Tac *generateCode(Ast *node) {

    int i;
    Tac *result = 0;
    Tac *code[MAX_SONS];

    if (!node)
        return 0;

    if(node->type == AST_FUNC_DEC){
        
    }

    for (i=0; i<MAX_SONS; i++)
        code[i] = generateCode(node->children[i]);

    switch (node->type)
    {
        case AST_IDENTIFIER : result = tacCreate(TAC_SYMBOL, node->hashReference, 0, 0); break;
        case AST_EXPR_SUM : result = tacCreateBinOp(TAC_SUM, code[0], code[1]); break;
        case AST_EXPR_SUB : result = tacCreateBinOp(TAC_SUB, code[0], code[1]); break;
        case AST_EXPR_MULT : result = tacCreateBinOp(TAC_MULT, code[0], code[1]); break;
        case AST_EXPR_DIV : result = tacCreateBinOp(TAC_DIV, code[0], code[1]); break;
        case AST_EXPR_LE : result = tacCreateBinOp(TAC_LE, code[0], code[1]); break;
        case AST_EXPR_GE : result = tacCreateBinOp(TAC_GE, code[0], code[1]); break;
        case AST_EXPR_EQ : result = tacCreateBinOp(TAC_EQ, code[0], code[1]); break;
        case AST_EXPR_DIFF : result = tacCreateBinOp(TAC_DIFF, code[0], code[1]); break;
        case AST_EXPR_GT : result = tacCreateBinOp(TAC_GT, code[0], code[1]); break; 
        case AST_EXPR_LT : result = tacCreateBinOp(TAC_LT, code[0], code[1]); break; 
        case AST_EXPR_AND : result = tacCreateBinOp(TAC_AND, code[0], code[1]); break; 
        case AST_EXPR_OR : result = tacCreateBinOp(TAC_OR, code[0], code[1]); break;
        case AST_EXPR_NOT : result = tacCreateBinOp(TAC_NOT, code[0], code[1]); break;  
        case AST_INT : result = tacCreate(TAC_SYMBOL, node->hashReference, 0, 0); break;
        case AST_FLOAT : result = tacCreate(TAC_SYMBOL, node->hashReference, 0, 0); break;
        case AST_CHAR : result = tacCreate(TAC_SYMBOL, node->hashReference, 0, 0); break;
        case AST_STRING : result = tacCreate(TAC_SYMBOL, node->hashReference, 0, 0); break;
        

        case AST_ASSIGN : result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_COPY, code[0] ? code[0]->result : 0, code[1] ? code[1]->result : 0, 0))); break;
        case AST_ASSIGN_ARR : 
            result = tacJoin(code[0], 
                        tacJoin(code[1], 
                            tacJoin(code[2], 
                                tacCreate(TAC_COPY_ARR, code[0]? code[0]->result : 0, code[1]? code[1]->result : 0, code[2]? code[2]->result : 0)))); break;

        case AST_IF : result = tacCreateIf(code[0], code[1]); break;
        case AST_IFE : result = tacCreateIfElse(code[0], code[1], code[2]); break;
        case AST_WHILE : result = tacCreateWhile(code[0], code[1]); break;
        case AST_EXPR_FUNC_CALL: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_FUNC_CALL, makeTemp(), code[0]? code[0]->result: 0,0))); break;
        case AST_PARAM_LIST: result = tacJoin(code[0], tacJoin(tacCreate(TAC_FUNC_PARAMS, code[0]? code[0]->result: 0, 0, 0), code[1])); break;
        case AST_EXPR_LIST: result = tacJoin(code[0], tacJoin(tacCreate(TAC_FUNC_ARG, code[0]? code[0]->result: 0, 0, 0), code[1])); break;
        case AST_READ: result = tacJoin(code[0], tacCreate(TAC_READ, code[0]? code[0]->result: 0, 0,0)); break;
        case AST_READ_ARR : result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_READ_ARR, code[0]? code[0]->result: 0,  code[1]? code[1]->result: 0, 0))); break;
        case AST_PRINT_LIST : result = tacJoin(code[0], tacJoin(tacCreate(TAC_PRINT_LIST, code[0]? code[0]->result: 0, 0, 0) , code[1])); break; 
        case AST_EXPR_ARR: result = tacJoin(code[0], tacJoin(code[1], tacCreate(TAC_EXPR_ARR, makeTemp(), code[0]? code[0]->result: 0,  code[1]? code[1]->result: 0))); break;
        case AST_RETURN: result = tacJoin(code[0], tacCreate(TAC_RETURN, code[0]? code[0]->result: 0,0, 0)); break;
        case AST_FUNC_DEC: result = tacCreateFuncDec(code[0], code[1], code[2], code[3]); break;
        

        default: result = tacJoin(code[0], tacJoin(code[1], tacJoin(code[2], code[3])));break;


    }



    return result;
}


Tac *reverse(Tac *tac) {
  Tac* t = tac;
  for (t = tac; t->prev; t = t->prev) {
    t->prev->next = t;
  }
  return t;
}

Tac *addArgumentsNames(Tac *tac){
    if (!tac){
        return 0;
    }
    else{
        for(Tac *result = tac; result != 0; result = result->prev){
            if (result->type == TAC_FUNC_CALL){
                if(result->prev? result->prev->type == TAC_FUNC_ARG : 0){
                    Tac *iteratingTac;
                    for(iteratingTac = result->prev->prev; iteratingTac->type != TAC_FUNC_BEGIN || strcmp(iteratingTac->result->name, result->op1->name); iteratingTac = iteratingTac->prev);
                    iteratingTac = iteratingTac->prev;
                    for(Tac *funcCallArgs = result->prev; funcCallArgs->type == TAC_FUNC_ARG || funcCallArgs->type == TAC_SYMBOL; funcCallArgs = funcCallArgs->prev){
                        if(funcCallArgs->type == TAC_FUNC_ARG){
                            if(iteratingTac->type == TAC_FUNC_PARAMS){
                                funcCallArgs->op1 = iteratingTac->result;
                                iteratingTac = iteratingTac->prev;
                            }
                            else{
                                funcCallArgs = funcCallArgs->next;
                                iteratingTac = iteratingTac->prev;
                            }
                        }
                        else{
                            if(iteratingTac->type == TAC_FUNC_PARAMS){
                            }
                            else{
                                iteratingTac = iteratingTac->prev;
                            }
                        }
                    }
                }
            }
        }
    }
    
}




