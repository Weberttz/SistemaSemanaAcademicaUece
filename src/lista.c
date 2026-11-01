#include <stdio.h>
#include <stdlib.h>
#include "../include/lista.h"

typedef struct No{
    Estudante estudante;
    struct No *prox;
}No;

struct ListaEncadeada{
    No *inicio;
    size_t tamanho;
};

ListaEncadeada *criarLista(){
    ListaEncadeada *nova = (ListaEncadeada*) malloc(sizeof(ListaEncadeada));
    if (nova != NULL) {
        nova->inicio = NULL;
        nova->tamanho = 0;
    }
    return nova;
}

int inicializarLista(ListaEncadeada *lista){
   lista->inicio = NULL;
   lista->tamanho = 0;
   return 1;
}

int listaVazia(ListaEncadeada *lista){
    return (lista->inicio == NULL)?1:0;
}

int inserirNoInicio(ListaEncadeada *lista, Estudante estudante){
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro na alocação do novo Nó!");
        return 0;
    }

    novo->estudante = estudante;
    novo->prox = lista->inicio;

    lista->inicio = novo;
    return 1;
}

int inserirNoFinal(ListaEncadeada *lista, Estudante estudante){
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro na alocação do novo Nó!");
        return 0;
    }

    novo->estudante = estudante;
    novo->prox = NULL;

    if(listaVazia(lista)) {
        lista->inicio = novo;
        return 1;
    }

    No *aux = lista->inicio;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }

    aux->prox = novo;
    return 1;
}

int imprimirLista(ListaEncadeada *lista){
    No *aux = lista->inicio;

    if(listaVazia(lista)){
        printf("Lista vazia!");
        return 0;
    }

    Estudante estudante = aux->estudante;
    while(aux != NULL){
        printf("Matrícula: %d\n", estudante.matricula);
        printf("Nome: %s\n", estudante.nome);
        aux = aux->prox;
    }

    return 1;
}

No *buscarElemento(ListaEncadeada *lista, Estudante estudante){
    No *aux = lista->inicio;

    if(listaVazia(lista)) {
        printf("Lista vazia!");
        return NULL;
    }
    
    while(aux != NULL){
        if (aux->estudante.matricula == estudante.matricula)
            return aux;
    }

    return NULL;
}

int alterarElemento(ListaEncadeada *lista, Estudante estudanteSubstiuido, Estudante estudanteNovo){
    No *no_substiuido = buscarElemento(lista, estudanteSubstiuido);

    if(no_substiuido == NULL) {
        printf("Elemento não foi encontrado, proibido alterar!");
        return 0;
    }

    no_substiuido->estudante = estudanteNovo;
    return 1;
}

int deletarUmElemento(ListaEncadeada *lista, Estudante estudante){
    No *alvo = buscarElemento(lista, estudante);
    No *aux = lista->inicio;

    if(alvo == NULL) {
        printf("Elemento não encontrado, proibido deletar!");
        return 0;
    }

    if(lista->inicio == alvo){
        lista->inicio = alvo->prox;
        free(alvo);
        alvo = NULL;
        return 1;
    }

    while(aux != NULL && aux->prox !=alvo){
        aux = aux->prox;
    }

    if(aux == NULL) {
        printf("Erro interno ao remover");
        return 0;
    }
    aux->prox = alvo->prox;
    free(alvo);
    return 1;
}

int deletarTudo(ListaEncadeada *lista){
    No *aux = lista->inicio;

    if (listaVazia(lista)) {
        printf("Lista vazia!");
        return 0;
    }

    while (aux != NULL) {
        lista->inicio = aux->prox;
        free(aux);
        aux = lista->inicio;
    }

    return 1;
}

int inserirOrdenado(ListaEncadeada *lista, Estudante estudante){
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("\nErro: memoria insuficiente!");
        return 0;
    }
    novo->estudante = estudante;
    novo->prox = NULL;

    // caso lista vazia ou entra antes do primeiro
    if (lista->inicio == NULL || estudante.matricula < lista->inicio->estudante.matricula) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        return 1;
    }
    // acha posição: aux para no nó anterior ao ponto de inserção
    No *aux = lista->inicio;
    while (aux->prox != NULL && aux->prox->estudante.matricula <= estudante.matricula) {
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