#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef struct fila_t* Fila;

Fila fila_criar();
bool fila_enfileirar(Fila f, int valor);
bool fila_desenfileirar(Fila f, int* valor);
bool fila_inicio(Fila f, int* valor);
void lista_exibir(Fila f);
bool fila_esta_vazia(Fila f);
void fila_destruir(Fila f);

#endif