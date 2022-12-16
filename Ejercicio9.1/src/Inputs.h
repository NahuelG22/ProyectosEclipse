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
#include <time.h>
#include <string.h>

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char* mensaje);

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
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
 * \param input Array donde se cargará el texto ingresado
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
 * @fn int getRandomNumber(int, int, int)
 * @brief Genera un numero aleatorio
 *
 * @param minimo Es el numero limite minimo
 * @param maximo Es el numero limite maximo
 * @param repeticion Indica si se trata del primer número solicitado 1 indica que si
 * @return retorna el numero aleatorio generado
 */
int getRandomNumber(int minimo, int maximo, int repeticion);

int GetString(char cadena[], int len, char mensaje[]);

#endif /* INPUTS_H_ */
