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
		printf ("%d - Voo %d\n", i, aux->voo->num);
		printf ("\tData: %d/%d/%d\n", aux->voo->data->dia, aux->voo->data->mes, aux->voo->data->ano);
		printf ("\t%s -> %s\n\n", aux->voo->origem, aux->voo->destino);

		aux = aux->prox;
		i++;
	}
}

Lista_Voo *buscar_voo(Lista_Voo *L, int i) { // buscar i-ésimo voo da lista
	if (i > count_voos(L) || i <= 0 || lista_voo_vazia(L)) return NULL;
	
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
void remover_voo(Lista_Voo **L, int num_voo){
    if(!L){
        printf("Erro: Lista de voos inexistente\n");
        return;
    }
    Lista_Voo *aux;
    if((*L)->voo->num == num_voo){
        aux = *L;
        *L = (*L)->prox;
        free(aux);
    }
    else{
        Lista_Voo *cur  = *L;
        while(!lista_voo_vazia(cur->prox)){
            if(cur->prox->voo->num == num_voo){
                aux = cur->prox;
                cur->prox = cur->prox->prox;
                free(aux);
                break;
            }
            else
                cur = cur->prox;
        }
    }
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
