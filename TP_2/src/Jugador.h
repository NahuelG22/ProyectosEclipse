/*
 * Jugador.h
 *
 *  Created on: 14 oct. 2022
 *      Author: Nahuel A
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#define LIBRE 0
#define CARGADO 1
#define BAJA -1
#include "Inputs.h"

typedef struct
{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	short isEmpty;
}eConfederacion;

typedef struct
{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

/**
 * @fn void inicializarListaJugadores(eJugador[], int)
 * @brief Pone todas las posiciones del array de jugadores en libre
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 */
void inicializarListaJugadores(eJugador jugadores[], int size);

/**
 * @fn int buscarEspacioLibre(eJugador[], int)
 * @brief Busca si en el array de jugadores hay espacio libre
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @return El index encontrado en caso de haber espacio
 */
int buscarEspacioLibre(eJugador jugadores[], int size);

/**
 * @fn int AltaJugador(eJugador[], int, int, eConfederacion[], int)
 * @brief Carga los datos del jugador
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param id El id del jugador
 * @param confederaciones El array de la estructura eConfederacion
 * @param sizeConfederaciones El tamaño del array de la estructura eJugador
 * @return 1 Si se pudo cargar el jugador o 0 si no se pudo
 */
int AltaJugador(eJugador jugadores[], int size, int id, eConfederacion confederaciones[], int sizeConfederaciones);

/**
 * @fn void MostrarConfederaciones(eConfederacion[], int)
 * @brief Muestra las confederaciones
 *
 * @param confederaciones El array de la estructura eConfederacion
 * @param size El tamaño del array de la estructura eConfederacion
 */
void MostrarConfederaciones(eConfederacion confederaciones[], int size);

/**
 * @fn void mostrarAltaJugador(eJugador[], int, eConfederacion[], int)
 * @brief Muestra los jugadores cargados
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param confederaciones El array de la estructura eConfederacion
 * @param sizeConfederaciones El tamaño del array de la estructura eConfederacion
 */
void mostrarAltaJugador(eJugador jugadores[], int size, eConfederacion confederaciones[], int sizeConfederaciones);

/**
 * @fn int BajaJugador(eJugador[], int)
 * @brief Realiza la baja logica de un jugador ingresado
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @return 1 Si se pudo eliminar al jugador o 0 si no se pudo
 */
int BajaJugador(eJugador jugadores[], int size);

/**
 * @fn int BuscarJugador(eJugador[], int, int)
 * @brief Busca el jugador cargado para realizar la modificacion
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param variableAModificar
 * @return
 */
int BuscarJugador(eJugador jugadores[],int size,int variableAModificar);

/**
 * @fn int VerificarLleno(eJugador[], int)
 * @brief
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @return
 */
int VerificarLleno(eJugador jugadores[], int size);

/**
 * @fn int modificarJugador(eJugador[], int, eConfederacion[], int, int)
 * @brief Pide los datos del jugador a modificar
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param confederaciones El array de la estructura eConfederacion
 * @param sizeConfederaciones El tamaño del array de la estructura eConfederacion
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int modificarJugador(eJugador jugadores[], int size, eConfederacion confederaciones[], int sizeConfederaciones);

/**
 * @fn int ModificarNombre(eJugador[], int, int)
 * @brief Modifica el nombre
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param id El id del jugador
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int ModificarNombre(eJugador jugadores[], int size, int id);

/**
 * @fn int ModificarPosicion(eJugador[], int, int)
 * @brief Modifica la posicion
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param id El id del jugador
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int ModificarPosicion(eJugador jugadores[], int size, int id);

/**
 * @fn int ModificarSalario(eJugador[], int, int)
 * @brief Modifica el salario
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param id El id del jugador
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int ModificarSalario(eJugador jugadores[], int size, int id);

/**
 * @fn int ModificarNumero(eJugador[], int, int)
 * @brief Modifica el numero
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param id El id del jugador
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int ModificarNumero(eJugador jugadores[], int size, int id);

/**
 * @fn int ModificarAniosContrato(eJugador[], int, int)
 * @brief Modifica los años de contrato del jugador
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param id El id del jugador
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int ModificarAniosContrato(eJugador jugadores[], int size, int id);

/**
 * @fn int ModificarConfederacion(eJugador[], int, int, eConfederacion[], int)
 * @brief Modifica la confederacion del jugador
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param id El id del jugador
 * @param confederaciones El array de la estructura eConfederacion
 * @param sizeConfederaciones El tamaño del array de la estructura eConfederacion
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int ModificarConfederacion(eJugador jugadores[], int size, int id, eConfederacion confederaciones[], int sizeConfederaciones);

/**
 * @fn int calcularPromedioSalarios(eJugador[], int)
 * @brief Calcula el promedio y total de los salarios
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @return El promedio de los salarios
 */
