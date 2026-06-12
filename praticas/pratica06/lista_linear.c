#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    int valor;
    struct no_t* anterior;
    struct no_t* proximo;
} no_t;

typedef struct lista_t {
    no_t* primeiro;
    no_t* ultimo;
} lista_t;


Lista lista_criar() {
    lista_t* l = (lista_t*) malloc(sizeof(lista_t));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}


bool lista_esta_vazia(Lista l) {
    if (l == NULL) return true;
    return (l->primeiro == NULL);
}

bool lista_inserir(Lista l, int valor) {
    if (l == NULL) return false;

    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return false;

    novo->valor = valor;
    novo->proximo = NULL;

    if (lista_esta_vazia(l)) {
        novo->anterior = NULL;
        l->primeiro = novo;
        l->ultimo = novo;
    } else {
        novo->anterior = l->ultimo;
        l->ultimo->proximo = novo;
        l->ultimo = novo;
    }
    return true;
}

bool lista_remover(Lista l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return false;

    no_t* atual = l->primeiro;

    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) return false;


    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        l->primeiro = atual->proximo; 
    }

    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    } else {
        l->ultimo = atual->anterior; 
    }

    free(atual);
    return true;
}

int lista_buscar(Lista l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return -1;

    no_t* atual = l->primeiro;
    int indice = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return indice;
        }
        atual = atual->proximo;
        indice++;
    }
    return -1;
}


void lista_exibir(Lista l) {
    if (l == NULL || lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }

    no_t* atual = l->primeiro;
    printf("Lista: ");
    while (atual != NULL) {
        printf("[%d] ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}


void lista_destruir(Lista l) {
    if (l == NULL) return;

    no_t* atual = l->primeiro;
    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(l);
}