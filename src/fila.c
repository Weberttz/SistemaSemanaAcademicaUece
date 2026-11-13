#include "../include/fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Estudante *Estudante;
    No *prox;
}No;

typedef struct {
    No *inicio;
    No *fim;
}Fila; 

typedef struct{
    int matricula;
    char nome[100];
}Estudante;

void inicializarFila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
}
int isVazia(Fila *f){
    return (f->inicio == NULL);
}

Estudante *inserirFila(Fila *f, Estudante *estudante){
    No *novoNo = malloc(sizeof(No));
    novoNo->Estudante = estudante;
    novoNo->prox = NULL;
    
    if(isVazia(f)){
        f->inicio = novoNo;
        f->fim = novoNo;
    }else{
        f->fim->prox = novoNo;
        f->fim = novoNo;
    }
    return estudante;
}
int removerFila(Fila *f, Estudante *removido){
    if(isVazia(f)){
        printf("\nFila vazia!");
        return 0;
    }
    No *noRemovido = f->inicio;
    removido = noRemovido->Estudante;
    f->inicio = noRemovido->prox;
    if(f->inicio == NULL){
        f->fim = NULL;
    }

    free(noRemovido);
    return 1;
}

Estudante *consultarPrimeiro(Fila *f){
    return f->inicio;
}