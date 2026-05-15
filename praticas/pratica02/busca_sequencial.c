#include <stdio.h>
#include <time.h>
//Análise
/*
 * Complexidade Assintótica:
 * - Melhor Caso: O(1) - O elemento está na primeira posição.
 * - Pior Caso: O(n) - O elemento está na última posição ou não existe no vetor.
 */
int buscaSequencial(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) return i;
    }
    return -1;
}
void medirTempoBusca(int vetor[], int tamanho, int valor, const char* descricao) {
    int repeticoes = 1000000; 
    clock_t inicio = clock();
    
    for(int i = 0; i < repeticoes; i++) {
        buscaSequencial(vetor, tamanho, valor);
    }
    
    clock_t fim = clock();
    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    printf("%s: %.8f segundos\n", descricao, tempo_gasto);
}

int main() {
    int tamanho = 100;
    int vetor[100];
    for (int i = 0; i < tamanho; i++) vetor[i] = i;

    printf("--- Testes de Tempo de Busca (100 elementos, 1 milhao de repeticoes) ---\n");

    medirTempoBusca(vetor, tamanho, 0, "Melhor caso");
    medirTempoBusca(vetor, tamanho, 50, "Caso medio");
    medirTempoBusca(vetor, tamanho, 99, "Pior caso");
    medirTempoBusca(vetor, tamanho, 999, "Caso inexistente");

    return 0;
}