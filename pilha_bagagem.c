
#include "pilha_bagagem.h"

Pilha_Bagagem *criar_pilha_bagagem(int num_voo) {
	Pilha_Bagagem *pilha = (Pilha_Bagagem *)malloc(sizeof(Pilha_Bagagem));
	if (!pilha) {
		printf("Erro: malloc falhou em 'criar_pilha_bagagem'\n");
		return NULL;
	}
	pilha->topo = -1;
	pilha->num_voo = num_voo;
	for (int i = 0; i < MAX_BAGS_PILHA; i++)
		pilha->bagagens[i] = NULL;
	return pilha;
}

void empilhar_bagagem(Pilha_Bagagem *pilha, Bagagem *bag) {
	if (!pilha) {
		printf ("Erro: pilha de bagagens inválida/nula\n");
		return;
	}
	
	if (!bag) {
		printf ("Erro: bagagem inválida/nula\n");
		return;
	}

	if(pilha_cheia(pilha)) {
		printf("Erro: pilha cheia\n");
		return;
	}

	if(pilha->num_voo != bag->num_voo) {
		printf("Erro: número de voo da pilha e da bagagem não correspondem\n");
		return;
	}
	pilha->bagagens[++pilha->topo] = bag;
}

void desempilhar_bagagem(Pilha_Bagagem *pilha) {
	if (!pilha) {
		printf ("Erro: pilha de bagagens inválida/nula\n");
		return;
	}	

	if(pilha_vazia(pilha)) {
		printf("Erro: pilha vazia\n");
		return;
	}

	destruir_bagagem(pilha->bagagens[pilha->topo--]);
}

int pilha_vazia(Pilha_Bagagem *pilha) {
	if (!pilha) {
		printf ("Erro: pilha de bagagens inválida/nula\n");
		return 0;
	}

	return pilha->topo < 0;
}

void destruir_pilha_bagagem(Pilha_Bagagem *pilha) {
	if (!pilha) {
		printf ("Erro: pilha de bagagens inválida/nula\n");
		return;
	}

	while (pilha->topo-- >= 0)
		destruir_bagagem(pilha->bagagens[pilha->topo]);
	free(pilha);
}

int pilha_cheia(Pilha_Bagagem *pilha) {
	if (!pilha) {
		printf ("Erro: pilha de bagagens inválida/nula\n");
		return 0;
	}

	return pilha->topo >= MAX_BAGS_PILHA - 1;
}


