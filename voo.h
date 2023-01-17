#ifndef VOO_H
#define VOO_H

#include "data.h"
#include <stdbool.h>

typedef struct tVoo Voo;

Voo *criar_voo(int num, Data data, char origem[], char destino[]);
void carregar_palete(Voo *voo, Palete *p);
bool porao_cheio(Voo *voo);
void destruir_voo(Voo *voo);
void fechar_voo(Voo *voo);

#endif
