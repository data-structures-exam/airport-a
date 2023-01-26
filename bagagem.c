#include "bagagem.h"

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
	else {
		printf ("Erro: peso da bagagem inválido\n");
		return NULL;
	}

	return bag;
}

int peso_valido(float peso) {
	return (peso > 0.0 && peso <= 32.0); // (0; 32]
}

void destruir_bagagem(Bagagem *bag) {
	if (!bag) return;
	free(bag);
}
