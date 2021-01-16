#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void VerificarGanhadores(Concurso x, int *total_5, int *total_6){

	FILE *arquivo;
	int i = 0, j = 0, troca, acertos = 0;
	Jogador apostador;

	

	if(total_6 != NULL && total_5 != NULL){

		arquivo = fopen("apostas.txt", "r");

		for(i = 0; i < 5; i++){
			j = i + 1;
			for(j; j < 6; j++){
				if(x.resultado[i] > x.resultado[j]){
					troca = x.resultado[i];
					x.resultado[i] = x.resultado[j];
					x.resultado[j] = troca;
				}
			}
		}	


		while(1){
			fread(&apostador, sizeof(Jogador), 1, arquivo);

			
			
			if(feof(arquivo))
				break;

			if(apostador.concurso == x.numero){
				acertos = 0;
				for(i = 0; i < 6; i++){
					if(x.resultado[i] == apostador.aposta[i])
						acertos++;
				}

				

			}
			if(acertos == 5)
				*total_5 = *total_5 + 1;
			if(acertos == 6)
				*total_6 = *total_6 + 1;
		}

		fclose(arquivo);
	}



}	