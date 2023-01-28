#include "pista.h"
#include <stdbool.h>

Pista *criar_pista(int num) {
	Pista *pista = (Pista *)malloc(sizeof(Pista));
	if (!pista) {
		printf ("Erro: malloc falhou em 'criar_pista'\n");
		return NULL;
	}
	
	pista->num = num;
	pista->ini = pista->fim = NULL;
	return pista;
}

void enfileirar_voo(Pista *pista, Lista_Voo *voo) {
	if (!pista) {
		printf ("Erro: pista inválida/nula\n");
		return;
	}

	if (!voo) {
		printf ("Erro: voo inválido/nulo\n");
		return;
	}

	if (pista_vazia(pista)) {
		pista->ini = pista->fim = voo;
		return;
	}

	pista->fim->prox = voo;
	pista->fim = voo;
}

void desenfileirar_voo(Pista *pista) {
	if (!pista) {
		printf ("Erro: pista inválida/nula\n");
		return;
	}

	if (!pista->ini) return;
	
	Voo *aux = pista->ini->voo;
	pista->ini = pista->ini->prox;
	destruir_voo(aux);
	if (pista_vazia(pista)) pista->fim = NULL;
}

bool pista_vazia(Pista *pista) {
	return pista->ini == NULL;
}

void destruir_pista(Pista *pista) {
	if (!pista) {
		printf ("Erro: pista inválida/nula\n");
		return;
	}
	Pista *aux = pista;
	while(pista->ini) {
		destruir_voo(pista->ini->voo);
		pista->ini = aux->ini;
		aux->ini = aux->ini->prox;
	}
}
