#ifndef LISTA_H
#define LISTA_H

#include <stddef.h>

// Para o compilador saber os dados do estudante
typedef struct Estudante Estudante;

// Declara variáveis para garantir que as operações possam ser concluídas com essas variáveis
typedef struct ListaInscritos* ListaPtr; // opaco

// Função que incializa uma nova lista encadeada
ListaPtr criarLista(void);

Estudante criarEstudante(const int matricula, const char *nome);
int inicializarLista(ListaPtr l);
int listaVazia(ListaPtr l);
int inserirNoFinal(ListaPtr l, const int matricula, const char *nome);
int inserirNoInicio(ListaPtr l, int matricula, const char *nome);
int imprimirLista(ListaPtr l);
int deletarUmElemento(ListaPtr l, const int matricula);
int deletarTudo(ListaPtr l);
void destruirLista(ListaPtr l);

// Talvez precise
//int inserirOrdenado(ListaPtr l, int matricula, const char *nome);
int alterarElemento(ListaPtr l, const int matriculaEstudanteSubstituido, const int matricula, const char *nome);
#endif