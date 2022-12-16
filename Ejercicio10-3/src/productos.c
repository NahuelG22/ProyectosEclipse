/*
 * productos.c
 *
 *  Created on: 5 may. 2022
 *      Author: Nahuel A
 */

#include <string.h>
#include "productos.h"

eApple PedirUnProducto()
{
	eApple UnProducto;
	char respuesta;

	printf("Ingrese el id del producto: ");
	scanf("%d", &UnProducto.idProducto);
	switch()
	{
		case 1000:
			printf("¿Usted desea ingresar Iphone?");
			fflush(stdin);
			scanf("%c", &respuesta);
			break;
	}
	printf("Ingrese la descripcion: ");
	fflush(stdin);
	gets(UnProducto.descripcion);//scanf("%[^\n]", miAlumno.nombre); ... fgets
	printf("Ingrese el tipo: ");
	scanf("%f", &UnProducto.tipo);

	return UnProducto;
}

int EliminarProducto(eApple listaProductos[], int sizeLista)
{
	int id;
	int elimino;
	elimino=-1;//No existe el id
	printf("Ingrese el id a eliminar: ");
	scanf("%d", &id);

	for(int i=0; i<sizeLista; i++)
	{
		if(listaProductos[i].estado==OCUPADO && listaProductos[i].idProducto==id)
		{
			listaProductos[i].estado=LIBRE;
			elimino=1;
			break;
		}
	}

	return elimino;
}

int ModificarAlumno(eApple listaProductos[], int sizeLista)
{
	int id;
	int modifico;
	int i;
	i=0;
	modifico=-1;//No existe el id
	MostrarListaDeAlumnos(listaProductos[i].idProducto);
	printf("Ingrese el legajo a modificar: ");
	scanf("%d", &id);

	for(int i=0; i<sizeLista; i++)
	{
		if(listaProductos[i].estado==OCUPADO && listaProductos[i].idProducto==id)
		{
			printf("Ingrese el nuevo promedio");
			scanf("%f", &listaProductos[i].promedio);
			modifico=1;
			break;
		}
	}

	return modifico;
}

int BuscarEspacioLibre(eApple listaProductos[], int sizeLista)
{
	int index;

	index=-1;

	for(int i=0; i<sizeLista; i++)
	{
		if(listaProductos[i].estado==LIBRE)
		{
			index=i;
			break;
		}
	}

	return index;
}

int CargarListaDeProductos(eApple listaProductos[], int sizeLista)
{
	int index;

	index=BuscarEspacioLibre(listaProductos, sizeLista);

	if(index!=-1)
	{
		listaProductos[index]=PedirUnProducto();
	}

	return index;
}

void MostrarUnProducto(eApple UnProducto)
{

	printf("%4d %10s %4d\n", UnProducto.idProducto, UnProducto.descripcion, UnProducto.tipo);
}

void MostrarListaDeProductos(eApple listaProductos[], int sizeLista)
{
	for(int i=0; i<sizeLista; i++)
	{
		if(listaProductos[i].estado==OCUPADO)
		{
			MostrarUnProducto(listaProductos[i]);
		}
	}

}

void MostrarProductosMasCaros(eApple listaProductos[], int sizeLista)
{
	for(int i=0; i<sizeLista-1; i++)
	{
		for(int j=i+1; j<sizeLista; j++)
		{
			if(listaProductos[i]>listaProductos[j])
			{
				MostrarUnProducto(listaProductos[i]);
			}
		}
	}
}

void CalcularPrecioPromedioxTipoProducto(eApple listaProductos[], int sizeLista)
{

}

void ListarProductoPorPrecio(eApple listaProductos[], int sizeLista)
{
	eApple auxiliarProducto;
	for(int i=0; i<sizeLista-1; i++)
	{
		for(int j=i+1; j<sizeLista; j++)
		{
			if(listaProductos[i].precio<listaProductos[j].precio)
			{
				auxiliarProducto = listaProductos[i];
				listaProductos[i] = listaProductos[j];
				listaProductos[j] = auxiliarProducto;
			}
			else
			{
				if(listaProductos[i].precio==listaProductos[j].precio)
				{
					if(strcmp(listaProductos[i].descripcion, listaProductos[j].descripcion)>0)
					{
						auxiliarProducto = listaProductos[i];
						listaProductos[i] = listaProductos[j];
						listaProductos[j] = auxiliarProducto;
					}
				}
			}
		}
	}
}

void MostrarProductosCaros(eApple listaProductos[], int sizeLista)
{
	for(int i=0; i<sizeLista; i++)
	{
		if(listaProductos[i]>700)
		{
			MostrarUnProducto(listaProductos[i]);
		}
	}
}

