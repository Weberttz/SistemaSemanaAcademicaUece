#include "../include/lista.h"
#include "../include/atividade.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARACTERES 100

typedef struct Atividade{
    int codigo;
    char titulo[MAX_CARACTERES];
    int capacidade;
    int qntInscritos;
    int qntEspera;
    ListaPtr lista; // tipo opaco
}Atividade;

AtividadePtr criarAtividade(int codigo, int capacidade, const char *nome){
    AtividadePtr atividade = malloc(sizeof(Atividade));

    if(atividade == NULL){
        return NULL;
    }
    
    atividade->codigo = codigo;
    atividade->capacidade = capacidade;
    atividade->qntEspera = 0;
    atividade->qntInscritos = 0;
    snprintf(atividade->titulo, MAX_CARACTERES, "%s", nome); 
    atividade->lista = criarLista();

    return atividade;
}

int getCodigo(AtividadePtr atividade){
    return atividade->codigo;
}

int inscreverEstudante(AtividadePtr atividade, const int matricula, const char *nome){
    return inserirNoFinal(atividade->lista, matricula, nome);
}
