#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include <time.h>

//Adiciona um novo concurso

int NovoConcurso(Concurso *a, int ult){

	Limpar();

	int res = 0;
		
	struct tm *ab;
	time_t t;

	char aux[5], data[15];
	int hr; 
	char horario[10];

	t = time(NULL);
	ab = localtime(&t);

 	hr = ab->tm_mday;

 	if(hr < 10)
 		sprintf(aux, "%i%i", 0,hr);	
 	else
 		sprintf(aux, "%i", hr);

 	sprintf(data, "%s", aux);

 	hr = ab->tm_mon+1;

 	if(hr < 10)
 		sprintf(aux, "%i%i", 0,hr);	
 	else
 		sprintf(aux, "%i", hr);

 	sprintf(data, "%s/%s", data,aux);

 	hr = ab->tm_year+1900;

 	sprintf(aux, "%i", hr);
 	sprintf(data, "%s/%s", data,aux);
	
	hr = ab->tm_hour;
	if(hr < 10)
 		sprintf(aux, "%i%i", 0,hr);	
 	else
 		sprintf(aux, "%i", hr);

 	sprintf(horario, "%s", aux);

	hr = ab->tm_min;
	if(hr < 10)
 		sprintf(aux, "%i%i", 0,hr);	
 	else
 		sprintf(aux, "%i", hr);

 	sprintf(horario, "%s:%s", horario,aux);

 	hr = ab->tm_sec;
 	if(hr < 10)
 		sprintf(aux, "%i%i", 0,hr);	
 	else
 		sprintf(aux, "%i", hr);

 	sprintf(horario, "%s:%s", horario,aux);
	
		


	if(a != NULL){
		a->numero = ult+1;
		strcpy(a->data, data);
		strcpy(a->horario, horario);	
		a->valor = ValorConcurso();
		a->status = 1;
		for(int i = 0; i < 6; i++)
			a->resultado[i] = 0;

		if(a->numero){
			res = SalvandoNumConcurso(a->numero);

			if(res){
				
				return res;
			}
		}else{
			return 0;
		}
	}

}