#ifndef LISTA_PALETE_H
#define LISTA_PALETE_H

#include <stdbool.h>
typedef struct tListaPalete Lista_Palete;

Lista_Palete *criar_lista_palete();
void adicionar_palete(Lista_Palete **L, Palete *P);
void remover_palete(Lista_Palete **L, int num_voo);
bool lista_vazia(Lista_Palete *L);
bool verificar_palete_numvoo(Lista_Palete *L, int num_voo);
void destruir_lista_palete(Lista_Palete *L);

#endif


