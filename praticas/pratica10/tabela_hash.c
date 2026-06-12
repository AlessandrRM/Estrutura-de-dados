#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

typedef struct hash_t {
    no_t** tabela;
    int tamanho;
} hash_t;

int funcao_hash(int valor, int tamanho) {
    int codigo = valor % tamanho;
    if (codigo < 0) {
        codigo += tamanho;
    }
    return codigo;
}

TabelaHash hash_criar(int tamanho) {
    if (tamanho <= 0) return NULL;

    hash_t* h = (hash_t*) malloc(sizeof(hash_t));
    if (h == NULL) return NULL;

    h->tamanho = tamanho;
    h->tabela = (no_t**) malloc(tamanho * sizeof(no_t*));
    
    if (h->tabela == NULL) {
        free(h);
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        h->tabela[i] = NULL;
    }

    return h;
}

bool hash_esta_vazia(TabelaHash h) {
    if (h == NULL) return true;

    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) {
            return false;
        }
    }
    return true;
}

bool hash_inserir(TabelaHash h, int valor) {
    if (h == NULL) return false;

    if (hash_buscar(h, valor)) return false;

    int indice = funcao_hash(valor, h->tamanho);

    no_t* novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return false;

    novo->valor = valor;
    novo->proximo = h->tabela[indice];
    h->tabela[indice] = novo;

    return true;
}

bool hash_buscar(TabelaHash h, int valor) {
    if (h == NULL) return false;

    int indice = funcao_hash(valor, h->tamanho);
    no_t* atual = h->tabela[indice];

    while (atual != NULL) {
        if (atual->valor == valor) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

bool hash_remover(TabelaHash h, int valor) {
    if (h == NULL) return false;

    int indice = funcao_hash(valor, h->tamanho);
    no_t* atual = h->tabela[indice];
    no_t* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return false;

    if (anterior == NULL) {
        h->tabela[indice] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return true;
}

void hash_exibir(TabelaHash h) {
    if (h == NULL) return;

    for (int i = 0; i < h->tamanho; i++) {
        printf("[%d]: ", i);
        no_t* atual = h->tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximo;
        }
        printf("NULL\n");
    }
}

void hash_destruir(TabelaHash h) {
    if (h == NULL) return;

    for (int i = 0; i < h->tamanho; i++) {
        no_t* atual = h->tabela[i];
        while (atual != NULL) {
            no_t* auxiliar = atual->proximo;
            free(atual);
            atual = auxiliar;
        }
    }
    free(h->tabela);
    free(h);
}