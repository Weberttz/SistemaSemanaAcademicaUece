#ifndef FILA_H
#define FILA_H

typedef struct Estudante Estudante;
typedef struct No No;
typedef struct Fila Fila;

void inicializarFila(Fila *f);
Estudante *inserirFila(Fila *f, Estudante *estudante);
int removerFila(Fila *f, Estudante *removido);
Estudante *consultarPrimeiro(Fila *f);
int isVazia(Fila *f);


#endif