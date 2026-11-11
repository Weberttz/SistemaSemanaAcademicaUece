#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../include/abb.h"
#include "../include/atividade.h"

/*
 * Implementacao privada do TAD.
 * Observe a correspondencia com o slide 12:
 *   valor, ponteiro esquerdo (esq) e ponteiro direito (dir).
 */
typedef struct NoArvore {
    struct NoArvore *esq;
    struct NoArvore *dir;
    AtividadePtr atividade;
}NoArvore;

NoArvore *criarNoArvore(int codigo, int capacidade, const char *nome) {
    NoArvore *novo = malloc(sizeof *novo);
    if (novo == NULL) {
        return NULL;
    }

    novo->atividade = criarAtividade(codigo, capacidade, nome);
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

NoArvore *inserirEsquerda(NoArvore *pai, int codigo, int capacidade, const char *nome) {
    if (pai == NULL || pai->esq != NULL) {
        return NULL;
    }

    NoArvore *filho = criarNoArvore(codigo, capacidade, nome);
    if (filho != NULL) {
        pai->esq = filho;
    }
    return filho;
}

NoArvore *inserirDireita(NoArvore *pai, int codigo, int capacidade, const char *nome) {
    if (pai == NULL || pai->dir != NULL) {
        return NULL;
    }

    NoArvore *filho = criarNoArvore(codigo, capacidade, nome);
    if (filho != NULL) {
        pai->dir = filho;
    }
    return filho;
}

AtividadePtr valorNoArvore(const NoArvore *no) {
    assert(no != NULL);
    return no->atividade;
}

const NoArvore *filhoEsquerdo(const NoArvore *no) {
    return no == NULL ? NULL : no->esq;
}

const NoArvore *filhoDireito(const NoArvore *no) {
    return no == NULL ? NULL : no->dir;
}

bool ehFolha(const NoArvore *no) {
    return no != NULL && no->esq == NULL && no->dir == NULL;
}

int altura(const NoArvore *raiz) {
    if (raiz == NULL) {
        return -1;
    }

    int alturaEsquerda = altura(raiz->esq);
    int alturaDireita = altura(raiz->dir);
    int maior = alturaEsquerda > alturaDireita
                    ? alturaEsquerda
                    : alturaDireita;

    return 1 + maior;
}

int nivel(const NoArvore *raiz, const NoArvore *alvo) {
    if (raiz == NULL || alvo == NULL) {
        return -1;
    }
    if (raiz == alvo) {
        return 0;
    }

    int nivelEsquerdo = nivel(raiz->esq, alvo);
    if (nivelEsquerdo != -1) {
        return nivelEsquerdo + 1;
    }

    int nivelDireito = nivel(raiz->dir, alvo);
    if (nivelDireito != -1) {
        return nivelDireito + 1;
    }

    return -1;
}

const NoArvore *encontrarPai(const NoArvore *raiz, const NoArvore *alvo) {
    if (raiz == NULL || alvo == NULL || raiz == alvo) {
        return NULL;
    }
    if (raiz->esq == alvo || raiz->dir == alvo) {
        return raiz;
    }

    const NoArvore *pai = encontrarPai(raiz->esq, alvo);
    if (pai != NULL) {
        return pai;
    }
    return encontrarPai(raiz->dir, alvo);
}

void preOrdem(const NoArvore *raiz) {
    if (raiz != NULL) {
        printf("%d ", get_codigo(raiz->atividade)); /* 1. Raiz */
        preOrdem(raiz->esq);        /* 2. Esquerda */
        preOrdem(raiz->dir);        /* 3. Direita */
    }
}

void emOrdem(const NoArvore *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);         /* 1. Esquerda */
        printf("%d ", get_codigo(raiz->atividade)); /* 2. Raiz */
        emOrdem(raiz->dir);         /* 3. Direita */
    }
}

void posOrdem(const NoArvore *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);        /* 1. Esquerda */
        posOrdem(raiz->dir);        /* 2. Direita */
        printf("%d ", get_codigo(raiz->atividade)); /* 3. Raiz */
    }
}

void liberarArvore(NoArvore *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

AtividadePtr encontrarAtividade(const NoArvore *raiz, int codigo) {
    if (raiz == NULL) return NULL;
    int c = get_codigo(raiz->atividade);
    if (codigo == c) return raiz->atividade;
    return encontrarAtividade(codigo < c ? raiz->esq : raiz->dir, codigo);
}

int inscreverEstudante(NoArvore *raiz, int codigo, int matricula, const char *nome){
    AtividadePtr a = encontrarAtividade(raiz, codigo);

    if(a == NULL) return 0;

    inserirEstudanteEmLista(a, matricula, nome);
}