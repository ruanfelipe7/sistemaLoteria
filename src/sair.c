#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void sair(){

	char SouN[1]; 

	Limpar();

	printf("Deseja sair? Sim = s, Nao = n\n");
	scanf(" %s",SouN);

	if(SouN[0] == 's' || SouN[0] == 'S'){
		Limpar();
		exit(0);		

		
	}else if(SouN[0] == 'n' || SouN[0] == 'N'){
		Limpar();
		MostrarMenu();
		EscolherOpcao();
	}
	else{
		
		printf("Opcao inválida\n");
		sair();
	}
}