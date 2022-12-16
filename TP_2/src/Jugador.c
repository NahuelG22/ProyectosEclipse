/*
 * Jugador.c
 *
 *  Created on: 14 oct. 2022
 *      Author: Nahuel A
 */

#include "Jugador.h"

void inicializarListaJugadores(eJugador jugadores[], int size)
{
	for(int i=0; i<size; i++)
	{
		jugadores[i].isEmpty=LIBRE;
	}
}

int buscarEspacioLibre(eJugador jugadores[], int size)
{
	int index;

	index=-1;

	for(int i=0; i<size; i++)
	{
		if(jugadores[i].isEmpty==LIBRE)
		{
			index=i;
			break;
		}
	}

	return index;
}

int VerificarLleno(eJugador jugadores[], int size)
{
	int retorno;
	retorno = 0;

	for(int i=0; i<size; i++)
    {
	   if(jugadores[i].isEmpty == CARGADO)
	   {
		   retorno = 1;
		   break;
	   }
    }

	return retorno;
}

int AltaJugador(eJugador jugadores[], int size, int id, eConfederacion confederaciones[], int sizeConfederaciones)
{
	int index;
	int retorno;
	int posicion;
	int validar;

	retorno=0;

	index=buscarEspacioLibre(jugadores, size);

	if(index!=-1)
	{
		jugadores[index].id=id;
		GetString(jugadores[index].nombre, 50, "\nIngrese el nombre del jugador: ");
		validar=getName(jugadores[index].nombre);
		while(validar==1)
		{
			GetString(jugadores[index].nombre, 50, "\nIngrese el nombre del jugador: ");
			validar=getName(jugadores[index].nombre);
		}
		strlwr(jugadores[index].nombre);
		posicion=getNumberInt("\n1.Arquero\n2.Defensor\n3.Mediocampista\n4.Delantero\nPosicion: ", "Posicion invalida", 1, 4);
		switch(posicion)
		{
			case 1:
				strcpy(jugadores[index].posicion, "Arquero");
			break;
			case 2:
				strcpy(jugadores[index].posicion,"Defensor");
			break;
			case 3:
				strcpy(jugadores[index].posicion,"Mediocampista");
			break;
			case 4:
				strcpy(jugadores[index].posicion,"Delantero");
			break;
		}
		jugadores[index].numeroCamiseta=getNumberShort("\nIngrese el numero del jugador: ", "Numero invalido", 1, 99);
		MostrarConfederaciones(confederaciones, sizeConfederaciones);
		jugadores[index].idConfederacion=getNumberInt("\nIngrese el ID de la confederacion: ", "ID invalido", 100, 105);
		jugadores[index].salario=getNumberFloat("\nIngrese el salario semanal del jugador: ", "Sueldo invalido", 1000, 250000);
		jugadores[index].aniosContrato=getNumberShort("\nIngrese los años de contrato del jugador: ", "Numero no valido", 1, 5);
		jugadores[index].isEmpty=CARGADO;
		retorno=1;
	}
	else
	{
		printf("\nNo hay espacio libre para mas jugadores.");
	}

	return retorno;
}

void MostrarConfederaciones(eConfederacion confederaciones[], int size)
{
	DatosMenuConfederacion();
	int i;
	for(i=0; i<size; i++)
	{
		printf("|%-15d|%-20s|%-22s|%-15d|\n", confederaciones[i].id, confederaciones[i].nombre, confederaciones[i].region, confederaciones[i].anioCreacion);
	}

	printf("+---------------+--------------------+----------------------+---------------+\n");
}

void mostrarAltaJugador(eJugador jugadores[], int size, eConfederacion confederaciones[], int sizeConfederaciones)
{
	DatosMenuJugador();
	int i;
	for(i=0; i<size; i++)
	{
		for(int j=0; j<sizeConfederaciones; j++)
		{
			if(jugadores[i].isEmpty==CARGADO && jugadores[i].idConfederacion==confederaciones[j].id)
			{
				printf("|%-15d|%-50s|%-20s|%-12d|%-20.2f|%-15s|%-17d|\n", jugadores[i].id, jugadores[i].nombre, jugadores[i].posicion, jugadores[i].numeroCamiseta,
						jugadores[i].salario, confederaciones[j].nombre, jugadores[i].aniosContrato);
			}
		}
	}
	printf("+---------------+--------------------------------------------------+--------------------+------------+--------------------+---------------+-----------------+\n");
}

