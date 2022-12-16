#include <stdio.h>
#include <stdlib.h>
#include "input.h"


int pedirEntero(char mensaje[])
{
    int entero;
	printf("%s",mensaje);
	scanf("%d", &entero);
    return entero;
}

void getString(char nombre[], char mensaje[])
{
	printf("%s", mensaje);
	scanf("%[^\n]s",nombre);
}
