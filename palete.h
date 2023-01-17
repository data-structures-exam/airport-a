#ifndef PALETE_H
#define PALETE_H

#include "pilha_bagagem.h"

typedef struct tPalete Palete;

Palete *criar_palete(int num_voo);
void inserir_bagagens(Palete *p, Pilha_Bagagem *pilha_bagagens);
void destruir_palete(Palete *p);

#endif
