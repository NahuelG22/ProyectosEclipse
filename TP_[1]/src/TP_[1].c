/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "input.h"
#include "funciones.h"

int main()
{
    setbuf(stdout, NULL);
	int opcion;

	int acumuladorCostoHospedaje=0;
    int acumuladorCostoComida=0;
    int acumuladorCostoTransporte=0;
    int contadorArqueros=0;
    int contadorDefensores=0;
    int contadorMediocampistas=0;
    int contadorDelanteros=0;
    int contadorJugadores=0;
    int contadorAFC=0;
    int contadorUEFA=0;
    int contadorConmebol=0;
    int contadorCAF=0;
    int contadorOFC=0;
    int contadorConcacaf=0;

    opcion = preguntar(acumuladorCostoHospedaje, acumuladorCostoComida, acumuladorCostoTransporte, contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);

    mostrarOpciones(opcion, acumuladorCostoHospedaje, acumuladorCostoComida, acumuladorCostoTransporte, contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros, contadorJugadores, contadorOFC, contadorAFC, contadorUEFA, contadorConcacaf, contadorConmebol, contadorCAF);

}

