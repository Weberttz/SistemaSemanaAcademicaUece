#ifndef LISTA_H
#define LISTA_H

// Para o compilador saber os dados do estudante
#include "estudante.h"

// Declara variáveis para garantir que as operações possam ser concluídas com essas variáveis
typedef struct ListaInscritos* ListaPtr; // opaco
typedef struct No No;

// Função que incializa uma nova lista encadeada
ListaPtr criarLista(void);
int inicializarLista(ListaPtr l);
int listaVazia(ListaPtr l);
int inserirNoFinal(ListaPtr l, EstudantePtr estudante);
int inserirNoInicio(ListaPtr l, EstudantePtr estudante);
int imprimirLista(ListaPtr l);
int removerInscritoLista(ListaPtr l, const int matricula);
int deletarTudoLista(ListaPtr l);
void destruirLista(ListaPtr *l);

EstudantePtr buscarEstudanteEmLista(ListaPtr l, const int matricula);
#endif