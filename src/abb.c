#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/abb.h"
#include "../include/atividade.h"
#include "../include/no_arvore.h"


AtividadePtr buscarAtividade(const NoArvore *raiz, const int codigo) {
    if (raiz == NULL) return NULL;
    int c = getCodigo(raiz->atividade);
    if (codigo == c) return raiz->atividade;
    return buscarAtividade(codigo < c ? raiz->esq : raiz->dir, codigo);
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

static void emOrdem(const NoArvore *raiz, const char *titulo) {
    if (raiz != NULL) {
        emOrdem(raiz->esq, titulo);         // 1. Esquerda 

        if(!strcmp(titulo, "ATIVIDADE"))    // 2. Raiz
            imprimirDados(raiz->atividade);
        else
            imprimirRelatorio(raiz->atividade);

        emOrdem(raiz->dir, titulo);         // 3. Direita 
    }
}

int getQntAtividade(const NoArvore *raiz){
    if(raiz == NULL) return 0;
    return raiz->qntAtividade;
}

int listarAtividades(const NoArvore *raiz, const char *titulo){
    if( raiz == NULL) return 0;
    emOrdem(raiz, titulo);
    return 1;
}

void liberarArvore(NoArvore *raiz) {
    if (raiz != NULL) {
        destruirAtividade(raiz->atividade);
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}