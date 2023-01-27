#ifndef PALETE_H
#define PALETE_H

#include "pilha_bagagem.h"
#include "bagagem.h"
#include <stdbool.h>

#define NUM_MAX_PILHA 3 // número máximo de pilhas de bagagens por palete
struct tPalete{
  int num_voo, pos;
  Pilha_Bagagem *pilha_bagagens[NUM_MAX_PILHA];
};


typedef struct tPalete Palete;

Palete *criar_palete(int num_voo);
void inserir_pilha_bagagens(Palete *p, Pilha_Bagagem *pilha_bagagens);
void inserir_bagagem(Palete *p, Bagagem *bag);
bool palete_cheia(Palete *p);
bool limite_pilhas_atingido(Palete *p);
bool palete_vazia(Palete *p);
void destruir_palete(Palete *p);

#endif
