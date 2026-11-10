#ifndef LISTA_H
#define LISTA_H

#define MAX_CARACTERES 60

#include <stddef.h>

// Para o compilador saber os dados do estudante
typedef struct Estudante Estudante;

// Declara variáveis para garantir que as operações possam ser concluídas com essas variáveis
typedef struct ListaEncadeada ListaEncadeada;
typedef struct No No;

// Função que incializa uma nova lista encadeada
ListaEncadeada *criarLista(void);


Estudante criarEstudante(int matricula, char nome[MAX_CARACTERES]);
int inicializarLista(ListaEncadeada *lista);
int listaVazia(ListaEncadeada *lista);
int inserirNoFinal(ListaEncadeada *lista, int matricula, char nome[MAX_CARACTERES]);
int imprimirLista(ListaEncadeada *lista);
int deletarUmElemento(ListaEncadeada *lista, int matricula);
int deletarTudo(ListaEncadeada *lista);
int finalizarLista(ListaEncadeada *lista);

// Talvez precise
int inserirNoInicio(ListaEncadeada *lista, int matricula, char nome[MAX_CARACTERES]);
int inserirOrdenado(ListaEncadeada *lista, int matricula, char nome[MAX_CARACTERES]);
int alterarElemento(ListaEncadeada *lista, int matriculaEstudanteSubstituido, int matricula, char nome[MAX_CARACTERES]);
#endif