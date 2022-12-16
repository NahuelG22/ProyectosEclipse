/*
 * imput.h
 *
 *  Created on: 22 nov 2022
 *      Author: alumno
 */

#ifndef IMPUT_H_
#define IMPUT_H_


#ifndef IMPUT_H_
#define IMPUT_H_





void GetStrings(char message[], char aux[], int tam);
int GetInt(char mensaje[], char messageError[]);
int GetIntRange(char mensaje[], char messageError[], int min_range, int max_range);
float GetFloat(char mensaje[], char messageError[]);
char getChar(char mensaje[], char messageError[]);
void Get_OnlyAlphabetStringWithSpaces(char MSJ[], char ERROR_MSJ[], char aux[], int TAM);
int eGen_ObtenerID(int Gen_idIncremental);
void GetDate(char mensaje[], char mensajeError[], char *aux, int min, int max);
//---------------------------------------------------------------------------------VALIDACIONES--------------------------------------------------------------------------------------------//
int ValidarInt(char numero[]);
char Validarchar(char caracter);
int ValidarFloat(char validfloat[]);
int Validate_OnlyAlphabetWithSpaces(char aux[]);
//---------------------------------------------------------------------------------CONVERSION DATOS--------------------------------------------------------------------------------------------//
float TurnIntoFloat(char stringdata[]);
int TurnIntoInt(char stringdata[]);
void ToDate(char *dia, char *mes, char *anio, char *aux);
#endif /* IMPUT_H_ */


#endif /* IMPUT_H_ */
