#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#include "lista.h"

typedef struct Atividade *AtividadePtr;

AtividadePtr criarAtividade(int codigo, int capacidade, const char *nome);
EstudantePtr buscarEstudanteEmAtividade(AtividadePtr atividade, const int matricula);
void imprimirDados(AtividadePtr atividade);
int inscreverEstudante(AtividadePtr atividade, EstudantePtr estudante);
void destruirAtividade(AtividadePtr atividade);
int aumentarCapacidade(AtividadePtr atividade, const int incremento);
int getCodigo(AtividadePtr atividade);
int getCapacidade(AtividadePtr atividade);
int getQntEspera(AtividadePtr atividade);
ListaPtr getLista(AtividadePtr atividade);

#endif