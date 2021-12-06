/*
Tree Struct File

PROJETO2 IAED 2020/2021 2Semestre

developed by:
Edson da Veiga 76380  LETI

*/

#ifndef _ST_
#define _ST_

#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

#define STvalor(a) (valor(a->item))
#define exch(A, B) { link temp = A; A = B; B = temp; }





typedef struct STnode* link;

/* Tree struct  */
struct STnode {
    int count;
    Item item;
    link next_side, next_below;
};

/* Initializes the root.*/
void STinit(link*);
/* Search for a path.*/
link* STsearch(link*, link*, Key);
/* Returns the structure in the subpath.*/
link* STbellow(link*);
/* Insert a directory into the tree.*/
void STinsert(link*,Item);
/* Inserts the value and local in the directory.*/
void STaddData(link, char*, char*);
/* Search the tree for a value.*/
void STprintSEARCH(link, char*, void (*visit)(Item));
/* Prints all directories.*/
void STprint_all(link,void (*visit)(Item));
/* Search the tree for a path.*/
void STlist(link*head);
/* Delete a directory in the tree.*/
void STdelete(link*);
/* Delete a branch from the tree.*/
void STfree(link*);

 #endif
