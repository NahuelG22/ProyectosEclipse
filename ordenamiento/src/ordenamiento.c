/*
 ============================================================================
 Name        : ordenamiento.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 4

int main(void)
{
	int vector[TAM]={5,9,1,3};
	int auxiliarEntero;

	for(int i=0; i<TAM-1; i++)
	{
		for(int j=i+1; j<TAM; j++)
		{
			if(vector[i]>vector[j])
			{
				auxiliarEntero=vector[i];
				vector[i]=vector[j];
				vector[j]=auxiliarEntero;
			}
		}
	}
	for(int i=0; i<TAM; i++)
	{
		printf("%d - ", vector[i]);
	}

	return 0;
}
