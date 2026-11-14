
#include "../include/abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARACTERES 100

typedef enum {
    CONTINUAR,
    ENCERRAR
} EstadoComando;

void imprimirErroParametros(void) {
    printf("ERRO PARAMETROS\n");
}

/* CRIAR a c titulo */
EstadoComando executarCriar(NoArvore **raiz) {
    int codigo, capacidade;
    char titulo[MAX_CARACTERES];

    if (scanf("%d %d %99s", &codigo, &capacidade, titulo) != 3) {
        imprimirErroParametros();
        return ENCERRAR;
    }

    if(capacidade <= 0 || codigo <= 0){
        imprimirErroParametros();
        return ENCERRAR;
    }

    if (buscarAtividade(*raiz, codigo) != NULL) {
        printf("ERRO ATIVIDADE_EXISTE");
        return ENCERRAR;
    }

    AtividadePtr atividade = criarAtividade(codigo, capacidade, titulo);

    if (atividade == NULL)
        return ENCERRAR;

    *raiz = inserirAtividadeNaArvore(*raiz, atividade);

    return CONTINUAR;
}

/* INSCREVER a m nome */
EstadoComando executarInscrever(NoArvore *raiz) {
    int codigo, matricula;
    char nome[MAX_CARACTERES];

    if (scanf("%d %d %99s", &codigo, &matricula, nome) != 3) {
        imprimirErroParametros();
        return ENCERRAR;
    }

    if(matricula <= 0 || codigo <= 0){
        imprimirErroParametros();
        return ENCERRAR;
    }

    AtividadePtr atividade = buscarAtividade(raiz, codigo);

    if (atividade == NULL) {
        printf("ERRO ATIVIDADE_INEXISTENTE");
        return ENCERRAR;
    }

    EstudantePtr estudante = criarEstudante(matricula, nome);

    if (estudante == NULL)
        return ENCERRAR;

    int resultado = inscreverEstudante(atividade, estudante);

    if (resultado == 1) {
        printf("OK INSCRITO %d %s\n", matricula, nome);
    }
    else if (resultado == 2) {
        printf("OK ESPERA %d %s %d\n",
               matricula, nome, getQntEspera(atividade) - 1);
    }
    else {
        /*
         * Válido somente se inscreverEstudante não
         * armazenou nem liberou estudante na falha.
         */
        free(estudante);
    }

    return CONTINUAR;
}

/* BUSCAR a */
EstadoComando executarBuscar(NoArvore *raiz) {
    int codigo;

    if (scanf("%d", &codigo) != 1) {
        imprimirErroParametros();
        return ENCERRAR;
    }

    AtividadePtr atividade = buscarAtividade(raiz, codigo);
    if (atividade == NULL) {
        printf("ERRO ATIVIDADE_INEXISTENTE");
        return ENCERRAR;
    }
    imprimirDados(atividade);

    return CONTINUAR;
}

/* INSCRITOS a */
EstadoComando executarInscritos(NoArvore *raiz) {
    int codigo;

    if (scanf("%d", &codigo) != 1 || codigo <= 0) {
        imprimirErroParametros();
        return ENCERRAR;
    }

    AtividadePtr atividade = buscarAtividade(raiz, codigo);

    if (atividade == NULL) {
        printf("ERRO ATIVIDADE_INEXISTENTE");
        return ENCERRAR;
    }

    printf("INSCRITOS %d ", codigo);

    int resultado = imprimirLista(getLista(atividade));

    if (!resultado)
        printf("%d", resultado);

    return CONTINUAR;
}

/* AUMENTAR a d */
EstadoComando executarAumentar(NoArvore *raiz) {
    int codigo, incremento;

    if (scanf("%d %d", &codigo, &incremento) != 2) {
        imprimirErroParametros();
        return ENCERRAR;
    }

    if(codigo <= 0 || incremento <= 0){
        imprimirErroParametros();
        return ENCERRAR;
    }

    AtividadePtr atividade = buscarAtividade(raiz, codigo);

    if (atividade == NULL){
        printf("ERRO ATIVIDADE_INEXISTENTE");
        return ENCERRAR;
    }

    int resultado = aumentarCapacidade(atividade, incremento);

    if (resultado) {
        printf("OK AUMENTAR %d %d %d\n",
               codigo, getCapacidade(atividade), incremento);
    }

    return CONTINUAR;
}

/* Interpretador de comandos */
EstadoComando executarComando(const char *comando, NoArvore **raiz) {
    if (strcmp(comando, "CRIAR") == 0)
        return executarCriar(raiz);

    if (strcmp(comando, "INSCREVER") == 0)
        return executarInscrever(*raiz);

    if (strcmp(comando, "BUSCAR") == 0)
        return executarBuscar(*raiz);

    if (strcmp(comando, "INSCRITOS") == 0)
        return executarInscritos(*raiz);

    if (strcmp(comando, "IMPRIMIR") == 0) {
        preOrdem(*raiz);
        return CONTINUAR;
    }

    if (strcmp(comando, "AUMENTAR") == 0)
        return executarAumentar(*raiz);

    if (strcmp(comando, "FIM") == 0)
        return ENCERRAR;

    imprimirErroParametros();
    return ENCERRAR;
}

int main(void) {
    char comando[MAX_CARACTERES];
    NoArvore *raiz = NULL;

    while (scanf("%99s", comando) == 1) {
        EstadoComando estado = executarComando(comando, &raiz);

        if (estado == ENCERRAR)
            break;
    }

    // Sempre vai ser executado
    liberarArvore(raiz);

    return 0;
}
