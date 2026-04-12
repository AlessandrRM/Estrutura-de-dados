#include <stdio.h>
int calcular_potencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    }
    
    int total = 1; 
    for(int i = 0; i < expoente; i++) {
        total *= base;
    }
    return total;
}

int main (){
    int base, expoente;

    printf("--- Calculadora de Potencia ---\n");
    printf("Digite a base: ");
    scanf("%d", &base); 
    
    printf("Digite o expoente (deve ser >= 0): ");
    scanf("%d", &expoente); 

    if (expoente < 0) {
        printf("Erro\n");
    } else {
        int resultado = calcular_potencia(base, expoente);
        printf("Resultado: %d elevado a %d = %d\n", base, expoente, resultado);
    }

    return 0;
}