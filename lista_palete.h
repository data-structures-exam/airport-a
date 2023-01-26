#ifndef LISTA_PALETE_H
#define LISTA_PALETE_H

#include <stdbool.h>
#include <stdio.h>
#include "palete.h"
#include "stdlib.h"
#include <stdbool.h>
#include "lista_palete.h"
#include "bagagem.h"
#include "voo.h" // para obter o número máximo de paletes por voo

struct tListaPalete{
    Palete *p;
    struct tListaPalete *prox;
};
typedef struct tListaPalete Lista_Palete;

Lista_Palete *criar_lista_palete();
void adicionar_palete(Lista_Palete **L, Palete *P);
void remover_palete(Lista_Palete **L, int num_voo);
bool lista_vazia(Lista_Palete *L);
bool verificar_palete_numvoo(Lista_Palete *L, int num_voo);
Lista_Palete *buscar_palete(Lista_Palete *L, int num_voo);
void inserir_bagagem_palete(Lista_Palete *L, Bagagem *bag);
int num_paletes_voo(Lista_Palete *L, int num_voo);
void destruir_lista_palete(Lista_Palete *L);

#endif


