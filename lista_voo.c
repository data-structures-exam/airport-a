#include <stdio.h>
#include "lista_voo.h"

struct tListaVoo{
    Voo *voo;
    struct tListaVoo *prox;
};

Lista_Voo *criar_lista_voo(){
    return NULL;
}

void adicionar_voo(Lista_Voo **L, Voo *voo){
    if(!L){
        printf("Erro: Lista de voo inexestinte\n");
        return;
    }
    Lista_Voo *l = (Lista_Voo *)malloc(sizeof(Lista_Voo));
    if(!l){
        printf("Erro: malloc falhou em 'adicionar_palete'\n");
        return;
    }
    l->voo = voo;
    l->prox = *L;
    *L = l;
}
Voo *verificar_voo_numero(Lista_Voo *L, int num_voo){
    Lista_Voo *aux = L;
    while(aux->voo->num != num_voo && aux)aux = aux->prox;
    return aux->voo;
}
void remover_voo(Lista_Voo **L, int num_voo){
    if(!L){
        printf("Erro: Lista de paletes inexestintes\n");
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
        while(!lista_vazia(cur->prox)){
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

bool lista_vazia(Lista_Voo *L){
    return L == NULL;
}

void destruir_lista_voo(Lista_Voo *L){
    while(!lista_vazia(L)){
        destruir_voo(L->voo);
        L = L->prox;
        free(L);
    }
}