int BajaJugador(eJugador jugadores[], int size)
{
	int jugadorABorrar;
	int retorno;
	int indice;

	jugadorABorrar = getInt("\nIngrese el id del jugador a borrar: ");
	indice = BuscarJugador(jugadores , size, jugadorABorrar);

	retorno = 0;

	if(indice > -1)
	{
		jugadores[indice].isEmpty=BAJA;
		retorno = 1;
	}

    return retorno;
}

int BuscarJugador(eJugador jugadores[],int size,int variableAModificar)
{
	int indice;
	int i;
	indice = -1;

	for(i=0; i<size; i++)
    {
	   if(jugadores[i].isEmpty==CARGADO && jugadores[i].id==variableAModificar)
	   {
		   indice = i;
		   break;
	   }
    }

	return indice;
}

int modificarJugador(eJugador jugadores[], int size, eConfederacion confederaciones[], int sizeConfederaciones)
{
	int idAModificar;
	int modificacion;
	int opcion;
	int i;

	modificacion=-1;

	idAModificar=getInt("\nIngrese el id del jugador a modificar: ");

	for(i=0; i<size; i++)
	{
		if(jugadores[i].isEmpty==CARGADO && jugadores[i].id==idAModificar)
		{
			opcion=getInt("\n¿Que desea modificar?\n1-Nombre\n2-Posicion\n3-Numero de camiseta\n4-Confederacion\n5-Salario\n6-Años de contrato\n\nIngresar: ");
			switch(opcion)
			{
				case 1:
					modificacion=ModificarNombre(jugadores, size, idAModificar);
					switch(modificacion)
                    {
                        case -1:
                        	printf("\nEl jugador no existe, no se puede modificar.\n");
                    	break;
                        case 0:
                        	printf("\nOperacion cancelada.\n");
                    	break;
                        case 1:
                        	printf("\nEl nombre se modifico con exito.\n");
                    	break;
                    }
				break;
				case 2:
					modificacion=ModificarPosicion(jugadores, size, idAModificar);
					switch(modificacion)
					{
						case -1:
							printf("\nEl jugador no existe, no se puede modificar.\n");
						break;
						case 0:
							printf("\nOperacion cancelada.\n");
						break;
						case 1:
							printf("\nLa posicion se modifico con exito.\n");
						break;
					}
				break;
				case 3:
					modificacion=ModificarNumero(jugadores, size, idAModificar);
					switch(modificacion)
                    {
                        case -1:
                        	printf("\nEl jugador no existe, no se puede modificar.\n");
                    	break;
                        case 0:
                        	printf("\nOperacion cancelada.\n");
                    	break;
                        case 1:
                        	printf("\nEl numero se modifico con exito.\n");
                    	break;
                    }
				break;
				case 4:
				    modificacion=ModificarConfederacion(jugadores, size, idAModificar, confederaciones, sizeConfederaciones);
				    switch(modificacion)
                    {
                        case -1:
                        	printf("\nEl jugador no existe, no se puede modificar.\n");
                    	break;
                        case 0:
                        	printf("\nOperacion cancelada.\n");
                    	break;
                        case 1:
                        	printf("\nLa confederacion se modifico con exito.\n");
                    	break;
                    }
				break;
				case 5:
				    modificacion=ModificarSalario(jugadores, size, idAModificar);
				    switch(modificacion)
                    {
                        case -1:
                        	printf("\nEl jugador no existe, no se puede modificar.\n");
                    	break;
                        case 0:
                        	printf("\nOperacion cancelada.\n");
                    	break;
                        case 1:
                        	printf("\nEl salario se modifico con exito.\n");
                    	break;
                    }
				break;
				case 6:
					modificacion=ModificarAniosContrato(jugadores, size, idAModificar);
					switch(modificacion)
					{
						case -1:
							printf("\nEl jugador no existe, no se puede modificar.\n");
						break;
						case 0:
							printf("\nOperacion cancelada.\n");
						break;
						case 1:
							printf("\nLos años del contrato se modificaron con exito.\n");
						break;
					}
				break;
				default:
					printf("\nOpcion invalida\n");
				break;
			}
		}
	}

	return modificacion;
}


