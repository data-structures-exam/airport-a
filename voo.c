#include "voo.h"
#include "data.h"
#include <string.h>

#define STR_MAX_SIZE 40

struct tVoo {
	int num;
	Data data;
	char origem[STR_MAX_SIZE], destino[STR_MAX_SIZE];
	int fechado; // 0 se o avião não está pronto, 1 caso contrário
};

Voo *criar_voo(int num, Data data, char origem[], char destino[]) {
	Voo *voo = (Voo *)malloc(sizeof(Voo));
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
