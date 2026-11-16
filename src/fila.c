#include "../include/fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    Estudante *Estudante;
    struct No *prox;
    // qnd um struct se auto-referencia ele deve chamar a si mesmo como struct {nome}
} No;

typedef struct Fila
{
    No *inicio;
    No *fim;
    int tamanho;
};

Fila *inicializarFila(void)
{
    Fila *fila = malloc(sizeof(Fila));
    if (fila == NULL)
        return NULL;
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

int isVazia(const Fila *f)
{
    return (f->inicio == NULL);
}
int tamanhoFila(const Fila *f)
{
    return f->tamanho;
}

Estudante *inserirFila(Fila *f, Estudante **estudante)
{
    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL)
    {
        retun NULL;
    }
    novoNo->Estudante = estudante;
    novoNo->prox = NULL;

    if (isVazia(f))
    {
        f->inicio = novoNo;
        f->fim = novoNo;
    }
    else
    {
        f->fim->prox = novoNo;
        f->fim = novoNo;
    }
    f->tamanho++;
    return estudante;
}
int removerFila(Fila *f, Estudante **removido)
{
    if (isVazia(f))
    {
        return 0;
    }
    No *noRemovido = f->inicio;
    *removido = noRemovido->Estudante;
    f->inicio = noRemovido->prox;
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    free(noRemovido);
    f->tamanho--;
    return 1;
}
void destruirFila(Fila *f)
{

    while (f->inicio != NULL)
    {
        No *noRemovido = f->inicio;
        f->inicio = noRemovido->prox;
        free(noRemovido);
    }

    free(f);
}

Estudante *consultarPrimeiro(const Fila *f)
{
    if (isVazia(f))
        return f->inicio->Estudante;
}