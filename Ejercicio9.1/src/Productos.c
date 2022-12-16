/*
 * Productos.c
 *
 *  Created on: 27 sep. 2022
 *      Author: Nahuel A
 */

#include "Productos.h"

void InicializarProductos(eProducto lista[], int size) {
	for(int i=0 ; i<size ; i++) {
		lista[i].isEmpty= LIBRE;
	}
}

int RealizarCargaForzada(eProducto lista[], int size) {
	int retorno= -1;
	eProducto aux[10]= {{95, "Celular", EEUU, IPHONE, 99000, OCUPADO},
						{96, "Computadora", CHINA, MAC, 70082, OCUPADO},
						{97, "Auriculares", OTRO, ACCESORIOS, 35040, OCUPADO},
						{98, "Compra", EEUU, IPAD, 67010, OCUPADO},
						{99, "Parlante", EEUU, ACCESORIOS, 10850, OCUPADO}};

	for(int i=0 ; i<size ; i++) {
		if(lista[i].isEmpty == LIBRE) {
			lista[i]= aux[i];
			retorno= 0;
		}
	}

	return retorno;
}

int BuscarEspacioLibre(eProducto lista[], int size) {
	int retorno= -1;

	for(int i=0 ; i<size ; i++) {
		if(lista[i].isEmpty == LIBRE) {
			retorno= i;
			break;
		}
	}

	return retorno;
}

int CargarProducto(eProducto lista[], int size, int id) {
	int auxiliar;

	auxiliar= BuscarEspacioLibre(lista, size);
	if(auxiliar != -1) {
		lista[auxiliar]= PedirDatosProducto(id);
		lista[auxiliar].isEmpty= OCUPADO;
	}

	return auxiliar;
}

eProducto PedirDatosProducto(int id) {
	eProducto unProducto;

	unProducto.idProducto= id;
	getString("\nIngrese la descripcion del producto: ", unProducto.descripcion);
	unProducto.nacionalidad= getNumberInt("\n1. EEUU\n2. CHINA\n3. OTRO\nIngrese la nacionalidad: ", "Error!!! La nacionalidad ingresada es incorrecta...", 1, 3);
	unProducto.tipoProducto= getNumberInt("\n1. IPHONE\n2. MAC\n3. IPAD\n4. ACCESORIOS\nIngrese el tipo de producto: ", "Error!!! El tipo de producto ingresado es incorrecta...", 1, 4);
	unProducto.precio= getNumberFloat("\nIngrese el precio del producto: ", "Error!!! El precio ingresado es incorrecto...", 1, 100000);

	return unProducto;
}


int ModificarUnProducto(eProducto lista[], int size, int posicion) {
	int retorno= -1;
	int opcion;

	do{
		printf("\nMenu Modificar\n"
			   "1. Descripcion\n"
			   "2. Nacionalidad\n"
			   "3. Tipo producto\n"
			   "4. Precio\n"
			   "5. Salir\n");
		opcion= getNumberInt("Ingrese una opcion: ", "\nError!!! La opcion ingresada es incorrecta", 1, 5);

		switch(opcion) {
			case 1:
				getString("\nIngrese la descripcion del producto: ", lista[posicion].descripcion);
				retorno= 0;
				break;
			case 2:
				lista[posicion].nacionalidad= getNumberInt("\n1. EEUU\n2. CHINA\n3. OTRO\nIngrese la nacionalidad: ", "Error!!! La nacionalidad ingresada es incorrecta...", 1, 3);
				retorno= 0;
				break;
			case 3:
				lista[posicion].tipoProducto= getNumberInt("\n1. IPHONE\n2. MAC\n3. IPAD\n4. ACCESORIOS\nIngrese el tipo de producto: ", "Error!!! El tipo de producto ingresado es incorrecta...", 1, 4);
				retorno= 0;
				break;
			case 4:
				lista[posicion].precio= getNumberFloat("\nIngrese el precio del producto: ", "Error!!! El precio ingresado es incorrecto...", 1, 100000);
				retorno= 0;
				break;
			default:
				printf("\nSaliendo del SubMenu Modificar...");
				break;
		}
	}while(opcion != 5);

	return retorno;
}

float CalcularPromedioPorTipoProducto(eProducto lista[], int size, int criterio) {  //Acumular los precios de un tipo de producto y dividirlo por la cantidad de productos de ese tipo
	float acumuladorPrecios= 0;
	int contadorProductos= 0;
	float promedio;

	for(int i=0 ; i<size ; i++) {
		if(lista[i].tipoProducto == criterio) {
			acumuladorPrecios= acumuladorPrecios + lista[i].precio;
			contadorProductos++;
		}
	}
	promedio= acumuladorPrecios/contadorProductos;

	return promedio;
}

