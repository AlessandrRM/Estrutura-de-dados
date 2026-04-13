#include <stdio.h>

#include <stdio.h>

double calcular_media(int lista[], int tamanho) {
    if (tamanho <= 0) return 0.0; 

    double soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += lista[i];
    }
    return soma / tamanho;
}

void executar_teste(int valores[], int n, char* nome_teste) {
    printf("\n--- %s ---\n", nome_teste);
    printf("Valores: ");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", valores[i]);
    }
    
    double media = calcular_media(valores, n);
    printf("\nResultado da Media: %.2f\n", media);
}

int main(){
    printf("================\n");
    int t1[] = {10, 20, 30, 40};
    executar_teste(t1, 4, "Lista Comum");
    int t2[] = {100};
    executar_teste(t2, 1, "Um Elemento");
    int t3[] = {-10, 10, -5, 5, 0};
    executar_teste(t3, 5, "Valores Mistos");
    printf("\nLista Vazia \n");
    double media_vazia = calcular_media(NULL, 0);
    printf("Resultado da Media : %.2f\n", media_vazia);
    return 0;
}
