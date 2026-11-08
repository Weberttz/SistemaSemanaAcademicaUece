#ifndef LISTA_H
#define LISTA_H

#include <stddef.h>

// Para o compilador saber os dados do estudante
typedef struct{
    int matricula;
    char nome[100];
}Estudante;

// Declara variáveis para garantir que as operações possam ser concluídas com essas variáveis
typedef struct ListaEncadeada ListaEncadeada;
typedef struct No No;

// Função que incializa uma nova lista encadeada
ListaEncadeada *criarLista();

int inicializarLista(ListaEncadeada *lista);
int listaVazia(ListaEncadeada *lista);
int inserirNoInicio(ListaEncadeada *lista, Estudante estudante);
int inserirNoFinal(ListaEncadeada *lista, Estudante estudante);
int imprimirLista(ListaEncadeada *lista);
No *buscarElemento(ListaEncadeada *lista, int matricula);
int alterarElemento(ListaEncadeada *lista, int matriculaEstudanteSubstituido, Estudante estudanteNovo);
int deletarUmElemento(ListaEncadeada *lista, int matricula);
int deletarTudo(ListaEncadeada *lista);
int inserirOrdenado(ListaEncadeada *lista, Estudante estudante);
int finalizarLista(ListaEncadeada *lista);

// int inserirAntes(Estudante estudante);
// int imprimirListaReversa(void);
//No *buscarElementoAnterior(Estudante estudante);
#endif