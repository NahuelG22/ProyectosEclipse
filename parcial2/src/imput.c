/*
 * imput.c
 *
 *  Created on: 22 nov 2022
 *      Author: alumno
 */






#include "imput.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


/** \brief recibe un  mensaje, un auxiliar,el tamaneo y valida el string
 *
 * \param char message, char aux , int tam
 * \return int numero
 *
 */
void GetStrings(char message[], char aux[], int tam)
{
	char buffer[50];

	printf("%s", message);
	fflush(stdin);
	scanf("%[^\n]", buffer);

	strcpy(aux, buffer);
}
/** \brief recibe un  mensaje, unmensaje de error y valida el int
 *
 * \param char message, char message error
 * \return int numero
 *
 */

int GetInt(char mensaje[], char messageError[])
{
	char aux[50];
	int auxInt;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", aux);

	while(ValidarInt(aux) == 0)
			{
				printf ("%s", messageError);
				fflush(stdin);
				scanf("%[^\n]", aux);
			}

	auxInt = TurnIntoInt(aux);

	return auxInt;
}
/** \brief recibe un  mensaje, unmensaje de error, un maximo y minimo, validando el rango y valida el int
 *
 * \param char message, char message error, int min_range, int max_range
 * \return int numero
 *
 */

int GetIntRange(char mensaje[], char messageError[], int min_range, int max_range)
{
	char aux[50];
	int auxInt;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", aux);

	while((ValidarInt(aux) == 0))
			{
				printf ("%s", messageError);
				fflush(stdin);
				scanf("%[^\n]", aux);
			}
	auxInt = TurnIntoInt(aux);

		while(auxInt < min_range || auxInt > max_range)
		{
			printf ("%s", messageError);
			scanf("%d", &auxInt);
		}

	return auxInt;
}

/** \brief recibe un  mensaje, unmensaje de error y valida el float
 * \param char message, char message error,
 * \return float numero
 *
 */
float GetFloat(char mensaje[], char messageError[])
{
	char aux[50];
	float auxFloat;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", aux);


	return auxFloat;
}
/** \brief recibe un  mensaje, unmensaje de error y valida el char
 * \param char message, char message error,
 * \return char aux
 *
 */

char getChar(char mensaje[], char messageError[])
{
	char aux;
	char buffer[50];

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &aux);

	while(aux != 's' || aux != 'n')
	{
		printf("%s", messageError);
		fflush(stdin);
		scanf("%c", &aux);
	}

	return aux;
}

/** \brief Obtiene solo una cadena alfab�tica con espacios
 * \param char message, char message error, char aux, int tamaneo
 * \return void
 *
 */

void Get_OnlyAlphabetStringWithSpaces(char MSJ[], char ERROR_MSJ[], char aux[], int TAM)
{
	char buffer[50];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > TAM || strlen(buffer) == 0
			|| Validate_OnlyAlphabetWithSpaces(buffer) == 0) {

		if (strlen(buffer) > TAM || strlen(buffer) == 0) {
			printf("ERROR. Fuera de rango -> CARACTERES [MIN]=1 [MAX]=%d.\n",
					TAM);
		} else {
			printf("ERROR. Solo caracteres alfabeticos validos.\n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(aux, buffer);
}

/** \brief Obtiene in id incremental
 * \param int
 * \return int
 *
 */
int eGen_ObtenerID(int Gen_idIncremental)
{
	return Gen_idIncremental += 1;
}

/** \brief valida un dato
 * \param char message, char message error, char aux, int minimo, int maximo
 * \return void
 *
 */
void GetDate(char mensaje[], char mensajeError[], char *aux, int min, int max)
{
	int intAux;
	intAux = GetIntRange(mensaje, mensajeError, min, max);

	sprintf(aux, "%d", intAux);
}


//---------------------------------------------------------------------------------VALIDACIONES--------------------------------------------------------------------------------------------//
/** \brief valida un int, recibe un char y lo parsea
 * \param char numero
 * \return int
 *
 */
int ValidarInt(char numero[])
{
	int i;
	int result;
	int countsign = 0;

	result = 1;

	for (i=0; i<strlen(numero); i++)
	{
		if(numero[i] == '-')
		{
			countsign++;
		}
		else
		 {
			if(!isdigit(numero[i]))
			{
				result = 0;
			}
		 }
	}
	if(countsign > 1)
	  {
		result = 0;
	  }

	return result;
}
/** \brief valida un char, recibe un char y lo parsea
 * \param char numero
 * \return char
 *
 */
/*char Validarchar(char caracter)
{
	char aux = 0;

	if(isalpha(caracter) != 0)

	{
		aux = caracter;
	}
	return aux;
}
/** \brief valida un float, recibe un char y lo parsea
 * \param char flotante
 * \return float
 *
 */
/*int ValidarFloat(char validfloat[])
{
	int i;
	int countsign = 0;
	int response;
	response = 1;

	for(i=0; i<strlen(validfloat); i++)
	{
		if(validfloat[i] == '.' || validfloat[i] == ',')
		{
			countsign++;
		}
		else
		{
			if(isdigit(validfloat[i]) == 0)
			{
				response = 0;
				break;
			}
		}
	}
	if(countsign > 1)
	{
		response = 0;
	}
	return response;
}



/** \brief Valida que solo sea alfabetos con espacios
 * \param char
 * \return int
 *
 */
int Validate_OnlyAlphabetWithSpaces(char aux[])
{
	int rtn = 1;

	if (strlen(aux) > 0)
	{
		for (int i = 0; i < strlen(aux); i++)
		{
			if (isalpha(aux[i]) == 0) {
				if (isspace(aux[i]) == 0)
				{
					rtn = 0;
					break;
				}
			}
		}
	}
	else
		{
			rtn = 0;
		}

	return rtn;
}

//---------------------------------------------------------------------------------CONVERSION DATOS--------------------------------------------------------------------------------------------//



/** \brief convierte un char en un flotante
 * \param char
 * \return float
 *
 */
/*float TurnIntoFloat(char stringdata[])
{
	float FloatNumber;

		FloatNumber = atof(stringdata);

		return FloatNumber;
}*/

/** \brief convierte un char en un int
 * \param char
 * \return int
 *
 */
int TurnIntoInt(char stringdata[])
{
	int IntNumber;

	IntNumber = atoi(stringdata);

	return IntNumber;
}

/** \brief recive datos de fecha y te lo arma
 * \param char dia char mes char anio, char aux
 * \return void
 *
 */

void ToDate(char *dia, char *mes, char *anio, char *aux)
{
	strcpy(aux, dia);
	strcpy(aux, "/");
	strcpy(aux, mes);
	strcpy(aux, "/");
	strcpy(aux, anio);
}


