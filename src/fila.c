#include "../include/fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Estudante{
    int matricula;
    char nome[100];
}Estudante;

typedef struct No{
    EstudantePtr estudante;
    No *prox;
}No;

typedef struct Fila{
    No *inicio;
    No *fim;
}Fila; 

FilaPtr criarFila(void){
    FilaPtr f = malloc(sizeof(Fila));
    if (f != NULL) {
       inicializarFila(f);
    }
    return f;
}

void inicializarFila(FilaPtr f){
    f->inicio = NULL;
    f->fim = NULL;
}
int isVazia(FilaPtr f){
    return (f->inicio == NULL);
}

int inserirFila(FilaPtr f, EstudantePtr estudante){
    No *novoNo = malloc(sizeof(No));
    novoNo->estudante = estudante;
    novoNo->prox = NULL;
    
    if(isVazia(f)){
        f->inicio = novoNo;
        f->fim = novoNo;
    }else{
        f->fim->prox = novoNo;
        f->fim = novoNo;
    }
    return 1;
}
int removerFila(FilaPtr f, EstudantePtr removido){
    if(isVazia(f)){
        printf("\nFila vazia!");
        return 0;
    }
    No *noRemovido = f->inicio;
    removido = noRemovido->estudante;
    f->inicio = noRemovido->prox;
    if(f->inicio == NULL){
        f->fim = NULL;
    }

    free(noRemovido);
    return 1;
}

EstudantePtr consultarPrimeiro(FilaPtr f){
    return f->inicio->estudante;
}

int deletarTudoFila(FilaPtr f){
    No *aux = f->inicio;

    if (isVazia(f)) return 0;

    while (aux != NULL) {
        f->inicio = aux->prox;
        free(aux->estudante);
        free(aux);
        aux = f->inicio;
    }

    free(aux);

    return 1;
}

int destruirFila(FilaPtr f){
    deletarTudoFila(f);
    f->inicio = NULL;
    f->fim = NULL;
    free(f);
    f = NULL;
    return 1;
}