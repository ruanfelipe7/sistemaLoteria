#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void Sorteio(){
	int i = 0, j = 0, numeros[6];
	int control = 0;
	FILE *arquivo;
	Concurso con;
	 
    srand((unsigned)time(NULL));

    for(i=0; i<6; i++)
        numeros[i] = 1 + rand() % (60);
     
    //verificacao de numeros repetidos
    do{
	    for(i = 0; i < 5; i++){
	    	for(j = i + 1; j < 6; j++){
	    		if(numeros[i] == numeros[j]){
	    			numeros[j] = 1 + rand() % (60);
	     			control = 1;
	     			break;
	     		}else{
	     			control = 0;
	     		}
	     	}
	    }
	}while(control); 

	
 	arquivo = fopen("conc.txt", "w+");
 	//guarda os dados do concurso aberto em con
 	fread(&con, sizeof(Concurso), 1, arquivo);

	
	//atualiza as informacoes do concurso aberto
	con.status = 0;
	for(i = 0; i < 6; i++)
		con.resultado[i] = numeros[i];
	

	//salva no arquivo as informações atualizadas do concurso
	if(fwrite(&con, sizeof(Concurso), 1, arquivo)){
		RelatorioSorteio(con); //se os dados forem salvos com sucesso -> mostra o relatorio/dados do sorteio
	}
	fclose(arquivo);

	//adiciona o concurso do sorteio nos concursos já realizados
	verificaArquivo("concursos_realizados.txt", 1);
	arquivo = fopen("concursos_realizados.txt","a");
	fwrite(&con, sizeof(Concurso), 1, arquivo);
	fclose(arquivo);
}