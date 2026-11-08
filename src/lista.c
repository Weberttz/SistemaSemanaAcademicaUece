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
        printf("Erro na alocação do novo Nó!\n");
        return 0;
    }

    No *no_busca = buscarElemento(lista, estudante.matricula);

    if(no_busca != NULL){
        printf("Um estudante com essa matrícula já existe na lista!\n");
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

    No *no_busca = buscarElemento(lista, estudante.matricula);
    if(no_busca != NULL){
        printf("Um estudante com essa matrícula já existe na lista\n");
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
        printf("Lista vazia!\n");
        return 0;
    }

    Estudante estudante;
    while(aux != NULL){
        estudante = aux->estudante;
        printf("Matrícula: %d\n", estudante.matricula);
        printf("Nome: %s\n", estudante.nome);
        aux = aux->prox;
    }

    return 1;
}

No *buscarElemento(ListaEncadeada *lista, int matricula){
    No *aux = lista->inicio;

    if(listaVazia(lista)) {
        printf("Lista vazia!\n");
        return NULL;
    }
    
    while(aux != NULL){
        if (aux->estudante.matricula == matricula)
            return aux;
        aux = aux->prox;
    }

    return NULL;
}

int alterarElemento(ListaEncadeada *lista, int matriculaEstudanteSubstiuido, Estudante estudanteNovo){
    No *no_substiuido = buscarElemento(lista, matriculaEstudanteSubstiuido);

    if(no_substiuido == NULL) {
        printf("Estudante não foi encontrado, proibido alterar!");
        return 0;
    }

    no_substiuido->estudante = estudanteNovo;
    return 1;
}

int deletarUmElemento(ListaEncadeada *lista, int matricula){
    No *alvo = buscarElemento(lista, matricula);
    No *aux = lista->inicio;

    if(alvo == NULL) {
        printf("Estudante não encontrado, proibido deletar!");
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