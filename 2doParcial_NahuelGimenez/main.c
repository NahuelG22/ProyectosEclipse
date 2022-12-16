/*
 ============================================================================
 Name        : main.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : 2do Parcial Laboratorio
 ============================================================================
 */

#include <stdio.h>
#include "LinkedList.h"
#include "controller.h"
#include "Libros.h"
#include "Parser.h"

int main()
{
	setbuf(stdout, NULL);
    LinkedList* listaLibros = ll_newLinkedList();
    int opcion;
    int flag = 0;

    do
    {
    	opcion=getNumberInt("\n1. Leer archivo.csv \n2. Imprimir por pantalla los datos de los libros/n3. Ordenar la lista generada en el ítem anterior/n4. Generar el archivo de salida ordenado.csv conteniendo la lista del ítem anterior./n5. Funcion ll_map(incremento de precios)/n6. Generar el archivo de salida mapeado.csv conteniendo la lista del ítem anterior.", "/nOpcion invalida", 1, 6);
		switch (opcion)
		{
			case 1:
				controller_loadFromText("datos_SP_1K",listaLibros);
				printf("\nLista de libros leida con exito\n");
				flag = 1;
				break;

		   case 2:
				controller_ListLibros(listaLibros);
				flag = 1;
				break;
		   case 3:
			   controller_sort(listaLibros);
			   break;
		   /*case 4:


			   break;
		   case 5:


			   break;
		   case 6:


			   break;
			   */
		}
    }while(opcion==0);

	return 0;
}
