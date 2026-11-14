#include "../include/historico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Evento {
    int sequencia; 
    char tipo[32];
    int codigoAtividade;
    int matricula;
    struct Evento *prox;
} Evento;

struct Historico {
    Evento *inicio;
    Evento *fim;
    int quantidade;
};

HistoricoPtr criarHistorico(void) {
    HistoricoPtr historico = malloc(sizeof(struct Historico));

    if (historico  == NULL) {
        printf("ERRO MEMÓRIA\n");
        return 0;
    }

    historico->inicio = NULL;
    historico->fim = NULL;
    historico->quantidade = 0;

    return historico;
}


int registrarEvento(HistoricoPtr historico,
                    const char *tipo,
                    int codigoAtividade,
                    int matricula) {

    // falta validar tamanho do *tipo
    if (historico == NULL || tipo == NULL ||
        codigoAtividade <= 0 || matricula < 0) {
        return 0;
    }

    Evento *novo = malloc(sizeof(Evento));

    if (novo == NULL) {
        return 0;
    }

    novo->sequencia = historico->quantidade + 1;
    strcpy(novo->tipo, tipo);
    novo->codigoAtividade = codigoAtividade;
    novo->matricula = matricula;
    novo->prox = NULL;

    if (historico->inicio == NULL) {
        historico->inicio = novo;
    } else {
        historico->fim->prox = novo;
    }

    historico->fim = novo;
    historico->quantidade++;

    return 1;
}


void imprimirHistorico(const HistoricoPtr historico) {
    if (historico == NULL) {
        return;
    }

    printf("HISTORICO %d\n", historico->quantidade);

    Evento *atual = historico->inicio;

    while (atual != NULL) {
        printf("EVENTO %d %s %d %d\n",
               atual->sequencia,
               atual->tipo,
               atual->codigoAtividade,
               atual->matricula);

        atual = atual->prox;
    }
}


void destruirHistorico(HistoricoPtr historico) {
    if (historico == NULL) {
        return;
    }

    Evento *atual = historico->inicio;

    while (atual != NULL) {
        Evento *proximo = atual->prox;

        free(atual);

        atual = proximo;
    }

    free(historico);
}
