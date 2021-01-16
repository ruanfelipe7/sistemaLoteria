#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "functions.h"

void salvarAposta(Jogador x){

	
	FILE *arquivo;

	if(!verificaSeArquivoNaoVazio(fopen("apostas2.txt", "r")) && !verificaSeArquivoNaoVazio(fopen("apostas.txt", "r"))){
	
	 arquivo = fopen("apostas.txt", "a");
	
	}

	else if (!verificaSeArquivoNaoVazio(fopen("apostas2.txt", "r"))){

	 arquivo = fopen("apostas.txt", "a");


	}

	else if (!verificaSeArquivoNaoVazio(fopen("apostas.txt", "r"))){

		arquivo = fopen("apostas2.txt", "a");
	}
	fwrite(&x, sizeof(Jogador), 1, arquivo);
	fclose(arquivo);	
}
