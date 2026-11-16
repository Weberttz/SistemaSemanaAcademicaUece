#include "../include/estudante.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARACTERES 100

typedef struct Estudante{
    int matricula;
    char nome[100];
}Estudante;

EstudantePtr criarEstudante(const int matricula, const char *nome){
    EstudantePtr estudante = malloc(sizeof(Estudante));
    if(estudante == NULL) return NULL;
    snprintf(estudante->nome, MAX_CARACTERES, "%s", nome);
    estudante->matricula = matricula;
    return estudante;
}

int getMatricula(EstudantePtr estudante){
    return estudante->matricula;
}