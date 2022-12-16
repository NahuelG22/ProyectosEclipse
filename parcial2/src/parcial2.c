/*
 ============================================================================
 Name        : parcial2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : pablo lazo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libros.h"
#include "Parser.h"
#include "imput.h"

int main()
{
	setbuf(stdout, NULL);
    LinkedList* listaLibros = ll_newLinkedList();
    char seguir='s';
    int opcion;
    int flag = 0;

    while (seguir=='s')
    {
        printf("\n------MENU------"
        	   "\n1- Realizar un programa que lea un archivo .csv (cuyo nombre se pasa como parámetro por línea de comandos), con los datos de libros, guardándolos en un linkedList de entidades eLibro.."
        	   "\n2- Imprimir por pantalla los datos de los libros. En lugar de idGenero, se deberá imprimirdependiendo el caso: 1=>CUENTO; 2=>NOVELA."
        	   "\n10-SALIR\n");
        scanf("%d", &opcion);


			switch (opcion)
			{
			case 1:
				controller_loadFromText("datos_SP_1F",listaLibros);
				printf("\nSe cargo EXITOSAMENTE la lista de Libros DATA CSV\n");
				flag = 1;
				break;

		   case 2:
				controller_ListLibros(listaLibros);
				flag = 1;
				break;



		/*	case 10:
				printf("Hasta Pronto :D");
				seguir='n';
				break;*/
			}
        }

	return 0;
}
