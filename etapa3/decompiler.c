/* Made by Bruno Correa and Alexadre Crestani */


#include "decompiler.h"

void decompile(Ast *ast, FILE *file){
    if(ast != NULL){
        switch(ast->type){
            case AST_IDENTIFIER: decompile_AST_IDENTIFIER(ast, file); break;
            case AST_INT: decompile_AST_INT(ast, file); break;
            case AST_FLOAT: decompile_AST_FLOAT(ast, file); break;
            case AST_CHAR: decompile_AST_CHAR(ast, file); break;
            case AST_STRING: decompile_AST_STRING(ast, file); break;
            case AST_DECL: decompile_AST_DECL(ast, file); break;
            case AST_FUNC_DEC: decompile_AST_FUNC_DEC(ast, file); break;
            case AST_VAR_DEC: decompile_AST_VAR_DEC(ast, file); break;
            case AST_ARR_DEC: decompile_AST_ARR_DEC(ast, file); break;
            case AST_KW_INT: decompile_AST_KW_INT(ast, file); break;
            case AST_KW_FLOAT: decompile_AST_KW_FLOAT(ast, file); break;
            case AST_KW_CHAR: decompile_AST_KW_CHAR(ast, file); break;
            case AST_LIT_LIST: decompile_AST_LIT_LIST(ast, file); break;
            case AST_PARAM_LIST: decompile_AST_PARAM_LIST(ast, file); break;
            case AST_PARAM: decompile_AST_PARAM(ast, file); break;
            case AST_COMMAND_BLOCK: decompile_AST_COMMAND_BLOCK(ast, file); break;
            case AST_COMMAND_LIST: decompile_AST_COMMAND_LIST(ast, file); break;
            case AST_ASSIGN: decompile_AST_ASSIGN(ast, file); break;
            case AST_ASSIGN_ARR: decompile_AST_ASSIGN_ARR(ast, file); break;
            case AST_EXPR_PAR: decompile_AST_EXPR_PAR(ast, file); break;
            case AST_EXPR_LIST: decompile_AST_EXPR_LIST(ast, file); break;
            case AST_EXPR_ARR: decompile_AST_EXPR_ARR(ast, file); break;
            case AST_EXPR_SUM: decompile_AST_EXPR_SUM(ast, file); break;
            case AST_EXPR_SUB: decompile_AST_EXPR_SUB(ast, file); break;
            case AST_EXPR_MULT: decompile_AST_EXPR_MULT(ast, file); break;
            case AST_EXPR_DIV: decompile_AST_EXPR_DIV(ast, file); break;
            case AST_EXPR_LT: decompile_AST_EXPR_LT(ast, file); break;
            case AST_EXPR_GT: decompile_AST_EXPR_GT(ast, file); break;
            case AST_EXPR_LE: decompile_AST_EXPR_LE(ast, file); break;
            case AST_EXPR_GE: decompile_AST_EXPR_GE(ast, file); break;
            case AST_EXPR_EQ: decompile_AST_EXPR_EQ(ast, file); break;
            case AST_EXPR_DIFF: decompile_AST_EXPR_DIFF(ast, file); break;
            case AST_EXPR_AND: decompile_AST_EXPR_AND(ast, file); break;
            case AST_EXPR_OR: decompile_AST_EXPR_OR(ast, file); break;
            case AST_EXPR_NOT: decompile_AST_EXPR_NOT(ast, file); break;
            case AST_EXPR_FUNC_CALL: decompile_AST_EXPR_FUNC_CALL(ast, file); break;
            case AST_IF: decompile_AST_IF(ast, file); break;
            case AST_IFE: decompile_AST_IFE(ast, file); break;
            case AST_WHILE: decompile_AST_WHILE(ast, file); break;
            case AST_READ: decompile_AST_READ(ast, file); break;
            case AST_READ_ARR: decompile_AST_READ_ARR(ast, file); break;
            case AST_PRINT: decompile_AST_PRINT(ast, file); break;
            case AST_PRINT_LIST: decompile_AST_PRINT_LIST(ast, file); break;
            case AST_RETURN: decompile_AST_RETURN(ast, file); break;
        }
    }
}
void decompile_AST_IDENTIFIER(Ast *ast, FILE *file){
    fprintf(file, "%s ", ast->hashReference->name);
}

void decompile_AST_INT(Ast *ast, FILE *file){
    fprintf(file, "%s ", ast->hashReference->name);
}

void decompile_AST_FLOAT(Ast *ast, FILE *file){
    fprintf(file, "%s ", ast->hashReference->name);
}

void decompile_AST_CHAR(Ast *ast, FILE *file){
    fprintf(file, "%s ", ast->hashReference->name);
}

