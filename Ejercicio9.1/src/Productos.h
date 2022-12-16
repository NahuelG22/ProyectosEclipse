/*
 * Productos.h
 *
 *  Created on: 27 sep. 2022
 *      Author: Nahuel A
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_

#include "Inputs.h"
//------------------
#define LIBRE 0
#define OCUPADO 1
//------------------
#define EEUU 1
#define CHINA 2
#define OTRO 3
//------------------
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4
//------------------

typedef struct {
	int idProducto;
	char descripcion[31];
	int nacionalidad;
	int tipoProducto;
	float precio;
	int isEmpty;
}eProducto;

void InicializarProductos(eProducto lista[], int size);
int RealizarCargaForzada(eProducto lista[], int size);
int BuscarEspacioLibre(eProducto lista[], int size);
int CargarProducto(eProducto lista[], int size, int id);
eProducto PedirDatosProducto(int id);
int ModificarUnProducto(eProducto lista[], int size, int posicion);
float CalcularPromedioPorTipoProducto(eProducto lista[], int size, int criterio);

#endif /* OPERACIONES_H_ */


#endif /* PRODUCTOS_H_ */
