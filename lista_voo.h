#ifndef LISTA_VOO_H
#define LISTA_VOO_H


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "voo.h"
typedef struct tListaVoo Lista_Voo;


Lista_Voo *criar_lista_voo();
void remover_aviao(Lista_Voo **L);

bool lista_vazia(Lista_Voo *L);

bool verificar_voo(Lista_Voo *L, int num_voo);

void destruir_lista_voo(Lista_Voo *L);
void adicionar_voo_lista(Lista_Voo **L, Voo *v);
#endif


