#ifndef LISTA_VOO_H
#define LISTA_VOO_H

#include "voo.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct tListaVoo Lista_Voo;

Lista_Voo *criar_lista_voo();
void adicionar_voo(Lista_Voo* lVoo);
void remover_aviao(Lista_Voo *lVoo);
bool lista_vazia(Lista_Voo *lVoo);
bool verificar_voo(Lista_Voo *lVoo, int num_voo);
void destruir_lista_voo(Lista_Voo *lVoo);

#endif


