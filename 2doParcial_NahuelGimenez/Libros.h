/*
 * Libros.h
 *
 *  Created on: 23 nov 2022
 *      Author: alumno
 */

#ifndef LIBROS_H_
#define LIBROS_H_

#include "input.h"
typedef struct
{
    int id;
    char titulo[100];
    char importe[100];
    int idTipo;
}eLibros;

eLibros* Libros_new(void);
eLibros* Libros_newParametros(char* idStr,char* tituloStr,char* ImporteStr, char* idTipoStr);

void Libros_delete(eLibros* this);

int Libros_setId(eLibros* this,int id);
int Libros_getId(eLibros* this,int* id);

int Libros_setTitulo(eLibros* this,char* titulo);
int Libros_getTitulo(eLibros* this,char* titulo);

int Libros_setImporte(eLibros* this,char importe);
int Libros_getImporte(eLibros* this,char* importe);

int Libros_setidTipo(eLibros* this,int idTipo);
int Libros_getidTipo(eLibros* this,int* idTipo);

int Libros_setIdStr(eLibros* this, char* id);
int Libros_getIdStr(eLibros* this, char* resultado);

int Libros_setImporteStr(eLibros* this,char* importe);
int Libros_getImporteStr(eLibros* this,char* importe);

int Libros_setidTipoStr(eLibros* this,char* idTipo);
int Libros_getidTipoStr(eLibros* this,char* idTipo);

int Libros_sortByImport(eLibros* this,char importe);
#endif /* LIBROS_H_ */
