#include <stdio.h>
//Análise
/**
 * Iterativo
 * Complexidade de Tempo: O(n)
 * Complexidade de Espaço: O(1)
 */
 /**
 * Recursivo
 * Complexidade de Tempo: O(n)
 * Complexidade de Espaço: O(n) - devido à pilha de chamadas
 */
int fatorialIterativo(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int fatorialRecursivo(int n) {
    if (n <= 1) return 1;
    return n * fatorialRecursivo(n - 1);
}

int main() {
    int limite = 5;

    printf("Tabela de Fatoriais (0 a %d):\n", limite);
    printf("N\tIterativo\tRecursivo\n");
    printf("--------------testes-------------------------\n");

    for (int i = 0; i <= limite; i++) {
        int resI = fatorialIterativo(i);
        int resR = fatorialRecursivo(i);
        
        printf("%d\t%d\t\t%d\n", i, resI, resR);
    }

    return 0;
}