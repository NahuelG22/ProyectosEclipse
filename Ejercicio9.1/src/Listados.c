/*
 * Listados.c
 *
 *  Created on: 27 sep. 2022
 *      Author: Nahuel A
 */

#include "Listados.h"

void ListarUnProducto(eProducto unProducto) {
	//------------------------
	printf("%4d | %-20s | %.2f |", unProducto.idProducto, unProducto.descripcion, unProducto.precio);
	//------------------------
	switch(unProducto.nacionalidad)
	{
		case 1:
			printf(" EEUU  |");
			break;
		case 2:
			printf(" CHINA |");
			break;
		default:
			printf(" OTRO  |");
			break;
	}
	//------------------------
	switch(unProducto.tipoProducto)
	{
		case 1:
			printf(" IPHONE\n");
			break;
		case 2:
			printf(" MAC\n");
			break;
		case 3:
			printf(" IPAD\n");
			break;
		default:
			printf(" ACCESORIOS\n");
			break;
	}
	//------------------------
}

void ListarProductos(eProducto lista[], int size) {
	printf("\n--------------------> LISTA PRODUCTOS <--------------------"
		   "\n___________________________________________________________\n\n");
	for(int i=0 ; i<size ; i++) {
		if(lista[i].isEmpty == OCUPADO) {
			ListarUnProducto(lista[i]);
		}
	}
	printf("___________________________________________________________\n\n");
}

void OrdenarListadoPorPrecio(eProducto lista[], int size) {
	eProducto aux;

	for(int i=0; i<size-1; i++) {
		for(int j=i+1; j<size ;j++) {
			if(lista[i].precio < lista[j].precio) {
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	}
	ListarProductos(lista, size);
}

void OrdenarListadoPorDescripcion(eProducto lista[], int size) {
	eProducto aux;

	for(int i=0 ; i<size-1 ; i++) {
		for(int j=i+1 ; j<size ; j++) {
			if(stricmp(lista[i].descripcion, lista[j].descripcion) > 0) {
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	}
	ListarProductos(lista, size);
}

void OrdenarListaProductosCaros(eProducto lista[], int size) {
    char flagMaximo= -1;
    int NumeroMax;

    for(int i=0 ; i<size ; i++) {
        if(flagMaximo == -1 || lista[i].precio > NumeroMax) {
            NumeroMax = lista[i].precio;
            ListarUnProducto(lista[i]);
            flagMaximo= 0;
        }
    }
}

void ListarProductosCuestenSetecientos(eProducto lista[], int size) {
	for(int i=0 ; i<size ; i++) {
		if(lista[i].precio == 700) {
			ListarUnProducto(lista[i]);
		}
	}
}

void ListarPromedioPorTipoProducto(float promedioIphone, float promedioMac, float promedioIpad, float promedioAccesorios) {
	printf("\n--------------------> LISTA PROMEDIOS <--------------------"
		   "\n___________________________________________________________\n\n");

	printf( "- Iphone: %.2f\n"
			"- Mac: %.2f\n"
			"- Ipad: %.2f\n"
			"- Accesorios: %.2f\n", promedioIphone, promedioMac, promedioIpad, promedioAccesorios);

	printf("___________________________________________________________\n\n");
}

void ListarIphoneMasBarato(eProducto lista[], int size) {
	eProducto aux;
	int flagPrimerIphone= 0;

	for(int i=0 ; i<size ; i++) {
		if(lista[i].tipoProducto == IPHONE) {
			if(flagPrimerIphone == 0 || aux.precio > lista[i].precio) {
				aux= lista[i];
				flagPrimerIphone= 1;
			}
		}
	}
	ListarUnProducto(aux);
}

void ListarProductosChina(eProducto lista[], int size) {

    for(int i=0 ; i<size ; i++) {
       if(lista[i].nacionalidad == CHINA) {
            ListarUnProducto(lista[i]);
        }
    }
}

void ListarMac(eProducto lista[], int size) {
	for(int i=0 ; i<size ; i++) {
	   if(lista[i].tipoProducto == MAC && lista[i].precio > 700) {
	      ListarUnProducto(lista[i]);
	   }
	}
}

void ListarAccesoriosMasCaros(eProducto lista[], int size) {
	int flagAccesorio = 0; //0 = descargado | 1 = cargado
	int accesorioMasCaro = 0;

	for(int i=0; i<size; i++) {
		if(lista[i].tipoProducto == ACCESORIOS) {
			if(lista[i].precio > accesorioMasCaro || flagAccesorio == 0) {
				accesorioMasCaro = lista[i].precio;
				ListarUnProducto(lista[i]);
				flagAccesorio = 1;
			}
		}
	}
	printf("\nEl accesorio mas caro vale: %d", accesorioMasCaro);
}


