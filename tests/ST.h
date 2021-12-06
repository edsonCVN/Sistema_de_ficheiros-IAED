#ifndef _ST_
#define _ST_

#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

#define STvalor(a) (valor(a->item))
#define exch(A, B) { link temp = A; A = B; B = temp; }





typedef struct STnode* link;
struct STnode {
    int count;
    Item item;
    link next_side, next_below;
};

void STinit(link*);
link* STsearch(link*, link*, Key);
link* STbellow(link*);
link insertSIDE(link, Item);
void STinsert(link*,Item);
void STaddData(link, char*, char*);
void STprintSEARCH(link*, char*, void (*visit)(Item));
void STprint_all(link,void (*visit)(Item));
void STlist(link*head);
void STdelete(link*);
void STfree(link*);

 #endif
