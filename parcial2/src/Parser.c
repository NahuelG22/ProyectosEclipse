/*
 * Paser.c
 *
 *  Created on: 22 nov 2022
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"





int parser_LibrosFromText(FILE* pFile , LinkedList* pArrayListaLibros)
{
	int ret;
	char buffer[4][20];

	eLibros *pLibro;

	if(pFile!=NULL && pArrayListaLibros!=NULL)
	{
		fscanf(pFile,"[^\n]\n");
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
		    //printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]); Para ver lo que va cargando

			pLibro = Libros_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

			if(pLibro != NULL)
			{
				if(!ll_add(pArrayListaLibros,pLibro))
				{
					ret = 0;
				}
			}
		}
	}
	fclose(pFile);
	return ret;
}

