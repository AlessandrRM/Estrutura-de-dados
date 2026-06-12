#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

typedef struct fila_t {
    no_t* inicio;
    no_t* fim;
} fila_t;

Fila fila_criar() {
    fila_t* f = (fila_t*) malloc(sizeof(fila_t));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }
    return f;
}

bool fila_esta_vazia(Fila f) {
    if (f == NULL) return true;
    return (f->inicio == NULL);
}

bool fila_enfileirar(Fila f, int valor) {
    if (f == NULL) return false;

    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return false;

    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_esta_vazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->proximo = novo;
    }
    
    f->fim = novo;
    return true;
}

bool fila_desenfileirar(Fila f, int* valor) {
    if (f == NULL || fila_esta_vazia(f)) return false;

    no_t* auxiliar = f->inicio;
    if (valor != NULL) {
        *valor = auxiliar->valor;
    }

    f->inicio = auxiliar->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(auxiliar);
    return true;
}

bool fila_inicio(Fila f, int* valor) {
    if (f == NULL || fila_esta_vazia(f) || valor == NULL) return false;
    
    *valor = f->inicio->valor;
    return true;
}

void lista_exibir(Fila f) {
    if (f == NULL || fila_esta_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    no_t* atual = f->inicio;
    printf("Fila (Inicio -> Fim): ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void fila_destruir(Fila f) {
    if (f == NULL) return;

    no_t* atual = f->inicio;
    while (atual != NULL) {
        no_t* auxiliar = atual->proximo;
        free(atual);
        atual = auxiliar;
    }
    free(f);
}