#include "Jugador.h"
#include <stdio.h>

Jugador* jug_new()
{
	Jugador* pJugador;
	pJugador=(Jugador*)malloc(sizeof(Jugador));

	return pJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* unJugador;
	unJugador=jug_new();
	int id;
	int idSeleccion;

	if(unJugador!=NULL && idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL
		&& nacionalidadStr != NULL && idSelccionStr != NULL)
	{
		id=atoi(idStr);
		idSeleccion=atoi(idSelccionStr);
		jug_setId(unJugador, id);
		jug_setNombreCompleto(unJugador, nombreCompletoStr);
		jug_setEdad(unJugador, edadStr);
		jug_setPosicion(unJugador, posicionStr);
		jug_setNacionalidad(unJugador, nacionalidadStr);
		jug_setIdSeleccion(unJugador, idSeleccion);
	}

	return unJugador;
}

void jug_delete(Jugador* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

int jug_setId(Jugador* this,int id)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && id>0)
	{
		this->id=id;
		estaOk=1;
	}

	return estaOk;
}

int jug_getId(Jugador* this,int* id)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		estaOk=1;
	}

	return estaOk;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && nombreCompleto>0)
	{
		strcpy(this->nombreCompleto, nombreCompleto);
		estaOk=1;
	}

	return estaOk;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && nombreCompleto!=NULL)
	{
		strcpy(nombreCompleto, this->nombreCompleto);
		estaOk=1;
	}

	return estaOk;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && posicion>0)
	{
		strcpy(this->posicion, posicion);
		estaOk=1;
	}

	return estaOk;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && posicion!=NULL)
	{
		strcpy(posicion, this->posicion);
		estaOk=1;
	}

	return estaOk;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && nacionalidad>0)
	{
		strcpy(this->nacionalidad, nacionalidad);
		estaOk=1;
	}

	return estaOk;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && nacionalidad!=NULL)
	{
		strcpy(nacionalidad, this->nacionalidad);
		estaOk=1;
	}

	return estaOk;
}

int jug_setEdad(Jugador* this,int edad)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && edad>0)
	{
		this->edad=edad;
		estaOk=1;
	}

	return estaOk;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && edad!=NULL)
	{
		*edad=this->id;
		estaOk=1;
	}

	return estaOk;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && idSeleccion>0)
	{
		this->idSeleccion=idSeleccion;
		estaOk=1;
	}

	return estaOk;
}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && idSeleccion!=NULL)
	{
		*idSeleccion=this->idSeleccion;
		estaOk=1;
	}

	return estaOk;
}

