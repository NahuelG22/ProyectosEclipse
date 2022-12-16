/*
 ============================================================================
 Name        : EjercicioDojo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int PedirEntero(char *, char *, int, int);

int main()
{
	setbuf(stdout, NULL);
    int edad;
    int altura;
    int temperatura;
    int banderaMasJovenYAlta;
    int banderaMayorTemperatura;
    int masJoven;
    int masAlta;
    int mayorTemperatura;
    int edadMayorTemperatura;
    //int minimo;
    //int maximo;

    banderaMasJovenYAlta = 0;
    banderaMayorTemperatura = 0;
    //minimo=-100;
    //maximo=100;

    for(int i = 0; i < 3; i++)
    {
        edad = PedirEntero("\n Ingrese edad: ", "Edad invalida", 1, 120);
        altura = PedirEntero("\n Ingrese altura: ", "Altura invalida",100, 220);
        temperatura = PedirEntero("\n Ingrese temperatura: ", "Temperatura invalida", 35, 42);

        if((edad < masJoven && altura > masAlta) || banderaMasJovenYAlta == 0)
        {
            masJoven = edad;
            masAlta = altura;
            banderaMasJovenYAlta = 1;
        }

        if(temperatura > mayorTemperatura || banderaMayorTemperatura == 0)
        {
            mayorTemperatura = temperatura;
            edadMayorTemperatura = edad;
            banderaMayorTemperatura = 1;
        }

        /*
        if(banderaMasJovenYAlta == 0)
        {
            masJoven = edad;
            masAlta = altura;
            banderaMasJovenYAlta = 1;
        }
        else
        {
            if(edad < masJoven && altura > masAlta)
            {
                masJoven = edad;
                masAlta = altura;
            }
        }
        */
    }

    printf("\n La altura de la más joven y más alta es: %d", masAlta);
    printf("\n La edad de la persona con mayor temperatura es: %d", edadMayorTemperatura);

    return 0;
}

int PedirEntero(char * mensaje, char* mensajeError, int minimo, int maximo)
{
    int dato;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &dato);

    while(dato<minimo || dato>maximo)
    {
    	printf("%s", mensajeError);
    	prinft("%s", mensaje);
    	fflush(stdin);
    	scanf("%d", &dato);
    }
    return dato;
}
