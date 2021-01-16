#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "functions.h"

//Lê numero do ultimo bilhete
// se apostas.txt estiver vazio -> return 0, se não -> return = numero da ultima aposta
int lerUltimoBilhete(){

	FILE *arquivo = fopen("apostas.txt","r"), *arq2 = fopen("apostas2.txt","r");
	Jogador aposta;

	int d;
	//movimenta a posicao de leitura para o fim do arquivo
	fseek(arquivo, 0, SEEK_END);
	fseek(arq2, 0, SEEK_END);
	//ve quantos bytes existe do comeco ao fim do arquivo
	if(ftell(arquivo) == 0 && ftell(arq2) == 0){
		fclose(arquivo);
		return 0;
	}else if(ftell(arquivo) == 0){
		fclose(arquivo);
		arquivo = fopen("apostas2.txt","r");

		while(1){
			fread(&aposta, sizeof(Jogador), 1, arquivo);
			if(feof(arquivo))
				break;
		}

		fclose(arquivo);
		return aposta.bilhete;

	}else if(ftell(arq2) == 0){
		fclose(arquivo);
		arquivo = fopen("apostas.txt","r");

		while(1){
			fread(&aposta, sizeof(Jogador), 1, arquivo);
			if(feof(arquivo))
				break;
		}

		fclose(arquivo);
		return aposta.bilhete;

	}	
		
		
	
}
