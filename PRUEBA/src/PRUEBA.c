/*
 ============================================================================
 Name        : PRUEBA.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXIMA_LONGITUD_CADENA 20

int ordenarAlfabeticamente (char string[], int len);

int main()
{
    char string[MAXIMA_LONGITUD_CADENA];
    int retorno;

    strcpy(string,"Dia soleado");

    retorno=ordenarAlfabeticamente(string, MAXIMA_LONGITUD_CADENA);
    if(retorno==0)
    {
    	printf("\nNo se pudo ordenar");
    }
    else
    {
    	printf("\nSe ordeno con exito");
    }

}

int ordenarAlfabeticamente(char string[], int len)
{
	int rtn;
    char aux[MAXIMA_LONGITUD_CADENA];
    int n;

    n=strlen(string);
    rtn=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<i; j++)
        {
            if(strcmp(string[i] , string[j])>0)
            {
                strcpy(aux, string[i]);
                strcpy(string[i], string[j]);
                strcpy(string[j], aux);
                rtn=1;
            }
        }
    }
    return rtn;
}
