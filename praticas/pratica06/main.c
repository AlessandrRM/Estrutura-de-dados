#include <stdio.h>
#include "lista_linear.h"

int main() {
    Lista minha_lista = lista_criar();
    
    if (lista_esta_vazia(minha_lista)) {
        printf("A lista  criada \n");
    }

    printf("\nInserindo elementos: \n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_inserir(minha_lista, 40);
    
    lista_exibir(minha_lista);

    printf("\nBuscando:\n");
    int pos30 = lista_buscar(minha_lista, 30);
    int pos50 = lista_buscar(minha_lista, 50);
    
    printf("Valor 30 no índice: %d\n", pos30);
    printf("Valor 50 no índice: %d (esperado -1)\n", pos50);


    printf("\nRemovendo 20 (meio):\n");
    lista_remover(minha_lista, 20);
    lista_exibir(minha_lista);

    printf("\nRemovendo 10 (início):\n");
    lista_remover(minha_lista, 10);
    lista_exibir(minha_lista);

    printf("\nRemovendo 40 (fim):\n");
    lista_remover(minha_lista, 40);
    lista_exibir(minha_lista);

    lista_destruir(minha_lista);

    return 0;
}