float calcularPromedioSalarios(eJugador jugadores[], int size);

/**
 * @fn void mostrarJugadoresQueSuperanElPromedio(eJugador[], int, eConfederacion[], int)
 * @brief Muestra los jugadores que superan el promedio de salarios
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param confederaciones El array de la estructura eConfederacion
 * @param sizeConfederaciones El tamaño del array de la estructura eConfederacion
 */
void mostrarJugadoresQueSuperanElPromedio(eJugador jugadores[], int size, eConfederacion confederaciones[], int sizeConfederaciones);

/**
 * @fn int ordenarAlfabeticamente(eJugador[], int, eConfederacion[], int)
 * @brief Ordena alfabeticamente el listado de jugadores por confederacion
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param confederaciones El array de la estructura eConfederacion
 * @param sizeConfederaciones El tamaño del array de la estructura eConfederacion
 */
void ordenarAlfabeticamente(eJugador jugadores[], int size, eConfederacion confederaciones[], int sizeConfederaciones);

int buscarIdConfederacion(eConfederacion* estructura,int id,int tam);

/**
 * @fn void obtenerDatosPorConfederacion(eJugador[], int, int, float)
 * @brief Suma los años de contrato y cuenta los jugadores por confederacion
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param criterio El criterio seleccionado para informar los datos obtenidos
 */
void obtenerDatosPorConfederacion(eJugador jugadores[], int size, int criterio);

/**
 * @fn void listarJugadoresXConfederacion(eJugador[], int, eConfederacion[], int)
 * @brief lista los jugadores de una confederacion seleccionada
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param confederaciones El array de la estructura eConfederacion
 * @param sizeConfederaciones El tamaño del array de la estructura eConfederacion
 */
void listarJugadoresXConfederacion(eJugador jugadores[], int size, eConfederacion confederaciones[], int sizeConfederaciones);


/**
 * @fn void informarRegionConMasJugadores(int, int, int, int, int, int)
 * @brief Informa la region con mas jugadores
 *
 * @param contadorConmebol contador de jugadores de Conmebol
 * @param contadorConcacaf contador de jugadores de Concacaf
 * @param contadorUEFA contador de jugadores de UEFA
 * @param contadorCAF contador de jugadores de CAF
 * @param contadorAFC contador de jugadores de AFC
 * @param contadorOFC contador de jugadores de OFC
 */
void informarRegionConMasJugadores(int contadorConmebol, int contadorConcacaf, int contadorUEFA, int contadorCAF, int contadorAFC, int contadorOFC);

/**
 * @fn void informarConfederacionConMayorCantidadAniosContrato(int, int, int, int, int, int)
 * @brief Informa la confederacion con mayor cantidad de años de contrato
 *
 * @param acumuladorConmebol
 * @param acumuladorConcacaf
 * @param acumuladorUEFA
 * @param acumuladorCAF
 * @param acumuladorAFC
 * @param acumuladorOFC
 */
void informarConfederacionConMayorCantidadAniosContrato(int acumuladorConmebol, int acumuladorConcacaf, int acumuladorUEFA, int acumuladorCAF, int acumuladorAFC, int acumuladorOFC);

/**
 * @fn float calcularPorcentaje(eJugador[], int)
 * @brief Calcula el porcentaje de jugadores por confederacion
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @return El porcentaje
 */
void calcularPorcentaje(int contadorConmebol, int contadorConcacaf, int contadorUEFA, int contadorCAF, int contadorAFC, int contadorOFC);

/**
 * @fn void mostrarPorcentaje(eJugador[], int, eConfederacion[], int)
 * @brief Muestra el porcentaje calculado
 *
 * @param jugadores El array de la estructura eJugador
 * @param size El tamaño del array de la estructura eJugador
 * @param confederaciones El array de la estructura eConfederacion
 * @param sizeConfederaciones El tamaño del array de la estructura eConfederacion
 */
void mostrarPorcentaje(float porcentajeConmebol, float porcentajeUEFA, float porcentajeConcacaf, float porcentajeCAF, float porcentajeAFC, float porcentajeOFC);

/**
 * @fn void DatosMenuJugador(void)
 * @brief Crea el formato de la tabla para mostrar los jugadores cargados
 *
 */
void DatosMenuJugador(void);

/**
 * @fn void DatosMenuConfederacion(void)
 * @brief Crea el formato de la tabla para mostrar las confederaciones cargadas
 *
 */
void DatosMenuConfederacion(void);

#endif /* JUGADOR_H_ */
