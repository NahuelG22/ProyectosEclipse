/*
 * Libros.h
 *
 *  Created on: 1 oct. 2022
 *      Author: Nahuel A
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#include "Inputs.h"
typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
    int codigoEditorial;
    char descripcion[51];
}sEditorial;

typedef struct
{
    int codigoPais;
    char descripcion[51];
}ePais;

typedef struct
{
    int codigoAutor;
    char nombreAutor[51];
    int codigoPais;
}eAutor;

typedef struct
{
	int codigoGenero;
	char descripcion[15];
}eGenero;

typedef struct
{
	int codigoLibro;
	char titulo[51];
	eFecha fecha;
	float importe;
	int autor;
	int editorial;
	int estado;
	int genero;
}eLibro;

/**
 * @fn void inicializarListaLibros(eLibro[], int)
 * @brief Pone todas las posiciones del array de la lista de libros en libre
 *
 * @param listaLibros El array de libros
 * @param size El tamaño del array
 */
void inicializarListaLibros(eLibro listaLibros[], int size);

/**
 * @fn int buscarEspacioLibre(eLibro[], int)
 * @brief Busca si en el array de libros hay espacio libre
 *
 * @param listaLibros El array de libros
 * @param size El tamaño del array
 * @return El index que confirma si hay o no espacio
 */
int buscarEspacioLibre(eLibro listaLibros[], int size);

/**
 * @fn eLibro CargarLibro(int, eAutor[], ePais[], sEditorial[])
 * @brief Pide los datos de la estructura eLibro
 *
 * @param codigoLibro El codigo del libro que se le asigna a la estructura
 * @param autores El array de autores para relacionarlo con la estructura eLibro
 * @param paises El array de paises para relacionarlo con la estrucura eAutor
 * @param editoriales El array de editoriales para relacionarlo con la estructura eLibro
 * @param generos
 * @return La estructura cargada con los datos
 */
eLibro cargarLibro(int codigoLibro, eAutor autores[], ePais paises[], sEditorial editoriales[], eGenero generos[]);

/**
 * @fn int AltaLibro(eLibro[], int, int, eAutor[], ePais[], sEditorial[])
 * @brief Permite dar de alta un libro
 *
 * @param listaLibros El array de libros
 * @param size El tamaño del array
 * @param codigoLibro El codigo del libro que se le asigna al libro cargado
 * @param autores El array de autores
 * @param paises El array de paises
 * @param editoriales El array de editoriales
 * @return 1 Si se pudo cargar el libro o 0 si no se pudo
 */
int altaLibro(eLibro listaLibros[], int size, int codigoLibro, eAutor autores[], ePais paises[], sEditorial editoriales[], eGenero generos[]);

/**
 * @fn void MostrarAutores(eAutor[], int, ePais[], int)
 * @brief Muestra los datos hardcodeados de los autores
 *
 * @param autores El array de autores
 * @param size El tamaño del array
 * @param paises El array de paises para relacionarlo con los autores
 * @param sizePaises El tamaño del array de paises
 */
void mostrarAutores(eAutor autores[], int size, ePais paises[],int sizePaises);

/**
 * @fn void MostrarEditoriales(sEditorial[], int)
 * @brief Muestra los datos hardcodeados de las editoriales
 *
 * @param editoriales El array de editoriales
 * @param size El tamaño del array
 */
void mostrarEditoriales(sEditorial editoriales[], int size);

/**
 * @fn void MostrarPaises(ePais[], int)
 * @brief Muestra los datos hardcodeados de los paises
 *
 * @param paises El array de paises
 * @param size El tamaño del array
 */
void mostrarPaises(ePais paises[], int size);

/**
 * @fn void mostrarAltaLibro(eLibro[], int, eAutor[], int, sEditorial[], int)
 * @brief Muestro los libros cargados hasta el momento con todos sus datos
 *
 * @param listaLibros El array de libros
 * @param size El tamaño del array
 * @param autores El array de autores
 * @param sizeAutores El tamaño del array
 * @param editoriales El array de editoriales
 * @param sizeEditoriales El tamaño del array
 */
void mostrarAltaLibro(eLibro listaLibros[], int size, eAutor autores[], int sizeAutores, sEditorial editoriales[], int sizeEditoriales, eGenero generos[], int sizeGeneros);

