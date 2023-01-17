#ifndef PILHA_BAGAGEM_H
#define PILHA_BAGAGEM_H

#include "bagagem.c"
typedef struct tPilha_Bagagem Pilha_Bagagem;

Pilha_Bagagem *criar_pilha_bagagem();
void empilhar_bagagem(Pilha_Bagagem *pilha, Bagagem *bag);
void desempilhar_bagagem(Pilha_Bagagem *pilha);
int pilha_vazia(Pilha_Bagagem *pilha);
void destruir_pilha_bagagem(Pilha_Bagagem *pilha);
int stack_overflow(Pilha_Bagagem *pilha);

#endif
