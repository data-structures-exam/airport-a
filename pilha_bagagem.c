#include "pilha_bagagem.h"
#include "bagagem.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS_PILHA 3 // número máximo de bagagens por pilha

struct tPilha_Bagagem {
	Bagagem *bagagens[MAX_BAGS_PILHA];
	int topo = -1;
};

Pilha_Bagagem *criar_pilha_bagagem() {
	Pilha_Bagagem *pilha = (Pilha_Bagagem *)malloc(sizeof(Pilha_Bagagem));
	if (!pilha) {
		printf("Erro: malloc falhou em 'criar_pilha_bagagem'\n");
		return NULL;
	}

	pilha->topo = -1;
	return pilha;
}

void empilhar_bagagem(Pilha_Bagagem *pilha, Bagagem *bag) {
	if(stack_overflow(pilha)) {
		printf("Erro: pilha cheia\n");
		return;
	}

	pilha->bagagens[++pilha->topo] = bag;
}

void desempilhar_bagagem(Pilha_Bagagem *pilha) {
	if(pilha_vazia(pilha)) {
		printf("Erro: pilha vazia\n");
		return;
	}

	destruir_bagagem(pilha->bagagens[pilha->top--]);
}

int pilha_vazia(Pilha_Bagagem *pilha) {
	return pilha->top < 0;
}

void destruir_pilha_bagagem(Pilha_Bagagem *pilha) {
	while (pilha->top-- >= 0)
		destruir_bagagem(pilha->bagagens[pilha->top]);
	free(pilha);
}

int stack_overflow(Pilha_Bagagem *pilha) {
	return pilha->top >= MAX_BAGS_PILHA - 1;
}


