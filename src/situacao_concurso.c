#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// Retorna 1 se o concurso estiver aberto(conc.status = 1), retorna 0 se o concurso estiver fechado
int situacaoConcurso(){
	FILE *ler;
	Concurso conc;
	
	ler = fopen("conc.txt", "r");

	if(verificaSeArquivoNaoVazio(fopen("conc.txt", "r"))){
		fread(&conc, sizeof(Concurso), 1, ler);
		fclose(ler);

		return conc.status;			
	}
	else{
		fclose(ler);

		return 0;
	}

	
	

	
}