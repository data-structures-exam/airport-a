#ifndef PISTA_H
#define PISTA_H

#include "pista.h"
#include "voo.h"
#include "bagagem.h"
#include <stdio.h>
#include <stdlib.h>
#include "lista_voo.h"


struct tPista {
	int num;
	Lista_Voo *ini, *fim;
};

typedef struct tPista Pista;

Pista *criar_pista(int num);
void enfileirar_voo(Pista *pista, Voo *voo);
void desenfileirar_voo(Pista *pista);
void destruir_pista(Pista *pista);

#endif
