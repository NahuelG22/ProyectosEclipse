/*
 * Parser.c
 *
 *  Created on: 23 nov 2022
 *      Author: alumno
 */
#include "Parser.h"
#include "input.h"

int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
	int retorno=0;
	char id[100];
	char titulo[100];
	char importe[100];
	char idTipo[100];
	eLibros* unLibro;

	if(pFile!=NULL && pArrayListLibro!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, titulo, importe, idTipo);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, titulo, importe, idTipo);
			unLibro=jug_newParametros(id, titulo, importe, idTipo);
			if(unLibro!=NULL)
			{
				ll_add(pArrayListLibro, unLibro);
				retorno=1;
			}
		}
	}

	return retorno;
}
