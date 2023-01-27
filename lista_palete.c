#include "lista_palete.h"

Lista_Palete *criar_lista_palete(){
    return NULL;
}

void adicionar_palete(Lista_Palete **L, Palete *p){
    Lista_Palete *l = (Lista_Palete *)malloc(sizeof(Lista_Palete));
    if(!l){
        printf("Erro: malloc falhou em 'adicionar_palete'\n");
        return;
    }
    l->p = p;
    l->prox = *L;
    *L = l;
}
bool verificar_palete_numvoo(Lista_Palete *L, int num_voo){
    Lista_Palete *aux = L;
    while(aux->p->num_voo != num_voo && aux)aux = aux->prox;
    return aux != NULL;
}

Lista_Palete *buscar_palete(Lista_Palete *L, int num_voo) { // retorna a primeira ocorrência
	Lista_Palete *aux = L;
	while (aux) {
		if (aux->p->num_voo == num_voo) break;
		aux = aux->prox;
	}
	return aux;
}

void inserir_bagagem_palete(Lista_Palete *L, Bagagem *bag) {
	if (!bag) {
		printf ("Erro: bagagem inexistente/nula\n");
		return;
	}

	Lista_Palete *lp = buscar_palete(L, bag->num_voo);
	
	if (lp && num_paletes_voo(lp, bag->num_voo) >= MAX_PAL_VOO && 
			palete_cheia(lp->p)) {
		printf ("Erro: paletes do voo %d estão cheias\n", bag->num_voo);
		destruir_bagagem(bag);
		return;
	}

	if (!lp || palete_cheia(lp->p)) {
		Palete *novo = criar_palete(bag->num_voo);
		inserir_bagagem(novo, bag);
		adicionar_palete(&L, novo);
		return;
	}

	inserir_bagagem(lp->p, bag);
}

int num_paletes_voo(Lista_Palete *L, int num_voo) {
	int num = 0;
	Lista_Palete *aux = L;
	while (aux) {
		if (aux->p->num_voo == num_voo) num++;
		aux = aux->prox;
	}
	return num;
}
	
// remove a primeira palete com o numero de voo passado
void remover_palete(Lista_Palete **L, int num_voo){
    Lista_Palete *aux;
    if((*L)->p->num_voo == num_voo){
        aux = *L;
        *L = (*L)->prox;
        free(aux);
    }
    else{
        Lista_Palete *cur  = *L;
        while(!lista_vazia(cur->prox)){
            if(cur->prox->p->num_voo == num_voo){
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

bool lista_vazia(Lista_Palete *L){
    return L == NULL;
}

void destruir_lista_palete(Lista_Palete *L){
    while(!lista_vazia(L)){
        destruir_palete(L->p);
        L = L->prox;
        free(L);
    }
}
