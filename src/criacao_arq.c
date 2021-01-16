#include <stdio.h>
#include <stdlib.h>

//Cria os arquivos para salvar dados

void CriarArquivos(){
	FILE *criar;
	int init = 0;

		criar = fopen("concursos.txt", "w");
		fclose(criar);

		criar = fopen("conc.txt", "w");
		fwrite(&init, sizeof(int), 1, criar);
		fclose(criar);

		criar = fopen("bilhete.txt", "w");
		fwrite(&init, sizeof(int), 1, criar);
		fclose(criar);

		criar = fopen("apostas.txt", "w");
		fclose(criar);
	
}
