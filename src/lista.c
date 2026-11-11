#include "../include/lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estudante{
    int matricula;
    char nome[100];
}Estudante;

typedef struct No{
    Estudante estudante;
    struct No *prox;
}No;

typedef struct ListaInscritos{
    No *inicio;
    No *fim;
    size_t tamanho;
}ListaInscritos;

static No *buscarElemento(ListaPtr l, int matricula){
    No *aux = l->inicio;
    
    while(aux != NULL){
        if (aux->estudante.matricula == matricula)
            return aux;
        aux = aux->prox;
    }

    return NULL;
}

ListaPtr criarLista(){
    ListaPtr l = malloc(sizeof(ListaInscritos));
    if (l != NULL) {
       inicializarLista(l);
    }
    return l;
}

Estudante criarEstudante(int matricula, const char *nome){
    Estudante estudante;
    snprintf(estudante.nome, MAX_CARACTERES, "%s", nome);
    estudante.matricula = matricula;
    return estudante;
}

int inicializarLista(ListaPtr l){
   l->inicio = NULL;
   l->fim = NULL;
   l->tamanho = 0;
   return 1;
}

int listaVazia(ListaPtr l){
    return (l->inicio == NULL)?1:0;
}

int inserirNoInicio(ListaPtr l, int matricula, const char *nome){
    No *no_busca = buscarElemento(l, matricula);
    if(no_busca != NULL){
        printf("ERRO ALUNO_DUPLICADO\n");
        return 0;
    }

    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("ERRO MEMÓRIA\n");
        return 0;
    }

    novo->estudante = criarEstudante(matricula, nome);

    // Se a lista estiver vazia, ao inserir no inicio, ambos os ponteiros devem apontar para o Nó
    if(listaVazia(l)) l->fim = novo;

    novo->prox = l->inicio;

    l->inicio = novo;
    return 1;
}

int inserirNoFinal(ListaPtr l, int matricula, const char *nome){
    No *no_busca = buscarElemento(l, matricula);
    if(no_busca != NULL){
        printf("ERRO ALUNO_DUPLICADO\n");
        return 0;
    }

    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("ERRO MEMÓRIA\n");
        return 0;
    }

    novo->estudante = criarEstudante(matricula, nome);
    novo->prox = NULL;

    if(listaVazia(l)) {
        l->inicio = novo;
        l->fim = novo;
        return 1;
    }

    l->fim->prox = novo;
    l->fim = novo;
    return 1;
}

int imprimirLista(ListaPtr l){
    No *aux = l->inicio;

    if(listaVazia(l)) return 0;

    Estudante estudante;
    while(aux != NULL){
        estudante = aux->estudante;
        printf("Matrícula: %d\n", estudante.matricula);
        printf("Nome: %s\n", estudante.nome);
        aux = aux->prox;
    }

    return 1;
}

int alterarElemento(ListaPtr l, int matriculaEstudanteSubstituido, int matricula, const char *nome){
    No *no_substiuido = buscarElemento(l, matriculaEstudanteSubstituido);

    if(no_substiuido == NULL) {
        printf("ERRO ALUNO_NAO_ENCONTRADO\n");
        return 0;
    }

    no_substiuido->estudante = criarEstudante(matricula, nome);
    return 1;
}

int deletarUmElemento(ListaPtr l, int matricula){
    No *alvo = buscarElemento(l, matricula);
    No *aux = l->inicio;

    if(alvo == NULL) {
        printf("ERRO ALUNO_NAO_ENCONTRADO\n");
        return 0;
    }

    // Se alvo está no início da lista, libera corretamente
    if(l->inicio == alvo){
        l->inicio = alvo->prox;
        free(alvo);
        alvo = NULL;
        return 1;
    }

    // Se alvo está na cauda da lista
    while(aux != NULL && aux->prox !=alvo){
        aux = aux->prox;
    }

    if(aux == NULL) {
        printf("ERRO INTERNO_AO_REMOVER\n");
        return 0;
    }
    aux->prox = alvo->prox;
    free(alvo);
    if(aux->prox == NULL) l->fim = aux;

    return 1;
}

int deletarTudo(ListaPtr l){
    No *aux = l->inicio;

    if (listaVazia(l)) return 0;

    while (aux != NULL) {
        l->inicio = aux->prox;
        free(aux);
        aux = l->inicio;
    }

    free(aux);

    return 1;
}

int finalizarLista(ListaPtr l){
    deletarTudo(l);
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
    free(l);
    l = NULL;
    return 1;
}