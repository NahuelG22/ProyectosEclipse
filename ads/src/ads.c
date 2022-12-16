/*
 ============================================================================
 Name        : ads.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	 char nombre[]= "Miguel";

	char apellido []= {'P','e','r','e','z','\0'};

	strcpy(nombre,apellido);

	printf("%s",nombre);

	return EXIT_SUCCESS;
}
