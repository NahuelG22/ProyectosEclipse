/*
 * Libros.c
 *
 *  Created on: 23 nov 2022
 *      Author: alumno
 */

#include "Libros.h"

eLibros* Libros_new(void)
{
    return (eLibros*) malloc(sizeof(eLibros));
}

eLibros* Libros_newParametros(char* idStr,char* tituloStr,char* ImporteStr, char* idTipoStr)
{
    eLibros* pLibros = Libros_new();
    eLibros* retorno = NULL;

    if(pLibros != NULL && idStr != NULL && tituloStr != NULL && ImporteStr != NULL && idTipoStr != NULL)
    {
                 Libros_setIdStr(pLibros, idStr);
                Libros_setNombre(pLibros, tituloStr);
                Libros_setAutorStr(pLibros, ImporteStr);
                Libros_setidGeneroStr(pLibros, idTipoStr);

            retorno = pLibros;
        }
        else
        {
            Libros_delete(pLibros);
        }

    return retorno;
}

void Libros_delete(eLibros* this)
{
    if(this != NULL)
    {
        free(this);
        this=NULL;
    }
}


int Libros_setId(eLibros* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}


int Libros_getId(eLibros* this,int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}


int Libros_setTitulo(eLibros* this,char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(this->titulo,titulo);
        retorno = 0;
    }
    return retorno;
}

int Libros_getTitulo(eLibros* this,char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo,this->titulo);
        retorno = 0;
    }
    return retorno;
}

int Libros_setImporte(eLibros* this,char importe)
{
    int retorno = -1;
    if(this != NULL && importe >= 0)
    {
    	this->importe = importe;
        retorno = 0;
    }
    return retorno;
}


int Libros_getImporte(eLibros* this,char* importe)
{
    int retorno = -1;
    if(this != NULL && importe != NULL)
    {
    	*importe = this->importe;
        retorno = 0;
    }
    return retorno;
}

int Libros_setidTipo(eLibros* this,int idTipo)
{
    int retorno = -1;
    if(this != NULL && idTipo >= 0)
    {
        this->idTipo = idTipo;
        retorno = 0;
    }
    return retorno;
}

int Libros_getidTipo(eLibros* this,int* idTipo)
{
    int retorno = -1;
    if(this != NULL && idTipo != NULL)
    {
        *idTipo = this->idTipo;
        retorno = 0;
    }
    return retorno;
}

int Libros_setIdStr(eLibros* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL )
    {
        retorno = Libros_setId(this,atoi(id));
    }
    return retorno;
}

int Libros_getIdStr(eLibros* this, char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        Libros_getId(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}

int Libros_setImporteStr(eLibros* this,char* importe)
{
    int retorno = -1;
    if(this != NULL && importe != NULL )
    {
        retorno = Libros_setAutor(this,atoi(importe));
    }
    return retorno;
}

int Libros_getImporteStr(eLibros* this,char* importe)
{
    int retorno = -1;
    char bufferInt[100];
    if(this != NULL && importe != NULL)
    {
        Libros_getImporte(this, &bufferInt);
        sprintf(importe, "%s", bufferInt); // Crea una cadena de texto segun el formato dado
        retorno = 0;
    }
    return retorno;
}

int Libros_setidTipoStr(eLibros* this,char* idTipo)
{
    int retorno = -1;
    if(this != NULL && idTipo != NULL)
    {
        retorno = Libros_setidTipo(this,atoi(idTipo));

    }
    return retorno;
}

int Libros_getidTipoStr(eLibros* this,char* idTipo)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && idTipo != NULL)
    {
        Libros_getidTipo(this, &bufferInt);
        sprintf(idTipo, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}


int Libros_sortByImport(eLibros* this,char importe)
{
	int retorno = -1;
	int primerImporte;
	int segundoImporte;
	eLibros* pUno = NULL;
	eLibros* pDos = NULL;

	if(pUno != NULL && pDos != NULL)
	{
		pUno = (eLibros*)pUno;
		pDos =  (eLibros*)pDos;

		if(pUno != NULL && pDos != NULL)
		{
			Libros_getImporte(pUno, &primerImporte);
			Libros_getImporte(pDos, &segundoImporte);
			if(primerImporte > segundoImporte)
			{
				retorno = 1;
			}
			else
			{
				if(primerImporte == segundoImporte)
				{
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}
