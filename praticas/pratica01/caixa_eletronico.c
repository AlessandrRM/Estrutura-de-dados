#include <stdio.h>
void processar_saque(int valor_original) {
    int cedulas[] = {200, 100, 50, 20, 10, 5, 2};
    int total_cedulas = sizeof(cedulas) / sizeof(cedulas[0]);
    int valor = valor_original;

    printf("Solicitacao: R$ %d\n", valor_original);

    if (valor <= 0 || valor > 1000) {
        printf("Resultado: Operacao Negada (Limite de R$ 2 a R$ 1000)\n");
        return;
    }

    for (int i = 0; i < total_cedulas; i++) {
        int qtd_notas = valor / cedulas[i];
        if (qtd_notas > 0) {
            printf("%d notas de R$ %d\n", qtd_notas, cedulas[i]);
            valor %= cedulas[i];
        }
    }

    if (valor > 0) {
        printf(" -> Sobra: R$ %d (sem notas disponiveis)\n", valor);
    }
}

int main (){
    printf("===testes===\n");
    printf("\n==========\n");
    processar_saque(380);
    printf("\n==========\n");
    processar_saque(7);
    printf("\n==========\n");
    processar_saque(2);
    printf("\n==========\n");
    processar_saque(1000);
    printf("\n==========\n");
    processar_saque(1500);
    printf("\n==========\n");
    processar_saque(-50);
    printf("\n==========\n");

    return 0;
}