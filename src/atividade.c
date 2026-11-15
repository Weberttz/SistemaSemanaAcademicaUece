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

EstudantePtr buscarEstudanteEmAtividade(AtividadePtr atividade, const int matricula){
    EstudantePtr estudanteLista = buscarEstudanteEmLista(atividade->lista, matricula);
    EstudantePtr estudanteFila = buscarEstudanteEmFila(atividade->fila, matricula);
    
    if(estudanteLista != NULL) return estudanteLista;
    if(estudanteFila != NULL) return estudanteFila;

    return NULL;
}

int removerEstudanteAtividade(AtividadePtr atividade, const int matricula){
    int resultado_lista = removerInscritoLista(atividade->lista, matricula);
    int resultado_fila = removerEsperaFila(atividade->fila, matricula);

    if(resultado_lista) {
        atividade->qntInscritos--;
        return 1;
    }
    if(resultado_fila) {
        atividade->qntEspera--;
        return 2;
    }

    return 0;
}

int promoverFilaEspera(AtividadePtr atividade, EstudantePtr *promovido){
    EstudantePtr estudante;
    // Se conseguiu remover da fila
    if(removerFila(atividade->fila, &estudante)){
        atividade->qntEspera--;
        // retorna estudante que foi removido, ele será promovido
        *promovido = estudante;
        // Se conseguiu inserir na lista de inscritos
        if(inserirNoFinal(atividade->lista, estudante))
            atividade->qntInscritos++;
            return 1;
    }
    return 0;
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

FilaPtr getFila(AtividadePtr atividade){
    return atividade->fila;
}
