#include <stdio.h>
#include "tabela_hash.h"

int main() {
    TabelaHash minha_hash = hash_criar(7);

    if (hash_esta_vazia(minha_hash)) {
        printf("Tabela Hash inicio com 7.\n\n");
    }

    hash_inserir(minha_hash, 15);
    hash_inserir(minha_hash, 22);
    hash_inserir(minha_hash, 30);
    hash_inserir(minha_hash, 44);
    hash_inserir(minha_hash, 10);
    hash_inserir(minha_hash, 17);

    printf("--- Estado Inicio-\n");
    hash_exibir(minha_hash);

    printf("\n-- Buscas ---\n");
    printf("Buscar 30: %s\n", hash_buscar(minha_hash, 30) ? "Encontrado" : "Nao encontrado");
    printf("Buscar 50: %s\n", hash_buscar(minha_hash, 50) ? "Encontrado" : "Nao encontrado");

    printf("\n--- Testando Remocoes ---\n");
    printf("Remover 22 (inicio da lista no indice 1): %s\n", hash_remover(minha_hash, 22) ? "Sucesso" : "erro");
    printf("Remover 17 (meio/fim da lista no indice 3): %s\n", hash_remover(minha_hash, 17) ? "Sucesso" : "erro");

    printf("\n---  Final--\n");
    hash_exibir(minha_hash);

    hash_destruir(minha_hash);
    return 0;
}