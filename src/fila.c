#include "../include/fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    EstudantePtr estudante;
    struct No *prox;
} No;

struct Fila
{
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

// Função auxiliar

static No *buscarElementoEmFila(FilaPtr f, int matricula)
{
    No *aux = f->inicio;

    while (aux != NULL)
    {
        if (aux->estudante->matricula == matricula)
            return aux;

        aux = aux->prox;
    }

    return NULL;
}

// Criação e inicialização

FilaPtr criarFila(void)
{
    FilaPtr f = malloc(sizeof(struct Fila));

    if (f != NULL)
        inicializarFila(f);

    return f;
}

void inicializarFila(FilaPtr f)
{
    if (f == NULL)
        return;

    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

// Consultas

int isVazia(const FilaPtr f)
{
    return f == NULL || f->inicio == NULL;
}

int tamanhoFila(const FilaPtr f)
{
    if (f == NULL)
        return 0;

    return f->tamanho;
}

EstudantePtr buscarEstudanteEmFila(FilaPtr f, const int matricula)
{
    if (f == NULL)
        return NULL;

    No *aux = buscarElementoEmFila(f, matricula);

    if (aux == NULL)
        return NULL;

    return aux->estudante;
}

EstudantePtr consultarPrimeiro(FilaPtr f)
{
    if (isVazia(f))
        return NULL;

    return f->inicio->estudante;
}

// Impressão

int imprimirFila(FilaPtr f)
{
    if (isVazia(f))
        return 0;

    No *aux = f->inicio;

    while (aux != NULL)
    {
        printf("%d ", aux->estudante->matricula);
        aux = aux->prox;
    }

    printf("\n");
    return 1;
}

// Inserção

int inserirFila(FilaPtr f, EstudantePtr estudante)
{
    if (f == NULL || estudante == NULL)
        return 0;

    No *novoNo = malloc(sizeof(No));

    if (novoNo == NULL)
        return 0;

    novoNo->estudante = estudante;
    novoNo->prox = NULL;

    if (isVazia(f))
    {
        f->inicio = novoNo;
    }
    else
    {
        f->fim->prox = novoNo;
    }

    f->fim = novoNo;
    f->tamanho++;

    return 1;
}

// Remoção do primeiro elemento

int removerFila(FilaPtr f, EstudantePtr *removido)
{
    if (isVazia(f))
        return 0;

    No *noRemovido = f->inicio;

    if (removido != NULL)
        *removido = noRemovido->estudante;

    f->inicio = noRemovido->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    free(noRemovido);
    f->tamanho--;

    return 1;
}

// Remoção de estudante específico

int removerEsperaFila(FilaPtr f, const int matricula)
{
    if (isVazia(f))
        return 0;

    No *alvo = buscarElementoEmFila(f, matricula);

    if (alvo == NULL)
        return 0;

    if (f->inicio == alvo)
    {
        f->inicio = alvo->prox;

        if (f->inicio == NULL)
            f->fim = NULL;
    }
    else
    {
        No *aux = f->inicio;

        while (aux->prox != alvo)
            aux = aux->prox;

        aux->prox = alvo->prox;

        if (f->fim == alvo)
            f->fim = aux;
    }

    free(alvo);
    f->tamanho--;

    return 1;
}

// Remoção de todos os nós

int deletarTudoFila(FilaPtr f)
{
    if (f == NULL)
        return 0;

    No *aux = f->inicio;

    while (aux != NULL)
    {
        No *removido = aux;
        aux = aux->prox;

        free(removido);
    }

    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;

    return 1;
}

// Destruição da fila

int destruirFila(FilaPtr f)
{
    if (f == NULL)
        return 0;

    deletarTudoFila(f);
    free(f);

    return 1;
}
