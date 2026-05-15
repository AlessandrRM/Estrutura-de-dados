#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ordenacao.h"
#define TAM 100

void copiar_vetor(int *origem, int *destino) {
    memcpy(destino, origem, TAM * sizeof(int));
}

int main() {
    int original[TAM], temp[TAM];
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) original[i] = rand() % 1000;

    clock_t inicio, fim;

    //Bubble Sort
    copiar_vetor(original, temp);
    inicio = clock();
    bubble_sort(temp, TAM);
    fim = clock();
    printf("Bubble Sort: %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    //Selection Sort
    copiar_vetor(original, temp);
    inicio = clock();
    selection_sort(temp, TAM);
    fim = clock();
    printf("Selection Sort: %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    //Quick Sort
    copiar_vetor(original, temp);
    inicio = clock();
    quick_sort(temp, 0, TAM - 1);
    fim = clock();
    printf("Quick Sort: %f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}