int ModificarNombre(eJugador jugadores[], int size, int id)
{
	int nombreAModificar;
	char nombreModificado[50];
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;


	nombreAModificar=id;
	indiceAModificar = BuscarJugador(jugadores, size, nombreAModificar);

	if(indiceAModificar > -1)
	{
	   GetString(nombreModificado,50,"Ingrese el nombre: ");
	   retorno = 0;
	   confirmacion = getChar("\nJugador encontrado ¿Desea modificar el nombre? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   strcpy(jugadores[indiceAModificar].nombre, nombreModificado);
		   retorno = 1;
	   }
	}

	return retorno;
}

int ModificarPosicion(eJugador jugadores[], int size, int id)
{
	int posicionAModificar;
	int posicionModificada;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;


	posicionAModificar=id;
	indiceAModificar = BuscarJugador(jugadores, size, posicionAModificar);

	if(indiceAModificar > -1)
	{
	   posicionModificada=getNumberInt("\n1.Arquero\n2.Defensor\n3.Mediocampista\n4.Delantero\nPosicion: ", "Posicion invalida", 1, 4);
	   retorno = 0;
	   confirmacion = getChar("\nJugador encontrado ¿Desea modificar la posicion? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   switch(posicionModificada)
		   {
				case 1:
					strcpy(jugadores[indiceAModificar].posicion, "Arquero");
				break;
				case 2:
					strcpy(jugadores[indiceAModificar].posicion,"Defensor");
				break;
				case 3:
					strcpy(jugadores[indiceAModificar].posicion,"Mediocampista");
				break;
				case 4:
					strcpy(jugadores[indiceAModificar].posicion,"Delantero");
				break;
			}
		   retorno = 1;
	   }
	}

	return retorno;
}

int ModificarSalario(eJugador jugadores[], int size, int id)
{
    int salarioAModificar;
	float salarioModificado;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;

	salarioAModificar=id;
	indiceAModificar = BuscarJugador(jugadores, size, salarioAModificar);

	if(indiceAModificar > -1)
	{
	   salarioModificado=getNumberFloat("\nIngrese el nuevo salario semanal: ", "\nSalario invalido", 1000, 250000);
	   retorno = 0;
	   confirmacion = getChar("\nJugador encontrado ¿Desea modificar el salario? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   jugadores[indiceAModificar].salario=salarioModificado;
		   retorno = 1;
	   }
	}

	return retorno;
}

int ModificarNumero(eJugador jugadores[], int size, int id)
{
    int numeroAModificar;
	int numeroModificado;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;

	numeroAModificar=id;
	indiceAModificar = BuscarJugador(jugadores, size, numeroAModificar);

	if(indiceAModificar > -1)
	{
	   numeroModificado=getNumberInt("\nIngrese el numero de la camiseta: \n", "\nNumero invalido\n", 1, 99);
	   retorno = 0;
	   confirmacion = getChar("\nJugador encontrado ¿Desea modificar el numero? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   jugadores[indiceAModificar].numeroCamiseta=numeroModificado;
		   retorno = 1;
	   }
	}

	return retorno;
}

int ModificarConfederacion(eJugador jugadores[], int size, int id, eConfederacion confederaciones[], int sizeConfederaciones)
{
    int confederacionAModificar;
	int confederacionModificada;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;

	confederacionAModificar=id;
	indiceAModificar = BuscarJugador(jugadores, size, confederacionAModificar);

	if(indiceAModificar > -1)
	{
	   MostrarConfederaciones(confederaciones, sizeConfederaciones);
       confederacionModificada=getNumberInt("\nSeleccione el ID de la confederacion: \n", "\nID invalido\n", 100, 105);
	   retorno = 0;
	   confirmacion = getChar("\nJugador encontrado ¿Desea modificar la confederacion? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   jugadores[indiceAModificar].idConfederacion=confederacionModificada;
		   retorno = 1;
	   }
	}

	return retorno;
}

int ModificarAniosContrato(eJugador jugadores[], int size, int id)
{
    int numeroAModificar;
	int numeroModificado;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;

	numeroAModificar=id;
	indiceAModificar = BuscarJugador(jugadores, size, numeroAModificar);

	if(indiceAModificar > -1)
	{
	   numeroModificado=getNumberInt("\nIngrese los años de contrato: \n", "\nNumero invalido\n", 1, 5);
	   retorno = 0;
	   confirmacion = getChar("\nJugador encontrado ¿Desea modificar los años de contrato? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   jugadores[indiceAModificar].aniosContrato=numeroModificado;
		   retorno = 1;
	   }
	}

	return retorno;
}

