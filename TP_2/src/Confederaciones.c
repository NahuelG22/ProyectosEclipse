/*
 * Confederaciones.c
 *
 *  Created on: 29 oct. 2022
 *      Author: Nahuel A
 */
#include "Jugador.h"
#include "Confederaciones.h"

void inicializarListaConfederaciones(eConfederacion confederaciones[], int size)
{
	for(int i=0; i<size; i++)
	{
		confederaciones[i].isEmpty=LIBRE;
	}
}

int buscarConfederacionLibre(eConfederacion confederaciones[], int size)
{
	int index;

	index=-1;

	for(int i=0; i<size; i++)
	{
		if(confederaciones[i].isEmpty==LIBRE)
		{
			index=i;
			break;
		}
	}

	return index;
}

int AltaConfederacion(int id, eConfederacion confederaciones[], int size)
{
	int index;
	int retorno;

	retorno=0;

	index=buscarConfederacionLibre(confederaciones, size);

	if(index!=-1)
	{
		confederaciones[index].id=id;
		GetString(confederaciones[index].nombre, 50, "\nIngrese el nombre de la confederacion: ");
		strupr(confederaciones[index].nombre);
		GetString(confederaciones[index].region, 50, "\nIngrese la region de la confederacion: ");
		strupr(confederaciones[index].region);
		confederaciones[index].anioCreacion=getNumberInt("\nIngrese el año de creacion de la confederacion: ", "Opcion invalida", 1930, 2022);
		confederaciones[index].isEmpty=CARGADO;
		retorno=1;
	}
	else
	{
		printf("\nNo hay espacio libre para mas confederaciones.");
	}

	return retorno;
}

int BajaConfederacion(eConfederacion confederaciones[], int size)
{
	int confederacionABorrar;
	int retorno;
	int indice;

	confederacionABorrar = getInt("\nIngrese el id del jugador a borrar: ");
	indice = BuscarConfederacion(confederaciones , size, confederacionABorrar);

	retorno = 0;

	if(indice > -1)
	{
		confederaciones[indice].isEmpty=BAJA;
		retorno = 1;
	}

    return retorno;
}

int BuscarConfederacion(eConfederacion confederaciones[],int size,int variableAModificar)
{
	int indice;

	indice = -1;

	for(int i=0; i<size; i++)
    {
	   if(confederaciones[i].isEmpty==CARGADO && confederaciones[i].id==variableAModificar)
	   {
		   indice = i;
		   break;
	   }
    }

	return indice;
}

int modificarConfederacion(eConfederacion confederaciones[], int sizeConfederaciones)
{
	int idAModificar;
	int modificacion;
	int opcion;

	modificacion=-1;

	idAModificar=getInt("\nIngrese el id del jugador a modificar: ");

	for(int i=0; i<sizeConfederaciones; i++)
	{
		if(confederaciones[i].isEmpty==CARGADO && confederaciones[i].id==idAModificar)
		{
			opcion=getInt("\n¿Que desea modificar?\n1-Nombre\n2-Region\n3-Año de creacion\n\nIngresar: ");
			switch(opcion)
			{
				case 1:
					modificacion=ModificarNombreConfederacion(confederaciones, sizeConfederaciones, idAModificar);
					switch(modificacion)
                    {
                        case -1:
                        	printf("\nLa confederacion no existe, no se puede modificar.\n");
                    	break;
                        case 0:
                        	printf("\nOperacion cancelada.\n");
                    	break;
                        case 1:
                        	printf("\nEl nombre se modifico con exito.\n");
                    	break;
                    }
				break;
				case 2:
					modificacion=ModificarRegion(confederaciones, sizeConfederaciones, idAModificar);
					switch(modificacion)
					{
						case -1:
							printf("\nLa confederacion no existe, no se puede modificar.\n");
						break;
						case 0:
							printf("\nOperacion cancelada.\n");
						break;
						case 1:
							printf("\nLa region se modifico con exito.\n");
						break;
					}
				break;
				case 3:
					modificacion=ModificarAnioCreacion(confederaciones, sizeConfederaciones, idAModificar);
					switch(modificacion)
                    {
                        case -1:
                        	printf("\nLa confederacion no existe, no se puede modificar.\n");
                    	break;
                        case 0:
                        	printf("\nOperacion cancelada.\n");
                    	break;
                        case 1:
                        	printf("\nEl año se modifico con exito.\n");
                    	break;
                    }
				break;
				default:
					printf("\nOpcion invalida\n");
				break;
			}
		}
	}

	return modificacion;
}

int ModificarNombreConfederacion(eConfederacion confederaciones[], int size, int id)
{
	int nombreAModificar;
	char nombreModificado[50];
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;


	nombreAModificar=id;
	indiceAModificar = BuscarConfederacion(confederaciones, size, nombreAModificar);

	if(indiceAModificar > -1)
	{
	   GetString(nombreModificado,50,"Ingrese el nombre: ");
	   retorno = 0;
	   confirmacion = getChar("\nConfederacion encontrada ¿Desea modificar el nombre? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   strcpy(confederaciones[indiceAModificar].nombre, nombreModificado);
		   retorno = 1;
	   }
	}

	return retorno;
}

int ModificarRegion(eConfederacion confederaciones[], int size, int id)
{
	int nombreAModificar;
	char nombreModificado[50];
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;


	nombreAModificar=id;
	indiceAModificar = BuscarConfederacion(confederaciones, size, nombreAModificar);

	if(indiceAModificar > -1)
	{
	   GetString(nombreModificado,50,"Ingrese la region: ");
	   retorno = 0;
	   confirmacion = getChar("\nConfederacion encontrada ¿Desea modificar la region? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   strcpy(confederaciones[indiceAModificar].region, nombreModificado);
		   retorno = 1;
	   }
	}

	return retorno;
}

int ModificarAnioCreacion(eConfederacion confederaciones[], int size, int id)
{
    int numeroAModificar;
	int numeroModificado;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;

	numeroAModificar=id;
	indiceAModificar = BuscarConfederacion(confederaciones, size, numeroAModificar);

	if(indiceAModificar > -1)
	{
	   numeroModificado=getNumberInt("\nIngrese el anño de creacion de la confederacion: \n", "\nNumero invalido\n", 1930, 2022);
	   retorno = 0;
	   confirmacion = getChar("\nConfederacion encontrada ¿Desea modificar el año? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   confederaciones[indiceAModificar].anioCreacion=numeroModificado;
		   retorno = 1;
	   }
	}

	return retorno;
}


