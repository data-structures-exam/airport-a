#include "lista_palete.h"

struct tPalete{
  int num_voo, pos;
  Pilha_Bagagem *pilha_bagagens[3];
  struct tPalete *prox;   
};

ListaPalete *criarListaPalete(int num_voo){
    ListaPalete *novo = (ListaPalete *)malloc(sizeof(ListaPalete));
    if(!novo){
        puts("Erro: alocacao de memoria invalida");
        return NULL;
    }
    novo->pos = -1;
    novo->num_voo = num_voo;
    return novo;
}

void adicionarBagagemPalete(ListaPalete **l, Pilha_Bagagem *pilha_bagagens){
    ListaPalete *aux  = *l;
    while(!pilha_vazia(pilha_bagagens)){
        Bagagem *B = pilha_bagagens->bagagens[pilha_bagagens->topo];
        bool found = false;
        while(aux->prox){
            if(aux->num_voo == B->num_voo){
                aux->pilha_bagagens[++aux->pos] = B;
                found = true;
                break;
            }
            aux = aux->prox;
        }
        if(!found){
            ListaPalete *novo = criarListaPalete(B->num_voo);
            novo->pilha_bagagens[++novo->pos] = B;
            novo->prox = *l;
            *l = novo;
        }
        desempilhar_bagagem(pilha_bagagens);
    }
}

void destruirPalete(ListaPalete **l){
    while(*l){
        destruir_pilha_bagagem((*l)->pilha_bagagens);
        *l = (*l)->prox;
    }
}