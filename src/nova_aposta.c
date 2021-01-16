#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "functions.h"

int casoDeErroAposta(int *numero){

	//verifica se os numeros digitados estão entre 1 e 60, se não estivem entre 1 e 60 return = 1
	for(int i = 0; i<6 ;i++){
		if((numero[i] <= 0) || (numero[i] > 60)){
			return 1;
		}
	}

	//verifica se existem numeros iguais, se forem iguais return = 2
	for(int i=0; i<5 ;i++){
		for(int cont = i+1, aux = 0; cont<6 ;cont++){
			if(numero[i]==numero[cont]){
				return 2;
			}else if(numero[i] > numero[cont]){
				aux = numero[i];
				numero[i] = numero[cont];
				numero[cont] = aux;
			}
		}	
	}

	return 0;

}



//Adiciona uma nova aposta
Jogador NovaAposta(){
	
	int *ctrl;
	Jogador j;

	ctrl = (int *) malloc(1);
	*ctrl = 0;

	j.concurso = dadosConcurso().numero;
	j.bilhete = lerUltimoBilhete()+1;
	j.status = 0;	/* 0 : esperando sorteio | -1 : nao ganhou | 1 : ganhou */	

	//menu de dados do concurso
	Limpar();
	printf("Situacao da aposta: Aguardando dados...\n");
	printf("Concurso: %d\n", j.concurso);
	printf("Bilhete: %d\n", j.bilhete);
	printf("Digite seu nome: ");
	scanf(" %[^\n]s",j.nome);
	printf("Digite a aposta: ");
	

	//verifica se numeros digitados seguem as regas para apostas. Nao se repetirem e estarem entre 1 e 60
	do{
		if(*ctrl){
				Limpar();
				if(*ctrl == 1){
					printf("Situacao da aposta: Algum numero invalido!!! - Digite a aposta novamente\n");
				}else if(*ctrl == 2){
					printf("Situacao da aposta: Numeros iguais!!! - Digite a aposta novamente\n");
				}
				printf("Concurso Referente Numero: %d\n", j.concurso);
				printf("Numero do bilhete: %d\n", j.bilhete);
				printf("Digite seu nome: %s\n", j.nome);
				printf("Digite a aposta: ");	
		}
		

		for(int i = 0; i<6 ; i++){
			scanf("%d", &j.aposta[i]);
		}

		/*verifica se existem numeros iguais ou  se os numeros digitados estão entre 1 e 60
		  se forem iguais *ctrl = 2, se não estivem entre 1 e 60 *ctrl = 1, se não entrar em nenhum desses casos return 0 */
		*ctrl = casoDeErroAposta(j.aposta);
	
		__fpurge(stdin);

	}while(*ctrl);

	free(ctrl);		

	//salva nova aposta em arquivo
	salvarAposta(j);

	return j;
}

