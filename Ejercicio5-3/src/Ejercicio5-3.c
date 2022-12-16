/*
 ============================================================================
 Name        : Ejercicio5-3.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#define size 10

int main(void)
{
	setbuf(stdout, NULL);
	int numeros[size];
	int i;
	float promedio;
	int suma;
	int flagMenorNegativo;
	int menorNegativo;
	int sumaNegativos;

	i=0;
	suma=0;
	flagMenorNegativo=0;
	sumaNegativos=0;
	getVector(numeros, size);
	if(numeros[i]>0)
	{
		suma+=numeros[i];
		promedio=suma/size;
	}
	if(numeros[i]<0)
	{
		if(flagMenorNegativo==0)
		{
			menorNegativo=numeros[i];
			sumaNegativos=numeros[i]+menorNegativo;
			flagMenorNegativo=1;
		}
	}
	printf("El promedio de los positivos es: %f\nLa suma de los negativos es: %d", promedio, sumaNegativos);

	return EXIT_SUCCESS;
}


