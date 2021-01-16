#include <stdio.h>
//funcao verifica se o arquivo existe/esta_vazio ou existe conteudo nele
/*opc indica se quando o arquivo nao existir, sera criado um novo arquivo ou apenas retornar 0. 
 	opc == 0 apenas retorna 0, opc !=0 cria arquivo 0*/
int verificaArquivo(char arquivo[], int opc){
	
    FILE * pFile;

    if(!fopen (arquivo,"r")){      
   		if(opc){
   			pFile = fopen(arquivo,"w");
	   		fclose(pFile);
   		}
   		return 0;
    }else{
    	return 1;
    }

    
}