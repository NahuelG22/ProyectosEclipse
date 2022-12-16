/*
 ============================================================================
 Name        : PrimerParcialLaboratorio.c
 Author      : Nahuel Gimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Libros.h"
#include "Inputs.h"
#define SIZE 5
#define TAM 10
#define CANTIDAD 100

int main(void)
{
	setbuf(stdout, NULL);

	sEditorial editoriales[SIZE]={{1, "Ivrea"}, {2, "Debolsillo"}, {3, "Salamandra"}, {4, "Nova"}, {5, "Alfaguara"}};
	ePais paises[SIZE]={{1, "Argentina"},{2, "Estados Unidos"},{3, "Inglaterra"},{4, "Colombia"},{5, "Chile"}};
	eAutor autores[TAM]={{1, "Julio Verne", 1}, {2, "Frank Herbert", 2}, {3, "Julio Cortazar", 1}, {4, "Stephen King", 2}, {5, "Luis Borges", 1},
	{6, "Edgar Allan Poe", 3},{7, "Garcia Marquez", 4},{8, "Joanne Rowling", 3},{9, "Pablo Neruda", 5},{10, "Dan Simmons", 2}};
	eGenero generos[SIZE]={{1, "Narrativo"}, {2, "Lirico"}, {3, "Dramatico"}, {4, "Didactico"}, {5, "Novela"}};
	eLibro libros[CANTIDAD];
	int opcion=0;
	int retorno;
	int contador=0;
	int codigoLibro=1;

	inicializarListaLibros(libros, 100);

	do
	{
		opcion=getNumberInt("1. Alta\n2. Modificar\n3. Baja\n4. Informar\n5. Listar\n6. Salir\n\nIngresar: ", "Opcion no valida, reingresar\n", 1, 6);
		switch(opcion)
		{
			case 1:
				if(altaLibro(libros, CANTIDAD, codigoLibro, autores, paises, editoriales, generos)==1)
				{
					printf("\nLibro ingresado correctamente\n\n");
					codigoLibro++;
					contador++;
				}
				else
				{
					printf("\nNo se puede ingresar el libro\n\n");
				}
			break;
			case 2:
				if(contador>0)
				{
					retorno=modificarLibro(libros, CANTIDAD, autores, TAM, editoriales, SIZE, paises, generos);
				}
				else
				{
					printf("\nNo se ingreso ningun libro\n");
				}
			break;
			case 3:
				if(contador>0)
				{
					mostrarAltaLibro(libros, CANTIDAD, autores, TAM, editoriales, SIZE, generos, SIZE);
					retorno=bajaLibro(libros, CANTIDAD);
					switch(retorno)
					{
						case 0:
							printf("\n\nNo se pudo encontrar el libro.\n");
						break;
						case 1:
							printf("\nEl libro se dio de baja con exito.\n");
							contador--;
						break;
					}
				}
				else
				{
					printf("\nNo se ingreso ningun libro\n");
				}
			break;
			case 4:
				if(contador>0)
				{
					retorno=getChar("\nIngrese que desea informar:\na. Total y promedio de los importes, y los libros que lo superan\nb. Cantidad de libros del siglo pasado\n\nInformar: ");
					switch(retorno)
					{
						case 'a':
							mostrarPromedioYTotalImportes(libros, CANTIDAD);
						break;
						case 'b':
							listarLibrosPorFecha(libros, CANTIDAD);
						break;
						default:
							printf("\nOpcion invalida\n");
						break;
					}
				}
				else
				{
					printf("\nNo se ingreso ningun libro\n");
				}
			break;
			case 5:
				retorno=getChar("\nIngrese que desea listar:\na. Todas las editoriales\nb. Todos los paises\nc. Todos los autores\nd. Todos los libros\ne. Listados ordenados por criterio\nf. Todos los generos\ng. Los libros que no son novelas\n\nListar: ");
				switch(retorno)
				{
					case 'a':
						mostrarEditoriales(editoriales, SIZE);
					break;
					case 'b':
						mostrarPaises(paises, SIZE);
					break;
					case 'c':
						mostrarAutores(autores, TAM, paises, SIZE);
					break;
					case 'd':
						if(contador>0)
						{
							mostrarAltaLibro(libros, CANTIDAD, autores, TAM, editoriales, SIZE, generos, SIZE);
						}
						else
						{
							printf("\nNo se ingresaron libros\n");
						}
					break;
					case 'e':
						if(contador>0)
						{
							listarLibrosOrdenadosPorCriterios(libros, CANTIDAD, autores, editoriales, generos);
						}
						else
						{
							printf("\nNo se ingresaron libros\n");
						}
					break;
					case 'f':
						mostrarGeneros(generos, SIZE);
					break;
					case 'g':
						mostrarLibrosNoSonNovelas(libros, CANTIDAD, generos, SIZE, autores, TAM, editoriales, SIZE);
					break;
					case 'h':
					    mostrarLibroDeEditorialDeterminada(libros, CANTIDAD, autores, TAM, editoriales, SIZE, paises, generos, SIZE);
					break;
					default:
						printf("\nOpcion invalida.\n");
					break;
				}
			break;
		}
	}while(opcion!=6);

	printf("\nPrograma finalizado.");


	return EXIT_SUCCESS;
}
