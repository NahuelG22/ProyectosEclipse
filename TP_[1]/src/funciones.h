/*
 * funciones.h
 *
 *  Created on: 15 nov. 2022
 *      Author: Nahuel A
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * @fn int preguntar(int, int, int, int, int, int, int)
 * @brief Pregunta nuevamente despues de elegir una opcion
 *
 * @param acumuladorCostoHospedaje Es el acumulador que recibe para mostrar el costo de hospedaje
 * @param acumuladorCostoComida Es el acumulador que recibe para mostrar el costo de comida
 * @param acumuladorCostoTransporte Es el acumulador que recibe para mostrar el costo de transporte
 * @param contadorArqueros Es el contador de cuantos arqueros se ingresaron
 * @param contadorDefensores Es el contador de cuantos defensores se ingresaron
 * @param contadorMediocampistas Es el contador de cuantos mediocampistas se ingresaron
 * @param contadorDelanteros Es el contador de cuantos delanteros se ingresaron
 * @return La opcion elegida
 */
int preguntar(int acumuladorCostoHospedaje, int acumuladorCostoComida, int acumuladorCostoTransporte, int contadorArqueros, int contadorDefensores, int contadorMediocampistas, int contadorDelanteros);

/**
 * @fn void mostrarOpciones(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)
 * @brief
 *
 * @param opcion Permite acceder al menu de opciones
 * @param acumuladorCostoHospedaje Es el acumulador que recibe para mostrar el costo de hospedaje
 * @param acumuladorCostoComida Es el acumulador que recibe para mostrar el costo de comida
 * @param acumuladorCostoTransporte Es el acumulador que recibe para mostrar el costo de transporte
 * @param contadorArqueros Es el contador de cuantos arqueros se ingresaron
 * @param contadorDefensores Es el contador de cuantos defensores se ingresaron
 * @param contadorMediocampistas Es el contador de cuantos mediocampistas se ingresaron
 * @param contadorDelanteros Es el contador de cuantos delanteros se ingresaron
 * @param contadorJugadores Es el contador de cuantos jugadores se ingresaron
 * @param contadorOFC Es el contador de cuantos jugadores de la OFC se ingresaron
 * @param contadorAFC Es el contador de cuantos jugadores de la AFC se ingresaron
 * @param contadorUEFA Es el contador de cuantos jugadores de la UEFA se ingresaron
 * @param contadorConcacaf Es el contador de cuantos jugadores de la Concacaf se ingresaron
 * @param contadorConmebol Es el contador de cuantos jugadores de la Conmebol se ingresaron
 * @param contadorCAF Es el contador de cuantos jugadores de la CAF se ingresaron
 */
void mostrarOpciones(int opcion, int acumuladorCostoHospedaje, int acumuladorCostoComida, int acumuladorCostoTransporte, int contadorArqueros, int contadorDefensores, int contadorMediocampistas, int contadorDelanteros, int contadorJugadores, int contadorOFC, int contadorAFC, int contadorUEFA, int contadorConcacaf, int contadorConmebol, int contadorCAF);

/**
 * @fn float promediar(int, int)
 * @brief Calcula el promedio de dos enteros
 *
 * @param contador1 Primer contador
 * @param contador2 Segundo contador
 * @return El promedio
 */
float promediar(int contador1, int contador2);

#endif /* FUNCIONES_H_ */
