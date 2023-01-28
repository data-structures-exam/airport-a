#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
void opcao_despachar_bagagem(Lista_Palete **paletes, Lista_Voo *voos);
void opcao_destruir_simulacao(Lista_Palete *P, Lista_Voo *Voos, Pista *p1, 
Pista *p2, Pista *p3, Pista *p4);
void opcao_despachar_bagagem_auto(Lista_Palete *paletes, Lista_Voo *voos);
void opcao_despachar_bagagem_manual(Lista_Palete **paletes, Lista_Voo *voos);
void opcao_carregar_bagagem(Lista_Palete *palete, Lista_Voo *voo);
void opcao_preparar_descolagem(Lista_Palete *paletes, Lista_Voo **voos, Pista *p1, Pista *p2);
void opcao_levantar_voo(Lista_Voo **voos, Pista *p1, Pista *p2);
void opcao_consultar_malas(Lista_Palete *paletes, Lista_Voo *voos, Pista *p1, Pista *p2, Pista *p3, Pista *p4);
void imprimir_detalhes_malas(Lista_Palete *paletes, Lista_Voo *voos);
Bagagem *obter_bagagem(Lista_Voo *voos);
void opcao_aterrar(Pista *p3, Pista *p4);
void opcao_consultar_voos(Lista_Voo *voos, Pista *p1, Pista *p2, Pista *p3, Pista *p4);
void opcao_verificar_bagagem_voo(Lista_Voo *voo, Pista *p1, Pista *p2, Pista *p3, Pista *p4);
bool bagagem_encontrada_voo(Lista_Voo *voos, char nome[]);

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

void opcao_despachar_bagagem(Lista_Palete **paletes, Lista_Voo *voos) {
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
		opcao_despachar_bagagem_auto(*paletes, voos);
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
			//ler directamente do ficheiro
            if (fscanf(f, "%s %s %s", nome,num_voo,peso) == 0) {
                fprintf(stderr, "ERRO\n");
                return;
            }
			Bagagem *bag = criar_bagagem(nome, atoi(num_voo), atof(peso));
			if(!(bag->peso_kg  >0.0 && bag->peso_kg<=32.0)){
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
			inserir_bagagem_palete(&paletes, bag);
		}	
		fclose(f);
	}else{
		puts("IMPOSSIVEL ABRIR O FICHEIRO");
	}
	
}