float calcularPromedioSalarios(eJugador jugadores[], int size)
{
	float acumulador=0;
	int contador=0;
	float promedio;

	for(int i=0; i<size; i++)
	{
		if(jugadores[i].isEmpty==CARGADO)
		{
			acumulador+=jugadores[i].salario;
			contador++;
		}
	}
	promedio=(float)acumulador/contador;

	printf("\nTotal de salarios: %f\nPromedio de salarios: %f\n", acumulador, promedio);

	return promedio;
}

void mostrarJugadoresQueSuperanElPromedio(eJugador jugadores[], int size, eConfederacion confederaciones[], int sizeConfederaciones)
{
	int promedio;

	promedio=calcularPromedioSalarios(jugadores, size);

	printf("\nJugador/es que superan el promedio de salarios: \n");
	DatosMenuJugador();

	for(int i=0; i<size; i++)
	{
		if(jugadores[i].salario>promedio && jugadores[i].isEmpty==CARGADO)
		{
			printf("|%-15d|%-50s|%-20s|%-12d|%-20.2f|%-15d|%-17d|\n", jugadores[i].id, jugadores[i].nombre,
					jugadores[i].posicion, jugadores[i].numeroCamiseta, jugadores[i].salario, jugadores[i].idConfederacion, jugadores[i].aniosContrato);
		}
	}

	printf("+---------------+--------------------------------------------------+--------------------+------------+--------------------+---------------+-----------------+\n");
}

int buscarIdConfederacion(eConfederacion* estructura,int id,int tam)
{
	int indice;
	if(estructura != NULL)
	{
		for(int i=0; i<tam;i++)
		{
			if(estructura[i].id == id)
			{
				indice = i;
				break;
			}
		}
	}
	else
	{
		indice = 0;
	}
	return indice;
}

void ordenarAlfabeticamente(eJugador jugadores[], int size, eConfederacion confederaciones[], int sizeConfederaciones)
{
	eJugador aux;
	int indiceConfederacion;
	if(jugadores != NULL && confederaciones != NULL)
	{
		for( int i=0; i<size-1; i++)
		{
			for(int j=i+1; j<size; j++ )
			{
				indiceConfederacion = buscarIdConfederacion(confederaciones,jugadores[i].idConfederacion,6);
				if(strcmp(confederaciones[indiceConfederacion].nombre, confederaciones[indiceConfederacion].nombre) > 0)
				{
					aux = jugadores[i];
					jugadores[i] = jugadores[j];
					jugadores[j] = aux;
				}
				else
				{
					if( strcmp(confederaciones[indiceConfederacion].nombre, confederaciones[indiceConfederacion].nombre) == 0 )
					{
						if( strcmp(jugadores[i].nombre, jugadores[i].nombre) > 0)
						{
							aux = jugadores[i];
							jugadores[i] = jugadores[j];
							jugadores[j] = aux;
						}
					}
				}
			}
		}
	}
	mostrarAltaJugador(jugadores, size, confederaciones, sizeConfederaciones);
}

void obtenerDatosPorConfederacion(eJugador jugadores[], int size, int criterio)
{
	int acumuladorConmebol=0;
	int acumuladorUEFA=0;
	int acumuladorConcacaf=0;
	int acumuladorAFC=0;
	int acumuladorCAF=0;
	int acumuladorOFC=0;
	int contadorAFC=0;
	int contadorUEFA=0;
	int contadorConmebol=0;
	int contadorCAF=0;
	int contadorOFC=0;
	int contadorConcacaf=0;

	for(int i=0; i<size; i++)
	{
		if(jugadores[i].isEmpty==CARGADO)
		{
			switch(jugadores[i].idConfederacion)
			{
				case 100:
					acumuladorConmebol+=jugadores[i].aniosContrato;
					contadorConmebol=contadorConmebol+1;
				break;
				case 101:
					acumuladorUEFA+=jugadores[i].aniosContrato;
					contadorUEFA = contadorUEFA+1;
				break;
				case 102:
					acumuladorAFC+=jugadores[i].aniosContrato;
					contadorAFC = contadorAFC+1;
				break;
				case 103:
					acumuladorCAF+=jugadores[i].aniosContrato;
					contadorCAF = contadorCAF+1;
				break;
				case 104:
					acumuladorConcacaf+=jugadores[i].aniosContrato;
					contadorConcacaf = contadorConcacaf+1;
				break;
				case 105:
					acumuladorOFC+=jugadores[i].aniosContrato;
					contadorOFC = contadorOFC+1;
				break;
			}
		}
	}

	if(criterio==1)
	{
		informarConfederacionConMayorCantidadAniosContrato(acumuladorConmebol, acumuladorConcacaf, acumuladorUEFA, acumuladorCAF, acumuladorAFC, acumuladorOFC);
	}
	else
	{
		if(criterio==2)
		{
			informarRegionConMasJugadores(contadorConmebol, contadorConcacaf, contadorUEFA, contadorCAF, contadorAFC, contadorOFC);
		}
		else
		{
			if(criterio==3)
			{
				calcularPorcentaje(contadorConmebol, contadorConcacaf, contadorUEFA, contadorCAF, contadorAFC, contadorOFC);
			}
			else
			{
				printf("\n");
			}
		}
	}

}

