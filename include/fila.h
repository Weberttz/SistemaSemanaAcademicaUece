#ifndef FILA_H
#define FILA_H

#include "estudante.h"
typedef struct Fila *FilaPtr;

int isVazia(const FilaPtr *f);
int tamanhoFila(const FilaPtr *f);

int removerFila(FilaPtr *f, Estudante **removido);
Estudante *consultarPrimeiro(const FilaPtr *f);

FilaPtr criarFila(void);
EstudantePtr buscarEstudanteEmFila(FilaPtr fila, const int matricula);
void inicializarFila(FilaPtr f);
int imprimirFila(FilaPtr f);
int inserirFila(FilaPtr f, EstudantePtr *estudante);
int removerEsperaFila(FilaPtr f, const int matricula);
int destruirFila(FilaPtr f);

#endif