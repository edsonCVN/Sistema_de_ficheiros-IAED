#ifndef _ITEM_
#define _ITEM_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define key(a) (a != NULL ? a->local : "")
#define key_v(a) (a != NULL ? a->valor : "")
#define less(a,b) (strcmp(a,b)<0)
#define eq(a,b) (strcmp(a,b)==0)
#define valor(a) (a->valor)
#define caminho(a) (a->caminho)
#define local(a) (a->local)
#define condition_1(a,b) (strcmp(a->local, b->local) > 0)
#define condition_2(a,b) (strcmp(a->local, b->local) < 0)

#define error_01 "not found"
#define error_02 "no data"

typedef char* Key;

typedef struct directory {
    char* local;
    char* caminho;
    char* valor;
}* Item;

Item newItem(char*local, char*caminho, char*valor);
char *dupstr(const char *s);
void deleteItem(Item a);
void printItem(Item a);
void searchItem(Item a);
void addData(Item a, char*caminho, char*valor);

#endif
