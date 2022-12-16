/*
 pedir el ingreso de los datos de una persona:
 nombre:
 edad:
 altura:
 temperatura:
 crear una funcion para pedir y retornar el valor numerico de las variables edad, altura y temperatura (que sea Int)
 mostrar la altura de la mas joven y mas alta.
 mostrar la edad de mayor temperatura.
 */

#include <stdio.h>
#include <stdlib.h>

int PedirEntero(char *);

int main(void)
{
	int edad;
	int altura;
	int temperatura;
	int banderaJovenAlta;
	int banderaMayorTemperatura;
	int masJoven;
	int masAlta;
	int mayorTemperatura;
	int edadMayorTemperatura;

	banderaJovenAlta=0;
	banderaMayorTemperatura=0;

	for(int i=0; i<3; i++)
	{
		edad=PedirEntero("\n Ingrese edad: ");
		altura=PedirEntero("\n Ingrese altura: ");
		temperatura=PedirEntero("\n Ingrese temperatura: ");

		if((edad<masJoven && altura>masAlta) || banderaJovenAlta==0)
		{
			masJoven=edad;
			masAlta=altura;
			banderaJovenAlta=1;
		}

		if(temperatura>mayorTemperatura || banderaMayorTemperatura==0)
		{
			mayorTemperatura=temperatura;
			edadMayorTemperatura=edad;
			banderaMayorTemperatura=1;
		}

	}

	printf("\n La altura de la mas joven y mas alta es: %d", masAlta);
	printf("\n La edad de la persona con mayor temperatura es: %d", edadMayorTemperatura);

	return 0;
}

int PedirEntero(char * mensaje)
{
	int dato;

	printf("%s", mensaje);
	scanf("%d", &dato);

	return dato;
}
