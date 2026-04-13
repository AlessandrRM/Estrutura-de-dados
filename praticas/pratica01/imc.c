#include <stdio.h>
float calcular_imc(float peso, float altura) {
    if (peso <= 0 || altura <= 0) {
        return -1.0; 
    }
    return peso / (altura * altura);
}

void classificar_imc(float imc) {
    if (imc < 0) {
        printf("Erro: Peso ou altura invalidos.\n");
        return;
    }

    printf("IMC: %.2f - Status: ", imc);
    if (imc < 18.5) printf("Abaixo do peso\n");
    else if (imc < 25.0) printf("Peso ideal\n");
    else if (imc < 30.0) printf("Sobrepeso\n");
    else if (imc < 35.0) printf("Obesidade Grau I\n");
    else if (imc < 40.0) printf("Obesidade Grau II\n");
    else printf("Obesidade Grau III\n");
}
int main() {
    float imc;
    imc = calcular_imc(0, 1.75);
    classificar_imc(imc);
    imc = calcular_imc(50.0, 1.75);
    classificar_imc(imc);
    imc = calcular_imc(70.0, 1.75);
    classificar_imc(imc);
    imc = calcular_imc(85.0, 1.75);
    classificar_imc(imc);
    imc = calcular_imc(130.0, 1.75);
    classificar_imc(imc);
    return 0;
}
