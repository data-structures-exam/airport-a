#include "lista_palete.h"
#include "pilha_bagagem.h"
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
	if(palete_cheia(p)) {
		printf("Erro: palete cheia\n");
		return;
	}

	p->pilha_bagagens[++p->pos] = pilha_bagagens;		
}

bool palete_cheia(Palete *p) {
	return p->pos >= NUM_MAX_PILHA;
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


