
#include "ST.h"

static int filled = 0, state = 1;




link NEW(Item item, link next_side, link next_below) {
    link x = (link)malloc(sizeof(struct STnode));
    x->count = 0;
    x->item = item;
    x->next_side = next_side;
    x->next_below = next_below;
    return x;
}

void STinit(link*head) {
    *head = NULL;
}

link* bellowST(link head) {
    link *x;
    x=&(head->next_below);
    return x;
}

link* STbellow(link*head){
    return bellowST(*head);
}


link* searchST(link*h, link *prev, Key v) {
    link *t;
    if (*h == NULL) {
        return h;
    }
    *prev = *h;
    for (t = h; *t != NULL; t = &(*t)->next_side) {
        if (eq(v, key((*t)->item)))
            return t;
        *prev = *t;
    }
    return t;
}


link* STsearch(link *head, link *prev, Key v) {
    return searchST(head, prev, v);
}

link insertSIDE(link h, Item item) {
    link x;
    if (h == NULL) {
        /*h->count++;*/
        return NEW(item, NULL, NULL);
    }
    for(x = h; x->next_side != NULL; x = x->next_side);
    /*h->count++;*/
    x->next_side = NEW(item, NULL, NULL);
    return h;
}

void STinsert(link*head, Item item) {
    *head = insertSIDE(*head, item);
}

void STaddData(link h, char* caminho, char* valor) {
    addData(h->item, caminho, valor);
}

void printST(link h, void (*visit)(Item)) {
    if (h == NULL || !h->count)
        return;
    visit(h->item);
    printST(h->next_below, visit);
    printST(h->next_side, visit);
}

void printSEARCHst(link h, char* val, void (*visit)(Item)) {
    
    if (h == NULL || !state)
        return;
    if (h->item->valor != NULL && eq(val, key_v(h->item))) {
        visit(h->item);
        state = 0;
        return;
    }
    printSEARCHst(h->next_below, val, visit);
    printSEARCHst(h->next_side, val, visit);
}

void STprintSEARCH(link*h, char* val, void (*visit)(Item)) {
    state = 1;
    printSEARCHst(*h, val, visit);
    if (state)
        printf("%s\n", error_01);
}

void STprint_all(link head, void (*visit)(Item)) {
    printST(head, visit);
}


/* Search for the position where  the task should be. */
int binarySearch(link*list, int l, int r, Item node) {
    
    if (r >= l) {
        int mid = l + (r - l) / 2;
        
        /* If the element should be  at the middle */
        if (condition_1(list[mid]->item, node) && condition_2(list[mid]->item, node))
            return mid;
        
        /* If element is smaller than mid, then it should be in left subarray. */
        if (condition_1(list[mid]->item, node))
            return binarySearch(list, l, mid - 1, node);
        
        /* Else the element should be in right subarray. */
        return binarySearch(list, mid + 1, r, node);
    }
    
    /* The task is in the right position. */
    return r+1;
}

/* Sorts the task alphabetically. */
void inserts_task(link*list, int index) {
    
    exch(list[index], list[filled-1]);
    ++index;
    
    while ( index < filled-1) {
        exch(list[index], list[filled-1]);
        ++index;
    }
}

link listST(link h) {
    link *list, x;
    int i = 0;
    
    filled = 0;
    
    if (h == NULL || !h->count) {
        return h;
    }
    list = (link*) malloc(h->count*sizeof(link));
    x=h->next_side;
    list[filled]=h; filled++;
    while (x!=NULL) {
        list[filled]=x; filled++;
        inserts_task(list, binarySearch(list, 0, filled-2, x->item));
        x=x->next_side;
    }
    while (i < h->count) {
        printf("%s\n", local(list[i]->item));
        i++;
    }
    free(list);
    return h;
}

void STlist(link*head) {
    *head = listST(*head);
}

link deleteST(link h) {
    if (h==NULL) return h;
    /*deleteST(h->next_below);
    deleteST(h->next_below);*/
    STfree(&h);
    
    return h;
}

void STdelete(link*head){
    
    /*if ((*head)->next_side != NULL) {
        (*prev)->next_side = (*head)->next_side;
    }*/
    
    *head = deleteST(*head);
    
}

link freeST(link h)
{
    if (h==NULL) return h;
    deleteItem(h->item);
    h->next_below=freeST(h->next_below);
    h->next_side=freeST(h->next_side);
    free(h);
    return h;
}

void STfree(link*head) {
    *head=freeST(*head);
}

