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
void testar_potencia(int base, int expoente) {
    printf("Calculando: %d elevado a %d\n", base, expoente);
    
    if (expoente < 0) {
        printf(
        "Resultado: Erro (Expoente negativo)\n");
    } else {
        int resultado = calcular_potencia(base, expoente);
        printf("Resultado: %d\n", resultado);
    }
}
int main (){
    testar_potencia(2, 3);
    testar_potencia(5, 1); 
    testar_potencia(10, 0); 
    testar_potencia(0, 5); 
    testar_potencia(-3, 2); 
    testar_potencia(2, -1); 
    return 0;
}