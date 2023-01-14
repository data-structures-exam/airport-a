#include "voo.h"
#include "data.h"
#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct tVoo {
	int num;
	Data data;
	char origem[STR_TAM_MAX], destino[STR_TAM_MAX];
	int fechado; // 0 se o avião não está pronto, 1 caso contrário
};

Voo *criar_voo(int num, Data data, char origem[], char destino[]) {
	Voo *voo = (Voo *)malloc(sizeof(Voo));
	if(!voo) {
		printf("Erro: malloc falhou em 'criar_voo'\n");
		return NULL;
	}

	voo->num = num;
	voo->data = data;
	strcpy(voo->origem, origem);
	strcpy(voo->destino, destino);
	voo->fechado = 0;
	
	return voo;
}

void destruir_voo(Voo *voo) {
	free(voo);
}

