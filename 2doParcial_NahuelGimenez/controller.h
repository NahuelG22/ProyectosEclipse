/*
 * controller.h
 *
 *  Created on: 23 nov 2022
 *      Author: alumno
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListalibros);
int controller_ListLibros(LinkedList* pArrayListLibros);
int controller_sort(LinkedList* pArrayListLibros);
int controller_saveAsText(char* path , LinkedList* pArrayListLibros);

#endif /* CONTROLLER_H_ */
