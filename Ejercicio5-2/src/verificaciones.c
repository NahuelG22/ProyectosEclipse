/*
 * verificaciones.c
 *
 *  Created on: 21 abr. 2022
 *      Author: Nahuel A
 */
#include "verificaciones.h"

int verificarParidad(int entero)
{
	int paridad;

	paridad=0;

	if(entero%2==0)
	{
		paridad=1;
	}

	return paridad;
}

int verificarSigno(int entero)
{
	int signo;

	signo=0;

	if(entero>0 && entero!=0)
	{
		signo=1;
	}
	else
	{
		if(entero<0)
		{
			signo=-1;
		}
	}

	return signo;
}
