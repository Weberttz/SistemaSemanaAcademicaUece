#ifndef ATIVIDADE_H
#define ATIVIDADE_H

typedef struct Atividade *AtividadePtr;

AtividadePtr criarAtividade(int codigo, int capacidade, const char *nome);
int inserirEstudanteEmLista(AtividadePtr atividade, int matricula, const char *nome);
int get_codigo(AtividadePtr atividade);

#endif