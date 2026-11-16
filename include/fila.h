#ifndef FILA_H
#define FILA_H

#include "estudante.h"

typedef struct Fila Fila;

Fila *inicializarFila(void);
void destruirFila(Fila *f);

int isVazia(const Fila *f);
int tamanhoFila(const Fila *f);

Estudante *inserirFila(Fila *f, Estudante **estudante);
int removerFila(Fila *f, Estudante **removido);
Estudante *consultarPrimeiro(const Fila *f);

#endif