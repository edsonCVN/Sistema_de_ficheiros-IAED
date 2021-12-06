/*
Directory Struct File

PROJETO2 IAED 2020/2021 2Semestre

developed by:
Edson da Veiga 76380  LETI

*/

#ifndef _ITEM_
#define _ITEM_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Macros */

/* Returns the local.*/
#define key(a) (a != NULL ? a->local : "")
/* Returns the value.*/
#define key_v(a) (a != NULL ? a->valor : "")
/* Returns true if the a string is less.*/
#define less(a,b) (strcmp(a,b)<0)
/* Returns true if the strings are equal.*/
#define eq(a,b) (strcmp(a,b)==0)
/* Returns the value.*/
#define valor(a) (a->valor)
/* Returns the path.*/
#define caminho(a) (a->caminho)
/* Returns the local.*/
#define local(a) (a->local)
/* Compares two strings and returns true if the first is greater.*/
#define condition_1(a,b) (strcmp(a->local, b->local) > 0)
/* Compares two strings and returns true if the first is less.*/
#define condition_2(a,b) (strcmp(a->local, b->local) < 0)

/* Error */

#define error_01 "not found"
#define error_02 "no data"
#define error_03 "no memory"

typedef char* Key;

/* directory struct  */
typedef struct directory {
    char* local;
    char* caminho;
    char* valor;
}* Item;

/* Initializes the directory.*/
Item newItem(char*local, char*caminho, char*valor);
/* Allocate memory and copy the string.*/
char *dupstr(const char *s);
/* Delete the directory.*/
void deleteItem(Item a);
/* Print a directory path and value.*/
void printItem(Item a);
/* Print a directory path.*/
void searchItem(Item a);
/* Inserts the value and local in the directory.*/
void addData(Item a, char*caminho, char*valor);

#endif
