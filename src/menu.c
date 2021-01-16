#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void  MostrarMenu(){
		
	printf("******* NOVO SISTEMA DE LOTERIA *******\n\n");
	printf("\t         MENU         \n");
	printf("\t 1 - Novo Conscurso   \n");
	printf("\t 2 - Adicionar Aposta \n");
	printf("\t 3 - Lista de Apostas \n");
	printf("\t 4 - Modificar Aposta \n");
	printf("\t 5 - Realizar Sorteio \n");
	printf("\t 6 - Ver Resultado    \n");
	printf("\t 7 - Ver Ganhadores   \n");
	printf("\t 8 - Sair             \n\n");

	EscolherOpcao();

}

void MostrarSubMenuAposta(){

	printf("\n\nEscolha uma opcao");
	printf("\n\t1 - Nova aposta");
	printf("\n\t2 - Voltar ao menu principal");
	printf("\n\nDigite a opcao desejada: ");
	EscolhaSubMenu();
	
}
