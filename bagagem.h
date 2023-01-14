#ifndef BAGAGEM_H
#define BAGAGEM_H

typedef struct tBagagem Bagagem;
Bagagem *criar_bagagem(char nome_passageiro[], int num_voo, float peso_kg);
int peso_valido(float peso);
void destruir_bagagem(Bagagem *bag);

#endif







