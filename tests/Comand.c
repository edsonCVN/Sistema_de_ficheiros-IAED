
#include "Comand.h"

static link prev = NULL;

void cmd_help(void) {
    printf("%s", help);
}

void cmd_quit(link*root) {
    STfree(root);
}

void cmd_set(link*root, char *caminho, char *valor) {
    char *local, *temp;
    char c[2] = "/";
    link destination = NULL;
    link *temp_2 = root;
    link *node = root;

    temp = dupstr(caminho);
    local = strtok(caminho, c);
    while( local != NULL ) {
        if (*(node = STsearch(node, &prev, local)) == NULL) {
            STinsert(node, newItem(local, NULL, NULL));
            destination = *node;
            if (*temp_2 != destination)
                (*temp_2)->count++;
            destination->count++;
            node = STbellow(node);
            temp_2 = node;
        }
        else {
            destination = *node;
            node = STbellow(node);
            temp_2 = node;
        }
        local = strtok(NULL, c);
    }
    
    STaddData(destination, temp, valor);
}

void cmd_print(link root) {
    STprint_all(root, printItem);
}

void cmd_find(link*root, char *caminho) {
    char *local;
    char c[2] = "/";
    link destination = *root;
    link *node = root;
    
    local = strtok(caminho, c);
    while( local != NULL ) {
        if (*(node = STsearch(node, &prev, local)) != NULL) {
            destination = *node;
            node = STbellow(node);
        }
        else {
            printf("%s\n", error_01);
            return;
        }
        local = strtok(NULL, c);
    }
    if (STvalor(destination) == NULL) {
            printf("%s\n", error_02);
        }
    else
        printf("%s\n", STvalor(destination));
}
 
void cmd_list(link *root, char *caminho) {
    char *local;
    char c[2] = "/";
    link *node = root;
    
    local = strtok(caminho, c);
    while( local != NULL ) {
        if (*(node = STsearch(node, &prev, local)) != NULL) {
            node = STbellow(node);
        }
        else {
            printf("%s\n", error_01);
            return;
        }
        local = strtok(NULL, c);
    }
    
    STlist(node);
}

void cmd_search(link root, char *valor) {
    if (root == NULL) {
        printf("%s\n", error_01);
        return;
    }
    STprintSEARCH(&root, valor, searchItem);
}


void cmd_delete(link*root, char *caminho) {
    char *local;
    char c[2] = "/";
    link destination = *root;
    link *node = root, no = *root;
    
    local = strtok(caminho, c);
    while( local != NULL ) {
        no = *node;
        if (*(node = STsearch(node, &prev, local)) != NULL) {
            destination = *node;
            node = STbellow(node);
        }
        else {
            printf("%s\n", error_01);
            return;
        }
        local = strtok(NULL, c);
    }
    no->count--;
    if (destination->next_side != NULL) {
        prev->next_side = destination->next_side;
        destination->next_side = NULL;
    }
    
    STdelete(&destination);
    
}
