#ifndef ABB_H
#define ABB_H
#include "atividade.h"
#include "avl.h"

/*
 * TAD Arvore Binaria - Aula 15
 *
 * O usuario conhece o tipo NoArvore, mas seus campos ficam ocultos.
 * Cada no guarda um inteiro e pode ter ate dois filhos.
 *
 * ATENCAO: esta e uma arvore binaria comum, NAO uma arvore de busca.
 * A posicao de cada filho e definida explicitamente pelo programa.
 */

NoArvore *inserirAtividadeNaArvore(NoArvore *raiz, AtividadePtr atividade);

/*
 * Altura = numero de ARESTAS no maior caminho ate uma folha.
 * Arvore vazia: -1; no isolado: 0; raiz com netos: 2.
 */
int altura(const NoArvore *raiz);

AtividadePtr buscarAtividade(const NoArvore *raiz, const int codigo);

int listarAtividades(const NoArvore *raiz, const char *titulo);

/* Libera todos os nos abaixo de raiz, inclusive a propria raiz. */
void liberarArvore(NoArvore *raiz);

int getQntAtividade(const NoArvore *raiz);

#endif
