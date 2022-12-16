/*
 * inputs.h
 *
 *  Created on: 20 sep. 2022
 *      Author: Nahuel A
 */

#ifndef INPUTS_H_
#define INPUTS_H_

int getInt();
float getFloat();
char getChar();

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);

void cleanStdin(void);
int getNumberInt(char mensaje[], char mensajeError[], int minimo, int maximo);

int getNumberFloat(float * pResultado, char * mensaje, char * mensajeError, float minimo, float maximo, int reintentos);
int getNumberInt(float * pResultado, char * mensaje, char * mensajeError, float minimo, float maximo, int reintentos);
#endif /* INPUTS_H_ */
