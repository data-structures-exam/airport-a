#ifndef PALETE_H
#define PALETE_H

#include "pilha_bagagem.h"
#include <stdbool.h>

typedef struct tPalete Palete;

Palete *criar_palete(int num_voo);
void inserir_bagagens(Palete *p, Pilha_Bagagem *pilha_bagagens);
bool palete_cheia(Palete *p);
bool limite_pilhas_atingido(Palete *p);
bool palete_vazia(Palete *p);
void destruir_palete(Palete *p);

#endif
