#include <stdio.h>
#include <stdlib.h>
#include "input.h"


int getInt(char mensaje[])
{
    int entero;
	printf("%s",mensaje);
	scanf("%d", &entero);
    return entero;
}

void getString(char nombre[], char mensaje[])
{
	printf("%s", mensaje);
	scanf("%[^\n]s",nombre);
}

void getVector(int numeros[], int size)
{
	for(int i=0; i<size; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numeros[i]);
	}
}
