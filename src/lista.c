#include "../include/lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTERES 100

typedef struct No
{
    EstudantePtr estudante;
    struct No *prox;
} No;

typedef struct ListaInscritos
{
    No *inicio;
    No *fim;
    size_t tamanho;
} ListaInscritos;

static int inicializarLista(ListaPtr l);

static No *buscarElemento(ListaPtr l, int matricula)
{
    No *aux = l->inicio;

    while (aux != NULL)
    {
        if (getMatricula(aux->estudante) == matricula)
            return aux;
        aux = aux->prox;
    }

    return NULL;
}

EstudantePtr buscarEstudanteEmLista(ListaPtr l, int matricula)
{
    No *aux = l->inicio;

    while (aux != NULL)
    {
        if (getMatricula(aux->estudante) == matricula)
            return aux->estudante;
        aux = aux->prox;
    }

    return NULL;
}

ListaPtr criarLista()
{
    ListaPtr l = malloc(sizeof(ListaInscritos));
    if (l != NULL)
    {
        inicializarLista(l);
    }
    return l;
}

static int inicializarLista(ListaPtr l)
{
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
    return 1;
}

static int listaVazia(ListaPtr l)
{
    return (l->inicio == NULL) ? 1 : 0;
}

int inserirNoFinal(ListaPtr l, EstudantePtr estudante)
{
    No *no_busca = buscarElemento(l, getMatricula(estudante));
    if (no_busca != NULL)
    {
        printf("ERRO ALUNO_DUPLICADO\n");
        return 0;
    }

    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        return 0;
    }

    novo->estudante = estudante;
    if (novo->estudante == NULL)
        return 0;
    novo->prox = NULL;

    if (listaVazia(l))
    {
        l->inicio = novo;
        l->fim = novo;
        return 1;
    }

    l->fim->prox = novo;
    l->fim = novo;
    return 1;
}

int imprimirLista(ListaPtr l)
{
    No *aux = l->inicio;

    if (listaVazia(l))
        return 0;

    EstudantePtr estudante;
    while (aux != NULL)
    {
        estudante = aux->estudante;
        printf("%d ", getMatricula(estudante));
        aux = aux->prox;
    }

    return 1;
}

int removerInscritoLista(ListaPtr l, const int matricula)
{
    No *alvo = buscarElemento(l, matricula);
    No *aux = l->inicio;

    if (alvo == NULL)
    {
        return 0;
    }

    // Se alvo está no início da lista, libera corretamente
    if (l->inicio == alvo)
    {
        l->inicio = alvo->prox;
        free(alvo->estudante);
        free(alvo);
        alvo = NULL;
        return 1;
    }

    // Se alvo está na cauda da lista
    while (aux != NULL && aux->prox != alvo)
    {
        aux = aux->prox;
    }

    if (aux == NULL)
    {
        return 0;
    }
    aux->prox = alvo->prox;
    free(alvo->estudante);
    free(alvo);
    if (aux->prox == NULL)
        l->fim = aux;

    return 1;
}

static int deletarTudoLista(ListaPtr l)
{
    No *aux = l->inicio;

    if (listaVazia(l))
        return 0;

    while (aux != NULL)
    {
        l->inicio = aux->prox;
        free(aux->estudante);
        free(aux);
        aux = l->inicio;
    }

    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;

    return 1;
}

void destruirLista(ListaPtr *l)
{
    if (l == NULL || *l == NULL)
        return;
    deletarTudoLista(*l);
    free(*l);
    *l = NULL;
}