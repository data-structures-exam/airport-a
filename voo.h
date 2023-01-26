#ifndef VOO_H
#define VOO_H

#include "data.h"
#include <stdbool.h>
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

typedef struct tVoo Voo;

Voo *criar_voo(int num, Data *data, char origem[], char destino[]);
void carregar_palete(Voo *voo, Palete *p);
bool porao_cheio(Voo *voo);
bool porao_vazio(Voo *voo);
void destruir_voo(Voo *voo);
void fechar_voo(Voo *voo);
bool voo_fechado(Voo *voo);

#endif
