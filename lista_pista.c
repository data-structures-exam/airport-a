#include <stdio.h>
#include <stdlib.h>
#include "lista_pista.h"
#include "pista.c"
#include "lista_palete.h"

#include "voo.c"
#include <stdbool.h>
#include "lista_voo.c"

struct tListaPista{
    Pista *pistasDecolagem[2];
    Pista *pistasAterragem[2];
};

void adicionar_voo_pistaDecolagem(ListaPista *lPista, int numero_pista, Voo *voo){
    if(lPista == NULL){
        printf("Erro: Lista de pista não existe\n");
        return;
    }
    if(voo == NULL){
        printf ("Erro: voo inválido/nulo\n");
		return;
    }
    if(voo->pos == -1){
        printf("O VOO NAO PODE SER ADICIONADO A PISTA\n");
        return;
    }
    enfileirar_voo(lPista->pistasDecolagem[numero_pista-1], voo);
}

void retirar_voo_pistaDecolagem(ListaPista *lPista, int numero_pista, Voo *voo){
    if(lPista == NULL){
        printf("Lista de pista inexistente\n");
        return;
    }
    if(voo == NULL){
        printf("Este voo nao existe\n");
        return;
    }
    remover_voo(&lPista->pistasDecolagem[numero_pista]->ini, voo->num);
}
void adicionar_voo_pistaAterragem(ListaPista *lPista, int numero_pista, Voo *voo){
    if(lPista == NULL){
        printf("Lista de pista inexistente\n");
        return;
    }
    if(voo == NULL){
        printf("Este voo nao existe\n");
        return;
    }
    enfileirar_voo(lPista->pistasDecolagem[numero_pista-1], voo);
}

void retirar_voo_pistaAterragem(ListaPista *lPista, int numero_pista, Voo *voo){
    if(lPista == NULL){
        printf("Lista de pista inexistente\n");
        return;
    }
    if(voo == NULL){
        printf("Este voo nao existe\n");
        return;
    }
    remover_voo(&lPista->pistasAterragem[numero_pista-3]->ini, voo->num);
}

void destruir_lista_pista(ListaPista *lPista){
    
    int i = 0;
    for(i = 0; i<2; i++)
        destruir_pista(lPista->pistasAterragem[i]);
    for(i = 0; i<2; i++)
        destruir_pista(lPista->pistasDecolagem[i]);
    
    free(lPista);
}