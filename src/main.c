#include <stdio.h>
#include "../include/lista.h"

int main(){

    Estudante estudante1 = {123, "Jonh_Webert"};
    Estudante estudante2 = {124, "Antônio_Frotta"};

    // criar lista, utilizando encapsulamento
    ListaEncadeada *lista = criarLista();

    if(lista == NULL) {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    inicializarLista(lista);
    inserirNoInicio(lista, estudante1);
    imprimirLista(lista);

    inserirNoInicio(lista, estudante2);
    imprimirLista(lista);

    finalizarLista(lista);

    return 0;
}