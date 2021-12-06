#include "Item.h"

Item newItem(char*local, char*caminho, char*valor) {
    Item x = (Item)malloc(sizeof(struct directory));
    x->local = dupstr(local);
    x->caminho = dupstr(caminho);
    x->valor = dupstr(valor);
    return x;
}

char *dupstr(const char *s) {
    char *p;
    if (s == NULL) return NULL;
    p = malloc(strlen(s) + 1);
    if(p != NULL) strcpy(p, s);
    return p;
}

void deleteItem(Item a) {
    free(a->local);
    free(a->caminho);
    free(a->valor);
    free(a);
}

void printItem(Item a) {
    if (a->valor == NULL) 
        return;
    if ((a->caminho)[0] != '/')
        printf("/");
    printf("%s %s\n",a->caminho, a->valor);
}

void searchItem(Item a) {
    if ((a->caminho)[0] != '/')
        printf("/");
    printf("%s\n",a->caminho);
}

void addData(Item a, char*caminho, char*valor) {
    a->caminho = dupstr(caminho);
    a->valor = dupstr(valor);
}
