
#include "../include/historico.h"
#include <stdio.h>
#include <stddef.h>

int main(void) {
    HistoricoPtr historico = criarHistorico();

    if (historico == NULL) {
        printf("Falha ao criar historico\n");
        return 1;
    }

    imprimirHistorico(historico);
    printf("\n");
    registrarEvento(historico, "CADASTRO", 10, 0);
    registrarEvento(historico, "INSCRICAO", 10, 101);
    registrarEvento(historico, "ENTRADA_ESPERA", 10, 102);
    registrarEvento(historico, "CANCEL_INSCRICAO", 10, 101);
    registrarEvento(historico, "PROMOCAO", 10, 102);

    imprimirHistorico(historico);
    printf("\n");

    registrarEvento(historico, "CADASTRO", 20, 0);
    registrarEvento(historico, "AUMENTO_CAPACIDADE", 20, 0);

    imprimirHistorico(historico);
    printf("\n");

    destruirHistorico(historico);
    historico = NULL;
    printf("\n");

    return 0;
}
