/*
Comands Struct File

PROJETO2 IAED 2020/2021 2Semestre

developed by:
Edson da Veiga 76380  LETI

*/

#ifndef Comand_h
#define Comand_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"

/* comand help text*/
#define help "help: Imprime os comandos disponíveis.\n\
quit: Termina o programa.\n\
set: Adiciona ou modifica o valor a armazenar.\n\
print: Imprime todos os caminhos e valores.\n\
find: Imprime o valor armazenado.\n\
list: Lista todos os componentes imediatos de um sub-caminho.\n\
search: Procura o caminho dado um valor.\n\
delete: Apaga um caminho e todos os subcaminhos.\n"

/*Prints available commands.*/
void cmd_help(void);
/*Ends the program.*/
void cmd_quit(link*);
/*Adds or modifies the value to be stored.*/
void cmd_set(link*, char*, char*);
/*Prints all paths and values.*/
void cmd_print(link);
/*Prints the stored value.*/
void cmd_find(link*, char*);
/* Lists all of the immediate components of a subpath.*/
void cmd_list(link*, char*);
/* Searches for the path given a value.*/
void cmd_search(link, char*);
/* Deletes a path and all subpaths.*/
void cmd_delete(link*, char*);

#endif /* Comand_h */
