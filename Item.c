/*
Directory Auxiliary File

PROJETO2 IAED 2020/2021 2Semestre

developed by:
Edson da Veiga 76380  LETI

*/

/* The functions without comment have the same description as the function below.*/

#include "Item.h"

/* Initializes the directory.*/
Item newItem(char*local, char*caminho, char*valor) {
    Item x = (Item)malloc(sizeof(struct directory));
    x->local = dupstr(local);
    x->caminho = dupstr(caminho);
    x->valor = dupstr(valor);
    return x;
}

/* Allocate memory and copy the string.*/
char *dupstr(const char *s) {
    char *p;
    if (s == NULL) return NULL;
    p = malloc(strlen(s) + 1);
    if(p != NULL) strcpy(p, s);
    return p;
}

/* Delete the directory.*/
void deleteItem(Item a) {
        free(a->local);
        free(a->caminho);
        free(a->valor);
        free(a);
}

/* Print a directory path and value.*/
void printItem(Item a) {
    if (a->valor == NULL) 
        return;
    if ((a->caminho)[0] != '/')
        printf("/");
    printf("%s %s\n",a->caminho, a->valor);
}

/* Print a directory path.*/
void searchItem(Item a) {
    if ((a->caminho)[0] != '/')
        printf("/");
    printf("%s\n",a->caminho);
}

/* Inserts the value and local in the directory.*/
void addData(Item a, char*caminho, char*valor) {
    free(a->caminho);
    free(a->valor);
    a->caminho = dupstr(caminho);
    a->valor = dupstr(valor);
}
