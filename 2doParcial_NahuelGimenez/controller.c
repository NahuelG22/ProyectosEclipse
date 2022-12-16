/*
 * controller.c
 *
 *  Created on: 23 nov 2022
 *      Author: alumno
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"
#include "Parser.h"
#include "input.h"

int controller_loadFromText(char* path , LinkedList* pArrayListalibros)
{
	int retorno = -1;
	FILE* pFileAux = NULL;

	if(path != NULL && pArrayListalibros != NULL)
	{
		pFileAux = fopen(path, "r");
		if(pFileAux !=NULL)
		{
			if(!parser_LibroFromText(pFileAux, pArrayListalibros))
			{
				printf("\tLibro cargado exitosamente\n");
				retorno = 0;
			}
		}
	}
	return retorno;
}

int controller_ListLibros(LinkedList* pArrayListLibros)
{
    int retorno = -1;
    eLibros* pLibros = NULL;
    char bufferId[1000];
    char bufferTitulo[1000];
    char bufferImporte[1000];
    char bufferidTipo[1000];

    for(int i=0; i<ll_len(pArrayListLibros); i++)
    {
        pLibros = ll_get(pArrayListLibros, i);
        if(pLibros != NULL)
        {
            Libros_getIdStr(pLibros, bufferId);
            Libros_getTitulo(pLibros, bufferTitulo);
            Libros_getImporte(pLibros, bufferImporte);
            Libros_getidTipoStr(pLibros, bufferidTipo);
            {
                printf("%s  %s  %s  %s\n", bufferId,bufferTitulo, bufferImporte, bufferidTipo);
                retorno = 0;
            }
        }

    }
    return retorno;
}

int controller_sort(LinkedList* pArrayListLibros)
{
	int retorno = -1;
	int flag = 0;

	if(pArrayListLibros != NULL)
	{
		ll_sort(pArrayListLibros,Libros_sortByImport,0);
		flag = 1;
	}
	if(flag == 1)
	{
		printf("\nSe ordeno correctamente\n");
	}
	else
	{
		printf("\nERROR\n");
	}
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListLibros)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListLibros != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTexto(pFile, pArrayListLibros);
			printf("\nGuardado con exito\n");
		}
		else
		{
			printf("\nERROR\n");
		}
		fclose(pFile);
		retorno = 0;
	}

	return retorno;
}
