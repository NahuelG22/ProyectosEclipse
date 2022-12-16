/*
 * biblioteca.c
 *
 *  Created on: 8 abr. 2022
 *      Author: Nahuel A
 */

#include "biblioteca.h"

int CalcularFactorial(int numeroIngresado)
{
	int factorial;
	if(numeroIngresado==0)
	{
		factorial=1;
	}
	else
	{
		factorial=numeroIngresado*CalcularFactorial(numeroIngresado-1);
	}
	return factorial;
}
