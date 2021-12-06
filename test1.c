#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define help "help: Imprime os comandos disponíveis.\n\
quit: Termina o programa.\n\
set: Adiciona ou modifica o valor a armazenar.\n\
print: Imprime todos os caminhos e valores.\n\
find: Imprime o valor armazenado.\n\
list: Lista todos os componentes imediatos de um sub-caminho.\n\
search: Procura o caminho dado um valor.\n\
delete: Apaga um caminho e todos os subcaminhos.\n"
#define local_key(A,B) A->local[B]
#define eq(A,B) (!strcmp(A,B))

typedef struct node {
    int count, profundidade;
    char** local;
    char** caminho;
    char** valor;
    struct node** child;
} *Item;

int local_do_caminho(Item node, char local[]){
    int i;
    for (i = 0; i < node->count; i++) {
        if (eq(local_key(node, i), local))
            return i;
    }
    return -1;
}

void cmd_set(Item node, char *caminho, char *valor) {
    char *local;
    char c[2] = "/";
    int index = 0;
    Item destino;
    
    local = strtok(caminho, c);
        
    /* walk through other tokens */
    while( local != NULL ) {
        if ((index = local_do_caminho(node, caminho)) < 0) {
            if (!node->count) {
                node->count++;
                node->local = (char**) malloc(sizeof(char));
                node->valor = (char**) malloc(sizeof(char));
                node->local[0] = (char*) malloc(sizeof(char)*(strlen(local)+1));
                node->local[0] = strdup(local);
                node->child = (Item*) malloc(sizeof(Item));
                node->child[0] = (Item) malloc(sizeof(struct node));
                destino = node;
                node = node->child[0];
                index = 0;
            }
            else {
                node->count++;
                node->local = (char**) realloc(node->local,(node->count) * sizeof(char));
                node->valor = (char**) realloc(node->local,(node->count) * sizeof(char));
                node->local[node->count-1] = (char*) malloc(sizeof(char)*(strlen(local)+1));
                node->local[node->count-1] = strdup(local);
                node->child = (Item*) realloc(node->child ,(node->count) * sizeof(Item));
                node->child[node->count-1] = (Item) malloc(sizeof(struct node));
                destino = node;
                node = node->child[node->count-1];
                index = node->count-1;
                
            }
        }
        else {
            destino = node;
        }
        local = strtok(NULL, c);
    }
    if (destino->valor[index] == NULL) {
        destino->valor[index] = (char*) malloc(sizeof(char)*(strlen(valor)+1));
        destino->valor[index] = strdup(valor);
        printf("%s\n", destino->valor[index]);
    }
    else {
        destino->valor[index] = (char*) realloc(node->valor[index], sizeof(char)*(strlen(valor)+1));
        destino->valor[index] = strdup(valor);
        printf("%s\n", node->valor[index]);
    }
    
    return;
}

int main () {
    char buffer[65535], comando[7], caminho[65535], valor[65535], temp;
    struct node* root;
    
    root = (struct node*) malloc(sizeof(struct node));
    root->local = (char**) malloc(1 * sizeof(char));
    root->caminho = (char**) malloc(1 * sizeof(char));
    
    
    fgets(buffer, 65535, stdin);
    sscanf(buffer, "%s", comando);
    
    while (strcmp(comando, "quit")) {
        if (!strcmp(comando, "help")) {
            printf("%s", help);
            fgets(buffer, 65535, stdin);
            sscanf(buffer, "%s", comando);
            continue;
        }
        else if (!strcmp(comando, "set")) {
            sscanf(buffer, "%s%s %[^\n]", comando, caminho, valor);
            cmd_set(root, caminho, valor);
            fgets(buffer, 65535, stdin);
            sscanf(buffer, "%s", comando);
            continue;
        }
        else if (!strcmp(comando, "print")) {
            printf("%s\n", comando);
            fgets(buffer, 65535, stdin);
            sscanf(buffer, "%s", comando);
            continue;
        }
        else if (!strcmp(comando, "find")) {
            sscanf(buffer, "%s%s", comando, caminho);
            printf("%s\n%s\n", comando,caminho);
            fgets(buffer, 65535, stdin);
            sscanf(buffer, "%s", comando);
            continue;
        }
        else if (!strcmp(comando, "list")) {
            sscanf(buffer, "%s%c", comando, &temp);
            switch (temp) {
                case ' ':
                    sscanf(buffer, "%s%s", comando, caminho);
                    printf("%s\n%s\n", comando,caminho);
                    fgets(buffer, 65535, stdin);
                    sscanf(buffer, "%s", comando);
                    break;
                    
                default:
                    printf("%s\n", comando);
                    fgets(buffer, 65535, stdin);
                    sscanf(buffer, "%s", comando);
                    break;
            }
            continue;
        }
        else if (!strcmp(comando, "search")) {
            sscanf(buffer, "%s %[^\n]", comando, valor);
            printf("%s\n%s\n", comando,valor);
            fgets(buffer, 65535, stdin);
            sscanf(buffer, "%s", valor);
            continue;
        }
        else if (!strcmp(comando, "delete")) {
            printf("%s\n", comando);
            fgets(buffer, 65535, stdin);
            sscanf(buffer, "%s", comando);
            continue;
        }
    }
   return(0);
}
    
/*
int gh(){
    char str[80] = "tests segundo teste";
    char t[90], ty[90];
    const char s[2] = "/";
    char *token;
    
    struct node* root;
    root = (struct node*) malloc(sizeof(struct node));
    
    root->count = 2;
    root->profundidade = 0;
    
    sscanf(str, "%[^ ] %[^/0]", t, ty);
    printf("%s + %s\n", t, ty);
   */
    /*root->count++;*/
/*
    root->local = (char**) malloc((root->count) * sizeof(char));
    root->local[0] = strdup(t);*//*
    root->local[0] = (char*) malloc(sizeof(char)*(strlen(t)+1));
    strcpy(root->local[0], t);*/
    /*root->local[0] = strdup(t);*/
    /*
    root->caminho = (char**) malloc((root->count) * sizeof(ty));
    root->caminho[0] = strdup(ty); *//*
    root->caminho[0] = (char*) malloc(sizeof(char)*(strlen(ty)+1));
    strcpy(root->caminho[0], ty); */
    /*root->caminho[0] = strdup(ty);*/
    /*
    printf("%d\n%d\n%s\n%s\n", root->count,root->profundidade,root->local[0],root->caminho[0]);*/
/*
    token = strtok(t, s);
        */
       /* walk through other tokens *//*
       while( token != NULL ) {
          printf( " %s\n", token );
        
          token = strtok(NULL, s);
       }
   *//*
}*/
