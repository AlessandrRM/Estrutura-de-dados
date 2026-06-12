#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct pilha_t* Pilha;

Pilha pilha_criar();
bool pilha_empilhar(Pilha p, int valor);   
bool pilha_desempilhar(Pilha p, int* valor);
bool pilha_topo(Pilha p, int* valor);        
bool pilha_esta_vazia(Pilha p);
void pilha_exibir(Pilha p);
void pilha_destruir(Pilha p);

#endif 