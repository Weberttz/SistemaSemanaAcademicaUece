#ifndef NO_ARVORE_H
#define NO_ARVORE_H

#include "atividade.h"

/*
 * Definicao INTERNA do no da arvore.
 *
 * Este header so deve ser incluido por abb.c e avl.c, que precisam
 * enxergar os campos. Quem usa a arvore (main.c) inclui apenas abb.h
 * e continua vendo NoArvore como tipo opaco.
 *
 * O typedef NoArvore esta em avl.h, entao inclua avl.h (ou abb.h)
 * antes deste header.
 */
struct NoArvore {
    struct NoArvore *esq;
    struct NoArvore *dir;
    AtividadePtr atividade;
    int qntAtividade;   /* quantidade de nos da subarvore (este no incluso) */
    int alt;            /* altura em arestas: folha = 0, NULL = -1 */
};

#endif