#include "voo.h"
#include "data.h"
#include "palete.c"
#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PAL_VOO 5 // número máximo de paletes por voo

struct tVoo {
	int num;
	Data *data;
	char origem[STR_TAM_MAX], destino[STR_TAM_MAX];
	bool fechado; // false se o avião não está pronto, true caso contrário
	int pos; // refere-se à lista de paletes
	Palete *paletes[MAX_PAL_VOO];
};

Voo *criar_voo(int num, Data *data, char origem[], char destino[]) {
	Voo *voo = (Voo *)malloc(sizeof(Voo));
	if(!voo) {
		printf("Erro: malloc falhou em 'criar_voo'\n");
		return NULL;
	}

	voo->num = num;
	voo->data = data;
	strcpy(voo->origem, origem);
	strcpy(voo->destino, destino);
	voo->pos = -1;
	voo->fechado = false;
	return voo;
}

void carregar_palete(Voo *voo, Palete *p) {
	if (!voo) {
		printf ("Erro: voo inválido/nulo\n");
		return;
	}

	if (!p) {
		printf ("Erro: palete inválida/nula\n");
		return;
	}

	if(porao_cheio(voo)) {
		printf("Erro: porão do avião cheio\n");
		return;
	}

	if(voo->num != p->num_voo) {
		printf("Erro: número de voo na palete não corresponde à esse voo\n");
		return;
	}

	voo->paletes[++voo->pos] = p;
}	

bool porao_cheio(Voo *voo) {
	if (!voo) {
		printf ("Erro: voo inválido/nulo\n");
		return;
	}

	return voo->pos >= MAX_PAL_VOO - 1;
}

bool porao_vazio(Voo *voo) {
	if (!voo) {
		printf ("Erro: voo inválido/nulo\n");
		return;
	}

	return voo->pos == -1;
}

void destruir_voo(Voo *voo) {
	if (!voo) return;
	
	free(voo);
}

void fechar_voo(Voo *voo) {
	if (!voo) {
		printf ("Erro: voo inválido/nulo\n");
		return;
	}
	if(porao_vazio(voo)) {
		printf("Erro: porão vazio\n");
		return;
	}
	voo->fechado = true;
}

bool voo_fechado(Voo *voo) {
	if (!voo) {
		printf ("Erro: voo inválido/nulo\n");
		return;
	}
	return voo->fechado;
}


