/*
 ============================================================================
 Name        : Ejercicio4-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void)
{
	setbuf(stdout, NULL);
	int numeroIngresado;
	int factorial;
	numeroIngresado=5;

	factorial=CalcularFactorial(numeroIngresado);

	printf("El factorial del numero es: %d", factorial);
	return EXIT_SUCCESS;
}


