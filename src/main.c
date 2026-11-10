#include <stdio.h>
#include <string.h>
#include "../include/lista.h"

int main(){

    char comando[MAX_CARACTERES];
    int rodando = 1;

    // criar lista, utilizando encapsulamento
    ListaEncadeada *lista = criarLista();

    if(lista == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    while(rodando && scanf("%s", comando) != EOF){
        // strcmp retorna 0 se as strings forem idênticas
        if (strcmp(comando, "INSCREVER") == 0) {
            int matricula; char nome[60];
            scanf("%d", &matricula);
            scanf("%s", nome);
            
            inserirNoFinal(lista, matricula, nome);
        }
        else if (strcmp(comando, "IMPRIMIR") == 0) {
            imprimirLista(lista);
        }
        else if (strcmp(comando, "FIM") == 0) {
            rodando = 0;
        }
        else {
            // printf("Comando invalido: %s\n", comando);
        }
    }

    finalizarLista(lista);
    
    return 0;
}