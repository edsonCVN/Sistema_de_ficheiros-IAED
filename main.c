/*
MAIN File

PROJETO2 IAED 2020/2021 2Semestre

developed by:
Edson da Veiga 76380  LETI
*/

#include <stdio.h>
#include "Comand.h"

static int do_init = 0;

int main(){
    char buffer[65536], *comando, *caminho, *valor;
    
    link root;
    STinit(&root);
        
    fgets(buffer, 65535, stdin);
    
    comando = strtok(buffer, " ");
    while (strcmp(comando, "quit\n") && strcmp(comando, "quit")) {
        
        if (!strcmp(comando, "help\n"))
            cmd_help();
        
        else if (!strcmp(comando, "set")) {
            caminho = strtok(NULL, " ");
            valor = strtok(NULL, "\n");
            cmd_set(&root, caminho, valor);
        }
        
        else if (!strcmp(comando, "print\n"))
            cmd_print(root);
        
        else if (!strcmp(comando, "find")) {
            caminho = strtok(NULL, "\n");
            cmd_find(&root, caminho);
        }
        
        else if (!strcmp(comando, "list") || !strcmp(comando, "list\n")) {
            caminho = strtok(NULL, "\n");
            if (caminho == NULL)
                cmd_list(&root, caminho);
            else
                cmd_list(&root, caminho);
        }
        
        else if (!strcmp(comando, "search")) {
            valor = strtok(NULL, "\n");
            cmd_search(root, valor);
        }
        
        else if (!strcmp(comando, "delete") || !strcmp(comando, "delete\n") ) {
            caminho = strtok(NULL, "\n");
            if (caminho == NULL) {
                cmd_delete(&root, caminho);
                STinit(&root);
            }
            else {
                if (root != NULL && !strcmp(caminho, key(root->item)) && root->next_side == NULL)
                    do_init = 1;
                cmd_delete(&root, caminho);
                if (do_init) {
                    STinit(&root);
                    do_init = 0;
                }
            }
        }
        
        fgets(buffer, 65535, stdin);
        comando = strtok(buffer, " ");
    }
    cmd_quit(&root);
    return EXIT_SUCCESS;
 }
