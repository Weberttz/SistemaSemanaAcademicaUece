#include "../include/abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/historico.h"

#define MAX_CARACTERES 100

typedef enum {
    CONTINUAR,
    ENCERRAR
} EstadoComando;

void imprimirErroParametros(void) {
    printf("ERRO PARAMETROS\n");
}


EstadoComando executarHistorico(HistoricoPtr historicoPtr){
    imprimirHistorico(historicoPtr);
    return CONTINUAR;
}

/* CRIAR a c titulo */
EstadoComando executarCriar(NoArvore **raiz, HistoricoPtr historicoPtr) {
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

    registrarEvento(historicoPtr, "CADASTRO", codigo, 0);

    printf("OK CRIAR %d\n", codigo);

    return CONTINUAR;
}

/* INSCREVER a m nome */
EstadoComando executarInscrever(NoArvore *raiz, HistoricoPtr historicoPtr) {
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

    EstudantePtr e = buscarEstudanteEmAtividade(atividade, matricula);

    if(e != NULL){
        printf("ERRO ESTUDANTE_DUPLICADO");
        return ENCERRAR;
    }

    EstudantePtr estudante = criarEstudante(matricula, nome);

    if (estudante == NULL)
        return ENCERRAR;

    int resultado = inscreverEstudante(atividade, estudante);

    if (resultado == 1) {
        printf("OK INSCRITO %d %s\n", matricula, nome);
        registrarEvento(historicoPtr, "INSCRICAO", codigo, matricula);
    }
    else if (resultado == 2) {
        printf("OK ESPERA %d %s %d\n", matricula, nome, getQntEspera(atividade) - 1);
        registrarEvento(historicoPtr, "ENTRADA_ESPERA", codigo, matricula);
    }
    else {
        free(estudante);
    }

    return CONTINUAR;
}

/* CANCELAR a m */
EstadoComando executarCancelar(NoArvore *raiz, HistoricoPtr historicoPtr){
    int codigo, matricula;

    if (scanf("%d %d", &codigo, &matricula) != 2) {
        imprimirErroParametros();
        return ENCERRAR;
    }

    AtividadePtr atividade = buscarAtividade(raiz, codigo);

    if(atividade == NULL){
        printf("ERRO ATIVIDADE_INEXISTENTE");
        return ENCERRAR;
    }

    int resultado_cacelar = removerEstudanteAtividade(atividade, matricula);

    if(resultado_cacelar == 1) {
        printf("OK CANCELADO_INSCRITO %d %d\n", codigo, matricula);
        registrarEvento(historicoPtr, "CANCEL_INSCRICAO", codigo, matricula);
        
        EstudantePtr promovido;
        int promocao = promoverFilaEspera(atividade, &promovido);

        if(promocao) printf("PROMOVIDO %d %d\n", codigo, getMatricula(promovido));
        registrarEvento(historicoPtr, "PROMOCAO", codigo, getMatricula(promovido));
    }
    else if(resultado_cacelar == 2) {
        printf("OK CANCELADO_ESPERA %d %d\n", codigo, matricula);
        registrarEvento(historicoPtr, "CANCEL_ESPERA", codigo, matricula);
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

    printf("\n");

    return CONTINUAR;
}

/* ESPERA a */
EstadoComando executarEspera(NoArvore *raiz){
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

    printf("ESPERA %d ", codigo);
    int resultado = imprimirFila(getFila(atividade));

    if (!resultado)
        printf("%d", resultado);

    printf("\n");
     
    return CONTINUAR;
}

/* AUMENTAR a d */
EstadoComando executarAumentar(NoArvore *raiz, HistoricoPtr historicoPtr) {
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
        registrarEvento(historicoPtr, "AUMENTO_CAPACIDADE", codigo, 0);

        // promoção de k alunos dps do incremento, sendo enviado aos registros.
        for(int i=0; i<incremento; i++){
            EstudantePtr promovido;
            if(promoverFilaEspera(atividade, &promovido))
                registrarEvento(historicoPtr, "PROMOCAO", codigo, getMatricula(promovido));
        }
    }

    return CONTINUAR;
}

EstadoComando executarRelatorio(NoArvore *raiz){
    printf("RELATORIO %d\n", getQntAtividade(raiz));
    listarAtividades(raiz, "RESUMO");
    return CONTINUAR;
}

/* Interpretador de comandos */
EstadoComando executarComando(const char *comando, NoArvore **raiz, HistoricoPtr historicoPtr) {
    if (strcmp(comando, "CRIAR") == 0){
        return executarCriar(raiz, historicoPtr);
    }

    if (strcmp(comando, "INSCREVER") == 0)
        return executarInscrever(*raiz, historicoPtr);
    
    if (strcmp(comando, "CANCELAR") == 0)
        return executarCancelar(*raiz, historicoPtr);

    if (strcmp(comando, "AUMENTAR") == 0)
        return executarAumentar(*raiz, historicoPtr);

    if (strcmp(comando, "BUSCAR") == 0)
        return executarBuscar(*raiz);

    if (strcmp(comando, "INSCRITOS") == 0)
        return executarInscritos(*raiz);

    if (strcmp(comando, "ESPERA") == 0)
        return executarEspera(*raiz);

    if (strcmp(comando, "HISTORICO") == 0)
        return executarHistorico(historicoPtr);

    if (strcmp(comando, "RELATORIO") == 0)
        return executarRelatorio(*raiz);

    if (strcmp(comando, "LISTAR") == 0) {
        printf("LISTAR %d\n", getQntAtividade(*raiz));
        //tratar esse resultado :
        int resultado = listarAtividades(*raiz, "ATIVIDADE");
        return CONTINUAR;
    }

    if (strcmp(comando, "FIM") == 0){
        printf("FIM\n");
        return ENCERRAR;
    }

    imprimirErroParametros();
    return ENCERRAR;
}

int main(void) {
    char comando[MAX_CARACTERES];
    NoArvore *raiz = NULL;
    HistoricoPtr historico = criarHistorico();

    while (scanf("%99s", comando) == 1) {
        EstadoComando estado = executarComando(comando, &raiz, historico);

        if (estado == ENCERRAR)
            break;
    }

    // Sempre vai ser executado
    liberarArvore(raiz);
    destruirHistorico(historico);

    return 0;
}
