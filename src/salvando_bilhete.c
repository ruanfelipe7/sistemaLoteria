#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int SalvandoNumBilhete(int bilhete){
	FILE *save;
	int retorno = 0;

	save = fopen("bilhete.txt", "w");

	if(save != NULL){
		fwrite(&bilhete, sizeof(int), 1, save);
		retorno = 1;
	}else{
		printf("Falha na escrita");
		retorno = 0;
	}

	fclose(save);

	return retorno;
}
