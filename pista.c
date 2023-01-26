#include "pista.h"

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

void enfileirar_voo(Pista *pista, Voo *voo) {
	if (!pista) {
		printf ("Erro: pista inválida/nula\n");
		return;
	}

	if (!voo) {
		printf ("Erro: voo inválido/nulo\n");
		return;
	}

	if (!pista->ini) {
		pista->ini->voo = pista->fim->voo = voo;
		return;
	}

	pista->fim->prox->voo = voo;
	pista->fim->voo = voo;
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
	if (!pista->ini) pista->fim = NULL;
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
