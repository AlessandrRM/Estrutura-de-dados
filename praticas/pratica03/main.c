#include <stdio.h>
#include "conta.h"

int main() {
    Conta minha_conta = conta_criar(1001, 500.00);

    if (minha_conta == NULL) {
        printf("Erro ao criar conta.\n");
        return 1;
    }

    printf("Saldo inicial: R$ %.2f\n", conta_ver_saldo(minha_conta));

    conta_depositar(minha_conta, 250.50);
    printf("Saldo depois depósito de R$ 250.50: R$ %.2f\n", conta_ver_saldo(minha_conta));

    if (conta_sacar(minha_conta, 100.00)) {
        printf("Saque de R$ 100.00 realizado com sucesso.\n");
    } else {
        printf("Falha no saque: Saldo insuficiente.\n");
    }
    printf("Saldo atual: R$ %.2f\n", conta_ver_saldo(minha_conta));

    printf("Tentando sacar R$ 1000.00...\n");
    if (!conta_sacar(minha_conta, 1000.00)) {
        printf("Saque negado: Saldo insuficiente.\n");
    }

    conta_destruir(minha_conta);
    printf("Conta destruída com sucesso.\n");

    return 0;
}