#ifndef HISTORICO_H
#define HISTORICO_H

typedef struct Historico *HistoricoPtr;

HistoricoPtr criarHistorico();

int registrarEvento(HistoricoPtr historico,
                    const char *tipo,
                    int codigoAtividade,
                    int matricula);

// imprimir os eventos em ordem cronologica
void imprimirHistorico(const HistoricoPtr historico);

void destruirHistorico(HistoricoPtr historico);

#endif
