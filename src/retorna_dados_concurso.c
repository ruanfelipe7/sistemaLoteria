#include <stdio.h>
#include "functions.h"

Concurso dadosConcurso(){
	
	Concurso a;
	FILE *arquivo = fopen("conc.txt","r");

	fread( &a , sizeof(Concurso) , 1 , arquivo);
	fclose(arquivo);

	return a;
}