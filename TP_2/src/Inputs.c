/*
 * Inputs.c
 *
 *  Created on: 27 sep. 2022
 *      Author: Nahuel A
 */

#include "Inputs.h"

int getInt(char mensaje[])
{
	int aux;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &aux);

	return aux;
}

short getShort(char mensaje[])
{
	short aux;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%hd", &aux);

	return aux;
}

float getFloat(char mensaje[])
{
	float aux;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &aux);

	return aux;
}

char getChar(char mensaje[])
{
	char aux;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &aux);

	return aux;
}

void getString(char mensaje[], char input[])
{
	printf("%s", mensaje);
	fflush(stdin);
	gets(input);
}

int getNumberInt(char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int retorno;
	int nroIngresado;
	int flagComprobante=-1;

	if(mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		do
		{
			nroIngresado=getInt(mensaje);
			if(nroIngresado >= minimo && nroIngresado <= maximo)
			{
				retorno=nroIngresado;
				flagComprobante=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
			}
		}while(flagComprobante==-1);
	}
	return retorno;
}

short getNumberShort(char mensaje[], char mensajeError[], short minimo, short maximo)
{
	short retorno;
	short nroIngresado;
	int flagComprobante=-1;

	if(mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		do
		{
			nroIngresado=getShort(mensaje);
			if(nroIngresado >= minimo && nroIngresado <= maximo)
			{
				retorno=nroIngresado;
				flagComprobante=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
			}
		}while(flagComprobante==-1);
	}
	return retorno;
}

float getNumberFloat(char mensaje[], char mensajeError[], float minimo, float maximo)
{
	float nroIngresado;
	float retorno;
	int flagComprobante=-1;

	if(mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		do
		{
			nroIngresado=getFloat(mensaje);
			if(nroIngresado >= minimo && nroIngresado <= maximo)
			{
				retorno=nroIngresado;
				flagComprobante=0;
			}
			else
			{
				printf("%s", mensajeError);
			}
		}while(flagComprobante==-1);
	}

	return retorno;
}

int GetString(char cadena[], int len, char mensaje[])
{
	int retorno;
	char buffer[1024];
	int largoBuffer;

	retorno=0;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", buffer);

	largoBuffer=(int)strlen(buffer);

	if(len>largoBuffer)
	{
		strcpy(cadena, buffer);
		retorno=1;
	}

	return retorno;
}

int getName(char cadena[])
{
	int retorno=0;
	int i;

	for(i=0; i<strlen(cadena); i++)
	{
		if((isdigit(cadena[i])==1) || (isalpha(cadena[i])==0))
		{
			retorno=1;
		}
	}

	return retorno;
}
