#include "ordenacao.h"

void bubble_sort(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int min = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[min]) min = j;
        }
        int temp = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = temp;
    }
}

void quick_sort(int *vetor, int esquerda, int direita) {
    if (esquerda >= direita) return;
    int pivo = vetor[esquerda];
    int i = esquerda, j = direita;
    while (i <= j) {
        while (vetor[i] < pivo) i++;
        while (vetor[j] > pivo) j--;
        if (i <= j) {
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++; j--;
        }
    }
    quick_sort(vetor, esquerda, j);
    quick_sort(vetor, i, direita);
}