void opcao_despachar_bagagem_manual(Lista_Palete **paletes, Lista_Voo *voos) {
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

// opcao carregar bagagem-----------
void opcao_carregar_bagagem(Lista_Palete *paletes, Lista_Voo *voos) {
	if (!voos) {
		printf ("Erro: lista de voos vazia\n");
		return;
	}
	
	int opcao_voo, qtd_voos = count_voos(voos);
	do {
		imprimir_voos(voos);
		printf ("Selecione o voo [1-%d]: ", qtd_voos);
		scanf ("%d", &opcao_voo);
		if (opcao_voo < 1 || opcao_voo > qtd_voos) 
			printf ("Erro: opção inválida\n");
	} while (opcao_voo < 1 || opcao_voo > qtd_voos);

	Lista_Voo *voo = buscar_voo(voos, opcao_voo);
	if(voo_fechado(voo->voo)) {
		printf ("Voo já carregado\n");
		return;
	}
	int num_voo = voo->voo->num;

	int n = num_paletes_voo(paletes, num_voo);
	
	if (n == 0) {
		printf ("Erro: voo não pode partir sem bagagens\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		Lista_Palete *palete = buscar_palete(paletes, num_voo, i);
		carregar_palete(voo->voo, palete->p);
	}

	fechar_voo(voo->voo);
}

// opcao consultar malas---------

void opcao_consultar_malas(Lista_Palete *paletes, Lista_Voo *voos, Pista *p1, Pista *p2, Pista *p3, Pista *p4) {
	imprimir_detalhes_malas(paletes, voos);
	imprimir_detalhes_malas(paletes, p1->ini);
	imprimir_detalhes_malas(paletes, p2->ini);
	imprimir_detalhes_malas(paletes, p3->ini);
	imprimir_detalhes_malas(paletes, p4->ini);
}

void imprimir_detalhes_malas(Lista_Palete *paletes, Lista_Voo *voos) {
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

		aux = aux->prox;
	}
}
// opcao preparar descolagem

void opcao_preparar_descolagem(Lista_Palete *paletes, Lista_Voo **voos, Pista *p1, Pista *p2) {
	int opcao_voo, qtd_voos = count_voos(*voos);

	do {
		imprimir_voos(*voos);		
		printf ("Selecione o voo [1-%d]: ", qtd_voos);
		scanf ("%d", &opcao_voo);
		if (opcao_voo < 1 || opcao_voo > qtd_voos) 
			printf ("Erro: opção inválida\n");
	} while (opcao_voo < 1 || opcao_voo > qtd_voos);
	
	Lista_Voo *voo = buscar_voo(*voos, opcao_voo);
	if (!voo_fechado(voo->voo)) {
		printf ("Erro: as bagagens deste voo não foram carregadas\n");
		return;
	}
	
	int opcao;
	do {
		printf ("Selecione a pista para onde deseja enviar o avião\n");
		printf ("1 - Pista 1\n");
		printf ("2 - Pista 2\n");
		printf ("Escolha [1-2]: ");
		scanf ("%d", &opcao);
		if (opcao != 1 && opcao != 2)
			printf ("Erro: escolha inválida\n");
	} while (opcao != 1 && opcao != 2);

	if (opcao == 1)
		enfileirar_voo(p1, voo);
	else if (opcao == 2)
		enfileirar_voo(p2, voo);
	remover_voo(voos, voo->voo->num);
}

// opcao levantar voo

void opcao_levantar_voo(Lista_Voo **voos, Pista *p1, Pista *p2) {
	if (pista_vazia(p1) && pista_vazia(p2)) {
		printf ("Erro: pistas vazias\n");
		return;
	}

	int opcao;
	do {
		printf ("Selecione a pista de onde deseja autorizar a descolagem\n");
		printf ("1 - Pista 1\n");
		printf ("2 - Pista 2\n");
		printf ("Escolha [1-2]: ");
		scanf ("%d", &opcao);
		if (opcao != 1 && opcao != 2)
			printf ("Erro: escolha inválida\n");
	} while (opcao != 1 && opcao != 2);

	if (opcao == 1) {
		if(pista_vazia(p1)) {
			printf ("Erro: pista vazia\n");
			return;
		}
		remover_voo(voos, p1->ini->voo->num);
		destruir_voo(p1->ini->voo);
		desenfileirar_voo(p1);
	} 
	else if (opcao == 2) {
		if(pista_vazia(p2)) {
			printf ("Erro: pista vazia\n");
			return;
		}
		remover_voo(voos, p2->ini->voo->num);
		destruir_voo(p2->ini->voo);
		desenfileirar_voo(p2);
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

// opcao verificar bagagem no voo

void opcao_verificar_bagagem_voo(Lista_Voo *voo, Pista *p1, Pista *p2, Pista *p3, Pista *p4) {
	if (!voo && !p1->ini && !p2->ini && !p3->ini && !p4->ini) {
		printf ("Erro: nenhum voo criado\n");
		return;
	}

	char nome[STR_TAM_MAX];
	printf ("Nome do(a) passageiro(a): ");
	ler_linha(nome, STR_TAM_MAX);
	
	if (bagagem_encontrada_voo(voo, nome) || bagagem_encontrada_voo(p1->ini, nome)
		|| bagagem_encontrada_voo(p2->ini, nome) || bagagem_encontrada_voo(p3->ini, nome)
		|| bagagem_encontrada_voo(p4->ini, nome)) {
			printf ("Bagagem já está no porão\n");
		}
	else {
		printf ("Nenhuma bagagem de '%s' foi encontrada no porão de algum avião\n", nome);
	}
}

// opcao destruir simulacao
void opcao_destruir_simulacao(Lista_Palete *P, Lista_Voo *Voos, Pista *p1, 
Pista *p2, Pista *p3, Pista *p4){
	destruir_lista_palete(P);
	destruir_lista_voo(Voos);
	destruir_pista(p1);
	destruir_pista(p2);
	destruir_pista(p3);
	destruir_pista(p4);
	printf("Simulação destruída\n\n");
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
			opcao_despachar_bagagem(&lista_palete, lista_voo);
		else if (opcao == 3)
			opcao_carregar_bagagem(lista_palete, lista_voo);
		else if (opcao == 4)
			opcao_consultar_malas(lista_palete, lista_voo, p1, p2, p3, p4);
		else if (opcao == 5)
			opcao_preparar_descolagem(lista_palete, &lista_voo, p1, p2);
		else if (opcao == 6)
			opcao_levantar_voo(&lista_voo, p1, p2);
		else if (opcao == 7)
			opcao_aterrar(p3, p4);
		else if (opcao == 8)
			opcao_consultar_voos(lista_voo, p1, p2, p3, p4);
		else if (opcao == 9)
			opcao_verificar_bagagem_voo(lista_voo, p1, p2, p3, p4);
		else if (opcao == 10)
			opcao_destruir_simulacao(lista_palete, lista_voo, p1, p2, p3, p4);
	} while (opcao != 0);
	return 0;
}
