#include "Seleccion.h"
#include "Inputs.h"

Seleccion* selec_new()
{
	Seleccion* pSeleccion;
	pSeleccion=(Seleccion*)malloc(sizeof(Seleccion));

	return pSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* seleccionAuxiliar;
	int id;

	if(idStr!=NULL && paisStr!=NULL && confederacionStr!=NULL && convocadosStr!=NULL)
	{
		id=atoi(idStr);
		jug_setId(seleccionAuxiliar, id);
		jug_setNombreCompleto(seleccionAuxiliar, nombreCompletoStr);
		jug_setEdad(seleccionAuxiliar, edadStr);
		jug_setPosicion(seleccionAuxiliar, posicionStr);
		jug_setNacionalidad(seleccionAuxiliar, nacionalidadStr);
		jug_setIdSeleccion(seleccionAuxiliar, idSeleccion);
	}

	return seleccionAuxiliar;
}

void selec_delete(Seleccion* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

int selec_getId(Seleccion* this,int* id)
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

int selec_getPais(Seleccion* this,char* pais)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && pais!=NULL)
	{
		strcpy(pais, this->pais);
		estaOk=1;
	}

	return estaOk;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && confederacion!=NULL)
	{
		strcpy(confederacion, this->confederacion);
		estaOk=1;
	}

	return estaOk;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && convocados>0)
	{
		this->convocados=convocados;
		estaOk=1;
	}

	return estaOk;
}

int selec_getConvocados(Seleccion* this,int* convocados)
{
	int estaOk;
	estaOk=0;

	if(this!=NULL && convocados!=NULL)
	{
		*convocados=this->convocados;
		estaOk=1;
	}

	return estaOk;
}

int selec_compararConfederacion(void* jugador1,void* jugador2)
{
	int validacion = -1;
	Jugador* unaSeleccionAux = NULL;
	Jugador* otraSeleccionAux = NULL;

	char confederacionUno[50];
	char confederacionDos[50];

	if(unaSeleccionAux != NULL && otraSeleccionAux != NULL)
	{
		unaSeleccionAux = (Seleccion*) jugador1;
		otraSeleccionAux = (Jugador*) jugador2;

		if((!jug_getNombreCompleto(unaSeleccionAux, confederacionUno)) && (!jug_getNombreCompleto(confederacionDos, otraSeleccionAux)))
		{
			validacion = strcmp(confederacionUno, otraSeleccionAux);
		}
	}

	return validacion;
}
