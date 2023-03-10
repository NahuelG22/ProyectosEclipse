/*
 * Inputs.h
 *
 *  Created on: 27 sep. 2022
 *      Author: Nahuel A
 */

#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * \brief Solicita un n?mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n?mero ingresado por el usuario
 *
 */
int getInt(char* mensaje);

/**
 * \brief Solicita un n?mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n?mero ingresado por el usuario
 *
 */
short getShort(char* mensaje);

/**
 * \brief Solicita un n?mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n?mero ingresado por el usuario
 *
 */
float getFloat(char* mensaje);


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char* mensaje);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar? el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);


/**
 * @fn int getNumberInt(char[], char[], int, int)
 * @brief Solicita un numero entero al usuario, luego de verificarlo devuelve el resultado.
 *
 * @param mensaje Es el mensaje que sera mostrado
 * @param mensajeError Es el mensaje de error que sera mostrado
 * @param minimo Es el numero limite minimo
 * @param maximo Es el numero limite maximo
 * @return El numero ingresado por el usuario
 */
int getNumberInt(char mensaje[], char mensajeError[], int minimo, int maximo);

/**
 * @fn short getNumberShort(char[], char[], short, short)
 * @brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado.
 *
 * @param mensaje Es el mensaje que sera mostrado
 * @param mensajeError Es el mensaje de error que sera mostrado
 * @param minimo Es el numero limite minimo
 * @param maximo Es el numero limite maximo
 * @return El numero ingresado por el usuario
 */
short getNumberShort(char mensaje[], char mensajeError[], short minimo, short maximo);

/**
 * @fn float getNumberFloat(char[], char[], float, float)
 * @brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado.
 *
 * @param mensaje Es el mensaje que sera mostrado
 * @param mensajeError Es el mensaje de error que sera mostrado
 * @param minimo Es el numero limite minimo
 * @param maximo Es el numero limite maximo
 * @return El numero ingresado por el usuario
 */
float getNumberFloat(char mensaje[], char mensajeError[], float minimo, float maximo);

/**
 * @fn int GetString(char[], int, char[])
 * @brief Solicita un texto al usuario y retorna si pudo obtener la cadena
 *
 * @param cadena En donde se guardara la cadena de texto
 * @param len Tama?o de la cadena de texto
 * @param mensaje Es el mensaje a ser mostrado
 * @return Si se copiar la cadena o no
 */
int GetString(char cadena[], int len, char mensaje[]);

#endif /* INPUTS_H_ */
