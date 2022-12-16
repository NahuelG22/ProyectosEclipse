/*
 ============================================================================
 Name        : Estructuras.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declarar una estructura de alumno que contenga los campos(nombre, edad, notaParcialUno, notaParcialDos y promedio).

typedef struct
{
	char nombre[15];
	int edad;
	int notaParcialUno;
	int notaParcialDos;
	float promedio;
}sAlumno;

int main(void)
{
	setbuf(stdout, NULL);

	sAlumno unAlumno={"Jorge, 19, 8, 5, 6.5"};

	printf("Nombre del alumno: %s\nEdad del Alumno: %d\n",unAlumno.nombre, unAlumno.edad);

	return EXIT_SUCCESS;
}
