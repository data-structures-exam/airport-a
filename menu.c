#include <stdio.h>
#include <stdlib.h>

int main (){
	int opcao,aux;
do{
	
printf("-----------------Menu---------------\n");
printf("\t[1]-Inserir Bagagem\n");
printf("\t[2]-Inserir Data\n");
printf("\t[3]-Inserir Voo\n");
printf("\t[4]-Inserir Pilha\n");
printf("\t[5]-Inserir Paleta\n");
printf("\t[6]-Inserir Pista\n");
printf("\t[7]-Imprimir\n");
printf("\t[8]-Remover");
printf("\t[0]-Sair\n");
printf("------------------------------------\n");
printf("selecione sua opcao:\n");
scanf("%d\n",opcao);

switch (opcao)
{

 case 1:
 	int voo;
 	char passageiro;
 	float peso;
 	
 	printf("Digite o nome do passageiro:\n");
 	scanf("%c",&passageiro);
 	printf("Digite o numero de voo:\n");
 	scanf("%d",&voo);
 	printf("Digite o peso da mala:\n");
 	scanf("%f",&peso);
 	
  break;
 		case 2:
 			
 		int d,m,a; //dia,mes,ano
 	    printf("Digite o dia:\n");
 		scanf("%d",&dia);
 		printf("Digite o mes:\n");
 		scanf("%d",&mes);
 		printf("Digite o ano:\n");
 		scanf("%d",&a);
		 		
 		break;
 			case 3:
 				
 			break;
 				case 4;
 				break;
 					case 5:
 						
 					break;
 						case 6:
 							int p //pista 
 							printf("Digite o numero da pista:\n");
 							scanf("%d",&pista);
 						break;
 							case 7:
 							
 							break;
								case 8:
								break;	
									case 0:
									break;
  									
default:
  if(opcao!=0)
  {
  	printf("opcao invalida\n");
  }				
}
}while(opcao=0);
  
  return 0;  
}

