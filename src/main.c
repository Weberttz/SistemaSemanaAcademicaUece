#include "../include/abb.h"
#include <stdio.h>
#include <string.h>

#define MAX_CARACTERES 100

int main(){

    char comando[MAX_CARACTERES];
    int rodando = 1;

    NoArvore *noArvore = NULL;

    while(rodando && scanf("%s", comando) != EOF){
        // strcmp retorna 0 se as strings forem idênticas
        if(strcmp(comando, "CRIAR") == 0){
            int codigo, capacidade;
            char nome[MAX_CARACTERES];
            scanf("%d", &codigo);
            scanf("%d", &capacidade);
            scanf("%s", nome);
            // criar atividade, utilizando encapsulamento
            noArvore = criarNoArvore(codigo, capacidade, nome);
        }
        else  if (strcmp(comando, "INSCREVER") == 0) {
            int matricula, codigo; char nome[MAX_CARACTERES];
            scanf("%d", &codigo);
            scanf("%d", &matricula);
            scanf("%s", nome);

            int result = inscreverEstudante(noArvore, codigo, matricula, nome);

            printf("%d\n", result);
        }
        else if (strcmp(comando, "IMPRIMIR") == 0) {
        }
        else if (strcmp(comando, "FIM") == 0) {
            rodando = 0;
        }
        else {
            // printf("Comando invalido: %s\n", comando);
        }
    }
    
    return 0;
}