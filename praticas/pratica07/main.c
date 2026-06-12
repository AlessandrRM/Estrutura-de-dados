#include <stdio.h>
#include "pilha.h"

int main() {

    Pilha minha_pilha = pilha_criar();

    if (pilha_esta_vazia(minha_pilha)) {
        printf("Pilha criada\n\n");
    }

    printf("Empilhando\n");
    pilha_empilhar(minha_pilha, 5);
    pilha_empilhar(minha_pilha, 15);
    pilha_empilhar(minha_pilha, 25);
    pilha_empilhar(minha_pilha, 35);

    pilha_exibir(minha_pilha);


    int valor_topo;
    if (pilha_topo(minha_pilha, &valor_topo)) {
        printf("\nElemento no topo atual: %d (esperado: 35)\n", valor_topo);
    }

    int item_removido;
    printf("\nDesempilhando\n");
    
    if (pilha_desempilhar(minha_pilha, &item_removido)) {
        printf("Removido: %d\n", item_removido);
    }
    if (pilha_desempilhar(minha_pilha, &item_removido)) {
        printf("Removido: %d\n", item_removido);
    }

    pilha_exibir(minha_pilha);


    pilha_destruir(minha_pilha);

    return 0;
}