#include "../include/atividade.h"
#include "../include/fila.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARACTERES 100

typedef struct Atividade{
    int codigo;
    char titulo[MAX_CARACTERES];
    int capacidade;
    int qntInscritos;
    int qntEspera;
    // tipos opacos
    ListaPtr lista; 
    FilaPtr fila;
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
    atividade->fila = criarFila();

    return atividade;
}

void imprimirDados(AtividadePtr atividade){
    printf("ATIVIDADE %d %s %d %d %d\n", 
    atividade->codigo,atividade->titulo, atividade->capacidade, 
    atividade->qntInscritos, atividade->qntEspera);
}

int inscreverEstudante(AtividadePtr atividade, EstudantePtr estudante){
    if(atividade == NULL) return -1;

    // Chamar inscrição em fila
    if(atividade->qntInscritos >= atividade->capacidade){
        int resultado = inserirFila(atividade->fila, estudante);
        if(resultado == 1) atividade->qntEspera+=resultado;
        else return 0;
        return 2;
    }

    int resultado = inserirNoFinal(atividade->lista, estudante);
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
        destruirLista(&atividade->lista);
        destruirFila(atividade->fila);
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

int getQntEspera(AtividadePtr atividade){
    return atividade->qntEspera;
}

ListaPtr getLista(AtividadePtr atividade){
    return atividade->lista;
}