#include "../include/abb.h"
#include <stdio.h>
#include <string.h>

#define MAX_CARACTERES 100

/*typedef struct Estrutura{
    char comando[MAX_CARACTERES];
    void *ptr;
}Estrutura;*/

int main(){

    char comando[MAX_CARACTERES];
    int rodando = 1;

    NoArvore *raiz = NULL;

    /* int qnt = 3;
    Estrutura estrutura[3] = {
        {"CRIAR", },{"INSCREVER", },{"FIM", }
    };

    for(int i=0; i<qnt; i++){
        if (stcmp(comando, strs[i]) == 0){

        }
    }*/
    
    while(rodando && scanf("%s", comando) != EOF){
        // strcmp retorna 0 se as strings forem idênticas
        if(strcmp(comando, "CRIAR") == 0){
            int codigo, capacidade;
            char nome[MAX_CARACTERES];
            scanf("%d", &codigo);
            scanf("%d", &capacidade);
            scanf("%s", nome);
            // criar atividade, utilizando encapsulamento
            AtividadePtr a = criarAtividade(codigo, capacidade, nome);
            raiz = inserirAtividadeNaArvore(raiz, a);
        }
        else  if (strcmp(comando, "INSCREVER") == 0) {
            int matricula, codigo; char nome[MAX_CARACTERES];
            scanf("%d", &codigo);
            scanf("%d", &matricula);
            scanf("%s", nome);
            
            AtividadePtr a = buscarAtividade(raiz, codigo);
            int result = inscreverEstudante(a, matricula, nome);

            printf("%d\n", result);
        }
        else if (strcmp(comando, "IMPRIMIR") == 0) {
            preOrdem(raiz);
        }
        else if(strcmp(comando, "AUMENTAR") == 0){
            int codigo, nova_capacidade;
            scanf("%d", &codigo);
            scanf("%d", &nova_capacidade);

            AtividadePtr a = buscarAtividade(raiz, codigo);
            

            // printf("Comando invalido: %s\n", comando);
        }
        else if (strcmp(comando, "FIM") == 0) {
            rodando = 0;
        }
    }

    liberarArvore(raiz);

    return 0;
}