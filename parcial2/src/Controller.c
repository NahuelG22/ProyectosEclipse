/*
 * Controller.c
 *
 *  Created on: 22 nov 2022
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"
#include "Parser.h"
#include "imput.h"
int controller_loadFromText(char* path , LinkedList* pArrayListalibros){
	  int ret = -1;
	    FILE* pFileAux = NULL;

	    if(path != NULL && pArrayListalibros != NULL)
	    {
	        pFileAux = fopen(path, "r");
	        if(pFileAux !=NULL)
	        {
	            if(!parser_LibrosFromText(pFileAux, pArrayListalibros))
	            {
	                printf("\tCARGA EXITOSA!\n");
	                ret = 0;
	            }
	        }
	    }
	    return ret;
}
int controller_ListLibros(LinkedList* pArrayListLibros)
{
    int ret = -1;
    eLibros* pLibros = NULL;
    char bufferId[1000];
    char bufferNombre[1000];
    char BufferAutor[1000];
    char bufferidGenero[100000];

    for(int i=0; i<ll_len(pArrayListLibros); i++)
    {printf("hola");
    	/*ll_get
			Retorna un puntero al elemento que se encuentra en el �ndice especificado.
     	 */
        pLibros = ll_get(pArrayListLibros, i);//guardar un puntero a libros
        if(pLibros != NULL)
        {
            Libros_getIdStr(pLibros, bufferId);
            Libros_getNombre(pLibros, bufferNombre);
            Libros_getAutorStr(pLibros, BufferAutor);
            Libros_getidGeneroStr(pLibros, bufferidGenero);
            {
                printf("%s  %s  %sHrs  $%s\n", bufferId,bufferNombre, BufferAutor, bufferidGenero);
                ret = 0;
            }
        }

    }
    return ret;
}