/**
 * @fn int modificarLibro(eLibro[], int, eAutor[], int, sEditorial[], int, ePais[])
 * @brief Pide los datos del libro a modificar
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 * @param autores El array de autores
 * @param sizeAutores El tamaño del array
 * @param editoriales El array de editoriales
 * @param sizeEditoriales El tamaño del array
 * @param paises El array de paises
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int modificarLibro(eLibro libros[], int size, eAutor autores[], int sizeAutores, sEditorial editoriales[], int sizeEditoriales, ePais paises[], eGenero generos[]);

/**
 * @fn int ModificarTitulo(eLibro[], int, int)
 * @brief Modifica el titulo
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 * @param codigoLibro El codigo del libro que se le asigna al libro cargado
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int modificarTitulo(eLibro libros[], int size, int codigoLibro);

/**
 * @fn int ModificarFecha(eLibro[], int, int)
 * @brief Modifica la fecha
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 * @param codigoLibro El codigo del libro que se le asigna al libro cargado
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int modificarFecha(eLibro libros[], int size, int codigoLibro);

/**
 * @fn int ModificarImporte(eLibro[], int, int)
 * @brief Modifica el importe
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 * @param codigoLibro El codigo del libro que se le asigna al libro cargado
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int modificarImporte(eLibro libros[], int size, int codigoLibro);

/**
 * @fn int ModificarAutor(eLibro[], int, int, eAutor[], ePais[])
 * @brief Modifica el autor
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 * @param codigoLibro El codigo del libro que se le asigna al libro cargado
 * @param autores El array de autores
 * @param paises El array de paises
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int modificarAutor(eLibro libros[], int size, int codigoLibro, eAutor autores[], ePais paises[]);

/**
 * @fn int ModificarEditorial(eLibro[], int, int, sEditorial[], int)
 * @brief Modifica la editorial
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 * @param codigoLibro El codigo del libro que se le asigna al libro cargado
 * @param editoriales El array de editoriales
 * @param sizeEditoriales El tamaño del array
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int modificarEditorial(eLibro libros[], int size, int codigoLibro, sEditorial editoriales[], int sizeEditoriales);

/**
 * @fn int BajaLibro(eLibro[], int)
 * @brief Cambia el estado de un libro cargado
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 * @return Si se pudo o no realizar la baja
 */
int bajaLibro(eLibro libros[], int size);

/**
 * @fn int BuscarLibro(eLibro[], int, int)
 * @brief
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 * @param variableAModificar
 * @return Posicion del libro encontrado
 */
int buscarLibro(eLibro libros[],int size,int variableAModificar);

/**
 * @fn void listarLibrosOrdenadosPorCriterios(eLibro libros[], int size, eAutor autores[], sEditorial editoriales[], eGenero generos[])
 * @brief Lista los libros por los criterios importe y titulo
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 * @param autores El array de autores
 * @param editoriales El array de editoriales
 * @param generos El array de generos
 */
void listarLibrosOrdenadosPorCriterios(eLibro libros[], int size, eAutor autores[], sEditorial editoriales[], eGenero generos[]);

/**
 * @fn void listarLibrosPorFecha(eLibro[], int)
 * @brief Lista los libros publicados antes del 2000
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 */
void listarLibrosPorFecha(eLibro libros[], int size);

/**
 * @fn int calcularPromedioImportes(eLibro[], int)
 * @brief Calcula el promedio y total de los importes
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 * @return El promedio de los importes
 */
int calcularPromedioImportes(eLibro libros[], int size);

/**
 * @fn void mostrarPromedioYTotalImportes(eLibro[], int)
 * @brief Muestra los libros que superan el promedio de importes
 *
 * @param libros El array de libros
 * @param size El tamaño del array
 */
void mostrarPromedioYTotalImportes(eLibro libros[], int size);

/**
 * @fn void MostrarGeneros(eGenero[], int)
 * @brief Muestra todos los generos
 *
 * @param generos El array de generos
 * @param size El tamaño del array
 */
void mostrarGeneros(eGenero generos[], int size);

/**
 * @fn int ModificarGenero(eLibro[], int, int, eGenero[], int)
 * @brief Modifica el genero
 *
 * @param libros El array de la estructura libros
 * @param size El tamaño de libros
 * @param codigoLibro El codigo del libro que se le asigna al libro cargado
 * @param generos El array de la estructura generos
 * @param sizeGeneros El tamaño de generos
 * @return Si la operacion no se hizo, se cancelo o se realizo correctamente
 */
int modificarGenero(eLibro libros[], int size, int codigoLibro, eGenero generos[], int sizeGeneros);

/**
 * @fn void MostrarLibrosNoSonNovelas(eLibro[], int, eGenero[], int, eAutor[], int, sEditorial[], int)
 * @brief Muestra los libros que no pertenecen al genero novela
 *
 * @param libros El array de la estructura libros
 * @param size El tamaño de libros
 * @param generos El array de la estructura generos
 * @param sizeGeneros El tamaño de generos
 * @param autores El array de la estructura autores
 * @param sizeAutores El tamaño del array
 * @param editoriales El array de la estructura editoriales
 * @param sizeEditoriales El tamaño del array
 */
void mostrarLibrosNoSonNovelas(eLibro libros[], int size, eGenero generos[], int sizeGeneros, eAutor autores[], int sizeAutores, sEditorial editoriales[], int sizeEditoriales);

void mostrarLibroDeEditorialDeterminada(eLibro libros[], int size, eAutor autores[], int sizeAutores, sEditorial editoriales[], int sizeEditoriales, ePais paises[], eGenero generos[], int sizeGeneros);

#endif /* LIBROS_H_ */
