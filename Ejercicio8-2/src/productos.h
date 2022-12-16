#ifndef OPERACIONES_H_
#define OPERACIONES_H_
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
int BuscarEspacioLibre(eProducto lista[], int size);
int CargarProducto(eProducto lista[], int size, int id);
eProducto PedirDatosProducto(int id);
void ListarUnProducto(eProducto unProducto);
void ListarProductos(eProducto lista[], int size);
int ModificarUnProducto(eProducto lista[], int size, int posicion);
void listadoOrdenadoPorPrecio (eProducto lista[], int size);
void mostrarListaProductosPorPrecio(eProducto lista[], int size);
void listadoOrdenadoPorDescripcion(listaProductos, TAM);

#endif /* OPERACIONES_H_ */
