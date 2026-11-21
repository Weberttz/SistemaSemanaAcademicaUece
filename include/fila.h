#ifndef FILA_H
#define FILA_H

#include "estudante.h"
typedef struct No No;
typedef struct Fila *FilaPtr;

FilaPtr criarFila(void);
EstudantePtr buscarEstudanteEmFila(FilaPtr fila, const int matricula);
int imprimirFila(FilaPtr f); 
int inserirFila(FilaPtr f, EstudantePtr estudante);
int removerFila(FilaPtr f, EstudantePtr *removido);
int removerEsperaFila(FilaPtr f, const int matricula);
int destruirFila(FilaPtr f);

#endif