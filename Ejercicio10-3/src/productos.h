/*
 * productos.h
 *
 *  Created on: 5 may. 2022
 *      Author: Nahuel A
 */

#ifndef PRODUCTOS_H_
#define PRODUCTOS_H_
#include <stdio.h>
#include <stdlib.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int idProducto;
	char descripcion[20];
	int nacionalidad;
	int tipo;
	float precio;
	int estado;
}eApple;
int opcion;

typedef struct
{
	int idTipo;
	char descripcionTipo[20];
}eTipoProducto;

int BuscarEspacioLibre(eApple listaProductos[], int sizeLista);
void MostrarUnProducto(eApple UnProducto);//POR VALOR
int CargarListaDeProductos(eApple listaProductos[], int sizeLista);//POR REFERENCIA
void MostrarListaDeProductos(eApple listaProductos[], int sizeLista);
void OrdenarListaDeAlumnosPorNombre(eApple listaProductos[], int sizeLista);
void ListarAlumnoPorPromedio(eApple listaProductos[], int sizeLista);
void ListarAlumnosAprobados(eApple listaProductos[], int sizeLista);
void InicializarListaProductos(eApple listaProductos[]);
int ModificarProducto(eApple listaProductos[], int sizeLista);
int EliminarProducto(eApple listaProductos[], int sizeLista);
eApple PedirUnProducto();
void MostrarProductosMasCaros(eApple listaProductos[], int sizeLista);
void CalcularPrecioPromedioxTipoProducto(eApple listaProductos[], int sizeLista);
void MostrarProductosCaros(eApple listaProductos[], int sizeLista);

#endif /* PRODUCTOS_H_ */
