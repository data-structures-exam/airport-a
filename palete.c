#include "palete.h"
#include "pilha_bagagem.h"
#include "bagagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_MAX_PILHA 3 // número máximo de pilhas de bagagens por palete

struct tPalete{
  int num_voo, pos;
  Pilha_Bagagem *pilha_bagagens[NUM_MAX_PILHA];
};

Palete *criar_palete(int num_voo){
    Palete *novo = (Palete *)malloc(sizeof(Palete));
    if(!novo){
        printf("Erro: malloc falhou em 'criar_palete'\n");
        return NULL;
    }
    novo->pos = -1;
    novo->num_voo = num_voo;
    return novo;
}

void inserir_bagagens(Palete *p, Pilha_Bagagem *pilha_bagagens){
	if(limite_pilhas_atingido(p)) {
		printf("Erro: limite de pilhas de bagagem por palete atingido\n");
		return;
	}

	if(p->num_voo != pilha_bagagens->num_voo) {
		printf("Erro: número de voo da palete e da pilha não correspondem\n");
		return;
	}

	p->pilha_bagagens[++p->pos] = pilha_bagagens;		
}

void inserir_bagagem(Palete *p, Bagagem *bag) {
	if (!bag) {
		printf ("Erro: bagagem inválida/nula\n");
		return;
	}

	if (palete_cheia(p)) {
		printf ("Erro: palete cheia\n");
		return;
	}

	empilhar_bagagem(p->pilha_bagagens[p->pos], bag);		
}

bool palete_cheia(Palete *p) {
	return limite_pilhas_atingido(p) && pilha_cheia(p->pilha_bagagens[p->pos]);
}

bool limite_pilhas_atingido(Palete *p) {
	return p->pos >= NUM_MAX_PILHA - 1;
}

bool palete_vazia(Palete *p) {
	return p->pos == -1;
}

void destruir_palete(Palete *p){
	if (!palete_vazia(p)) {
		while (p->pos >= 0)
			destruir_pilha_bagagem(p->pilha_bagagens[p->pos--]);
	}

	free(p);
}
