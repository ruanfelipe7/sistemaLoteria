#include <stdio.h>

int ContaDigitos(int num){
	int contador = 0;

	while(num > 0){
		contador++;
		num /= 10;
	}

	return contador;
}