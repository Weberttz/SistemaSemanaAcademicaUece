#ifndef LISTA_H
#define LISTA_H

#define MAX_CARACTERES 100

#include <stddef.h>

// Para o compilador saber os dados do estudante
typedef struct Estudante Estudante;

// Declara variáveis para garantir que as operações possam ser concluídas com essas variáveis
typedef struct ListaInscritos* ListaPtr; // opaco

// Função que incializa uma nova lista encadeada
ListaPtr criarLista(void);

Estudante criarEstudante(int matricula, const char *nome);
int inicializarLista(ListaPtr l);
int listaVazia(ListaPtr l);
int inserirNoFinal(ListaPtr l, int matricula, const char *nome);
int imprimirLista(ListaPtr l);
int deletarTudo(ListaPtr l);
int finalizarLista(ListaPtr l);

// Talvez precise
int inserirNoInicio(ListaPtr l, int matricula, const char *nome);
//int inserirOrdenado(ListaPtr l, int matricula, const char *nome);
int alterarElemento(ListaPtr l, int matriculaEstudanteSubstituido, int matricula, const char *nome);
#endif