/*
 ============================================================================
 Name        : Cadenas.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout, NULL);

	char cadena[15]; //="programacion";

	printf("Ingrese una cadena: ");
	fflush(stdin);
	//scanf("%s", cadena);
	gets(cadena);
	//scanf("%[^\n]");Excluye el contrabarra n
	//fgets(cadena, 15, stdin);
	printf("La cadena es: %s", cadena);

	int len;

	len=strlen(cadena);

	printf("El largo es: %d", len);

	return EXIT_SUCCESS;
}
