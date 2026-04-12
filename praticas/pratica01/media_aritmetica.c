#include <stdio.h>

double calcular_media(int lista[], int tamanho) {
    if (tamanho <= 0) return 0.0; 

    double soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += lista[i];
    }
    return soma / tamanho;
}

void imprimir_valores(int lista[], int tamanho) {
    printf("Valores processados: ");
    for (int i = 0; i < tamanho; i++) {
        printf("[%d] ", lista[i]);
    }
    printf("\n");
}

int main(){
    int n;

    printf("Quantidade de valores: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Quantidade invalida!\n");
        return 1;
    }

    int valores[n];
    for (int i = 0; i < n; i++) {
        printf("Digite o %do valor: ", i + 1);
        scanf("%d", &valores[i]);
    }

    imprimir_valores(valores, n);
    double media = calcular_media(valores, n);

    printf("---------------------------\n");
    printf("A media final e: %.2f\n", media);
    printf("---------------------------\n");

    return 0;
}
