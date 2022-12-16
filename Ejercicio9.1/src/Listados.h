/*
 * Listados.h
 *
 *  Created on: 27 sep. 2022
 *      Author: Nahuel A
 */

#ifndef LISTADOS_H_
#define LISTADOS_H_

#include "Inputs.h"
#include "Productos.h"

void ListarUnProducto(eProducto unProducto);
void ListarProductos(eProducto lista[], int size);

void OrdenarListadoPorPrecio(eProducto lista[], int size); 																		//Case 5
void OrdenarListadoPorDescripcion(eProducto lista[], int size);																	//Case 6
void OrdenarListaProductosCaros(eProducto lista[], int size);																	//Case 7
void ListarProductosCuestenSetecientos(eProducto lista[], int size);															//Case 8
void ListarPromedioPorTipoProducto(float promedioIphone, float promedioMac, float promedioIpad, float promedioAccesorios);		//Case 9
void ListarIphoneMasBarato(eProducto lista[], int size);																		//Case 10
void ListarProductosChina(eProducto lista[], int size);																			//Case 11
void ListarMac(eProducto lista[], int size);																					//Case 12
void ListarAccesoriosMasCaros(eProducto lista[], int size);

#endif /* LISTADOS_H_ */
