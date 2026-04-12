#include <stdio.h>
void processar_saque(int valor) {
    int cedulas[] = {200, 100, 50, 20, 10, 5, 2};
    int total_cedulas = sizeof(cedulas) / sizeof(cedulas[0]);

    printf("\n--- Detalhes do Saque ---\n");
    for (int i = 0; i < total_cedulas; i++) {
        int qtd_notas = valor / cedulas[i];
        if (qtd_notas > 0) {
            printf("%d nota(s) de R$ %d\n", qtd_notas, cedulas[i]);
            valor %= cedulas[i]; 
        }
    }

    if (valor > 0) {
        printf("Aviso: Nao foi possivel entregar R$ %d (notas indisponiveis).\n", valor);
    }
}

int main (){
    int valor_saque;

    printf("Digite o valor para saque (Limite R$ 1000): ");
    if (scanf("%d", &valor_saque) != 1) {
        printf("Erro: Entrada invalida.\n");
        return 1;
    }

    
    if (valor_saque <= 0 || valor_saque > 1000) {
        printf("Operacao invalida! O valor deve ser entre R$ 2 e R$ 1000.\n");
    } else {
        processar_saque(valor_saque);
    }

    return 0;
}