#include "voo.h"

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

	if (palete_vazia(p)) {
		printf("Erro: palete vazia\n");
		return;
	}

	voo->paletes[++voo->pos] = p;
}	

bool porao_cheio(Voo *voo) {
	if (!voo) {
		printf ("Erro: voo inválido/nulo\n");
		return 0;
	}

	return voo->pos >= MAX_PAL_VOO - 1;
}

bool porao_vazio(Voo *voo) {
	if (!voo) {
		printf ("Erro: voo inválido/nulo\n");
		return 0;
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
		return 0;
	}
	return voo->fechado;
}


