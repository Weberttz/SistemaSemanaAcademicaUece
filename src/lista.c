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

struct ListaEncadeada{
    No *inicio;
    No *fim;
    size_t tamanho;
};

static No *buscarElemento(ListaEncadeada *lista, int matricula){
    No *aux = lista->inicio;
    
    while(aux != NULL){
        if (aux->estudante.matricula == matricula)
            return aux;
        aux = aux->prox;
    }

    return NULL;
}

ListaEncadeada *criarLista(){
    ListaEncadeada *nova = (ListaEncadeada*) malloc(sizeof(ListaEncadeada));
    if (nova != NULL) {
       inicializarLista(nova);
    }
    return nova;
}

Estudante criarEstudante(int matricula, char nome[MAX_CARACTERES]){
    Estudante estudante;
    strcpy(estudante.nome, nome);
    estudante.matricula = matricula;
    return estudante;
}

int inicializarLista(ListaEncadeada *lista){
   lista->inicio = NULL;
   lista->fim = NULL;
   lista->tamanho = 0;
   return 1;
}

int listaVazia(ListaEncadeada *lista){
    return (lista->inicio == NULL)?1:0;
}

int inserirNoInicio(ListaEncadeada *lista, int matricula, char nome[MAX_CARACTERES]){
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("ERRO: MEMÓRIA\n");
        return 0;
    }

    No *no_busca = buscarElemento(lista, matricula);

    if(no_busca != NULL){
        printf("ERRO: ALUNO DUPLICADO\n");
        return 0;
    }

    novo->estudante = criarEstudante(matricula, nome);

    // Se a lista estiver vazia, ao inserir no incio, ambos os ponteiros devem apontar para o Nó
    if(listaVazia(lista)) lista->fim = novo;

    novo->prox = lista->inicio;

    lista->inicio = novo;
    return 1;
}

int inserirNoFinal(ListaEncadeada *lista, int matricula, char nome[MAX_CARACTERES]){
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("ERRO: MEMÓRIA\n");
        return 0;
    }

    No *no_busca = buscarElemento(lista, matricula);
    if(no_busca != NULL){
        printf("ERRO: ALUNO DUPLICADO\n");
        return 0;
    }

    novo->estudante = criarEstudante(matricula, nome);
    novo->prox = NULL;

    if(listaVazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
        return 1;
    }

    lista->fim->prox = novo;
    lista->fim = novo;
    return 1;
}

int imprimirLista(ListaEncadeada *lista){
    No *aux = lista->inicio;

    if(listaVazia(lista)) return 0;

    Estudante estudante;
    while(aux != NULL){
        estudante = aux->estudante;
        printf("Matrícula: %d\n", estudante.matricula);
        printf("Nome: %s\n", estudante.nome);
        aux = aux->prox;
    }

    return 1;
}

int alterarElemento(ListaEncadeada *lista, int matriculaEstudanteSubstituido, int matricula, char nome[MAX_CARACTERES]){
    No *no_substiuido = buscarElemento(lista, matriculaEstudanteSubstituido);

    if(no_substiuido == NULL) {
        printf("ERRO: ALUNO_NAO_ENCONTRADO\n");
        return 0;
    }

    no_substiuido->estudante = criarEstudante(matricula, nome);
    return 1;
}

int deletarUmElemento(ListaEncadeada *lista, int matricula){
    No *alvo = buscarElemento(lista, matricula);
    No *aux = lista->inicio;

    if(alvo == NULL) {
        printf("ERRO: ALUNO_NAO_ENCONTRADO\n");
        return 0;
    }

    // Se alvo está no início da lista, libera corretamente
    if(lista->inicio == alvo){
        lista->inicio = alvo->prox;
        free(alvo);
        alvo = NULL;
        return 1;
    }

    // Se alvo está na cauda da lista
    while(aux != NULL && aux->prox !=alvo){
        aux = aux->prox;
    }

    if(aux == NULL) {
        printf("ERRO: INTERNO_AO_REMOVER\n");
        return 0;
    }
    aux->prox = alvo->prox;
    free(alvo);
    return 1;
}

int deletarTudo(ListaEncadeada *lista){
    No *aux = lista->inicio;

    if (listaVazia(lista)) return 0;

    while (aux != NULL) {
        lista->inicio = aux->prox;
        free(aux);
        aux = lista->inicio;
    }

    return 1;
}

int inserirOrdenado(ListaEncadeada *lista, int matricula, char nome[MAX_CARACTERES]){
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("ERRO: MEMÓRIA\n");
        return 0;
    }
    novo->estudante = criarEstudante(matricula, nome);
    novo->prox = NULL;

    // caso lista vazia ou entra antes do primeiro
    if (lista->inicio == NULL || matricula < lista->inicio->estudante.matricula) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        return 1;
    }
    // acha posição: aux para no nó anterior ao ponto de inserção
    No *aux = lista->inicio;
    while (aux->prox != NULL && aux->prox->estudante.matricula <= matricula) {
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
    return 1;
}

int finalizarLista(ListaEncadeada *lista){
    deletarTudo(lista);
    lista->inicio = NULL;
    lista = NULL;
    return 1;
}