/*
 * Libros.c
 *
 *  Created on: 22 nov 2022
 *      Author: alumno
 */

#ifndef LIBROS_C_
#define LIBROS_C_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Libros.h"
#include "imput.h"
#include "LinkedList.h"

/** \brief Reserva espacio en memoria para un empleado
 * \param void vacio
 * \return Libros* un puntero al espacio reservado para cargar un empleado
 */
eLibros* Libros_new(void)
{
    return (eLibros*) malloc(sizeof(eLibros));
}

eLibros* Libros_newParametros(char* idStr,char* nombreStr,char* AutorStr, char* idGeneroStr)
{
    eLibros* pLibros = Libros_new();
    eLibros* retorno = NULL;

    if(pLibros != NULL && idStr != NULL && nombreStr != NULL && AutorStr != NULL && idGeneroStr != NULL)
    {
                 Libros_setIdStr(pLibros, idStr);
                Libros_setNombre(pLibros, nombreStr);
                Libros_setAutorStr(pLibros, AutorStr);
                Libros_setidGeneroStr(pLibros, idGeneroStr);

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
        return free(this);
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


int Libros_getId(eLibros* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}


int Libros_setNombre(eLibros* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->titulo,nombre);
        retorno = 0;
    }
    return retorno;
}

int Libros_getNombre(eLibros* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strcpy(resultado,this->titulo);
        retorno = 0;
    }
    return retorno;
}

int Libros_setAutor(eLibros* this,char Autor)
{
    int retorno = -1;
    if(this != NULL && Autor >= 0)
    {
    	strcpy(this->Autor,Autor);
        retorno = 0;
    }
    return retorno;
}


int Libros_getAutor(eLibros* this,char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
    	 strcpy(resultado,this->Autor);
        retorno = 0;
    }
    return retorno;
}

int Libros_setidGenero(eLibros* this,int idGenero)
{
    int retorno = -1;
    if(this != NULL && idGenero >= 0)
    {
        this->idGenero = idGenero;
        retorno = 0;
    }
    return retorno;
}

int Libros_getidGenero(eLibros* this,int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->idGenero;
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

int Libros_setAutorStr(eLibros* this,char* Autor)
{
    int retorno = -1;
    if(this != NULL && Autor != NULL )
    {
        retorno = Libros_setAutor(this,atoi(Autor));
    }
    return retorno;
}

int Libros_getAutorStr(eLibros* this,char* resultado)
{
    int retorno = -1;
    char bufferInt[100];
    if(this != NULL && resultado != NULL)
    {
        Libros_getAutor(this, &bufferInt);
        sprintf(resultado, "%s", bufferInt); // Crea una cadena de texto segun el formato dado
        retorno = 0;
    }
    return retorno;
}

int Libros_setidGeneroStr(eLibros* this,char* idGenero)
{
    int retorno = -1;
    if(this != NULL && idGenero != NULL)
    {
        retorno = Libros_setidGenero(this,atoi(idGenero));

    }
    return retorno;
}

int Libros_getidGeneroStr(eLibros* this,char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        Libros_getidGenero(this, &bufferInt);
        sprintf(resultado, "%d", bufferInt);
        retorno = 0;
    }
    return retorno;
}


#endif /* LIBROS_C_ */