void decompile_AST_STRING(Ast *ast, FILE *file){
    fprintf(file, "%s ", ast->hashReference->name);
}

void decompile_AST_DECL(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "\n");
    decompile(ast->children[1], file);
}

void decompile_AST_FUNC_DEC(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    decompile(ast->children[1], file);
    fprintf(file, "( ");
    decompile(ast->children[2], file);
    fprintf(file, "){\n");
    decompile(ast->children[3], file);
    fprintf(file, "\n} ");
}

void decompile_AST_VAR_DEC(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    decompile(ast->children[1], file);
    fprintf(file, "( ");
    decompile(ast->children[2], file);
    fprintf(file, "); ");
}

void decompile_AST_ARR_DEC(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    decompile(ast->children[1], file);
    fprintf(file, "[ ");
    decompile(ast->children[2], file);
    fprintf(file, "] ");
    decompile(ast->children[3], file);
    fprintf(file, "; ");
}

void decompile_AST_KW_INT(Ast *ast, FILE *file){
    fprintf(file, "int ");
}

void decompile_AST_KW_FLOAT(Ast *ast, FILE *file){
    fprintf(file, "float ");
}

void decompile_AST_KW_CHAR(Ast *ast, FILE *file){
    fprintf(file, "char ");
}

void decompile_AST_LIT_LIST(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    decompile(ast->children[1], file);
}

void decompile_AST_PARAM_LIST(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    decompile(ast->children[1], file);
}

void decompile_AST_PARAM(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    decompile(ast->children[1], file);
}

void decompile_AST_COMMAND_BLOCK(Ast *ast, FILE *file){
    fprintf(file, "{\n");
    decompile(ast->children[0], file);
    fprintf(file, "\n}");
}

void decompile_AST_COMMAND_LIST(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, ";\n");
    decompile(ast->children[1], file);
}

void decompile_AST_ASSIGN(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "<- ");
    decompile(ast->children[1], file);
}

void decompile_AST_ASSIGN_ARR(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "[ ");
    decompile(ast->children[1], file);
    fprintf(file, "] <- ");
    decompile(ast->children[2], file);
}

void decompile_AST_EXPR_PAR(Ast *ast, FILE *file){
    fprintf(file, "( ");
    decompile(ast->children[0], file);
    fprintf(file, ") ");
}

void decompile_AST_EXPR_LIST(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_ARR(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "[ ");
    decompile(ast->children[0], file);
    fprintf(file, "] ");
}

void decompile_AST_EXPR_SUM(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "+ ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_SUB(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "- ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_MULT(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, ". ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_DIV(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "/ ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_LT(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "< ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_GT(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "> ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_LE(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "<= ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_GE(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, ">= ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_EQ(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "== ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_DIFF(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "!= ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_AND(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "& ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_OR(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "| ");
    decompile(ast->children[1], file);
}

void decompile_AST_EXPR_NOT(Ast *ast, FILE *file){
    fprintf(file, "~ ");
    decompile(ast->children[0], file);
}

void decompile_AST_EXPR_FUNC_CALL(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    fprintf(file, "( ");
    decompile(ast->children[1], file);
    fprintf(file, ")");
}

void decompile_AST_IF(Ast *ast, FILE *file){
    fprintf(file, "if (");
    decompile(ast->children[0], file);
    fprintf(file, ") ");
    decompile(ast->children[1], file);
}

void decompile_AST_IFE(Ast *ast, FILE *file){
    fprintf(file, "if (");
    decompile(ast->children[0], file);
    fprintf(file, ") ");
    decompile(ast->children[1], file);
    fprintf(file, "else ");
    decompile(ast->children[2], file);
}

void decompile_AST_WHILE(Ast *ast, FILE *file){
    fprintf(file, "while (");
    decompile(ast->children[0], file);
    fprintf(file, ") ");
    decompile(ast->children[1], file);
}

void decompile_AST_READ(Ast *ast, FILE *file){
    fprintf(file, "read ");
    decompile(ast->children[0], file);
}

void decompile_AST_READ_ARR(Ast *ast, FILE *file){
    fprintf(file, "read ");
    decompile(ast->children[0], file);
    fprintf(file, "[ ");
    decompile(ast->children[1], file);
    fprintf(file, "] ");
}

void decompile_AST_PRINT(Ast *ast, FILE *file){
    fprintf(file, "print ");
    decompile(ast->children[0], file);
}

void decompile_AST_PRINT_LIST(Ast *ast, FILE *file){
    decompile(ast->children[0], file);
    decompile(ast->children[1], file);
}

void decompile_AST_RETURN(Ast *ast, FILE *file){
    fprintf(file, "return ");
    decompile(ast->children[0], file);
}