#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Inputs.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno=0;
	char id[100];
	char nombreCompleto[100];
	char edad[100];
	char posicion[100];
	char nacionalidad[100];
	char idSeleccion[100];
	Jugador* unJugador;

	if(pFile!=NULL && pArrayListJugador!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			unJugador=jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			if(unJugador!=NULL)
			{
				ll_add(pArrayListJugador, unJugador);
				retorno=1;
			}
		}
	}

    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno=0;
	Jugador* unJugador;

	if(pFile!= NULL && pArrayListJugador!= NULL)
	{
		while(!feof(pFile))
		{
			unJugador=jug__new();
			if(unJugador!= NULL && fread(unJugador,sizeof(Jugador),1,pFile) == 1)
			{
				ll_add(pArrayListJugador, unJugador);
				retorno=1;
			}
		}
	}

	return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	char id[100];
	char pais[100];
	char confederacion[100];
	char convocados[100];
	int retorno=0;
	Seleccion seleccion;

	if(pFile!=NULL && pArrayListSeleccion!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, pais, confederacion, convocados);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, pais, confederacion, convocados);
			seleccion=selec_newParametros(id, pais, confederacion, convocados);
			if(seleccion!=NULL)
			{
				ll_add(pArrayListSeleccion, seleccion);
				retorno=1;
			}
		}
	}

    return retorno;
}

