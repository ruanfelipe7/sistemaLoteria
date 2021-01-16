#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "functions.h"

void EscolherOpcao(){

	int op;

	
	//cria objeto para concurso
	Concurso b;
	Jogador j;
	printf("Escolha uma opcao: ");
	scanf("%d",&op);

	switch(op){
		case 1:
			/*funcao verificaArquivo("conc.txt",0): verifica se o arquivo conc.txt existe e o cria caso não exista. Obs.: A funcao não escreve no arquivo.
				se a funcao criou o arquivo e opc == 0 apenas retorna 0, opc !=0 cria arquivo e retorna 0 
				se o arquivo já existia -> return 1 */
			if(verificaArquivo("conc.txt", 1)){
				//se a situacao for igual a 0 -> concursos fechados, se situacao != 0 -> existe um concurso aberto 
				if(situacaoConcurso()){
					Limpar();
					printf("Impossivel Criar um concurso!!\nExiste um concurso em aberto\n\n ");
					MostrarMenu(); //chama o menu principal
					
					break;
				}else{//se concurso fechado -> cria um novo concurso
					//funcao LeituradeConcursos(): Recebe o numero do ultimo concurso
					//funcao NovoConcurso(&b,  ): gera os dados de um novo concurso
					//printf("asd\n");
					if( NovoConcurso(&b, LeituradeConcursos()) ){//verifica os dados do concurso foram gerados
						if(SalvarConcurso(b)){ //tenta salvar os dados e verifica se os dados foram salvos em arquivo
							RelatorioConcurso(b); //mostra um relatorio dos dados inseridos do concurso	
							MostrarMenu();
							break;
						}
					}
				}
			// se conc.txt não existia	
			}else{
				if(NovoConcurso(&b, 0)){
					if(SalvarConcurso(b)){ 
						RelatorioConcurso(b);	
						MostrarMenu();
						break;
					}
				}
			}
			break;

		case 2:
			
	
			verificaArquivo("apostas.txt", 1);
			verificaArquivo("apostas2.txt", 1); //verifica se apostas.txt existe, e cria-o caso não exista



			if(!situacaoConcurso()){ //se for 0,	 nenhum concurso esta aberto
				Limpar();
				printf("Impossivel realizar aposta\n");
				printf("Nenhum concurso em aberto\n\n");
				MostrarMenu();
				
				break;
				
			}else{ //Criacao de uma nova aposta/
				// Funcao NovaAposta() cria e salva nova aposta em arquivo
				RelatorioAposta(NovaAposta(), 2); //se ela for salva chama o relatorio da aposta
				MostrarSubMenuAposta();
				
			}	
			break;

		case 3:
	
			if(!situacaoConcurso()){ //se for 0,	 nenhum concurso esta aberto
				Limpar();
				printf("Impossivel listar aposta\n");
				printf("Nenhum concurso em aberto\n\n");
				MostrarMenu();
				
				break;
				
			}
			ListarApostas( LeituradeConcursos() ); //listando as apostas realizadas
			break;
		
		case 4:

			verificaArquivo("apostas.txt", 1);
			verificaArquivo("apostas2.txt", 1);
			if(!situacaoConcurso()){ //se for 0,	 nenhum concurso esta aberto
				Limpar();
				printf("Impossivel listar aposta\n");
				printf("Nenhum concurso em aberto\n\n");
				MostrarMenu();
				
				break;
				
			}
			__fpurge(stdin);
			Limpar();
			/* vai pra 6
				// verificaNumeroConcursos verifica se o numero do concurso digitado pelo usuario existe
	 			recebeDadosConcursos(verificaNumeroConcursos()); // recebeDados retorna os dados do concurso de acordo com o numero do concurso passado como parametro
	 		*/
			
			if(modificaAposta(&j)){
				RelatorioAposta(j, 1);	
			}

			
	 		MostrarMenu();
			
			break;
		
		case 5:

			__fpurge(stdin);
			
			if(situacaoConcurso()){
				Sorteio(); //Realiza o sorteio
				
				MostrarMenu();
				
			}else{
				Limpar();
				printf("Impossivel realizar sorteio\n");
				printf("Nenhum concurso em aberto\n\n");
				MostrarMenu();
			
			}
			break;
		
		case 6:
			__fpurge(stdin);
			Limpar();

			if(!verificaArquivo("conc.txt", 0)){
				
				printf("Nenhum concurso foi realizado\n");

			}else{
				
				b = dadosConcurso(); //dadosConcurso pega os dados do concurso atual e salva em "b", em seguida os dados do concurso atual são mostradors
				
				printf("***********  Resultado  **************\n");
				printf("\tConcurso Numero: %d\n", b.numero);
				printf("\tData: %s\n", b.data);
				printf("\tHorario: %s\n", b.horario);
				printf("\tValor: %.2f\n", b.valor);
				printf("\tResultado: ");
				
				for(int i =0; i<6; i++)
					printf("%d ", b.resultado[i]);
				
				printf("\n\n");
			}
			
			MostrarMenu();
			
			break;
		
		case 7:
			__fpurge(stdin);
			break;

		case 8:
			__fpurge(stdin);
			sair();
			break;

		default:
			__fpurge(stdin);
			Limpar();
			printf("Opcao invalida\n");
			MostrarMenu();
			
	}
}

void EscolhaSubMenu(){

	int opcao = 0;
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			RelatorioAposta(NovaAposta(), 2);
			MostrarSubMenuAposta();
			EscolhaSubMenu();	
			break;
		
		case 2:
			Limpar();
			MostrarMenu();
			EscolherOpcao();
			break;	

		default:
			Limpar();
			printf("Opcao inválida\n");
			__fpurge(stdin);
			MostrarSubMenuAposta();
			EscolhaSubMenu();	
	}
}