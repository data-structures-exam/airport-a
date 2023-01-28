#ifndef PILHA_BAGAGEM_H
#define PILHA_BAGAGEM_H

#include "bagagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BAGS_PILHA 3 // número máximo de bagagens por pilha

struct tPilha_Bagagem {
	Bagagem *bagagens[MAX_BAGS_PILHA];
	int num_voo, topo;
};


typedef struct tPilha_Bagagem Pilha_Bagagem;

Pilha_Bagagem *criar_pilha_bagagem(int num_voo);
void imprimir_pilha_bagagem(Pilha_Bagagem *pilha);
bool bagagem_encontrada(Pilha_Bagagem *pilha, char nome[]);
void empilhar_bagagem(Pilha_Bagagem *pilha, Bagagem *bag);
void desempilhar_bagagem(Pilha_Bagagem *pilha);
int pilha_vazia(Pilha_Bagagem *pilha);
void destruir_pilha_bagagem(Pilha_Bagagem *pilha);
int pilha_cheia(Pilha_Bagagem *pilha);

#endif
