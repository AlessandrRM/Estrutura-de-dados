#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;


typedef struct pilha_t {
    no_t* topo;
} pilha_t;

Pilha pilha_criar() {
    pilha_t* p = (pilha_t*) malloc(sizeof(pilha_t));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

bool pilha_esta_vazia(Pilha p) {
    if (p == NULL) return true;
    return (p->topo == NULL);
}


bool pilha_empilhar(Pilha p, int valor) {
    if (p == NULL) return false;

    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return false;

    novo->valor = valor;
    novo->proximo = p->topo; 
    p->topo = novo;          
    return true;
}

bool pilha_desempilhar(Pilha p, int* valor) {
    if (p == NULL || pilha_esta_vazia(p)) return false;

    no_t* auxiliar = p->topo;
    if (valor != NULL) {
        *valor = auxiliar->valor; 
    }

    p->topo = auxiliar->proximo; 
    free(auxiliar);              

    return true;
}

bool pilha_topo(Pilha p, int* valor) {
    if (p == NULL || pilha_esta_vazia(p) || valor == NULL) return false;
    
    *valor = p->topo->valor;
    return true;
}

void pilha_exibir(Pilha p) {
    if (p == NULL || pilha_esta_vazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }

    no_t* atual = p->topo;
    printf("Pilha (Topo -> Base):\n");
    while (atual != NULL) {
        printf(" %3d \n", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void pilha_destruir(Pilha p) {
    if (p == NULL) return;

    no_t* atual = p->topo;
    while (atual != NULL) {
        no_t* auxiliar = atual->proximo;
        free(atual);
        atual = auxiliar;
    }
    free(p);
}