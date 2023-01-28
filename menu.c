#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "voo.h" 
#include "pista.h"
#include "string.h"
#include "bagagem.h"
#include "lista_voo.h"
#include "lista_palete.h"

void imprimir_menu_principal();
int obter_opcao();
Voo *obter_voo();
void opcao_criar_voo(Lista_Voo **lista_voo);
void opcao_despachar_bagagem(Lista_Palete *paletes, Lista_Voo *voos);
void opcao_despachar_bagagem_auto(Lista_Palete *paletes, Lista_Voo *voos);
void opcao_despachar_bagagem_manual(Lista_Palete *paletes, Lista_Voo *voos);
void opcao_consultar_malas(Lista_Palete *paletes, Lista_Voo *voos);
Bagagem *obter_bagagem(Lista_Voo *voos);
void opcao_aterrar(Pista *p3, Pista *p4);
void opcao_consultar_voos(Lista_Voo *voos, Pista *p1, Pista *p2, Pista *p3, Pista *p4);

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
	do {
		printf ("Escolha [0-10]: ");
		scanf("%d", &opcao);
		if (opcao < 0 || opcao > 10)
			printf ("Erro: escolha inválida\n");
	} while (opcao < 0 || opcao > 10);

	return opcao;
}

// opcao criar voo-----------

Voo *obter_voo() {
	int num_voo, dia, mes, ano;
	char origem[STR_TAM_MAX], destino[STR_TAM_MAX];
	printf ("Número de voo: ");
	scanf("%d", &num_voo);
	printf ("Data do voo [formato DD/MM/AAAA]: ");
	scanf ("%d/%d/%d", &dia, &mes, &ano);
	printf ("Origem: ");
	ler_linha(origem, STR_TAM_MAX);
	printf ("Destino: ");
	ler_linha(destino, STR_TAM_MAX);
	Data *data = criar_data(dia, mes, ano);
	Voo *voo = criar_voo(num_voo, data, origem, destino);

	return voo;
}

void opcao_criar_voo(Lista_Voo **lista_voo) {
	Voo *voo = obter_voo();
	adicionar_voo_lista(lista_voo, voo);
}

// opcao despachar bagagem-----------

void opcao_despachar_bagagem(Lista_Palete *paletes, Lista_Voo *voos) {
	int opcao;
	do {
		printf ("1 - Automático\n");
		printf ("2 - Manual\n");
		printf ("Escolha [1-2]: ");
		scanf ("%d", &opcao);
		if (opcao != 1 && opcao != 2)
			printf ("Erro: escolha inválida\n");
	} while (opcao != 1 && opcao != 2);

	if (opcao == 1)
		opcao_despachar_bagagem_auto(paletes, voos);
	else if (opcao == 2) {
		if (lista_voo_vazia(voos)) {
			printf ("Erro: não há voos criados. Crie um voo para poder despachar uma bagagem\n");
			return;
		}

		opcao_despachar_bagagem_manual(paletes, voos);
	}
}

void opcao_despachar_bagagem_auto(Lista_Palete *paletes, Lista_Voo *voos) {
	FILE *f = fopen("bagagem.txt", "r");
	if(f != NULL){
		//dados estao delimitados desta forma: nome,num_voo,peso
		while(!feof(f)){
			char buffer[100], nome[50], num_voo[20], peso[20];
			memset(buffer, 0, sizeof(buffer));
			fgets(buffer, 100, f);
			strcpy(nome, strtok(buffer, ","));
			strcpy(num_voo, strtok(NULL, ","));
			strcpy(peso, strtok(NULL, "\n"));
			Bagagem *bag = criar_bagagem(nome, atoi(num_voo), atof(peso));
			if(!(bag->peso_kg  >=0.0 && bag->peso_kg<=32.0)){
				printf ("Peso da bagagem invalido\n");
				return;
			}
			//call  function
			int encontrado = 0;
			Lista_Voo *aux= voos;
			while(aux){
				if(aux->voo->num == bag->num_voo){
					encontrado =1;
					break;
				}
				aux = aux->prox;
			}
			if(!encontrado){
				printf("Voo nao econtrado\n");
				return;
			}
			inserir_bagagem_palete(paletes, bag);
		}	
		fclose(f);
	}else{
		puts("TESTE");
	}
	
}

void opcao_despachar_bagagem_manual(Lista_Palete *paletes, Lista_Voo *voos) {
	Bagagem *bag = obter_bagagem(voos);
	inserir_bagagem_palete(paletes, bag);
}

