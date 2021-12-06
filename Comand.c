/*
Comands Auxiliary File

PROJETO2 IAED 2020/2021 2Semestre

developed by:
Edson da Veiga 76380  LETI

*/

/* The functions without comment have the same description as the function below.*/

#include "Comand.h"

static link prev = NULL;

/*Prints available commands.*/
void cmd_help(void) {
    printf("%s", help);
}

/*Ends the program.*/
void cmd_quit(link*root) {
    STfree(root);
}

/*Adds or modifies the value to be stored.*/
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
    free(temp);
}

/*Prints all paths and values.*/
void cmd_print(link root) {
    if (root == NULL) {
        return;
    }
    STprint_all(root, printItem);
}

/*Prints the stored value.*/
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

/* Lists all of the immediate components of a subpath.*/
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

/* Searches for the path given a value.*/
void cmd_search(link root, char *valor) {
    if (root == NULL) {
        printf("%s\n", error_01);
        return;
    }
    STprintSEARCH(root, valor, searchItem);
}

/* Deletes a path and all subpaths.*/
void cmd_delete(link*root, char *caminho) {
    char *local;
    char c[2] = "/";
    link destination = *root;
    link *node = root, no = *root;
    
    if (*root == NULL) {
        return;
    }
    
    prev = *root;
    
    if (prev == NULL && caminho == NULL) 
        return;
    
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
    
    if ( prev == *root && prev != destination && destination->next_side == NULL) {
        prev->next_side = NULL;
    }
    
    else if (prev->next_side != NULL && prev != *root) {
        prev->next_side = destination->next_side;
        destination->next_side = NULL;
    }
    else if ( prev == *root && destination != prev && destination->next_side != NULL) {
        prev->next_side = destination->next_side;
        destination->next_side = NULL;
    }
    
    else if ( prev == *root && destination == prev && destination->next_side != NULL) {
        prev = destination->next_side;
        destination->next_side = NULL;
        prev->count = no->count;
        *root = prev;
    }
    
    STdelete(&destination);
}
