/*
 Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la aplicación con distintos valores.
Ejemplo 1:  3 - 5 - 7 - 9 - 1
Ejemplo 2:  2 - 1 - 8 - 1 - 2

 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num;
	float prom;
	int i;
	int acumulador=0;
	for(i=0; i<5; i++)
	{
		printf("Ingrese un numero");
		scanf("%d", &num);
		acumulador+=num;
	}
	prom=num/i;
	printf("\nEl promedio es %f", prom);

	return 0;
}
