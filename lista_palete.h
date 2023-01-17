#ifndef LISTA_PALETE_H
#define LISTA_PALETE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha_bagagem.c"

typedef struct tPalete ListaPalete;

ListaPalete *criarListaPalete(int num_voo);
void adicionarBagagemPalete(ListaPalete **l, Pilha_Bagagem *pilha_bagagens);
void destruirPalete(ListaPalete **l);
#endif
