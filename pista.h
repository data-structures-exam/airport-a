#ifndef PISTA_H
#define PISTA_H

#include "voo.h"

typedef struct tPista Pista;

Pista *criar_pista(int num);
void enfileirar_voo(Pista *pista, Voo *voo);
void desenfileirar_voo(Pista *pista);
void destruir_pista(Pista *pista);

#endif
