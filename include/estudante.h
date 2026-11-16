#ifndef ESTUDANTE_H
#define ESTUDANTE_H

typedef struct Estudante
{
    int matricula;
    char nome[100];
} Estudante;

typedef struct Estudante *EstudantePtr;

EstudantePtr criarEstudante(const int matricula, const char *nome);
int getMatricula(EstudantePtr estudante);
#endif