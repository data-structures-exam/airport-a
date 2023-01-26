#ifndef PISTA_H
#define PISTA_H

#include "lista_voo.h"

typedef struct tPista Pista;

Pista *criar_pista(int num);
void enfileirar_voo(Pista *pista, Lista_Voo *voo);
void desenfileirar_voo(Pista *pista);
void destruir_pista(Pista *pista);

#endif
