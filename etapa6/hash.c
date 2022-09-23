/* Made by Bruno Correa and Alexadre Crestani */

#include "hash.h"

Hash **table;

static char declarationsString[10000] = "";
static char arrDeclaration[1000] = "";

void hashInit(void){
    table = (Hash **) calloc(HASH_SIZE, sizeof(Hash *));
}

int hashFunction(char *name){
    
    int hash = 1;
    int i;

    while (i = *name++){
        hash = (hash * i) % HASH_SIZE + 1;
    }
    
    return hash-1;
}

Hash *hashInsert(char *name, int type){

    if (hashFind(name) != NULL)
        return hashFind(name);

    Hash *newNode = (Hash *) calloc(1, sizeof(Hash));
    char *newName = (char *) calloc(strlen(name) + 1, sizeof(char));
    strcpy(newName, name);

    int pos = hashFunction(name);
    Hash *list = table[pos];

    newNode->type = type;
    newNode->name = newName;
    newNode->next = list;
    
    table[pos] = newNode;

    return newNode;
}

void hashFree(void){
    
    int i;

    for (i = 0; i < HASH_SIZE; ++i) {
        Hash *list = table[i];

        while (list != NULL) {
            Hash *prev = list;
            list = list->next;

            free(prev->name);    
            free(prev);
        }
    }

    free(table);
    table = NULL;
}

void hashPrint(void){
    
    int i;
    
    for (i = 0; i < HASH_SIZE; i++){
        Hash *list = table[i];
        if (list != NULL){
            printf("Table[%d]: ", i);

            while (list != NULL) {
                printf("(str=%s type=%d) ", list->name, list->type);
                list = list->next;
            }
            printf("\n");
        }
    }
    
}

Hash *hashFind(char *name){
    int pos = hashFunction(name);
    Hash *list = table[pos];

    while (list != NULL) {
        if (strcmp(list->name, name) == 0){
            return list;
        }
        list = list->next;
    }

    return NULL;
}


Hash *makeTemp() {
   static int serial = 0;
   char buffer[256] = "";
   sprintf(buffer, "tempVar_%d", serial++);
   return hashInsert(buffer, SYMBOL_VAR);
}


Hash *makeLabel() {
   static int serial = 0;
   char buffer[256] = "";
   sprintf(buffer, "label_%d", serial++);
   return hashInsert(buffer, SYMBOL_LABEL);
}


void printASM(FILE* fout){
   int i;
   Hash* node;
   fprintf(fout, "\n\n##DATA SECTION\n"
      ".data\n\n");


   for (int i=0; i<HASH_SIZE; i++){
      for (node = table[i]; node; node=node->next){
        switch (node->type)
        {
            case SYMBOL_VAR:
            if(strstr(node->name, "tempVar")){
                fprintf(fout, "_%s:\t.long\t0\n", node->name);
            }
            break;
            case SYMBOL_LIT_INT:
            case SYMBOL_LIT_CHAR: 
            case SYMBOL_LIT_FLOAT:
            fprintf(fout, "_%s:\t.long\t%s\n", node->name, node->name);
            break;
            case SYMBOL_LIT_STRING:
                fprintf(fout, "_%s%ld:\t.string\t%s\n\t.zero\n", "str", strlen(node->name), node->name);
            break;
            default:
            break;
        }
      }
    }
    fprintf(fout, "%s", declarationsString);
    fflush(fout);
}

void addToDeclaration(char *text){
    strcat(declarationsString, text);
}

void addToArrDeclaration(char *text){
    char auxString[1000];
    strcpy(auxString, text);
    strcat(auxString, arrDeclaration);
    strcpy(arrDeclaration, auxString);

}

void addArrToString(){
    strcat(declarationsString, arrDeclaration);
    char empty[1000] = "";
    strcpy(arrDeclaration, empty);
}