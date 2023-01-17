#include <stdio.h>
#include <stdlib.h>
#include "bagagem.h"
#include "utils.h"

struct tBagagem{
	char nome_passageiro[STR_TAM_MAX];
	int num_voo;
	float peso_kg;
};

Bagagem *criar_bagagem(char nome_passageiro[], int num_voo, float peso_kg) {
	Bagagem *bag = (Bagagem *)malloc(sizeof(Bagagem));
	if (!bag) {
		printf ("Erro: malloc falhou em 'criar_bagagem'\n");
		return NULL;
	}
	strcpy(bag->nome_passageiro, nome_passageiro);
	bag->num_voo = num_voo;
	if (peso_valido(peso_kg))
		bag->peso_kg = peso_kg;
	else
		bag->peso_kg = 0.0;

	return bag;
}

int peso_valido(float peso) {
	return (peso > 0.0 && peso <= 32.0); // (0; 32]
}

void destruir_bagagem(Bagagem *bag) {
	free(bag);
}
