#include "selecao.h"

int linear_search(int *vetor, int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) return i;
    }
    return -1;
}

int particao(int *vetor, int esquerda, int direita) {
    int pivo = vetor[direita];
    int i = esquerda;
    for (int j = esquerda; j < direita; j++) {
        if (vetor[j] <= pivo) {
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
            i++;
        }
    }
    int temp = vetor[i];
    vetor[i] = vetor[direita];
    vetor[direita] = temp;
    return i;
}

int quick_select(int *vetor, int esquerda, int direita, int k) {
    if (esquerda == direita) return vetor[esquerda];
    
    int pivo_index = particao(vetor, esquerda, direita);
    
    if (k == pivo_index) return vetor[k];
    else if (k < pivo_index) return quick_select(vetor, esquerda, pivo_index - 1, k);
    else return quick_select(vetor, pivo_index + 1, direita, k);
}