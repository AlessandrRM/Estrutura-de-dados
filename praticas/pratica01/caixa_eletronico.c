#include <stdio.h>
void opcao_saque(int valor_saque) {
    int cedulas[7] = {200, 100, 50, 20, 10, 5, 2};
    int valor_restante = valor_saque;

    printf("Saque de R$ %d:\n", valor_saque);

    for (int i = 0; i < 7; i++) {
        int qtd_notas = valor_restante / cedulas[i];
        if (qtd_notas > 0) {
            printf("%d nota(s) de R$ %d\n", qtd_notas, cedulas[i]);
            valor_restante = valor_restante % cedulas[i];
        }
    }
    if (valor_restante > 0) {
        printf("Não é possível sacar o restante de R$ %d com as notas disponíveis.\n", valor_restante);
    }
}

int main (){
    int valor_saque;
    printf("Digite o valor para saque: ");
    scanf("%d", &valor_saque);
    if(valor_saque>1000 || valor_saque<0 || valor_saque == 0){
        printf("Operação inválida\n SAQUE CANCELADA \n");
        return 1;
    }
    opcao_saque(valor_saque);
    return 0;
}