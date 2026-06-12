#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    int valor;
    struct no_t* esquerda;
    struct no_t* direita;
} no_t;

typedef struct arvore_t {
    no_t* raiz;
} arvore_t;

Arvore arvore_criar() {
    arvore_t* a = (arvore_t*) malloc(sizeof(arvore_t));
    if (a != NULL) {
        a->raiz = NULL;
    }
    return a;
}

bool arvore_esta_vazia(Arvore a) {
    if (a == NULL) return true;
    return (a->raiz == NULL);
}

no_t* inserir_no(no_t* raiz, int valor, bool* sucesso) {
    if (raiz == NULL) {
        no_t* novo = (no_t*) malloc(sizeof(no_t));
        if (novo == NULL) {
            *sucesso = false;
            return NULL;
        }
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        *sucesso = true;
        return novo;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_no(raiz->esquerda, valor, sucesso);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_no(raiz->direita, valor, sucesso);
    } else {
        *sucesso = false;
    }

    return raiz;
}

bool arvore_inserir(Arvore a, int valor) {
    if (a == NULL) return false;
    bool sucesso = false;
    a->raiz = inserir_no(a->raiz, valor, &sucesso);
    return sucesso;
}

void pre_ordem(no_t* raiz) {
    if (raiz != NULL) {
        printf("[%d] ", raiz->valor);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void arvore_exibir_pre_ordem(Arvore a) {
    if (a == NULL || arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Pre-Ordem: ");
    pre_ordem(a->raiz);
    printf("\n");
}

void em_ordem(no_t* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esquerda);
        printf("[%d] ", raiz->valor);
        em_ordem(raiz->direita);
    }
}

void arvore_exibir_em_ordem(Arvore a) {
    if (a == NULL || arvore_esta_vazia(a)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Em-Ordem: ");
    em_ordem(a->raiz);
    printf("\n");
}

void destruir_nos(no_t* raiz) {
    if (raiz != NULL) {
        destruir_nos(raiz->esquerda);
        destruir_nos(raiz->direita);
        free(raiz);
    }
}

void arvore_destruir(Arvore a) {
    if (a == NULL) return;
    destruir_nos(a->raiz);
    free(a);
}