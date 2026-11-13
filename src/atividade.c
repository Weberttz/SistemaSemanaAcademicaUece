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

void imprimirDados(AtividadePtr atividade){
    if (atividade == NULL) {
        printf("ERRO ATIVIDADE_INECISTENTE");
        return;
    }
    printf("ATIVIDADE %d %s %d %d %d\n", 
    atividade->codigo,atividade->titulo, atividade->capacidade, 
    atividade->qntInscritos, atividade->qntEspera);
}

int inscreverEstudante(AtividadePtr atividade, const int matricula, const char *nome){
    if(atividade == NULL) return -1;

    // Chamar inscrição em fila
    if(atividade->qntInscritos >= atividade->capacidade) return 0;

    int resultado =  inserirNoFinal(atividade->lista, matricula, nome);
    if(resultado) atividade->qntInscritos++;
    return resultado;
}

int aumentarCapacidade(AtividadePtr atividade, const int incremento){
    if (atividade == NULL) return 0;
    atividade->capacidade += incremento;
    return 1;
}

void destruirAtividade(AtividadePtr atividade){
    if(atividade != NULL){
        destruirLista(atividade->lista);
        //destruirFila(atividade->fila);
        free(atividade);
        atividade = NULL;
    }
}

int getCodigo(AtividadePtr atividade){
    return atividade->codigo;
}

int getCapacidade(AtividadePtr atividade){
    return atividade->capacidade;
}