void jug_mostrar(Jugador* this)
{
	int id;
	char nombre[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
	int idSeleccion;

	jug_getId(this, &id);
	jug_getNombreCompleto(this, nombre);
	jug_getEdad(this, &edad);
	jug_getPosicion(this, posicion);
	jug_getNacionalidad(this, nacionalidad);
	printf("%-5s %-15s %-5s %-17s %-17s %-17s\n", "ID", "Nombre", "Edad", "Posicion", "Tipo de pasajero", "Estado de Vuelo");
	printf("%4d %10s %4d %10s %10s %10s %4d", id, nombre, edad, posicion, nacionalidad, idSeleccion);
}

int jug_mostrarLista(LinkedList* this)
{
	int retorno=0;
	int len;
	Jugador* unJugador;

	if(this!=NULL)
	{
		len=ll_len(this);
		if(len>0)
		{
			for(int i=0; i<len; i++)
			{
				unJugador=(Jugador*)ll_get(this, i);
				if(unJugador!=NULL)
				{
					jug_mostrar(unJugador);
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

int jug_alta(LinkedList* this)
{
	int estaOk;
	estaOk=0;
	int id;
	char nombre[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	Jugador* unJugador;

	if(this!=NULL)
	{
		GetString(nombre, 100, "\nIngrese el nombre completo del jugador: ");
		edad=getNumberInt("\nIngrese la edad del jugador: ", "Edad invalida", 16, 40);
		GetString(posicion, 30, "\nIngrese la posicion del jugador: ");
		GetString(nacionalidad, 30, "\nIngrese la nacionalidad: ");
	}

	return estaOk;
}

int jug_modificar(LinkedList* this)
{
	int idAModificar;
	int modificacion=-1;
	int opcion;
	int i;
	int index;
	Jugador* jugadorAux;
	char nombre[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
	int size;

	if(this != NULL)
	{
		jug_mostrarLista(this);
		idAModificar=getInt("\nIngrese el id del jugador a modificar: ");
		index=jug_obtenerId(this, idAModificar);
		if(index!=-1)
		{
			jugadorAux=(Jugador*)ll_get(this, index);
			jug_mostrar(jugadorAux);
			opcion=getInt("\n¿Que desea modificar?\n1-Nombre\n2-Edad\n3-Posicion\n4-Nacionalidad\nIngresar: ");
			switch(opcion)
			{
				case 1:
					GetString(nombre, size, "Ingrese el nuevo nombre: ");
					if(jug_setNombreCompleto(jugadorAux, nombre) == 1)
					{
						modificacion = 1;
						printf("\nEl nombre fue modificado exitosamente");
					}
					else
					{
						printf("\nHubo un problema al modificar");
					}
				break;
				case 2:
					edad=getNumberInt("Ingrese la edad: ", "Edad invalida", 16, 50);
					if(jug_setEdad(jugadorAux, edad) == 1)
					{
						modificacion = 1;
						printf("\nLa edad fue modificada exitosamente");
					}
					else
					{
						printf("\nHubo un problema al modificar");
					}
				break;
				case 3:
					posicion=getNumberInt("\n1.Portero\n2.Defensa Central\n3.Lateral Izquierdo\n4.Lateral derecho\n5.Pivote\n6.Mediocentro\n7.Mediocentro ofensivo\n8.Extremo izquierdo\n9.Extremo derecho\n10.Mediopunta\n11.Delantero centro\nPosicion: ", "Posicion invalida", 1, 11);
					switch(posicion)
					{
						case 1:
							strcpy(posicion,"Portero");
						break;
						case 2:
							strcpy(posicion,"Defensa central");
						break;
						case 3:
							strcpy(posicion,"Lateral izquierdo");
						break;
						case 4:
							strcpy(posicion,"Lateral derecho");
						break;
						case 5:
							strcpy(posicion,"Pivote");
						break;
						case 6:
							strcpy(posicion,"Mediocentro");
						break;
						case 7:
							strcpy(posicion,"Mediocentro ofensivo");
						break;
						case 8:
							strcpy(posicion,"Extremo izquierdo");
						break;
						case 9:
							strcpy(posicion,"Extremo derecho");
						break;
						case 10:
							strcpy(posicion,"Mediopunta");
						break;
						case 11:
							strcpy(posicion,"Delantero centro");
						break;
					}
					if(jug_setPosicion(jugadorAux, posicion) == 1)
					{
						modificacion = 1;
						printf("\nLa posicion fue modificada exitosamente");
					}
					else
					{
						printf("\nHubo un problema al modificar!");
					}
				break;
				case 4:
					GetString(nombre, size, "Ingrese la nueva nacionalidad: ");
					if(jug_setNacionalidad(jugadorAux, nombre) == 1)
					{
						modificacion = 1;
						printf("\nLa nacionalidad fue modificada exitosamente");
					}
					else
					{
						printf("\nHubo un problema al modificar");
					}
				break;
			}
		}
	}

	return modificacion;
}

int jug_obtenerId(LinkedList* this, int id)
{
	int len;
	int index;
	int idAux;
	Jugador* unJugador;
	index=-1;

	if(this!=NULL)
	{
		len = ll_len(this);
		if(len>0)
		{
			for(int i=0; i<len ;i++)
			{
				unJugador=(Jugador*)ll_get(this,i);
				if(jug_getId(unJugador, &idAux)==1)
				{
					if(idAux==id)
					{
						index=i;
						break;
					}
				}
			}
		}
	}

	return index;
}

int jug_compararNacionalidad(void* unJugador, void* otroJugador)
{
	int validacion = -1;
	Jugador* unJugadorAux = NULL;
	Jugador* otroJugadorAux = NULL;

	char nacionalidadUno[50];
	char nacionalidadDos[50];

	if(unJugador != NULL && otroJugador != NULL)
	{
		unJugadorAux = (Jugador*) unJugador;
		otroJugadorAux = (Jugador*) otroJugador;

		if((jug_getNacionalidad(unJugadorAux, nacionalidadUno)) && (jug_getNacionalidad(otroJugadorAux, nacionalidadDos)))
		{
			validacion = strcmp(nacionalidadUno, nacionalidadDos);
		}
	}

	return validacion;
}

int jug_compararNombre(void* unJugador, void* otroJugador)
{
	int validacion = -1;
	Jugador* unJugadorAux = NULL;
	Jugador* otroJugadorAux = NULL;
	char unNombre[50];
	char otroNombre[50];

	if(unJugador != NULL && otroJugador != NULL)
	{
		unJugadorAux = (Jugador*) unJugador;
		otroJugadorAux = (Jugador*) otroJugador;
		if((jug_getNombreCompleto(unJugadorAux, unNombre)) && (jug_getNombreCompleto(otroJugadorAux, otroNombre)))
		{
			validacion = strcmp(unNombre, otroNombre);
		}
	}

	return validacion;
}

int jug_compararEdad(void* unJugador, void* otroJugador)
{
	int retorno=0;
	Jugador* unJugadorAux = NULL;
	Jugador* otroJugadorAux = NULL;

	int edadUno;
	int edadDos;

	if(unJugador != NULL && otroJugador != NULL)
	{
		unJugadorAux = (Jugador*) unJugador;
		otroJugadorAux = (Jugador*) otroJugador;

		if((jug_getEdad(unJugadorAux, edadUno)) && (jug_getEdad(otroJugadorAux, edadDos)))
		{
			if(edadUno > edadDos)
			{
				retorno = 1;
			}
			else
			{
				if(edadUno < edadDos)
				{
					retorno = -1;
				}
			}
		}
	}

	return retorno;
}

int jug_compararId(void* unJugador, void* otroJugador)
{
	int retorno=0;
	Jugador* unJugadorAux = NULL;
	Jugador* otroJugadorAux = NULL;
	int IDuno;
	int IDdos;

	if(unJugador != NULL && otroJugador != NULL)
	{
		unJugadorAux = (Jugador*) unJugador;
		otroJugadorAux = (Jugador*) otroJugador;

		if((jug_getId(unJugadorAux, IDuno)) && (jug_getId(otroJugadorAux, IDdos)))
		{
			if(IDuno > IDdos)
			{
				retorno = 1;
			}
			else
			{
				if(IDuno < IDdos)
				{
					retorno = -1;
				}
			}
		}
	}

	return retorno;
}
