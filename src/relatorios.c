#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

void RelatorioConcurso(Concurso c){
			Limpar();
			printf("**************  Concurso criado com sucesso!  ******************\n");
			printf("\tConcurso Numero: %d\n", c.numero);
			printf("\tData: %s\n", c.data);
			printf("\tHorario: %s\n", c.horario);
			printf("\tValor: %.2f\n\n", c.valor);

}

void RelatorioAposta(Jogador x, int opcao){

	int numBilhete;
	int cartela[6][10], num = 1, temp = 0;
	

	Limpar();
	if(opcao == 1){
		printf("Situacao da aposta: Alterada com sucesso!!\n");
	}else if(opcao == 2){
		printf("Situacao da aposta: Realizada com sucesso!!\n");

	}	
	printf("Concurso Referente Numero: %d\n", x.concurso);
	printf("Numero do bilhete: %d\n", x.bilhete);
	printf("Nome do jogador: %s\n", x.nome);
	printf("Numeros apostados: ");
	for(int  i=0; i<6 ;i++){
		printf("%d ", x.aposta[i] );
	}
	printf("\n\t\tCartela\n");
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 10; j++){
			temp = 0;
			for(int l = 0; l < 6; l++){
				if(x.aposta[l] == num){
					temp = 1;
					break;
				}	


			}

			if(temp)
				printf("XX  ");
			else if(i == 0 && num < 10)
				printf("0%d  ", num);
			else
				printf("%d  ", num);

			num++;

		}

		printf("\n");
	}
			
}

void RelatorioSorteio(Concurso c){
			int ganha6 = 0, ganha5 = 0;
			Limpar();
			printf("*****************  Sorteio realizado com sucesso!  ***********************\n");
			printf("\tConcurso Numero: %d\n", c.numero);	
			printf("\tValor: %.2f\n", c.valor);
			printf("\tNumeros: ");
			for(int i = 0; i < 6; i++)
				printf("%d ",c.resultado[i]);

			printf("\n");

			VerificarGanhadores(c, &ganha5, &ganha6);

			printf("\t\tGanhadores\n");

			printf("\tAcertos \t Vencedores \t Prêmio\n");
			printf("\t6 \t\t %d \t\t ", ganha6);
			if(!ganha6){
				printf("Acumulado\n");
			}else{
				printf("%.2f\n", c.valor / ganha6);
			}
			printf("\t5 \t\t %d \t\t ", ganha5 );
			if(!ganha5){
				printf("Acumulado\n");
			}else{
				printf("%.2f\n", (c.valor / 5) / ganha5);
			}

			if(ganha6){
				FILE *arquivo;
				arquivo = fopen("conc.txt", "r");
				fread(&c, sizeof(Concurso), 1, arquivo);
				fclose(arquivo);
				c.valor = 0.00;
				arquivo = fopen("conc.txt", "w+");
				fwrite(&c, sizeof(Concurso), 1, arquivo);
				fclose(arquivo);
				

			}

		
}