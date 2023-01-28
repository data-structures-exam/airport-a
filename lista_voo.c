#include "lista_voo.h"

Lista_Voo *criar_lista_voo(){
    return NULL;
}

void adicionar_voo_lista(Lista_Voo **L, Voo *voo){
    Lista_Voo *l = (Lista_Voo *)malloc(sizeof(Lista_Voo));
    if(!l){
        printf("Erro: malloc falhou em 'adicionar_voo'\n");
     return;
    }
    l->voo = voo;
    l->prox = *L;
    *L = l;
}

void imprimir_voos(Lista_Voo *L) {
	if (lista_voo_vazia(L)) {
		printf ("Lista vazia\n");
		return;
	}

	Lista_Voo *aux = L;
	int i = 1;
	while (aux) {
		imprimir_voo(aux, i);
		aux = aux->prox;
		i++;
	}
}

void imprimir_voo(Lista_Voo *L, int i) {
    if (lista_voo_vazia(L)) return;
    printf ("%d - Voo %d\n", i, L->voo->num);
	printf ("\tData: %d/%d/%d\n", L->voo->data->dia, L->voo->data->mes, L->voo->data->ano);
	printf ("\t%s -> %s\n\n", L->voo->origem, L->voo->destino);
}

Lista_Voo *buscar_voo(Lista_Voo *L, int i) { // buscar i-ésimo voo da lista
	if (lista_voo_vazia(L) || i <= 0 || i > count_voos(L)) return NULL;
	Lista_Voo *aux = L;
	for (int j = 1; j < i; ++j)
		aux = aux->prox;
	return aux;
}

int count_voos(Lista_Voo *L) {
	int count = 0;
	Lista_Voo *aux = L;
	while (aux) {
		count++;
		aux = aux->prox;
	}

	return count;
}

Voo *verificar_voo_numero(Lista_Voo *L, int num_voo){
    Lista_Voo *aux = L;
    while(aux->voo->num != num_voo && aux)aux = aux->prox;
    return aux->voo;
}
Lista_Voo *remover_voo(Lista_Voo **L, int num_voo){
    Lista_Voo *aux = *L, *ant;
    if(!lista_voo_vazia(*L) && (*L)->voo->num == num_voo){
        *L = (*L)->prox;
        return aux;
    }
    
    while(!lista_voo_vazia(aux) && aux->voo->num != num_voo){
        ant = aux;
        aux = aux->prox;
    }

    if (lista_voo_vazia(aux)) return NULL;

    ant->prox = aux->prox;
    return aux;
}

int lista_voo_vazia(Lista_Voo *L){
    return L == NULL;
}

void destruir_lista_voo(Lista_Voo *L){
    while(!lista_voo_vazia(L)){
        destruir_voo(L->voo);
        free(L);
	Lista_Voo *aux = L->prox;
	L = aux;
	if (aux) aux = aux->prox;
    }
}
