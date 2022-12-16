/*
 ============================================================================
 Name        : Ejercicio5-2.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "verificaciones.h"

#define TAM 10

void cargarNumeros(int numeros[], int size);

int contarPositivos(int numeros[], int size);

int contarNegativos(int numeros[], int size);

int sumarPares(int numero[], int size);

int imparMayor(int numero[], int size);

void listarNumeros(int numeros[], int size);

void listarPares(int numeros[], int size);

void listarPosicionImpares(int numeros[], int size);

void burbujeoPositivos(int numeros[], int size);

void burbujeoNegativos(int numeros[], int size);

void listarPositivos(int numeros[], int size);

void listarNegativos(int numeros[], int size);

int main(void)
{
	int numeros[TAM];
	int cantidadPositivos;
	int cantidadNegativos;
	int sumatoriaPares;
	int mayorImparIngresado;

	cargarNumeros(numeros, TAM);
	cantidadPositivos = contarPositivos(numeros, TAM);
	cantidadNegativos = contarNegativos(numeros, TAM);
	sumatoriaPares = sumarPares(numeros, TAM);
	mayorImparIngresado = imparMayor(numeros, TAM);

	printf("Se ingresaron un total de: %d numeros positivos \n", cantidadPositivos);
	printf("Se ingresaron un total de: %d numeros negativos \n", cantidadNegativos);
	printf("La suma de todos los numeros pares es de: %d \n", sumatoriaPares);
	printf("El mayor numero impar ingresado es: %d \n\n", mayorImparIngresado);
	printf("Los numeros ingresados fueron:\n");
	listarNumeros(numeros, TAM);
	printf("\n\nLos numeros pares ingresados fueron:\n");
	listarPares(numeros, TAM);
	printf("\nLos numeros impares se encuentran en la posicion: \n");
	listarPosicionImpares(numeros, TAM);

	return 0;
}

void cargarNumeros(int numeros[], int size)
{
    for(int i=0; i < size; i++)
    {

        numeros[i] = pedirEntero("Ingrese un numero");
		while(numeros[i] < -1000 || numeros[i] > 1000)
		{
			numeros[i] = pedirEntero("Reingrese un numero valido");
		}
    }
}

int contarPositivos(int numeros[], int size)
{
    int contadorPositivos;

    contadorPositivos = 0;

        for(int i=0; i < size; i++)
        {
            if(verificarSigno(numeros[i]) == 1)
            {
                contadorPositivos++;
            }
        }
    return contadorPositivos;
}

int contarNegativos(int numeros[], int size)
{
   int contadorNegativos;

    contadorNegativos = 0;

        for(int i=0; i < size; i++)
        {
            if(verificarSigno(numeros[i]) == -1)
            {
                contadorNegativos++;
            }
        }
    return contadorNegativos;
}

int sumarPares(int numero[], int size)
{
    int acumuladorPares;

    acumuladorPares = 0;

        for(int i=0; i < size; i++)
        {
            if(verificarParidad(numero[i]) == 1)
            {
                acumuladorPares += numero[i];
            }
        }
    return acumuladorPares;
}

int imparMayor(int numero[], int size)
{
    int flagImparMayor;
    int imparMayorIngresado;

    flagImparMayor = 0;

        for(int i=0; i < size; i++)
        {
            if(verificarParidad(numero[i]) == 0)
            {
                if(imparMayorIngresado < numero[i] || flagImparMayor == 0)
                {
                    imparMayorIngresado = numero[i];
                    flagImparMayor = 1;
                }
            }
        }
    return imparMayorIngresado;
}

void listarNumeros(int numeros[], int size)
{
    for(int i=0; i < size; i++)
    {
        printf("%d \n", numeros[i]);
    }
}

void listarPares(int numeros[], int size)
{
    for(int i=0; i < size; i++)
    {
        if(verificarParidad(numeros[i]) == 1)
        {
           printf("%d \n", numeros[i]);
        }
    }
}

void listarPosicionImpares(int numeros[], int size)
{
   for(int i=0; i < size; i++)
   {
       if(verificarParidad(i) == 0)
       {
           printf("%d \n", numeros[i]);
       }
   }
}
