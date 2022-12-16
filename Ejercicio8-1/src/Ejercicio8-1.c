/*
 ============================================================================
 Name        : Ejercicio8-1.c
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
#include "input.h"

//Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
//Crear una función que permita cargar los datos de un jugador y otra que los muestre.
//Una tercera función calculará el promedio de goles.

typedef struct
{
	char nombre[15];
	char apellido[15];
	char nombreCompleto[30];
	int goles;
	int partidosJugados;
	float promedioGoles;
}sJugador;

sJugador CargarDatosJugador();

int main(void)
{
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

sJugador CargarDatosJugador()
{
	sJugador messi;

	getString(messi.nombre, "Ingrese nombre: ");
	messi.goles=
}
