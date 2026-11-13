#ifndef ATIVIDADE_H
#define ATIVIDADE_H

typedef struct Atividade *AtividadePtr;

AtividadePtr criarAtividade(int codigo, int capacidade, const char *nome);
void imprimirDados(AtividadePtr atividade);
int inscreverEstudante(AtividadePtr atividade, const int matricula, const char *nome);
void destruirAtividade(AtividadePtr atividade);
int aumentarCapacidade(AtividadePtr atividade, const int incremento);
int getCodigo(AtividadePtr atividade);
int getCapacidade(AtividadePtr atividade);

#endif