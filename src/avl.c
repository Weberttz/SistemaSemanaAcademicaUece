#include <stdlib.h>
#include "../include/avl.h"
#include "../include/no_arvore.h"
#include "../include/atividade.h"


static int alturaNo(const NoArvore *no) {
    return no == NULL ? -1 : no->alt;
}

static int qntNo(const NoArvore *no) {
    return no == NULL ? 0 : no->qntAtividade;
}

static void atualizar(NoArvore *no) {
    int he = alturaNo(no->esq);
    int hd = alturaNo(no->dir);

    no->alt = 1 + (he > hd ? he : hd);
    no->qntAtividade = 1 + qntNo(no->esq) + qntNo(no->dir);
}

static int fator(const NoArvore *no) {
    return alturaNo(no->esq) - alturaNo(no->dir);
}


static NoArvore *rotacaoDireita(NoArvore *y) {
    NoArvore *x = y->esq;

    y->esq = x->dir;
    x->dir = y;

    atualizar(y);   
    atualizar(x);
    return x;
}

static NoArvore *rotacaoEsquerda(NoArvore *x) {
    NoArvore *y = x->dir;

    x->dir = y->esq;
    y->esq = x;

    atualizar(x);   
    atualizar(y);
    return y;
}

static NoArvore *balancear(NoArvore *no) {
    atualizar(no);

    int fb = fator(no);

    switch (fb) {
        case 2:
            if (fator(no->esq) < 0)
                no->esq = rotacaoEsquerda(no->esq);
            return rotacaoDireita(no);
        case -2:
            if (fator(no->dir) > 0)
                no->dir = rotacaoDireita(no->dir);
            return rotacaoEsquerda(no);
        default:
            return no;
    }
}


static NoArvore *criarNoArvore(AtividadePtr a) {
    if (a == NULL) return NULL;

    NoArvore *novo = malloc(sizeof *novo);
    if (novo == NULL) return NULL;

    novo->atividade = a;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->qntAtividade = 1;
    novo->alt = 0;
    return novo;
}

NoArvore *inserirAtividadeNaArvore(NoArvore *raiz, AtividadePtr atividade) {
    if (atividade == NULL) return raiz;

    if (raiz == NULL)
        return criarNoArvore(atividade);

    int codigoNovo = getCodigo(atividade);
    int codigoRaiz = getCodigo(raiz->atividade);

    if (codigoNovo == codigoRaiz)
        return raiz;                    

    if (codigoNovo < codigoRaiz)
        raiz->esq = inserirAtividadeNaArvore(raiz->esq, atividade);
    else
        raiz->dir = inserirAtividadeNaArvore(raiz->dir, atividade);

    return balancear(raiz);
}


static NoArvore *extrairMinimo(NoArvore *no, AtividadePtr *min) {
    if (no->esq == NULL) {
        NoArvore *dir = no->dir;
        *min = no->atividade;
        free(no);
        return dir;
    }

    no->esq = extrairMinimo(no->esq, min);
    return balancear(no);
}

NoArvore *removerAtividadeDaArvore(NoArvore *raiz, const int codigo) {
    if (raiz == NULL) return NULL;      

    int c = getCodigo(raiz->atividade);

    if (codigo < c) {
        raiz->esq = removerAtividadeDaArvore(raiz->esq, codigo);
    } else if (codigo > c) {
        raiz->dir = removerAtividadeDaArvore(raiz->dir, codigo);
    } else {
        if (raiz->esq == NULL || raiz->dir == NULL) {
            NoArvore *filho = raiz->esq != NULL ? raiz->esq : raiz->dir;
            destruirAtividade(raiz->atividade);
            free(raiz);
            return filho;
        }

        destruirAtividade(raiz->atividade);
        raiz->dir = extrairMinimo(raiz->dir, &raiz->atividade);
    }

    return balancear(raiz);
}