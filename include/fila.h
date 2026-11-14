#ifndef FILA_H
#define FILA_H

typedef struct Estudante *EstudantePtr;
typedef struct No No;
typedef struct Fila *FilaPtr;

FilaPtr criarFila(void);
EstudantePtr buscarEstudanteEmFila(FilaPtr fila, const int matricula);
void inicializarFila(FilaPtr f);
int inserirFila(FilaPtr f, EstudantePtr estudante);
int removerFila(FilaPtr f, EstudantePtr removido);
EstudantePtr consultarPrimeiro(FilaPtr f);
int isVazia(FilaPtr f);
int destruirFila(FilaPtr f);

#endif