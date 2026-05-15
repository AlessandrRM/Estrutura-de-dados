#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAM 100

int main() {
    int vetor[TAM];
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) vetor[i] = rand() % 1000;

    clock_t inicio, fim;
    
    int alvo = vetor[50]; 
    inicio = clock();
    int pos = linear_search(vetor, TAM, alvo);
    fim = clock();
    printf("Linear Search (encontrou no indice %d): %f segundos\n", 
            pos, (double)(fim - inicio) / CLOCKS_PER_SEC);

    inicio = clock();
    int valor = quick_select(vetor, 0, TAM - 1, 50);
    fim = clock();
    printf("Quick Select (50º menor elemento é %d): %f segundos\n", 
            valor, (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}