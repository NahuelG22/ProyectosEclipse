/*
 ============================================================================
 Name        : Ejercicio10-3.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productos.h"
#define EEUU 50
#define CHINA 100
#define OTRO 120
#define T 10



int main(void)
{
	setbuf(stdout, NULL);
	eApple listaProductos[];
	eTipoProducto listadoTipoProducto[4]={{1000, "Iphone"},{1001, "Ipad"},{1002,"Mac"}, {1003, "Accessorios"}};
	int opcion;
	int retorno;

	do
		{
			printf("1.Alta producto\n2.Baja producto\n3.Modificacion producto\n4.Listado productos\n5Listado ordenado por precio\n"
					"6.Listado ordenado por descripcion\n7.Productos mas caros\n8.Precio promedio por producto\n"
					"9.Productos que cuestan 700\n10.Iphone mas barato\n11.Productos hechos en China\n12.Mac mayor a 700\n13.Accesorios mas caros\n"
					"\n14.Listado de productos con descripcion del tipo\n15.Lista de productos por tipo\nElija una opcion: ");
			scanf("%d", &opcion);
			switch(opcion)
			{
				case 1:
					retorno=CargarListaDeProductos(listaProductos, T);
					switch(retorno)
					{
						case -1:
							printf("\nNo hay mas espacio\n");
						break;
						default:
							printf("\nSe cargo exitosamente al alumno\n");
						break;
					}
				break;
				case 2:
					retorno=EliminarProducto(listaProductos, T);
					switch(retorno)
					{
						case -1:
							printf("\nNo se encontro el id\n");
						break;
						default:
							printf("\nProducto eliminado\n");
						break;
					}
				break;
				case 3:
					retorno=ModificarProducto(listaProductos, T);
					switch(retorno)
					{
						case -1:
							printf("\nNo se encontro el id\n");
						break;
						default:
							printf("\Producto modificado\n");
						break;
					}
				break;
				case 4:
					MostrarListaDeProductos(listaProductos, T);
				break;
				case 5:
					ListarProductoPorPrecio(listaProductos, T);
				break;
				case 6:
					retorno=ModificarAlumno(listaProductos, T);
					switch(retorno)
					{
						case -1:
							printf("\nNo se encontro el legajo\n");
						break;
						default:
							printf("\nAlumno modificado\n");
						break;
					}//hacer funcion para no repetir el switch
				break;
				case 7:
					MostrarProductosMasCaros(listaProductos, T);
				break;
				case 8:
					for(int i=0;i<T;i++)
					{
						for(int j=0; j<3; j++)
						{
							if(listaProductos[i]. estado == OCUPADO && listaProductos[i].idCurso==listaProductos[j].idCurso)
							{
								printf("%4d %10s %2.2f %10s\n", listaProductos[i].legajo,listaProductos[i].nombre, listaProductos[i].promedio, listaProductos[j].descripcion);
							}
						}
					}
				break;
				case 9:
					MostrarProductosCaros(listaProductos, T);
				break;
				case 10:
					MostrarIphoneBarato();
				break;
				case 11:
					MostrarHechoenChina();
				break;
				case 12:
					MostrarMacCara();
				break;
				case 13:
					MostrarAccesoriosCaros();
				break;
				case 14:

				break;
				case 15:

				break;
			}
		}while(opcion!=16);

	return EXIT_SUCCESS;
}
