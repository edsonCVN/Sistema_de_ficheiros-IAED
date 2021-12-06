
#ifndef Comand_h
#define Comand_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"

#define help "help: Imprime os comandos disponíveis.\n\
quit: Termina o programa.\n\
set: Adiciona ou modifica o valor a armazenar.\n\
print: Imprime todos os caminhos e valores.\n\
find: Imprime o valor armazenado.\n\
list: Lista todos os componentes imediatos de um sub-caminho.\n\
search: Procura o caminho dado um valor.\n\
delete: Apaga um caminho e todos os subcaminhos.\n"

void cmd_help(void);
void cmd_quit(link*);
void cmd_set(link*, char*, char*);
void cmd_print(link);
void cmd_find(link*, char*);
void cmd_list(link*, char*);
void cmd_search(link, char*);
void cmd_delete(link*, char*);

#endif /* Comand_h */
