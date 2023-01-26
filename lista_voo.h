#ifndef LISTA_VOO_H
#define LISTA_VOO_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "voo.h"
#include "data.h"

struct tListaVoo{
    Voo *voo;
    struct tListaVoo *prox;
};

typedef struct tListaVoo Lista_Voo;


Lista_Voo *criar_lista_voo();
void remover_voo(Lista_Voo **L, int num_voo);
int verificar_voo(Lista_Voo *L, int num_voo);
void imprimir_voos(Lista_Voo *L);
Lista_Voo *buscar_voo(Lista_Voo *L, int i);
int count_voos(Lista_Voo *L);
int lista_voo_vazia(Lista_Voo *L);
void destruir_lista_voo(Lista_Voo *L);
void adicionar_voo_lista(Lista_Voo **L, Voo *v);
#endif


