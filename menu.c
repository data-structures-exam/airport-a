#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "voo.h" 
#include "pista.h"
#include "lista_voo.h"
#include "lista_palete.h"

void imprimir_menu_principal() {
	printf ("1 - Criar voo\n");
	printf ("2 - Despachar bagagem\n");
	printf ("3 - Carregar bagagem\n");
	printf ("4 - Consulta de malas\n");
	printf ("5 - Preparar descolagem\n");
	printf ("6 - Levantar voo\n");
	printf ("7 - Aterrar\n");
	printf ("8 - Consultar voos\n");
	printf ("9 - Verificar bagagem no voo\n");
	printf ("10 - Destruir a simulação\n");
	printf ("0 - Sair\n");
}

int obter_opcao() {
	int opcao; 
	printf ("Escolha [0-10]: ");
	scanf("%d", &opcao);
	if (opcao < 0 || opcao > 10) {
		printf ("Erro: escolha inválida\n");
		obter_opcao();
	}

	return opcao;
}

// opcao criar voo-----------

void opcao_criar_voo(Lista_Voo *lista_voo) {
	int num_voo, dia, mes, ano;
	char origem[STR_TAM_MAX], destino[STR_TAM_MAX];
	printf ("Número de voo: ");
	scanf("%d", &num_voo);
	printf ("Data do voo [formato DD/MM/AAAA]: ");
	scanf ("%d/%d/%d", dia, mes, ano);
	printf ("Origem: ");
	ler_linha(origem, STR_TAM_MAX);
	printf ("Destino: ");
	ler_linha(destino, STR_TAM_MAX);
	Data *data = criar_data(dia, mes, ano);

	adicionar_voo(criar_voo(num_voo, data, origem, destino));
}

// opcao despachar bagagem-----------

void opcao_despachar_bagagem(Lista_Palete *paletes, Lista_Voo *voos) {
	// TODO: separar em despachar_bagagem_auto/manual
	// usar a função inserir_bagagem_palete de lista_palete.h
}

// opcao aterrar------------

void opcao_aterrar(Pista *p3, Pista *p4) {
	// criar um voo
	// perguntar ao usuário em qual das pistas o avião deve aterrar
	// adicionar o voo a pista correspondente (enfileirar voo)
}

int main () {
	Pista *p1, *p2, *p3, *p4;
	Lista_Voo *lista_voo = criar_lista_voo();
	Lista_Palete *lista_palete = criar_lista_palete();
	p1 = criar_pista(1);
	p2 = criar_pista(2);
	p3 = criar_pista(3);
	p4 = criar_pista(4);

	int opcao;
	do {
		imprimir_menu_principal();
		opcao = obter_opcao();
	} while (opcao != 0);

	if (opcao == 1)
		opcao_criar_voo(lista_voo);
	else if (opcao == 2)
		opcao_despachar_bagagem(lista_palete);
	else if (opcao == 7)
		opcao_aterrar(p3, p4);

	return 0;
}
