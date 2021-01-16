#include <stdio.h>
#include "functions.h"

int verificaNumeroConcursos(){  //funcao verifica quantos concursos existem e recebe do usuário o concurso escolhido
	
	Concurso c;
	int temp;
	FILE * arquivo = fopen("concursos_realizados.txt","r");

	while(1){ //recebe o numero do ultimo concurso
		if(feof(arquivo)) 
			break;
		fread(&c, sizeof(Concurso) ,1, arquivo);
	}
	fclose(arquivo);

	printf("*********** Resultado de Concursos Passados ***********\n\n");

	do{
		printf("\tExistem: %d concursos\n\tDigite o numero do concurso escolhido: ", c.numero);
		scanf("%d",&temp);
		printf("\n\n");

		if(temp > 0 && temp<=c.numero) break; //verifica se o numero escolhido pelo usuario e um concurso

		Limpar();
		printf("*********** Resultado de Concursos Passados ***********\n");
		printf("\t     !!!Numero digitado invalido!!!\n");
	}while(1);

	return c.numero;
}

Concurso verificaConcursos(int numero){
	
	FILE * arquivo = fopen("concursos_realizados.txt","r");
	Concurso escolhido;

	while(1){

		fread( &escolhido ,sizeof(Concurso),1, arquivo);

		if(!feof(arquivo) || escolhido.numero==numero){
			if(escolhido.numero==numero){
				break;
			}else{
				break;
			}
		}

	}
	fclose(arquivo);

	return escolhido;
}