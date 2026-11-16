#include <stdio.h>
#include <stdlib.h>
#include "../include/lista.h"

#define MAX_CARACTERES 100

typedef struct No
{
    EstudantePtr estudante;
    struct No *prox;
} No;

typedef struct ListaEncadeada
{
    No *inicio;
    size_t tamanho;
};

static No *buscarElemento(ListaPtr l, int matricula)
{
    No *aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->estudante->matricula == matricula)
            return aux;
        aux = aux->prox;
    }
    return nova;
}

EstudantePtr buscarEstudanteEmLista(ListaPtr l, int matricula)
{
    No *aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->estudante->matricula == matricula)
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

int inicializarLista(ListaPtr l)
{
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
    return 1;
}

int listaVazia(ListaPtr l)
{
    return (l->inicio == NULL) ? 1 : 0;
}

int inserirNoInicio(ListaPtr l, EstudantePtr estudante)
{
    No *no_busca = buscarElemento(l, estudante->matricula);
    if (no_busca != NULL)
    {
        printf("ERRO ALUNO_DUPLICADO\n");
        return 0;
    }

    No *novo = malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("ERRO MEMÓRIA\n");
        return 0;
    }

    novo->estudante = estudante;

    if (novo->estudante == NULL)
        return 0;

    // Se a lista estiver vazia, ao inserir no inicio, ambos os ponteiros devem apontar para o Nó
    if (listaVazia(l))
        l->fim = novo;

    novo->prox = l->inicio;

    l->inicio = novo;
    return 1;
}

int inserirNoFinal(ListaPtr l, EstudantePtr estudante)
{
    No *no_busca = buscarElemento(l, estudante->matricula);
    if (no_busca != NULL)
    {
        printf("ERRO ALUNO_DUPLICADO\n");
        return 0;
    }

    int inserirNoInicio(ListaEncadeada * lista, Estudante estudante)
    {
        No *novo = malloc(sizeof(No));
        if (novo == NULL)
        {
            printf("Erro na alocação do novo Nó!\n");
            return 0;
        }

        novo->estudante = estudante;
        if (novo->estudante == NULL)
            return 0;
        novo->prox = NULL;

        if (listaVazia(lista))
        {
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

    int imprimirLista(ListaEncadeada * lista)
    {
        No *aux = lista->inicio;

        if (listaVazia(lista))
        {
            printf("Lista vazia!\n");
            return 0;
        }

        EstudantePtr estudante;
        while (aux != NULL)
        {
            estudante = aux->estudante;
            printf("%d ", estudante->matricula);
            aux = aux->prox;
        }

        return 1;
    }

    int alterarElemento(ListaPtr l, const int matriculaEstudanteSubstituido, EstudantePtr estudante)
    {
        No *no_substiuido = buscarElemento(l, matriculaEstudanteSubstituido);

        if (listaVazia(lista))
        {
            printf("Lista vazia!\n");
            return NULL;
        }

        while (aux != NULL)
        {
            if (aux->estudante.matricula == estudante.matricula)
                return aux;
            aux = aux->prox;
        }

        return NULL;
    }

    int alterarElemento(ListaEncadeada * lista, Estudante estudanteSubstiuido, Estudante estudanteNovo)
    {
        No *no_substiuido = buscarElemento(lista, estudanteSubstiuido);

        if (no_substiuido == NULL)
        {
            printf("Elemento não foi encontrado, proibido alterar!");
            return 0;
        }

        no_substiuido->estudante = estudante;
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

        while (aux != NULL && aux->prox != alvo)
        {
            aux = aux->prox;
        }

        if (aux == NULL)
        {
            printf("Erro interno ao remover");
            return 0;
        }
        aux->prox = alvo->prox;
        free(alvo->estudante);
        free(alvo);
        return 1;
    }

    int deletarTudoLista(ListaPtr l)
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

    void destruirLista(ListaPtr * l)
    {
        if (l == NULL || *l == NULL)
            return;
        deletarTudoLista(*l);
        free(*l);
        *l = NULL;
    }