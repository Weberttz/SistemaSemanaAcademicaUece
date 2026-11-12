#ifndef ATIVIDADE_H
#define ATIVIDADE_H

typedef struct Atividade *AtividadePtr;

AtividadePtr criarAtividade(int codigo, int capacidade, const char *nome);
int inscreverEstudante(AtividadePtr atividade, const int matricula, const char *nome);
void destruirAtividade(AtividadePtr atividade);
int getCodigo(AtividadePtr atividade);

#endif