#include <stdio.h>
#include <time.h>
#define TAM 10
//Análise
/*
 * Complexidade Assintótica 
 * Ambas as soluções percorrem todos os N*N elementos.
 * - Dois laços: O(n²)
 * - Um laço: O(n²) 
 * (Embora a complexidade seja a mesma, o acesso com um laço pode ser 
 * marginalmente mais rápido devido à redução da sobrecarga de controle de loops).
 */

void percorrerDoisLacos(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            int val = matriz[i][j];
        }
    }
}

void percorrerUmLaco(int matriz[TAM][TAM]) {
    int *ptr = (int *)matriz;
    for (int i = 0; i < TAM * TAM; i++) {
        int val = ptr[i];
    }
}

void realizarTeste(void (*funcao)(int[TAM][TAM]), int matriz[TAM][TAM], const char* nome) {
    int repeticoes = 1000000;
    clock_t inicio = clock();
    
    for (int i = 0; i < repeticoes; i++) {
        funcao(matriz);
    }
    
    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("%s: %.6f segundos\n", nome, tempo);
}

int main() {
    int matriz[TAM][TAM];
    
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = i + j;
        }
    }

    printf("--- testes ---\n");
    
    realizarTeste(percorrerDoisLacos, matriz, "Com dois laços");
    realizarTeste(percorrerUmLaco, matriz, "Com um laço");

    return 0;
}