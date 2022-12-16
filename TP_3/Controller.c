#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "Inputs.h"
#include "parser.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno=0;
	FILE* pArchivo=NULL;

	if(path!=NULL && pArrayListJugador!=NULL)
	{
		pArchivo=fopen(path,"r");
		if(pArchivo!=NULL)
		{
			parser_JugadorFromText(pArchivo,pArrayListJugador);
			printf("\nEl jugador fue cargado con exito\n");
			retorno=1;
		}
		else
		{
			printf("\nNo se pudo cargar al jugador\n");
		}
		fclose(pArchivo);
	}

	return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno;
	FILE* pArchivo;

	if(path!=NULL && pArrayListJugador!=NULL)
	{
		pArchivo=fopen(path, "rb");
		retorno=parser_JugadorFromBinary(pArchivo, pArrayListJugador);
		fclose(pArchivo);
	}

    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = 0;

	Jugador* jugadorAux;

	int idAux = 0;
	char nombreAux[100];
	int edadAux;
	char posicionAux[30];
	char nacionalidadAux[30];
	int idSeleccionAux;
	int size;

	if(pArrayListJugador != NULL)
	{
		size = ll_len(pArrayListJugador);
		GetString(nombreAux, size, "Ingrese el nombre completo del jugador: ");
		edadAux=getNumberInt("Ingrese la edad: ", "Edad invalida", 16, 50);
		posicionAux=getNumberInt("\n1.Portero\n2.Defensa Central\n3.Lateral Izquierdo\n4.Lateral derecho\n5.Pivote\n6.Mediocentro\n7.Mediocentro ofensivo\n8.Extremo izquierdo\n9.Extremo derecho\n10.Mediopunta\n11.Delantero centro\nPosicion: ", "Posicion invalida", 1, 11);
		switch(posicionAux)
		{
			case 1:
				strcpy(posicionAux,"Portero");
			break;
			case 2:
				strcpy(posicionAux,"Defensa central");
			break;
			case 3:
				strcpy(posicionAux,"Lateral izquierdo");
			break;
			case 4:
				strcpy(posicionAux,"Lateral derecho");
			break;
			case 5:
				strcpy(posicionAux,"Pivote");
			break;
			case 6:
				strcpy(posicionAux,"Mediocentro");
			break;
			case 7:
				strcpy(posicionAux,"Mediocentro ofensivo");
			break;
			case 8:
				strcpy(posicionAux,"Extremo izquierdo");
			break;
			case 9:
				strcpy(posicionAux,"Extremo derecho");
			break;
			case 10:
				strcpy(posicionAux,"Mediopunta");
			break;
			case 11:
				strcpy(posicionAux,"Delantero centro");
			break;
		}
		GetString(nacionalidadAux, size, "Ingrese la nacionalidad del jugador: ");
		jugadorAux = jug_newParametros(idStr, nombreAux, edadAux, posicionAux, nacionalidadAux, "0");
		if(jugadorAux != NULL)
		{
			ll_add(pArrayListJugador, jugadorAux);
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	int validacion = -1;

	if(pArrayListJugador != NULL)
	{
		if(jug_modificar(pArrayListJugador))
		{
			printf("Se realizó la modificación con éxito.\n");
			validacion = 0;
		}
		else
		{
			printf("No se realizó la modificación.\n");
		}
	}

	return validacion;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int validacion = -1;
	int id;
	int index = -1;
	int confirmacion;
	Jugador* jugadorAuxiliar = NULL;

	if(pArrayListJugador != NULL)
	{
		ll_sort(pArrayListJugador, jug_compararId, 1);
		jug_mostrarLista(pArrayListJugador);
		id = getNumberInt("Ingrese el ID del jugador a dar de baja: \n", 1, 1000);
		index = jug_obtenerId(pArrayListJugador, id);
		if(index != -1)
		{
			jugadorAuxiliar = ll_get(pArrayListJugador, index);
			jug_mostrar(jugadorAuxiliar);
			confirmacion = getInt("Ingrese 1 para confirmar la eliminacion", 1);
			if(confirmacion == 1)
			{
				ll_remove(pArrayListJugador, index);
				jug_delete(jugadorAuxiliar);
				printf("El jugador fue dado de baja.\n");
				validacion = 0;
			}
			else
			{
				printf("Error al eliminar al jugador.\n");
			}
		}
		else
		{
			printf("No se encontro el ID.\n");
		}
	}

	return validacion;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno=-1;

	if(pArrayListJugador!=NULL)
	{
		jug_mostrarLista(pArrayListJugador);
		retorno=0;
	}

    return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno=0;
	int ordenamiento;
	int opcion;
	LinkedList* clon=NULL;

	if(pArrayListJugador!=NULL)
	{
		clon = ll_clone(pArrayListJugador);
		if(clon != NULL)
		{
			do
			{
				opcion = getNumberInt("\n1. Jugadores por nacionalidad\n2. Selecciones por confederacion\n3. Jugadores por edad\n4. Jugadores por nombre\nIngresar: ", "Opcion invalida", 1, 4);
				if(opcion != 4)
				{
					ordenamiento = getNumberInt("\n1. Orden Descendente\n2. Orden Ascendente\nIngresar: ", "Opcion invalida", 1, 2);
				}
				switch(opcion)
				{
					case 1:
						ll_sort(clon, jug_compararNacionalidad, ordenamiento);
						controller_ListPassenger(clon);
						retorno = 1;
					break;

					case 2:
						ll_sort(clon, selec_compararConfederacion, ordenamiento);
						controller_ListPassenger(clon);
						retorno = 1;
					break;

					case 3:
						ll_sort(clon, jug_compararEdad, ordenamiento);
						controller_ListPassenger(clon);
						retorno = 1;
					break;

					case 4:
						ll_sort(clon, jug_compararNombre, ordenamiento);
						controller_ListPassenger(clon);
						retorno = 1;
					break;
				}
			}while(opcion!=4);
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pFile;

	Jugador* jugadorAux;

	int id;
	char nombre[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	int size;

	if(pArrayListJugador != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			size = ll_len(pArrayListJugador);
			fprintf(pFile, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
			for(int i=0; i<size; i++)
			{
				jugadorAux = (Jugador*) ll_get(pArrayListJugador, i);
				if(jugadorAux != NULL)
				{
					if(jug_getId(jugadorAux, &id) && jug_getNombreCompleto(jugadorAux, nombre) && jug_getEdad(jugadorAux, &edad) && jug_getPosicion(jugadorAux, posicion) && jug_getNacionalidad(jugadorAux, nacionalidad) && jug_getSIdSeleccion(jugadorAux, idSeleccion))
					{
						fprintf(pFile,"%s,%s,%s,%s,%s,%s\n",id,nombre,edad,posicion,nacionalidad,idSeleccion);
						retorno = 1;
					}
				}
			}
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int size;
	FILE* pArchivo;
	Jugador* jugador = NULL;
	if(path != NULL && pArrayListJugador != NULL)
	{
		pArchivo = fopen(path, "wb");
		size = ll_len(pArrayListJugador);
		if(pArchivo != NULL && size > 0)
		{
			for(int i = 0; i<size;i++)
			{
				jugador = (Jugador*) ll_get(pArrayListJugador,i);
				if(jugador != NULL)
				{
					fwrite(jugador,sizeof(Jugador),1,pArchivo);
					retorno = 1;
				}
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;

	if(pArrayListSeleccion != NULL)
	{
		FILE* pArchivo;
		pArchivo = fopen(path,"r");
		if(pArchivo != NULL)
		{
			if(parser_SeleccionFromText(pArchivo,pArrayListSeleccion) == 1)
			{
				retorno = 1;
			}
		}
		fclose(pArchivo);
	}

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}


