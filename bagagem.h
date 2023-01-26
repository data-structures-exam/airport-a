#ifndef BAGAGEM_H
#define BAGAGEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

struct tBagagem{
	char nome_passageiro[STR_TAM_MAX];
	int num_voo;
	float peso_kg;
};

typedef struct tBagagem Bagagem;
Bagagem *criar_bagagem(char nome_passageiro[], int num_voo, float peso_kg);
int peso_valido(float peso);
void destruir_bagagem(Bagagem *bag);
#endif