Bagagem *obter_bagagem(Lista_Voo *voos) {
	char nome_passageiro[STR_TAM_MAX];
	int num_voo; float peso_kg;
	printf("Nome do(a) passageiro(a): ");
	ler_linha(nome_passageiro, STR_TAM_MAX);
	imprimir_voos(voos);
	int opcao, qtd_voos = count_voos(voos);
	do {
		printf ("Selecione o voo [1-%d]: ", qtd_voos);
		scanf ("%d", &opcao);
		if (opcao < 1 || opcao > qtd_voos) 
			printf ("Erro: opção inválida\n");
	} while (opcao < 1 || opcao > qtd_voos);
	Lista_Voo *voo = buscar_voo(voos, opcao);
	num_voo = voo->voo->num;
	do {
		printf ("Peso da bagagem em kg [até 32 kg]: ");
		scanf ("%f", &peso_kg);
		if (peso_kg <= 0.0 || peso_kg >= 32.0)
			printf ("Erro: peso inválido\n");
	} while (peso_kg <= 0.0 || peso_kg >= 32.0);

	Bagagem *bag = criar_bagagem(nome_passageiro, num_voo, peso_kg);
	return bag;
}

// opcao consultar malas---------

void opcao_consultar_malas(Lista_Palete *paletes, Lista_Voo *voos) {
	Lista_Voo *aux = voos;
	while (aux) {
		int num_paletes = num_paletes_voo(paletes, aux->voo->num);
		printf ("Voo %d (%s -> %s):\n", aux->voo->num, aux->voo->origem, aux->voo->destino);
		if (num_paletes == 0) {
			printf ("\tSem bagagens registadas\n\n");
			aux = aux->prox;
			continue;
		}

		for (int i = 1; i <= num_paletes; i++) {
			Lista_Palete *lp = buscar_palete(paletes, aux->voo->num, i);
			printf ("\tPalete %d: \n", i);
			imprimir_bagagens(lp->p);
		}
	}
	
}

// opcao aterrar------------

void opcao_aterrar(Pista *p3, Pista *p4) {
	Lista_Voo *voo_no = criar_lista_voo();
	int opcao;
	do {
		printf ("Selecione a pista onde deseja que o avião aterre\n");
		printf ("1 - Pista 3\n");
		printf ("2 - Pista 4\n");
		printf ("Escolha [1-2]: ");
		scanf ("%d", &opcao);
		if (opcao != 1 && opcao != 2)
			printf ("Erro: escolha inválida\n");
	} while (opcao != 1 && opcao != 2);

	Voo *voo = obter_voo();
	adicionar_voo_lista(&voo_no, voo);
	if (opcao == 1) enfileirar_voo(p3, voo_no);
	else if (opcao == 2) enfileirar_voo(p4, voo_no);
}

// opcao consultar voos-------------
void opcao_consultar_voos(Lista_Voo *voos, Pista *p1, Pista *p2, Pista *p3, Pista *p4) {
	printf("Voos em preparação: \n");
	imprimir_voos(voos);

	printf("Voos em espera (partidas):\nPista 1: \n");
	imprimir_voos(p1->ini);
	printf("Pista 2: \n");
	imprimir_voos(p2->ini);

	printf("Voos em espera (chegadas):\nPista 3: \n");
	imprimir_voos(p3->ini);
	printf("Pista 4: \n");
	imprimir_voos(p4->ini);

}

int main () {
	Pista *p1, *p2, *p3, *p4;
	Lista_Voo *lista_voo = criar_lista_voo();
	Lista_Palete *lista_palete = criar_lista_palete();
	p1 = criar_pista(1);
	p2 = criar_pista(2);
	p3 = criar_pista(3);
	p4 = criar_pista(4);

	int opcao = -1;
	do {
		do {
			imprimir_menu_principal();
			opcao = obter_opcao();
		} while (opcao < 0 || opcao > 10);

		if (opcao == 1)
			opcao_criar_voo(&lista_voo);
		else if (opcao == 2)
			opcao_despachar_bagagem(lista_palete, lista_voo);
		else if (opcao == 4)
			opcao_consultar_malas(lista_palete, lista_voo);
		else if (opcao == 7)
			opcao_aterrar(p3, p4);
		else if (opcao == 8)
			opcao_consultar_voos(lista_voo, p1, p2, p3, p4);
	} while (opcao != 0);
	return 0;
}