void informarRegionConMasJugadores(int contadorConmebol, int contadorConcacaf, int contadorUEFA, int contadorCAF, int contadorAFC, int contadorOFC)
{
	if(contadorConmebol>contadorUEFA && contadorConmebol>contadorAFC && contadorConmebol>contadorOFC && contadorConmebol>contadorConcacaf && contadorConmebol>contadorCAF)
	{
		printf("\nLa region con mas jugadores es conmebol");
	}
	else
	{
		if(contadorUEFA>contadorConmebol && contadorUEFA>contadorAFC && contadorUEFA>contadorOFC && contadorUEFA>contadorConcacaf && contadorUEFA>contadorCAF)
		{
			printf("\nLa region con mas jugadores es UEFA");
		}
		else
		{
			if(contadorAFC>contadorUEFA && contadorAFC>contadorConmebol && contadorAFC>contadorOFC && contadorAFC>contadorConcacaf && contadorAFC>contadorCAF)
			{
				printf("\nLa region con mas jugadores es AFC");
			}
			else
			{
				if(contadorOFC>contadorUEFA && contadorOFC>contadorAFC && contadorOFC>contadorConmebol && contadorOFC>contadorConcacaf && contadorOFC>contadorCAF)
				{
					printf("\nLa region con mas jugadores es OFC");
				}
				else
				{
					if(contadorConcacaf>contadorUEFA && contadorConcacaf>contadorAFC && contadorConcacaf>contadorOFC && contadorConcacaf>contadorConmebol && contadorConcacaf>contadorCAF)
					{
						printf("\nLa region con mas jugadores es Concacaf");
					}
					else
					{
						if(contadorCAF>contadorUEFA && contadorCAF>contadorAFC && contadorCAF>contadorOFC && contadorCAF>contadorConcacaf && contadorCAF>contadorConmebol)
						{
							printf("\nLa region con mas jugadores es CAF");
						}
					}
				}
			}
		}
	}
}

void informarConfederacionConMayorCantidadAniosContrato(int acumuladorConmebol, int acumuladorConcacaf, int acumuladorUEFA, int acumuladorCAF, int acumuladorAFC, int acumuladorOFC)
{
	if(acumuladorConmebol>acumuladorUEFA && acumuladorConmebol>acumuladorAFC && acumuladorConmebol>acumuladorOFC && acumuladorConmebol>acumuladorConcacaf && acumuladorConmebol>acumuladorCAF)
	{
		printf("\nLa confederacion con mayor cantidad de años de contrato es Conmebol");
	}
	else
	{
		if(acumuladorAFC>acumuladorUEFA && acumuladorAFC>acumuladorConmebol && acumuladorAFC>acumuladorOFC && acumuladorAFC>acumuladorConcacaf && acumuladorAFC>acumuladorCAF)
		{
			printf("\nLa confederacion con mayor cantidad de años de contrato es AFC");
		}
		else
		{
			if(acumuladorOFC>acumuladorUEFA && acumuladorOFC>acumuladorAFC && acumuladorOFC>acumuladorConmebol && acumuladorOFC>acumuladorConcacaf && acumuladorOFC>acumuladorCAF)
			{
				printf("\nLa confederacion con mayor cantidad de años de contrato es OFC");
			}
			else
			{
				if(acumuladorConcacaf>acumuladorUEFA && acumuladorConcacaf>acumuladorAFC && acumuladorConcacaf>acumuladorOFC && acumuladorConcacaf>acumuladorConmebol && acumuladorConmebol>acumuladorCAF)
				{
					printf("\nLa confederacion con mayor cantidad de años de contrato es Concacaf");
				}
				else
				{
					if(acumuladorCAF>acumuladorUEFA && acumuladorCAF>acumuladorAFC && acumuladorCAF>acumuladorOFC && acumuladorCAF>acumuladorConcacaf && acumuladorCAF>acumuladorConmebol)
					{
						printf("\nLa confederacion con mayor cantidad de años de contrato es CAF");
					}
					else
					{
						if(acumuladorUEFA>acumuladorConmebol && acumuladorUEFA>acumuladorAFC && acumuladorUEFA>acumuladorOFC && acumuladorUEFA>acumuladorConcacaf && acumuladorUEFA>acumuladorCAF)
						{
							printf("\nLa confederacion con mayor cantidad de años de contrato es UEFA");
						}
					}
				}
			}
		}
	}
}

