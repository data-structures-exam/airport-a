
#include "bagagem.h"

typedef struct tPilha_Bagagem Pilha_Bagagem;

Pilha_Bagagem *criar_pilha_bagagem(int num_voo);
void empilhar_bagagem(Pilha_Bagagem *pilha, Bagagem *bag);
void desempilhar_bagagem(Pilha_Bagagem *pilha);
int pilha_vazia(Pilha_Bagagem *pilha);
void destruir_pilha_bagagem(Pilha_Bagagem *pilha);
int pilha_cheia(Pilha_Bagagem *pilha);

#endif
