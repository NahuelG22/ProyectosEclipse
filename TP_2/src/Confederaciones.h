/*
 * Confederaciones.h
 *
 *  Created on: 29 oct. 2022
 *      Author: Nahuel A
 */

#ifndef CONFEDERACIONES_H_
#define CONFEDERACIONES_H_
#include "Inputs.h"
#include "Jugador.h"

/**
 * @fn int BuscarConfederacion(eConfederacion[], int, int)
 * @brief Busca la confederacion cargada para realizar la modificacion
 *
 * @param confederaciones El array de la estructura eConfederacion
 * @param size El tamaño del array de la estructura eConfederacion
 * @param variableAModificar
 * @return
 */
int BuscarConfederacion(eConfederacion confederaciones[],int size,int variableAModificar);

/**
 * @fn int buscarConfederacionLibre(eConfederacion[], int)
 * @brief Busca si en el array de confederaciones hay espacio libre
 *
 * @param confederaciones El array de la estructura eConfederacion
 * @param size El tamaño del array de la estructura eConfederacion
 * @return El index encontrado en caso de haber espacio
 */
int buscarConfederacionLibre(eConfederacion confederaciones[], int size);

/**
 * @fn void inicializarListaConfederaciones(eConfederacion[], int)
 * @brief Pone todas las posiciones del array de confederaciones en libre
 *
 * @param confederaciones El array de la estructura eConfederacion
 * @param size El tamaño del array de la estructura eConfederacion
 */
void inicializarListaConfederaciones(eConfederacion confederaciones[], int size);

/**
 * @fn int AltaConfederacion(int, eConfederacion[], int)
 * @brief Carga los datos de la confederacion
 *
 * @param id El id de la confederacion
 * @param confederaciones El array de la estructura eConfederacion
 * @param size El tamaño del array de la estructura eJugador
 * @return 1 Si se pudo cargar el jugador o 0 si no se pudo
 */
int AltaConfederacion(int id, eConfederacion confederaciones[], int size);

/**
 * @fn int BajaConfederacion(eConfederacion[], int)
 * @brief Realiza la baja logica de una confederacion ingresada
 *
 * @param confederaciones El array de la estructura eConfederacion
 * @param size El tamaño del array de la estructura eConfederacion
 * @return 1 Si se pudo eliminar la confederacion o 0 si no se pudo
 */
int BajaConfederacion(eConfederacion confederaciones[], int size);

/**
 * @fn int modificarConfederacion(eConfederacion[], int)
 * @brief Pide los datos de la confederacion a modificar
 *
 * @param confederaciones El array de la estructura eConfederacion
 * @param size El tamaño del array de la estructura eConfederacion
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int modificarConfederacion(eConfederacion confederaciones[], int sizeConfederaciones);

/**
 * @fn int ModificarNombreConfederacion(eConfederacion[], int, int)
 * @brief Modifica el nombre de la confederacion
 *
 * @param confederaciones El array de la estructura eConfederacion
 * @param size El tamaño del array de la estructura eConfederacion
 * @param id El id de la confederacion
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int ModificarNombreConfederacion(eConfederacion confederaciones[], int size, int id);

/**
 * @fn int ModificarRegion(eConfederacion[], int, int)
 * @brief  Modifica la region de la confederacion
 *
 * @param confederaciones El array de la estructura eConfederacion
 * @param size El tamaño del array de la estructura eConfederacion
 * @param id El id de la confederacion
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int ModificarRegion(eConfederacion confederaciones[], int size, int id);

/**
 * @fn int ModificarAnioCreacion(eConfederacion[], int, int)
 * @brief Modifica el año de la creacion de la confederacion
 *
 * @param confederaciones El array de la estructura eConfederacion
 * @param size El tamaño del array de la estructura eConfederacion
 * @param id El id de la confederacion
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int ModificarAnioCreacion(eConfederacion confederaciones[], int size, int id);

#endif /* CONFEDERACIONES_H_ */
