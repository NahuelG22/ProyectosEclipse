/*
 ============================================================================
 Name        : 1.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Inputs.h"
#include "Productos.h"
#include "Listados.h"
#define TAM 10

int main(void) {
	setbuf(stdout, NULL);

	eProducto listaProductos[TAM];

	int opcionSeleccionada;
	int idAutoincremental= 100;
	int comprobanteCarga;
	int comprobanteCargaForzada;
	int comprobanteModificacion;
	int cantidadProductos= 0;
	int aux;

	float promedioIphone;
	float promedioMac;
	float promedioIpad;
	float promedioAccesorios;

	InicializarProductos(listaProductos, TAM);

	do
	{
		printf("0. Carga forzada\n"
			   "1. ALTA\n"
			   "2. BAJA\n"
			   "3. MODIFICACION\n"
			   "4. Listado productos\n"
			   "5. Listado ordenado por precio\n"
			   "6. Listado ordenado por descripcion\n"
			   "7. Listado el/los  productos más caros\n"
			   "8. Listado los productos que cuestan 700\n"
			   "9. Listado precio promedio por tipo de producto\n"
			   "10. Listado de los Iphone el más barato\n"
			   "11. Listado sos productos MADE IN CHINA\n"
			   "12. Listado las MAC que cuestan más de 700 USD\n"
			   "13. Listado el/Los Accesorios más caros\n"
			   "14. SALIR\n");
		opcionSeleccionada= getNumberInt("\nSeleccione una opcion: ", "\nError!!! La opcion ingresada es incorrecta...", 0, 14);

		switch(opcionSeleccionada)
		{
			case 0:
				comprobanteCargaForzada= RealizarCargaForzada(listaProductos, TAM);
				if(comprobanteCargaForzada == 0) {
					printf("Se realizo la carga forzada...\n\n");
					cantidadProductos= cantidadProductos + 5;
				}
				break;
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
			case 5: //Listado ordenado por precio
				OrdenarListadoPorPrecio(listaProductos, TAM);
				break;
			case 6: //Listado ordenado por descripcion
				OrdenarListadoPorDescripcion(listaProductos, TAM);
				break;
			case 7: //El/los productos más caros
				OrdenarListaProductosCaros(listaProductos, TAM);
				break;
			case 8: //Los productos que cuestan 700
				ListarProductosCuestenSetecientos(listaProductos, TAM);
				break;
			case 9: //Precio promedio por tipo de producto
				promedioIphone= CalcularPromedioPorTipoProducto(listaProductos, TAM, IPHONE);
				promedioMac= CalcularPromedioPorTipoProducto(listaProductos, TAM, MAC);
				promedioIpad= CalcularPromedioPorTipoProducto(listaProductos, TAM, IPAD);
				promedioAccesorios= CalcularPromedioPorTipoProducto(listaProductos, TAM, ACCESORIOS);
				ListarPromedioPorTipoProducto(promedioIphone, promedioMac, promedioIpad, promedioAccesorios);
				break;
			case 10: //De los Iphone el más barato
				ListarIphoneMasBarato(listaProductos, TAM);
				break;
			case 11: //Los productos "MADE IN CHINA"
				ListarProductosChina(listaProductos, TAM);
				break;
			case 12: //Las MAC que cuestan más de 700 USD
				ListarMac(listaProductos, TAM);
				break;
			case 13: //El/Los Accesorios más caros
				ListarAccesoriosMasCaros(listaProductos, TAM);
				break;
			default: //Salir
				printf("\nSaliendo del programa...");
				break;
		}
	}while(opcionSeleccionada != 15);

	return EXIT_SUCCESS;
}
}
