#ifndef VOO_H
#define VOO_H
#include "data.h"

typedef struct tVoo Voo;

Voo *criar_voo(int num, Data data, char origem[], char destino[]);
void destruir_voo(Voo *voo);

#endif
