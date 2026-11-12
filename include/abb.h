#ifndef ABB_H
#define ABB_H
#include <stdbool.h>

#include "atividade.h"

/*
 * TAD Arvore Binaria - Aula 15
 *
 * O usuario conhece o tipo NoArvore, mas seus campos ficam ocultos.
 * Cada no guarda um inteiro e pode ter ate dois filhos.
 *
 * ATENCAO: esta e uma arvore binaria comum, NAO uma arvore de busca.
 * A posicao de cada filho e definida explicitamente pelo programa.
 */
typedef struct NoArvore NoArvore;

/* Cria um no isolado. Ele pode ser usado como raiz de uma arvore. */
NoArvore *criarNoArvore(AtividadePtr a);

/*
 * Adiciona um NOVO no na posicao indicada e devolve seu endereco.
 * Retorna NULL se pai for NULL, a posicao ja estiver ocupada ou
 * nao houver memoria. Nunca substitui um filho existente.
 */
NoArvore *inserirEsquerda(NoArvore *pai, AtividadePtr atividade);
NoArvore *inserirDireita(NoArvore *pai, AtividadePtr atividade);

NoArvore *inserirAtividadeNaArvore(NoArvore *raiz, AtividadePtr atividade);

/* Acesso controlado aos dados de um no. valorNoArvore requer no != NULL. */
int valorNoArvore(const NoArvore *no);
const NoArvore *filhoEsquerdo(const NoArvore *no);
const NoArvore *filhoDireito(const NoArvore *no);
bool ehFolha(const NoArvore *no);

/*
 * Altura = numero de ARESTAS no maior caminho ate uma folha.
 * Arvore vazia: -1; no isolado: 0; raiz com netos: 2.
 */
int altura(const NoArvore *raiz);

/*
 * A raiz esta no nivel 0. Retorna -1 se alvo nao pertence a arvore.
 * Identificamos o alvo pelo endereco (nao pelo valor inteiro).
 */
int nivel(const NoArvore *raiz, const NoArvore *alvo);

/* Encontra o pai de alvo; NULL para a raiz ou para no inexistente. */
const NoArvore *encontrarPai(const NoArvore *raiz, const NoArvore *alvo);
AtividadePtr buscarAtividade(const NoArvore *raiz, const int codigo);

/* Percursos recursivos: imprimem valores separados por espacos. */
void preOrdem(const NoArvore *raiz); /* Raiz, Esquerda, Direita */
void emOrdem(const NoArvore *raiz);  /* Esquerda, Raiz, Direita */
void posOrdem(const NoArvore *raiz); /* Esquerda, Direita, Raiz */

/* Libera todos os nos abaixo de raiz, inclusive a propria raiz. */
void liberarArvore(NoArvore *raiz);

#endif
