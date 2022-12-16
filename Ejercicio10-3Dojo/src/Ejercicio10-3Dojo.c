/*
 ============================================================================
 Name        : Ejercicio10-3Dojo.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EEUU 1
#define CHINA 2
#define OTRO 3

typedef struct
{
	int idProducto;
	char descripcion[50];
	int nacionalidad;
	int idTipo;
	float precio;
}eProducto;

typedef struct
{
	int idTipo;
	char descripcionTipo[20];
}etipoProducto;

//float CalcularPromedio(float acumulador, int contador);

float

int main(void)
{
	setbuf(stdout, NULL);

	int contador;
	float acumulador;
	float promedio;
	int bandera;
	float productoCaro;

	bandera=0;

	eProducto producto[5]={{1, "Producto 1", 1, 1000 ,15000},{2, "Producto 2", 2, 1001, 15000},
							{3,"Producto 3", 3, 1003, 15000},{4, "Producto 4", 3, 1003, 60000},
							{5, "Producto 5", 2, 1001, 50000}};
	etipoProducto tipo[4]= {{1000,"Iphone"},{1001,"Ipad"},{1002,"Mac"},{1003,"Accesorios"}};

//	for(int i=0; i<4; i++)
//	{
//		contador=0;
//		printf("%s", tipo[i].descripcionTipo);
//		acumulador=0;
//
//		for(int j=0; j<5; j++)
//		{
//			if(tipo[i].idTipo==producto[j].idTipo)
//			{
//				//acumulador++;
//				acumulador=acumulador+producto[j].precio;
//				contador++;
//			}
//		}
//		promedio=acumulador/contador;
//		printf("\n%-4s %10.2f", promedio);
//	}

	for(int i=0; i<5; i++)
	{
		if(bandera==0 || producto[i].precio>productoCaro)
		{
			productoCaro=producto[i].precio;
			bandera=1;
		}
	}
	for(int i=0; i<5; i++)
	{
		if(producto[i].precio==productoCaro)
		{
			printf("\n%-4d %-10s %4.2f", producto[i].idProducto, producto[i].descripcion, producto[i].precio);
		}
	}

	return EXIT_SUCCESS;
}

//float CalcularPromedio(float acumulador, int contador)
//{
//	float resultado;
//
//	resultado=acumulador/contador;
//
//	return resultado;
//}
