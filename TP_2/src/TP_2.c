/*
 ============================================================================
 Name        : TP_2.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Jugador.h"
#include "Inputs.h"
#include "Confederaciones.h"
#define T 3000
#define P 6

int main(void)
{
	setbuf(stdout, NULL);
	eConfederacion confederaciones[P]={{100, "CONMEBOL", "SUDAMERICA", 1916},{101, "UEFA", "EUROPA", 1954},{102, "AFC", "ASIA", 1954},{103, "CAF", "AFRICA", 1957},{104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961},{105, "OFC", "OCEANIA", 1966}};
	eJugador jugadores[T];
	int id=1;
	int contador=0;
	int opcion;
	int retorno;

	inicializarListaJugadores(jugadores, T);
	inicializarListaConfederaciones(confederaciones, P);
	do
	{
		opcion=getNumberInt("1. Alta de jugador\n2. Baja de jugador\n3. Modificacion de jugador\n4. Informar\n5. Salir\n\nIngresar: ", "Opcion no valida, reingresar\n", 1, 5);
		switch(opcion)
		{
			case 1:
				if(AltaJugador(jugadores, T, id, confederaciones, P)==1)
				{
					printf("\nJugador ingresado correctamente\n\n");
					id++;
					contador++;
				}
				else
				{
					printf("\nNo se puede ingresar el jugador\n\n");
				}
			break;
			case 2:
				if(contador>0)
				{
					mostrarAltaJugador(jugadores, T, confederaciones, P);
					retorno=BajaJugador(jugadores, T);
					switch(retorno)
					{
						case 0:
							printf("\n\nNo se pudo encontrar el jugador.\n");
						break;
						case 1:
							printf("\nEl jugador se dio de baja con exito.\n");
							contador--;
						break;
					}
				}
				else
				{
					printf("\nNo se ingreso ningun jugador\n");
				}
			break;
			case 3:
				if(contador>0)
				{
					mostrarAltaJugador(jugadores, T, confederaciones, P);
					retorno=modificarJugador(jugadores, T, confederaciones, P);
				}
				else
				{
					printf("\nNo se ingreso ningun jugador\n");
				}
			break;
			case 4:
				if(contador>0)
				{
					retorno=getChar("\nIngrese que desea listar:\na. Jugadores ordenados alfabeticamente por confederacion\nb. Jugadores por confederacion\nc. Total y promedio de los salarios y los jugadores que cobran mas que el promedio\nd. Confederacion con mayor cantidad de años de contratos\ne. Porcentaje de jugadores por confederacion\nf. Region con mas jugadores\n\nListar: ");
					switch(retorno)
					{
						case 'a':
							ordenarAlfabeticamente(jugadores, T, confederaciones, P);
						break;
						case 'b':
							listarJugadoresXConfederacion(jugadores, T, confederaciones, P);
						break;
						case 'c':
							mostrarJugadoresQueSuperanElPromedio(jugadores, T, confederaciones, P);
						break;
						case 'd':
							obtenerDatosPorConfederacion(jugadores, T, 1);
						break;
						case 'e':
							obtenerDatosPorConfederacion(jugadores, T, 3);
						break;
						case 'f':
							obtenerDatosPorConfederacion(jugadores, T, 2);
							listarJugadoresXConfederacion(jugadores, T, confederaciones, P);
						break;
						default:
							printf("\nOpcion invalida.\n");
						break;
					}
				}
				else
				{
					printf("\nNo se ingreso ningun jugador\n");
				}
			break;
			case 5:
				retorno = getChar("\n¿Seguro que desea salir? s para si, n para no\n");
				if(retorno == 's')
				{
				   opcion=6;
				}
			break;
		}
	}while(opcion!=6);

	printf("\nPrograma finalizado.");

	return EXIT_SUCCESS;
}
