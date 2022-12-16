/*============================================================================
 Name        : Forni, Gonzalo
 Div 	     : 1C
 Description : Ejercicio 8.2
 ============================================================================*/
#include "inputs.h"
#include "Productos.h"
#include <stdio.h>
#define TAM 10

int main(void) {
	setbuf(stdout, NULL);

	int opcionSeleccionada;
	eProducto listaProductos[10];
	int idAutoincremental= 100;
	int comprobanteCarga;
	int comprobanteModificacion;
	int cantidadProductos= 0;
	int aux;

	InicializarProductos(listaProductos, TAM);

	do
	{
		printf("1. ALTA\n"
			   "2. BAJA\n"
			   "3. MODIFICACION\n"
			   "4. Listado productos\n"
			   "5. Listado ordenado por precio\n"
			   "6. Listado ordenado por descripcion\n"
			   "7. SALIR");
		opcionSeleccionada= getNumberInt("\nSeleccione una opcion: ", "\nError!!! La opcion ingresada es incorrecta...", 1, 7);

		switch(opcionSeleccionada)
		{
			case 1: //ALTA
				comprobanteCarga= CargarProducto(listaProductos, TAM, idAutoincremental);
				if(comprobanteCarga != -1) {
					printf("\nLa carga fue realizada con exito!!!\nEl ID de su producto es: %d\n", idAutoincremental);

					cantidadProductos++;
					idAutoincremental++;
				}
				else {
					printf("\nError!!! La carga no fue realizada con exito...\n");
				}
				break;
			case 2: //BAJA
				if(cantidadProductos > 0) {
					ListarProductos(listaProductos, TAM);
					aux= getNumberInt("\nIngrese el id del producto a dar de baja: ", "\nError!!! El id ingresado no pertenece a un producto...", 100, 110);
					for(int i=0 ; i<TAM ; i++) {
						if(listaProductos[i].idProducto == aux && listaProductos[i].isEmpty == OCUPADO) {
							listaProductos[i].isEmpty= LIBRE; //Aca deberia crear otro define ej "BAJA" para que no se pisen los datos o listas bajas???
							cantidadProductos--;
							printf("Los datos fueron borrados...\n");
							break;
						}
					}
				}
				else {
					printf("Error!!! No se registraron cargas de productos...");
				}
				break;
			case 3: //MODIFICACION
				if(cantidadProductos > 0) {
					ListarProductos(listaProductos, TAM);
					aux= getNumberInt("\nIngrese el id del producto a modificar: ", "\nError!!! El id ingresado no pertenece a un producto...", 100, 110);
					for(int i=0 ; i<TAM ; i++) {
						if(listaProductos[i].idProducto == aux && listaProductos[i].isEmpty == OCUPADO) {
							comprobanteModificacion= ModificarUnProducto(listaProductos, TAM, i);
							if(comprobanteModificacion == 0) {
								printf("\nLos datos fueron modificados...\n");
							}
						}
					}
				}
				else {
					printf("\nError!!! No se registraron cargas de productos...\n");
				}
				break;
			case 4: //Listado productos
				if(cantidadProductos > 0) {
					ListarProductos(listaProductos, TAM);
				}
				else {
					printf("\nError!!! No se registraron cargas de productos...\n");
				}
				break;
			case 5:
				if(cantidadProductos > 0)
				{
					listadoOrdenadoPorPrecio(listaProductos, TAM);
				}
				else {
					printf("\nError!!! No se registraron cargas de productos...\n");
				}
				break;
			case 6:
				if(cantidadProductos > 0)
				{
					listadoOrdenadoPorDescripcion(listaProductos, TAM);
				}
				else {
					printf("\nError!!! No se registraron cargas de productos...\n");
				}
				break;
			default: //Salir
				printf("\nSaliendo del programa...");
				break;
		}
	}while(opcionSeleccionada != 7);

	return 0;
}

