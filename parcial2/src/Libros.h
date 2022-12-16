/*
 * Libros.h
 *
 *  Created on: 22 nov 2022
 *      Author: alumno
 */

#ifndef LIBROS_H_
#define LIBROS_H_
typedef struct
{
    int id;
    char titulo[128];
    char Autor [128];
    int idGenero;
}eLibros;

/** \brief Reserva espacio en memoria para un empleado
 *  \param  no tiene
 *  \return Libros* un puntero a un espacio reservado para cargar un nuevo empleado
 */
eLibros* Libros_new();

/** \brief Valida los elementos que contiene un empleado y los carga en una variable Libros
 * \param idStr char* id del empleado.
 * \param nombreStr char* nombre
 * \param AutorStr char* horas trabajadas
 * \param idGenero char* idGenero del empleado..
 * \return Libros* pAuxLibros, devuelve - NULL si alguno de los parametros de la funcion es NULL.
 *                                 devuelve - puntero al empleado si valido sus elementos.
 */
eLibros* Libros_newParametros(char* idStr,char* nombreStr,char* AutorStr, char* idGenero);

/** \brief Libera el espacio reservado en memoria para un empleado.
 * \param Libros* this puntero al empleado
 * \return int retorno -1 si this NULL,
 *                       0 si logro liberar el espacio reservado.
 */
void Libros_delete();
/** \brief Valida el elemento id del Empleado y lo carga en la estructura
 * \param this Libros* puntero al empleado
 * \param id id del Empleado
 * \return int retorno -1 si no pudo validar el ID
 *                      0 si pudo validar y cargar el ID:
 */
int Libros_setId(eLibros* this,int id);
/** \brief Obtiene el id de un empleado.
 * \param this Libros* puntero a empleado.
 * \param resultado int* id de Libros
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo el id.
 */
int Libros_getId(eLibros* this,int* id);

/** \brief Valida el elemento nombre del Empleado y lo settea
 * \param this Libros* puntero al empleado.
 * \param nombre char* nombre del Empleado.
 * \return int retorno -1 si no pudo validar el nombre.
 *                      0 si pudo validar y cargar el nombre.
 */
int Libros_setNombre(eLibros* this,char* nombre);

/** \brief Obtiene el nombre de un empleado.
 * \param this Libros* puntero a empleado.
 * \param resultado char* nombre de Libros
 * \return int retorno -1 si this es NULL o nombre es NULL,
 *                      0 si se obtuvo el nombre.
 */
int Libros_getNombre(eLibros* this,char* nombre);

/** \brief Verifica el elemento Autor del Empleado y lo settea
 * \param this Libros* puntero al empleado
 * \param Autor Autor del Empleado.
 * \return int retorno -1 si no pudo validar la/las Autor.
 *                      0 si pudo validar y cargar la/las Autor.
 */
int Libros_setAutor(eLibros* this,char Autor);
/** \brief Obtiene las Autor de un empleado.
 * \param this Libros* puntero a empleado.
 * \param resultado int* Autor de Libros
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo las Autor.
 */
int Libros_getAutor(eLibros* this,char* Autor);
/** \brief Valida el elemento idGenero del Empleado y lo settea
 * \param this Libros* puntero al empleado
 * \param idGenero idGenero del Empleado.
 * \return int retorno -1 si no pudo validar el idGenero.
 *                      0 si pudo validar y cargar el idGenero.
 */
int Libros_setidGenero(eLibros* this,int idGenero);

/** \brief Obtiene el idGenero de un empleado.
 * \param this Libros* puntero a empleado.
 * \param resultado int* idGenero de Libros
 * \return int retorno -1 si this es NULL o id es NULL,
 *                      0 si se obtuvo el idGenero.
 */
int Libros_getidGenero(eLibros* this,int* idGenero);

/** \brief Valida el elemento id string del Empleado y lo carga en la estructura Libros.
 * \param this Libros* puntero al empleado.
 * \param id char* id del Empleado.
 * \return int retorno -1 si no pudo validar el id.
 *                      0 si pudo validar y cargar el id.
 */
int Libros_setIdStr(eLibros* this, char* id);

/** \brief Obtiene el id de tipo string de un empleado.
 * \param this Libros* puntero a empleado.
 * \param resultado char* ID de Libros
 * \return int retorno -1 si this es NULL o ID es NULL,
 *                      0 si se obtuvo el ID.
 */
int Libros_getIdStr(eLibros* this, char* resultado);
/** \brief Valida el elemento Autor del Empleado de tipo string y lo settea.
 * \param this Libros* puntero al empleado.
 * \param Autor char* Autor del Empleado.
 * \return int retorno -1 si no pudo validar la/las Autor.
 *                      0 si pudo validar y cargar la/las Autor .
 */
int Libros_setAutorStr(eLibros* this,char* Autor);
/** \brief Obtiene las Autor de tipo string de un empleado.
 * \param this Libros* puntero a empleado.
 * \param resultado char* ID de Libros
 * \return int retorno -1 si this es NULL o ID es NULL,
 *                      0 si se obtuvo la/las Autor.
 */
int Libros_getAutorStr(eLibros* this,char* resultado);

/** \brief Valida el elemento idGenero del ip Empleado y lo settea
 * \param this Libros* puntero al empleado.
 * \param idGenero char* idGenero
 * \return int retorno -1 si no pudo validar el idGenero.
 *                      0 si pudo validar y cargar el idGenero.
 */
int Libros_setidGeneroStr(eLibros* this,char* idGenero);

/** \brief Obtiene el idGenero de tipo string de un empleado.
 * \param this Libros* puntero a empleado.
 * \param resultado char* ID de Libros
 * \return int retorno -1 si this es NULL o ID es NULL,
 *                      0 si se obtuvo el idGenero.
 */
int Libros_getidGeneroStr(eLibros* this,char* resultado);

/** \brief Recorre la lista de empleados, busca el id maximo y lo incrementa en uno al retornarlo
 * \param LinkedList* pArrayLibros puntero al array de empleados.
 * \return retunr el id maximo incrementado en uno.
 */
//int Libros_lastId(LinkedList* pArrayLibros);


#endif /* LIBROS_H_ */
