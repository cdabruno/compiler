/* Made by Bruno Correa and Alexadre Crestani */

#include "asm.h"

static int labelSerial = 0;

void generateASM(Tac *first){

    int labelAnd1;
    int labelAnd2;
    int labelOr1;
    int labelOr2;
    int labelOr3;
    
    Tac *tac;
    FILE *fout = fopen("out.s","w");

    fprintf(fout, "## FIXED INIT\n"
    ".section	.rodata\n"
    ".printstring:\n .string \"%%s\"\n"
    ".printintstring:\n .string \"%%d\"\n"
    ".printfloatstring:\n .string \"%%f\"\n"
    ".printcharstring:\n .string \"%%c\"\n"
    ".text\n\n");


    for (tac = first; tac; tac = tac->next){
        switch (tac->type){
            case TAC_SYMBOL : break;
            case TAC_SUM : fprintf(fout, "\n## TAC_SUM\n"
                "movl   _%s(%%rip), %%edx\n"
                "movl	_%s(%%rip), %%eax\n"
                "addl	%%edx, %%eax\n"
                "movl	%%eax, _%s(%%rip)\n", tac->op1->name, tac->op2->name, tac->result->name);
                break;
            case TAC_SUB : fprintf(fout, "\n## TAC_SUB\n"
                "movl   _%s(%%rip), %%edx\n"
                "movl	_%s(%%rip), %%eax\n"
                "subl	%%eax, %%edx\n"
                "movl	%%edx, %%eax\n"
                "movl	%%edx, _%s(%%rip)\n", tac->op1->name, tac->op2->name, tac->result->name);
                break;
            case TAC_MULT : fprintf(fout, "\n## TAC_MULT\n"
                "movl   _%s(%%rip), %%edx\n"
                "movl	_%s(%%rip), %%eax\n"
                "imull	%%edx, %%eax\n"
                "movl	%%eax, _%s(%%rip)\n", tac->op1->name, tac->op2->name, tac->result->name);
                break;
            case TAC_DIV : fprintf(fout, "\n## TAC_DIV\n"
                "movl   _%s(%%rip), %%eax\n"
                "movl	_%s(%%rip), %%ecx\n"
                "cltd"
                "idivl	%%ecx\n"
                "movl	%%eax, _%s(%%rip)\n", tac->op1->name, tac->op2->name, tac->result->name);
                break;
            case TAC_LE : fprintf(fout, "\n## TAC_LE\n"
                "movl   _%s(%%rip), %%edx\n"
                "movl   _%s(%%rip), %%eax\n"
                "cmp    %%eax, %%edx"
                "setle  %%al"
                "movzbl	%%al, %%eax"
	            "movl	%%eax, _%s(%%rip)", tac->op1->name, tac->op2->name, tac->result->name);
                break;
            case TAC_GE : fprintf(fout, "\n## TAC_GE\n"
                "movl   _%s(%%rip), %%edx\n"
                "movl   _%s(%%rip), %%eax\n"
                "cmp    %%eax, %%edx"
                "setge  %%al"
                "movzbl	%%al, %%eax"
	            "movl	%%eax, _%s(%%rip)", tac->op1->name, tac->op2->name, tac->result->name);
                break;
            case TAC_EQ : fprintf(fout, "\n## TAC_EQ\n"
                "movl   _%s(%%rip), %%edx\n"
                "movl   _%s(%%rip), %%eax\n"
                "cmp    %%eax, %%edx"
                "sete  %%al"
                "movzbl	%%al, %%eax"
	            "movl	%%eax, _%s(%%rip)", tac->op1->name, tac->op2->name, tac->result->name);
                break;            
            case TAC_DIFF : fprintf(fout, "\n## TAC_DIFF\n"
                "movl   _%s(%%rip), %%edx\n"
                "movl   _%s(%%rip), %%eax\n"
                "cmp    %%eax, %%edx"
                "setne  %%al"
                "movzbl	%%al, %%eax"
	            "movl	%%eax, _%s(%%rip)", tac->op1->name, tac->op2->name, tac->result->name);
                break;
            case TAC_COPY : fprintf(fout, "\n## TAC_COPY\n"
                "movl   _%s(%%rip), %%eax\n"
                "movl	%%eax, _%s(%%rip)", tac->op1->name, tac->result->name);
                break;
            case TAC_JUMP_FALSE : fprintf(fout, "\n## TAC_JUMP_FALSE\n"
                "movl   _%s(%%rip) %%eax\n"
                "cmpl   $1 %%eax\n"
                "jne    _%s", tac->op1->name, tac->result->name);
                break;
            case TAC_LABEL : fprintf(fout, "\n## TAC_LABEL\n"
                "_%s:", tac->result->name);
                break;
            case TAC_JUMP : fprintf(fout, "\n## TAC_JUMP\n"
                "jmp    _%s", tac->result->name);
                break;
            case TAC_GT : fprintf(fout, "\n## TAC_GT\n"
                "movl   _%s(%%rip), %%edx\n"
                "movl   _%s(%%rip), %%eax\n"
                "cmp    %%eax, %%edx"
                "setg  %%al"
                "movzbl	%%al, %%eax"
	            "movl	%%eax, _%s(%%rip)", tac->op1->name, tac->op2->name, tac->result->name);
                break;
            case TAC_LT : fprintf(fout, "\n## TAC_LT\n"
                "movl   _%s(%%rip), %%edx\n"
                "movl   _%s(%%rip), %%eax\n"
                "cmp    %%eax, %%edx"
                "setl  %%al"
                "movzbl	%%al, %%eax"
	            "movl	%%eax, _%s(%%rip)", tac->op1->name, tac->op2->name, tac->result->name);
                break;
            case TAC_AND: 
                labelAnd1 = labelSerial++;
                labelAnd2 = labelSerial++;
                    fprintf(fout, "\n## TAC_AND\n"
                "movl   _%s(%%rip), %%eax\n"
                "testl  %%eax, %%eax\n"
                "je     _and%d\n"
                "movl   _%s(%%rip), %%eax\n"
                "testl  %%eax, %%eax\n"
                "je     _and%d\n"
                "movl   $1, %%eax\n"
                "jmp    _and%d\n"
                "_and%d:\n"
                "movl   $0, %%eax\n"
                "_and%d:\n"
                "movl   %%eax, _%s(%%rip)\n", tac->op1->name, labelAnd1, tac->op2->name, labelAnd1, labelAnd2, labelAnd1, labelAnd2, tac->result->name);
                break; 
            case TAC_OR:
                labelOr1 = labelSerial++;
                labelOr2 = labelSerial++;
                labelOr3 = labelSerial++;

                    fprintf(fout, "\n## TAC_OR\n"
                "movl	_%s(%%rip), %%eax\n"
                "testl	%%eax, %%eax\n"
                "jne	_or%d\n"
                "movl	_%s(%%rip), %%eax\n"
                "testl	%%eax, %%eax\n"
                "je	_or%d\n"
                "_or%d:\n"
                "movl	$1, %%eax\n"
                "jmp	_or%d\n"
                "_or%d:\n"
                "movl	$0, %%eax\n"
                "_or%d\n"
                "movl   %%eax, _%s(%%rip)\n", tac->op1->name, labelOr1, tac->op2->name, labelOr2, labelOr1, labelOr3, labelOr2, labelOr3, tac->result->name);
            break;
            case TAC_NOT : fprintf(fout, "\n## TAC_NOT\n"
                "movq	%%rsp, %%rbp\n"
	            "movl	_%s(%%rip), %%eax\n"
	            "testl	%%eax, %%eax\n"
	            "sete	%%al\n"
	            "movzbl	%%al, %%eax\n"
	            "movl	%%eax, _%s(%%rip)\n", tac->op1->name, tac->result->name);
                break;
            case TAC_COPY_ARR : fprintf(fout, "\n## TAC_READ_ARR\n"
            	"movzbl	_%s(%%rip), %%eax\n"
	            "movb	%%al, %d+_%s(%%rip)\n", tac->op2->name, 4 * atoi(tac->op1->name), tac->result->name);
                break;
            case TAC_FUNC_CALL : fprintf(fout, "\n## TAC_FUNC_CALL\n"
                "movl   $0, %%eax\n"
                "call   _%s\n", tac->op1->name);
                break;
            case TAC_FUNC_ARG: fprintf(fout, "\n## TAC_callparams\n"
                "movl   _%s(%%rip), %%eax\n"
                "movl	%%eax, _%s(%%rip)", tac->result->name, tac->op1->name);
                break;
            case TAC_READ: fprintf(fout, "\n## TAC_READ\n"
                "leaq	_%s(%%rip), %%rsi\n"
	            "leaq	.printintstring(%%rip), %%rdi\n"
        	    "movl	$0, %%eax\n"
	            "call	__isoc99_scanf@PLT\n", tac->result->name);
                break;
            case TAC_READ_ARR: fprintf(fout, "\n## TAC_READ_ARR\n"
            	"leaq	%d+_%s(%%rip), %%rsi\n"
	            "leaq	.printintstring(%%rip), %%rdi\n"
	            "movl	$0, %%eax\n"
	            "call	__isoc99_scanf@PLT\n", 4 * atoi(tac->op1->name), tac->result->name);
                break;
            case TAC_PRINT_LIST: 
                if(tac->result->datatype == DATATYPE_INT || tac->result->type == SYMBOL_LIT_INT){
                    fprintf(fout, "\n## TAC_PRINT_LIST\n"
                    "movl	_%s(%%rip), %%eax\n"
                    "movl	%%eax, %%esi\n"
                    "leaq	.printintstring(%%rip), %%rdi\n"
                    "movl	$0, %%eax\n"
                    "call	printf@PLT\n", tac->result->name);
                }
                else if(tac->result->datatype == DATATYPE_CHAR || tac->result->type == SYMBOL_LIT_CHAR){
                    fprintf(fout, "\n## TAC_PRINT_LIST\n"
                    "movl	_%s(%%rip), %%eax\n"
                    "movl	%%eax, %%esi\n"
                    "leaq	.printcharstring(%%rip), %%rdi\n"
                    "movl	$0, %%eax\n"
                    "call	printf@PLT\n", tac->result->name);
                }
                else if(tac->result->datatype == DATATYPE_FLOAT || tac->result->type == SYMBOL_LIT_FLOAT){
                    fprintf(fout, "\n## TAC_PRINT_LIST\n"
                    "movl	_%s(%%rip), %%eax\n"
                    "movl	%%eax, %%esi\n"
                    "leaq	.printfloatstring(%%rip), %%rdi\n"
                    "movl	$0, %%eax\n"
                    "call	printf@PLT\n", tac->result->name);
                }
                else if(tac->result->datatype == DATATYPE_STRING || tac->result->type == SYMBOL_LIT_STRING){
                    fprintf(fout, "\n## TAC_PRINT_LIST\n"
                    "leaq	_%s%ld(%%rip), %%rsi\n"
                    "leaq	.printstring(%%rip), %%rdi\n"
                    "movl	$0, %%eax\n"
                    "call	printf@PLT\n", "str", strlen(tac->result->name));
                }
                else{
                    fprintf(fout, "\n## TAC_PRINT_LIST\n"
                    "movl	_%s(%%rip), %%eax\n"
                    "movl	%%eax, %%esi\n"
                    "leaq	.printintstring(%%rip), %%rdi\n"
                    "movl	$0, %%eax\n"
                    "call	printf@PLT\n", tac->result->name);
                }
                break;
            case TAC_EXPR_ARR: 
            fprintf(fout, "\n## TAC_EXPR_ARR\n"
            "movzbl	%d+_%s(%%rip), %%eax\n"
	        "movb	%%al, _%s(%%rip)\n", 4 * atoi(tac->op2->name), tac->op1->name, tac->result->name); break;
            case TAC_RETURN : fprintf(fout, "\n## TAC_RETURN\n"
                "movl   %%edi, -4(%%rbp)\n"
                "movl   _%s(%%rip), %%eax\n", tac->op1->name);
                break;
            case TAC_FUNC_BEGIN : 
            if(strcmp(tac->result->name, "main") == 0){
                fprintf(fout, "\n## TAC_FUNC_BEGIN\n"
                    ".globl %s\n"
                    "%s:\n"
                    "pushq  %%rbp\n"
                    "movq   %%rsp, %%rbp\n", tac->result->name, tac->result->name);
            }
            else{
                fprintf(fout, "\n## TAC_FUNC_BEGIN\n"
                    ".globl _%s\n"
                    "_%s:\n"
                    "pushq  %%rbp\n"
                    "movq   %%rsp, %%rbp\n", tac->result->name, tac->result->name);
            }
                break;
            case TAC_FUNC_END : fprintf(fout, "\n## TAC_FUNC_END\n"
                "popq   %%rbp\n"
                "ret\n");
                break;
            default:          fprintf(fout, "\n ##TAC_UNKNOWN\n"); break;
        }

        fflush(fout);
    } 
    printASM(fout);

    fclose(fout);
}