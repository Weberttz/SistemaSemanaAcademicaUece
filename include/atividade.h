#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#include "lista.h"
#include "fila.h"

typedef struct Atividade *AtividadePtr;

AtividadePtr criarAtividade(int codigo, int capacidade, const char *nome);
EstudantePtr buscarEstudanteEmAtividade(AtividadePtr atividade, const int matricula);
void imprimirDados(AtividadePtr atividade);
int inscreverEstudante(AtividadePtr atividade, EstudantePtr estudante);
int removerEstudanteAtividade(AtividadePtr atividade, const int matricula);
int promoverFilaEspera(AtividadePtr atividade, EstudantePtr *promovido);
void destruirAtividade(AtividadePtr atividade);
int aumentarCapacidade(AtividadePtr atividade, const int incremento);
int promoverEstudantes(AtividadePtr atividade, const int incremento);
int getCodigo(AtividadePtr atividade);
int getCapacidade(AtividadePtr atividade);
int getQntEspera(AtividadePtr atividade);
char *getTitulo(AtividadePtr atividade);
ListaPtr getLista(AtividadePtr atividade);
FilaPtr getFila(AtividadePtr atividade);

#endif