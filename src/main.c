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
            if(scanf("%d", &codigo) == 0) return 0;
            if(scanf("%d", &capacidade) == 0) return 0;
            if(scanf("%s", nome) == 0) return 0;
            // criar atividade, utilizando encapsulamento
            AtividadePtr atividade = buscarAtividade(raiz, codigo);
            if(atividade != NULL) {
                printf("ERRO ATIVIDADE_EXISTE");
                return 0;
            }
            AtividadePtr a = criarAtividade(codigo, capacidade, nome);
            raiz = inserirAtividadeNaArvore(raiz, a);
        }
        else  if (strcmp(comando, "INSCREVER") == 0) {
            int matricula, codigo; char nome[MAX_CARACTERES];
            if(scanf("%d", &codigo) == 0) return 0;
            if(scanf("%d", &matricula) == 0) return 0;
            if(scanf("%s", nome) == 0) return 0;
            
            AtividadePtr a = buscarAtividade(raiz, codigo);
            int resultado = inscreverEstudante(a, matricula, nome);

            if(resultado) printf("OK INSCRITO %d %s\n", matricula, nome);
        }
        else if (strcmp(comando, "BUSCAR") == 0){
            int codigo;
            if(scanf("%d", &codigo) == 0) return 0;
            AtividadePtr atividade = buscarAtividade(raiz, codigo);
            imprimirDados(atividade);      
        }
        else if (strcmp(comando, "IMPRIMIR") == 0) {
            preOrdem(raiz);
        }
        else if(strcmp(comando, "AUMENTAR") == 0){
            int codigo, incremento;
            if(scanf("%d", &codigo) == 0) return 0;
            if(scanf("%d", &incremento) == 0) return 0;

            AtividadePtr a = buscarAtividade(raiz, codigo);
            int resultado = aumentarCapacidade(a, incremento);

            if(resultado) printf("OK AUMENTAR %d %d %d\n", codigo, getCapacidade(a) ,incremento);
        }
        else if (strcmp(comando, "FIM") == 0) {
            rodando = 0;
        }
    }

    liberarArvore(raiz);

    return 0;
}