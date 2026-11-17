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

static No *buscarElementoEmFila(FilaPtr l, int matricula){
    No *aux = l->inicio;
    
    while(aux != NULL){
        if (aux->estudante->matricula == matricula)
            return aux;
        aux = aux->prox;
    }

    return NULL;
}

FilaPtr criarFila(void){
    FilaPtr f = malloc(sizeof(Fila));
    if (f != NULL) {
       inicializarFila(f);
    }
    return f;
}

EstudantePtr buscarEstudanteEmFila(FilaPtr fila, const int matricula){
    No *aux = fila->inicio;
    
    while(aux != NULL){
        if (aux->estudante->matricula == matricula)
            return aux->estudante;
        aux = aux->prox;
    }

    return NULL;
}

void inicializarFila(FilaPtr f){
    f->inicio = NULL;
    f->fim = NULL;
}
int isVazia(FilaPtr f){
    return (f->inicio == NULL);
}

int imprimirFila(FilaPtr f){
    No *aux = f->inicio;

    if(isVazia(f)) return 0;

    EstudantePtr estudante;
    while(aux != NULL){
        estudante = aux->estudante;
        printf("%d ", estudante->matricula);
        aux = aux->prox;
    }

    return 1;
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
int removerFila(FilaPtr f, EstudantePtr *removido){
    if(isVazia(f)){
        return 0;
    }
    No *noRemovido = f->inicio;
    *removido = noRemovido->estudante;
    f->inicio = noRemovido->prox;
    if(f->inicio == NULL){
        f->fim = NULL;
    }

    free(noRemovido);
    return 1;
}

int removerEsperaFila(FilaPtr f, const int matricula){
    No *alvo = buscarElementoEmFila(f, matricula);
    No *aux = f->inicio;

    if(alvo == NULL) {
        return 0;
    }

    // Se alvo está no início da lista, libera corretamente
    if(f->inicio == alvo){
        f->inicio = alvo->prox;
        free(alvo->estudante);
        free(alvo);
        alvo = NULL;
        return 1;
    }

    // Se alvo está na cauda da lista
    while(aux != NULL && aux->prox !=alvo){
        aux = aux->prox;
    }

    if(aux == NULL) {
        return 0;
    }
    aux->prox = alvo->prox;
    free(alvo->estudante);
    free(alvo);
    if(aux->prox == NULL) f->fim = aux;

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