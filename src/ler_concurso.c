#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "functions.h"

//Ler qual o numero dos concursos retornando ele

int LeituradeConcursos(){
	
	int retorno;

	FILE *ler;

	
	
	
	if(verificaSeArquivoNaoVazio(fopen("conc.txt", "r"))){
		ler = fopen("conc.txt", "r");	
		fread(&retorno, sizeof(int), 1, ler);	
		fclose(ler);

		return retorno;			
	}
	else{
		fclose(ler);

		return 0;
	}
	
}
