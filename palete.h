#ifndef PALETE_H
#define PALETE_H

#include "pilha_bagagem.h"

typedef struct tPalete Palete;

Palete *criar_palete(int num_voo);
void inserir_bagagens(ListaPalete **l, Pilha_Bagagem *pilha_bagagens);
void destruirPalete(ListaPalete **l);

#endif
