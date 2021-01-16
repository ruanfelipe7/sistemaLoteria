#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

//Lista todas as apostas que estão salvas

void ListarApostas(int concurso){
	Limpar();

	FILE *ler;
	int cont  = 0;

	//verifica se o arquivo esta vazio. Ler vai ser = ao arquivo com as apostas
	if(!verificaSeArquivoNaoVazio(fopen("apostas.txt","r"))){	
		ler = fopen("apostas2.txt", "r");	
	}else if(!verificaSeArquivoNaoVazio(fopen("apostas2.txt","r"))){
		ler = fopen("apostas.txt", "r");	
	}

	Jogador apostador;
	
	if(ler == NULL){
		printf("Imposssivel abrir o arquivo\n");
		printf("Nenhuma aposta feita\n\n");
		MostrarMenu();
	}else{

		printf("\t \t \t \t \t \t Lista de Apostas\n");
		printf("*********************************************************************************************************************\n");
		printf("*               *                    *                            *                          *                      *\n");
		printf("*   Concurso    *       Bilhete      *            Nome            *          Aposta          *         Status       *\n");
		printf("*               *                    *                            *                          *                      *\n");
		printf("*********************************************************************************************************************\n");

	


		while(1){

			 
			fread(&apostador, sizeof(Jogador), 1, ler);
			
			if(feof(ler))
				break;	

				if(concurso == apostador.concurso){		
					//Colocando espacos e o numero no local certo centralizado
					printf("*");
					cont = ContaDigitos(apostador.concurso);
					cont = 15 - cont;
					if(cont % 2 == 1)
						printf(" ");
					for(int j = 0; j < (cont/2); j++)
						printf(" ");
					printf("%d",apostador.concurso);
					for(int j = 0; j < (cont/2); j++)
						printf(" ");
					printf("*");

					cont = ContaDigitos(apostador.bilhete);
					cont = 20 - cont;
					if(cont % 2 == 1)
						printf(" ");
					for(int j = 0; j < (cont/2); j++)
						printf(" ");
					printf("%d",apostador.bilhete);
					for(int j = 0; j < (cont/2); j++)
						printf(" ");
					printf("*");

					cont = strlen(apostador.nome);
					cont = 28 - cont;
					if(cont % 2 == 1)
						printf(" ");
					for(int j = 0; j < (cont/2); j++)
						printf(" ");
					printf("%s",apostador.nome);
					for(int j = 0; j < (cont/2); j++)
						printf(" ");
					printf("*");			

					
					cont = 0;

					for(int i = 0; i < 6; i++){
						cont += ContaDigitos(apostador.aposta[i]);
					}
					cont += 10;
					cont = 26 - cont;
					if(cont % 2 == 1)
						printf(" ");
					for(int j = 0; j < (cont/2); j++)
						printf(" ");
					for(int i = 0; i < 6; i++){
						if(i == 5)
							printf("%d", apostador.aposta[i]);
						else
							printf("%d, ", apostador.aposta[i]);
					}
					for(int j = 0; j < (cont/2); j++)
						printf(" ");
					printf("*");
					
				if(apostador.status == 0){
					cont = 22 - 17;
					
					printf(" ");
					for(int j = 0; j < (cont/2); j++)
					printf(" ");
					printf("Esperando sorteio");
					for(int j = 0; j < (cont/2); j++)
					printf(" ");
					printf("*");
				}
				else if(apostador.status == 1){
					cont = 22 - 8;
					for(int j = 0; j < (cont/2); j++)
					printf(" ");
					printf("Ganhador");
					for(int j = 0; j < (cont/2); j++)
					printf(" ");
					printf("*");	
				}
				else{
					cont = 22 - 10;
					for(int j = 0; j < (cont/2); j++)
					printf(" ");
					printf("Nao ganhou");
					for(int j = 0; j < (cont/2); j++)
					printf(" ");
					printf("*");
				}			
				printf("\n");
				printf("*               *                    *                            *                          *                      *\n");
				printf("*********************************************************************************************************************\n");	
		
				}	
		}

		

	}

	fclose(ler);
	printf("\n\n");
	MostrarMenu();

}