void listarJugadoresXConfederacion(eJugador jugadores[], int size, eConfederacion confederaciones[], int sizeConfederaciones)
{
	int confederacion;

	MostrarConfederaciones(confederaciones, sizeConfederaciones);
	confederacion=getNumberInt("\nIngrese el ID de la confederacion: ", "ID invalido", 100, 105);
	DatosMenuJugador();
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<sizeConfederaciones; j++)
		{
			if(confederacion==jugadores[i].idConfederacion && jugadores[i].idConfederacion==confederaciones[j].id)
			{
				printf("|%-15d|%-50s|%-20s|%-12d|%-20.2f|%-15s|%-17d|\n", jugadores[i].id, jugadores[i].nombre,
				jugadores[i].posicion, jugadores[i].numeroCamiseta, jugadores[i].salario, confederaciones[j].nombre, jugadores[i].aniosContrato);
			}
		}
	}
	printf("+---------------+--------------------------------------------------+--------------------+------------+--------------------+---------------+-----------------+\n");
}

void calcularPorcentaje(int contadorConmebol, int contadorConcacaf, int contadorUEFA, int contadorCAF, int contadorAFC, int contadorOFC)
{
	float porcentajeConmebol;
	float porcentajeUEFA;
	float porcentajeConcacaf;
	float porcentajeCAF;
	float porcentajeAFC;
	float porcentajeOFC;

	porcentajeConmebol=(float)contadorConmebol*100/contadorConmebol;
	porcentajeUEFA=(float)contadorUEFA*100/contadorUEFA;
	porcentajeConcacaf=(float)contadorConcacaf*100/contadorConcacaf;
	porcentajeCAF=(float)contadorCAF*100/contadorCAF;
	porcentajeAFC=(float)contadorAFC*100/contadorAFC;
	porcentajeOFC=(float)contadorOFC*100/contadorOFC;

	mostrarPorcentaje(porcentajeConmebol, porcentajeUEFA, porcentajeConcacaf, porcentajeCAF, porcentajeAFC, porcentajeOFC);
}

void mostrarPorcentaje(float porcentajeConmebol, float porcentajeUEFA, float porcentajeConcacaf, float porcentajeCAF, float porcentajeAFC, float porcentajeOFC)
{
	printf("\nEl porcentaje de jugadores de Conmebol es %.2f.", porcentajeConmebol);
	printf("\nEl porcentaje de jugadores de UEFA es %.2f.", porcentajeUEFA);
	printf("\nEl porcentaje de jugadores de Concacaf es %.2f.", porcentajeConcacaf);
	printf("\nEl porcentaje de jugadores de CAF es %.2f.", porcentajeCAF);
	printf("\nEl porcentaje de jugadores de AFC es %.2f.", porcentajeAFC);
	printf("\nEl porcentaje de jugadores de OFC es %.2f.", porcentajeOFC);
}

void DatosMenuJugador()
{
	printf("+---------------+--------------------------------------------------+--------------------+------------+--------------------+---------------+-----------------+\n");
	printf("|%-15s|%-50s|%-20s|%-12s|%-20s|%-15s|%-17s|\n", "ID", "NOMBRE", "POSICION", "N° CAMISETA", "SUELDO", "CONFEDERACION", "AÑOS de CONTRATO");
	printf("+---------------+--------------------------------------------------+--------------------+------------+--------------------+---------------+-----------------+\n");
}

void DatosMenuConfederacion()
{
	printf("+---------------+--------------------+----------------------+---------------+\n");
	printf("|%-15s|%-20s|%-22s|%-15s|\n", "ID", "NOMBRE", "REGION", "AÑO CREACION");
	printf("+---------------+--------------------+----------------------+---------------+\n");
}

