#include <stdio.h>
#include "fila.h"

int main() {
    Fila minha_fila = fila_criar();

    if (fila_esta_vazia(minha_fila)) {
        printf("Fila inicio.\n");
    }

    fila_enfileirar(minha_fila, 10);
    fila_enfileirar(minha_fila, 20);
    fila_enfileirar(minha_fila, 30);
    fila_enfileirar(minha_fila, 40);

    lista_exibir(minha_fila);

    int valor_inicio;
    if (fila_inicio(minha_fila, &valor_inicio)) {
        printf("Inicio atual: %d\n", valor_inicio);
    }

    int item_removido;
    if (fila_desenfileirar(minha_fila, &item_removido)) {
        printf("Removido: %d\n", item_removido);
    }
    if (fila_desenfileirar(minha_fila, &item_removido)) {
        printf("Removido: %d\n", item_removido);
    }

    lista_exibir(minha_fila);

    if (fila_inicio(minha_fila, &valor_inicio)) {
        printf("Novo inicio: %d\n", valor_inicio);
    }

    fila_destruir(minha_fila);
    return 0;
}