#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

float ValorConcurso(){
	FILE *arquivo;
	Concurso conc;
	arquivo = fopen("conc.txt", "r");
	fread(&conc, sizeof(Concurso), 1, arquivo);
	fclose(arquivo);

	conc.valor = conc.valor + 3000;

	return conc.valor;
}