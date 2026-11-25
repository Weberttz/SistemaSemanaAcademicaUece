#ifndef AVL_H
#define AVL_H

#include "atividade.h"

/*
 * TAD Arvore AVL - insercao e remocao com balanceamento.
 *
 * Mantem a arvore de busca (indexada pelo codigo da atividade)
 * balanceada: em todo no, as alturas das subarvores esquerda e direita
 * diferem em no maximo 1. Com isso a altura fica O(log n) e insercao
 * e remocao custam O(log n) no pior caso.
 *
 * O tipo NoArvore e opaco; os campos ficam em no_arvore.h.
 */
typedef struct NoArvore NoArvore;

/*
 * Insere a atividade e devolve a NOVA raiz (a raiz pode mudar por
 * causa de rotacoes). Uso: raiz = inserirAtividadeNaArvore(raiz, a);
 *
 * Codigo ja existente: nada e inserido e a raiz volta inalterada
 * (a atividade continua sendo responsabilidade de quem chamou).
 * Falha de malloc: arvore inalterada.
 */
NoArvore *inserirAtividadeNaArvore(NoArvore *raiz, AtividadePtr atividade);

/*
 * Remove a atividade de codigo informado e devolve a NOVA raiz.
 * A arvore e dona das atividades (como em liberarArvore), entao a
 * atividade removida tambem e destruida com destruirAtividade.
 * Codigo inexistente: arvore inalterada.
 */
NoArvore *removerAtividadeDaArvore(NoArvore *raiz, const int codigo);

#endif