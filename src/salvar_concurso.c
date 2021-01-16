#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "functions.h"

int SalvandoNumConcurso(int numero){
	FILE *save;
	int retorno = 0;

	save = fopen("conc.txt", "w");

	if(save != NULL){
		fwrite(&numero, sizeof(int), 1, save);
		
		retorno = 1;
	}else{
		printf("Falha na escrita");
		retorno = 0;
	}
	
	fclose(save);
	return retorno;
}

int SalvarConcurso(Concurso x){

	int resposta;
	FILE *adicionar;

	adicionar = fopen("conc.txt", "w");
	
	resposta = fwrite(&x, sizeof(Concurso), 1, adicionar);

	fclose(adicionar);

	if(resposta == 1){
		return resposta;
	}
	else{
		return 0;
	}
}