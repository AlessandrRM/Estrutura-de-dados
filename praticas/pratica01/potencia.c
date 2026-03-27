#include <stdio.h>
int cal_expoente(int base, int expoente){
    int total = 1; 
    for(int i = 0; i<expoente; i++){
        total *= base;
    }
    return total;
}

int main (){
    int expoente;
    int base;
    printf("Digite a sua base: ");
    scanf("%d", &base); 
    printf("Digite o seu expeonte: ");
    scanf("%d", &expoente); 
    int resultado = 0;
    resultado = cal_expoente(base,expoente);
    printf("Resultado é: %d\n", resultado);
    return 0;
}