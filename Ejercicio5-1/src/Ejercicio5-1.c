/*
 ============================================================================
 Name        : Ejercicio5-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5//le da el valor que quiera a una variable(en este caso TAM pero puede tener cualquier nombre)

void CargarVector(int numeros[], int size);
void MostrarVector(int numeros[], int size);
int SumarNumerosVector(int numeros[], int size);

int main(void)
{
	setbuf(stdout, NULL);
	int numeros[TAM];
	//int numeros[5];vector normal
	//int vector[10];tamaño especifico de vector
	int suma;
	suma=0;
	CargarVector(numeros, TAM);
	suma=SumarNumerosVector(numeros, TAM);
	printf("\nLa  suma es: %d", suma);
}
void CargarVector(int numeros[], int size)
{
	for(int i=0; i<size; i++)
	{
		printf("Ingrese un numero: ");
		scanf("%d", &numeros[i]);
	}
}
void MostrarVector(int numeros[], int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%d\n", numeros[i]);
	}
}
int SumarNumerosVector(int numeros[], int size)
{
	int suma;
	suma=0;
	for(int i=0; i<size; i++)
	{
		suma+=numeros[i];
	}
	return suma;
}



