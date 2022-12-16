/*
 ============================================================================
 Name        : Ejercicio6-3.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	setbuf(stdout, NULL);

	char nombre[15];
	char apellido[15];
	char nombreCompleto[30];
	int largo;

	printf("Ingrese su nombre: ");
	fflush(stdin);
	gets(nombre);
	strlwr(nombre);
	nombre[0]=toupper(nombre[0]);

	largo=strlen(nombre);

	for(int i=0; i<largo; i++)
	{
		if(isspace(nombre[i]))
		{
			nombre[i]==toupper(nombre[i]);
		}
	}

	printf("\nIngrese su apellido: ");
	fflush(stdin);
	gets(apellido);
	strlwr(apellido);
	apellido[0]=toupper(apellido[0]);

	strcpy(nombreCompleto, apellido);
	strcat(nombreCompleto, ", ");
	strcat(nombreCompleto, nombre);

	printf("\n%s", nombreCompleto);

	return EXIT_SUCCESS;
}

//cuando queres cambiar a mayuscula vas a tener un if preguntando si en esa poscion hay un espacio y entra
//adentro cambias y metes el i++
