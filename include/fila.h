#ifndef FILA_H
#define FILA_H

#include "estudante.h"
typedef struct No No;
typedef struct Fila *FilaPtr;

FilaPtr criarFila(void);
EstudantePtr buscarEstudanteEmFila(FilaPtr fila, const int matricula);
void inicializarFila(FilaPtr f);
int imprimirFila(FilaPtr f); 
int inserirFila(FilaPtr f, EstudantePtr estudante);
int removerFila(FilaPtr f, EstudantePtr *removido);
int removerEsperaFila(FilaPtr f, const int matricula);
EstudantePtr consultarPrimeiro(FilaPtr f);
int isVazia(FilaPtr f);
int destruirFila(FilaPtr f);

#endif