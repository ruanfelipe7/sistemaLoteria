#include <stdio.h>
#include <stdio_ext.h>
#include "functions.h"
#include <string.h>
// se o arquivo for vazio retorna 0, se nao for vazio retorna 1
int verificaSeArquivoNaoVazio(FILE *arquivo){
	//movimenta a posicao de leitura para o fim do arquivo
	fseek(arquivo, 0 , SEEK_END);
	//ve quantos bytes existe do comeco ao fim do arquivo
	if(ftell(arquivo) == 0){
		fclose(arquivo);
		return 0;
	}else{
		fclose(arquivo);
		return 1;
	}
}

int modificaAposta(Jogador *jog){
	FILE *apostas, *apostasAux; 
	Jogador escolhido, resto;
	char arq[10];
	int numBilhete, numero = 0;

	printf("******** Altera de aposta ********\n\n");
	printf("Digite o numero do bilhete da aposta: ");
	scanf("%d",&numBilhete);
	printf("\n\n");	

	if(verificaSeArquivoNaoVazio(fopen("apostas.txt", "r"))){	
		apostas = fopen("apostas.txt","r");
		apostasAux = fopen("apostas2.txt","a");
		strcpy(arq, "apostas.txt");
	}else if(verificaSeArquivoNaoVazio(fopen("apostas2.txt", "r"))){
		apostas = fopen("apostas2.txt","r");
		apostasAux = fopen("apostas.txt","a");
		strcpy(arq, "apostas2.txt");
	}

	while(1){
		fread(&escolhido, sizeof(Jogador) , 1 , apostas);
		
		
		if(feof(apostas) || escolhido.bilhete == numBilhete){
			// se o arquivo chegar ao final e não encontrar nada, return 0, ou seja, aposta não encontrada
			if(escolhido.bilhete != numBilhete){
				printf("Bilhete não existe\n");
		
				return 0;
			}
			// se o bilhete digitado for igual ao da aposta em arquivo.
			break;
		}

	}
	// so executa se existir um numero de bilhete igual ao digitado
	while(1){
		
		//se chegar na aposta que tem o numero digitado
		if(escolhido.bilhete == numBilhete){
			Limpar();

			do{
				printf("******** Escolha de modificacao ********\n\n");
				printf("\t 1 - Editar o nome do jogador\n");
				printf("\t 2 - Editar a aposta\n\n");
				printf("Digite a opcao escolhida: ");
				scanf("%d", &numero);
				__fpurge(stdin);
				Limpar();
				
				if(numero == 1){ // se escolha for 1 ou 2 -> modifica o dado referente 
					printf("******** Modificacao de nome de jogador********\n\n");
					printf("\tDigite o nome do jogador: \n");
					scanf("%[^\n]s", escolhido.nome);
					numero = 0;
					__fpurge(stdin);
					*jog = escolhido;
				}else if(numero == 2){
					printf("******** Modificacao de aposta ********\n\n");
					printf("\tDigite a aposta: \n");
					for(int i = 0; i<6 ; i++){
						scanf("%d", &escolhido.aposta[i]);
					}
					*jog = escolhido;
					numero = 0;
					__fpurge(stdin);
				}else{ // se escolha nao for 1 nem 2
					printf("    !!! A opcao digitada nao existe !!! \n");
					numero = 3;
				}
				
				__fpurge(stdin);
			}while(numero != 0);
		}

		fwrite( &escolhido , sizeof(Jogador) , 1 , apostasAux);	

		if(feof(apostas)){
			break;
			
			return 1;
		}

	}

	fclose(apostas);
			//exclui dados do arquivo desatualizado
	apostas = fopen(arq, "w+");
		fclose(apostas);
		fclose(apostasAux);
	
			
}