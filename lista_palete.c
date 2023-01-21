#include <stdio.h>
#include "lista_palete.h"

struct tListaPalete{
    Palete *p;
    struct tListaPalete *prox;
};

Lista_Palete *criar_lista_palete(){
    return NULL;
}

void adicionar_palete(Lista_Palete **L, Palete *p){
    if(!L){
        printf("Erro: Lista de paletes inexestintes\n");
        return;
    }
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
// remove a primeira palete com o numero de voo passado
void remover_palete(Lista_Palete **L, int num_voo){
    if(!L){
        printf("Erro: Lista de paletes inexestintes\n");
        return;
    }
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
    while(lista_vazia(L)){
        destruir_palete(L->p);
        free(L);
        L = L->prox;
    }
}