/* Made by Bruno Correa and Alexadre Crestani */

#ifndef HASH_H
#define HASH_H

#define SYMBOL_LIT_INT 1
#define SYMBOL_LIT_CHAR 2
#define SYMBOL_LIT_FLOAT 3
#define SYMBOL_LIT_STRING 4
#define SYMBOL_VAR 6
#define SYMBOL_FUNC 7
#define SYMBOL_ARR 8
#define DATATYPE_INT 9
#define DATATYPE_FLOAT 10
#define DATATYPE_CHAR 11
#define DATATYPE_BOOL 12
#define DATATYPE_STRING 13
#define SYMBOL_LABEL 14



#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 997

typedef struct HASH_STRUCT {
    int type;
    int datatype;
    char *name;
    struct HASH_STRUCT *next;
} Hash;

// Initiate hash table.
void hashInit(void);

// Hash function to map strings to positions on the hash table.
int hashFunction(char *name);

// Insert an element in the hash table.
Hash *hashInsert(char *name, int type);

// Free hash table memory.
void hashFree(void);

// Print the table.
void hashPrint(void);

// Find the hash element by name.
Hash *hashFind(char *name);

Hash *makeTemp();

Hash *makeLabel();

void printASM(FILE* fout);


#endif
