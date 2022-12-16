/*
 * Libros.c
 *
 *  Created on: 1 oct. 2022
 *      Author: Nahuel A
 */

#include "Libros.h"


void inicializarListaLibros(eLibro listaLibros[], int size)
{
	for(int i=0; i<size; i++)
	{
		listaLibros[i].estado=LIBRE;
	}
}

int buscarEspacioLibre(eLibro listaLibros[], int size)
{
	int index;

	index=-1;

	for(int i=0; i<size; i++)
	{
		if(listaLibros[i].estado==LIBRE)
		{
			index=i;
			break;
		}
	}

	return index;
}

eLibro cargarLibro(int codigoLibro, eAutor autores[], ePais paises[], sEditorial editoriales[], eGenero generos[])
{
	eLibro libro;

	libro.codigoLibro=codigoLibro;
	GetString(libro.titulo, 51, "\nIngrese el titulo del libro: ");
	libro.fecha.dia=getNumberInt("\nIngrese el dia en el que se publico el libro: ", "Dia invalido", 1, 31);
	libro.fecha.mes=getNumberInt("\nIngrese el mes en el que se publico el libro: ", "Mes invalido", 1, 12);
	libro.fecha.anio=getNumberInt("\nIngrese el año en el que se publico el libro: ", "Año invalido", 1950, 2022);
	libro.importe=getNumberFloat("\nIngrese el importe: ", "Importe invalido", 1000, 20000);
	mostrarAutores(autores, 10, paises, 5);
	libro.autor=getNumberInt("\nSeleccione el ID del autor: \n", "\nID invalido\n", 1, 10);
	mostrarEditoriales(editoriales, 5);
	libro.editorial=getNumberInt("\nSeleccione el codigo de la editorial: \n", "\nCodigo invalido\n", 1, 5);
	mostrarGeneros(generos, 5);
	libro.genero=getNumberInt("\nSeleccione el codigo del genero: \n", "\nCodigo invalido\n", 1, 5);

	return libro;
}

int altaLibro(eLibro listaLibros[], int size, int codigoLibro, eAutor autores[], ePais paises[], sEditorial editoriales[], eGenero generos[])
{
	int index;
	int retorno;

	retorno=0;

	index=buscarEspacioLibre(listaLibros, size);

	if(index!=-1)
	{
		listaLibros[index]=CargarLibro(codigoLibro, autores, paises, editoriales, generos);
		listaLibros[index].estado=OCUPADO;
		mostrarAltaLibro(listaLibros, size, autores, 10, editoriales, 5, generos, 5);
		retorno=1;
	}
	else
	{
		printf("\nNo hay espacio libre para mas libros.");
	}

	return retorno;
}

void mostrarAltaLibro(eLibro listaLibros[], int size, eAutor autores[], int sizeAutores, sEditorial editoriales[], int sizeEditoriales, eGenero generos[], int sizeGeneros)
{
	int anchoFecha=-14;
	printf("+---------------+--------------------------------------------------+--------------------+--------------------+--------------------+---------------+---------------+\n");
	printf("|%-15s|%-50s|%-20s|%-20s|%-20s|%-15s|%-15s|\n", "ID del libro", "Titulo", "Fecha de publicacion", "Importe", "Autor", "Editorial", "Genero");
	printf("+---------------+--------------------------------------------------+--------------------+--------------------+--------------------+---------------+---------------+\n");
	int i;
	int j;
	int k;
	int x;

	for(i=0; i<size; i++)
	{
		for(j=0; j<sizeAutores; j++)
		{
			for(k=0; k<sizeEditoriales; k++)
			{
				for(x=0; x<sizeGeneros; x++)
				{
					if(listaLibros[i].estado==OCUPADO && listaLibros[i].autor==autores[j].codigoAutor && listaLibros[i].editorial==editoriales[k].codigoEditorial && listaLibros[i].genero==generos[x].codigoGenero)
					{
						printf("|%-15d|%-50s|%02d/%02d/%*d|%-20.2f|%-20s|%-15s|%-15s|\n", listaLibros[i].codigoLibro, listaLibros[i].titulo,
								listaLibros[i].fecha.dia, listaLibros[i].fecha.mes, anchoFecha, listaLibros[i].fecha.anio,
								listaLibros[i].importe, autores[j].nombreAutor, editoriales[k].descripcion, generos[x].descripcion);
					}
				}
			}
		}
	}
	printf("+---------------+--------------------------------------------------+--------------------+--------------------+--------------------+---------------+---------------+\n");
}

void mostrarAutores(eAutor autores[], int size, ePais paises[],int sizePaises)
{
	printf("\nID autor\tNombre\t\t\tPais");

	for(int i=0; i<size; i++)
	{
		for(int j=0; j<sizePaises; j++)
		{
			if(autores[i].codigoPais==paises[j].codigoPais)
			{
				printf("\n\t%d\t%s\t\t%s", autores[i].codigoAutor, autores[i].nombreAutor, paises[j].descripcion);
			}
		}
	}
	printf("\n\n");
}

void mostrarEditoriales(sEditorial editoriales[], int size)
{
	printf("\nCodigo de editorial\tNombre de editorial");
	for(int i=0; i<size; i++)
	{
		printf("\n\t%d\t\t%s", editoriales[i].codigoEditorial, editoriales[i].descripcion);
	}
	printf("\n\n");
}

void mostrarPaises(ePais paises[], int size)
{
    printf("\nCodigo de pais\tPais");
    for(int i=0; i<size; i++)
    {
        printf("\n\t%d\t%s", paises[i].codigoPais, paises[i].descripcion);
    }
    printf("\n\n");
}

void mostrarGeneros(eGenero generos[], int size)
{
	int i;
	printf("\nCodigo del genero\tDescripcion");
	for(i=0; i<size; i++)
	{
		printf("\n\t%d\t%s", generos[i].codigoGenero, generos[i].descripcion);
	}
	printf("\n\n");
}


void mostrarLibrosNoSonNovelas(eLibro libros[], int size, eGenero generos[], int sizeGeneros, eAutor autores[], int sizeAutores, sEditorial editoriales[], int sizeEditoriales)
{
	int i;
	int j;
	int k;
	int x;
	printf("\nLibros que no son novelas: \n");
	printf("%-15s%-50s%-20s\t%-20s%-20s%-15s-%-15s\n", "ID del libro", "Titulo", "Fecha de publicacion", "Importe", "Autor", "Editorial", "Genero");

	for(i=0; i<size; i++)
	{
		if(libros[i].estado==OCUPADO)
		{
			for(j=0; j<sizeAutores; j++)
			{
				if(libros[i].autor==autores[j].codigoAutor)
				{
					for(k=0; k<sizeEditoriales; k++)
					{
						if(libros[i].editorial==editoriales[k].codigoEditorial)
						{
							for(x=0; x<sizeGeneros; x++)
							{
								if(libros[i].genero!=5 && libros[i].genero==generos[x].codigoGenero)
								{
									printf("%-15d%-50s%02d/%02d/%d\t\t%-15.2f\t\t%-15s\t%-15s\t%-15s\n", libros[i].codigoLibro, libros[i].titulo,
														libros[i].fecha.dia, libros[i].fecha.mes, libros[i].fecha.anio,
														libros[i].importe, autores[j].nombreAutor, editoriales[k].descripcion, generos[x].descripcion);
								}
							}
						}
					}
				}
			}
		}
	}
}

void mostrarLibroDeEditorialDeterminada(eLibro libros[], int size, eAutor autores[], int sizeAutores, sEditorial editoriales[], int sizeEditoriales, ePais paises[], eGenero generos[], int sizeGeneros)
{
	int editorial;
	int i;
	int j;
	int k;
	int x;
	mostrarEditoriales(editoriales, sizeEditoriales);
	editorial=getNumberInt("\nIngrese el id de la editorial: ", "Error ID invalido", 1, 5);

	for(i=0; i<size; i++)
	{
		if(libros[i].estado==OCUPADO)
		{
			for(j=0; j<sizeAutores; j++)
			{
				if(autores[j].codigoPais==1)
				{
					for(k=0; k<sizeEditoriales; k++)
					{
						if(editorial==editoriales[k].codigoEditorial)
						{
							for(x=0; x<sizeGeneros; x++)
							{
								if(libros[i].genero!=5 && libros[i].genero==generos[x].codigoGenero)
								{
									printf("%-15d%-50s%02d/%02d/%d\t\t%-15.2f\t\t%-15s\t%-15s\t%-15s\n", libros[i].codigoLibro, libros[i].titulo,
														libros[i].fecha.dia, libros[i].fecha.mes, libros[i].fecha.anio,
														libros[i].importe, autores[j].nombreAutor, editoriales[k].descripcion, generos[x].descripcion);
								}
							}
						}
					}
				}
			}
		}
	 }
}

int modificarLibro(eLibro libros[], int size, eAutor autores[], int sizeAutores, sEditorial editoriales[], int sizeEditoriales, ePais paises[], eGenero generos[])
{
	int id;
	int modificacion;
	int opcion;
	int i;

	modificacion=-1;
	mostrarAltaLibro(libros, size, autores, sizeAutores, editoriales, sizeEditoriales , generos, 5);

	id=getInt("\nIngrese el codigo del libro a modificar: ");

	for(i=0; i<size; i++)
	{
		if(libros[i].estado==OCUPADO && libros[i].codigoLibro==id)
		{
			opcion=getInt("\n¿Que desea modificar?\n1-Titulo\n2-Fecha\n3-Importe\n4-Autor\n5-Editorial\n6-Genero\n\nIngresar: ");
			switch(opcion)
			{
				case 1:
					modificacion=modificarTitulo(libros, size, id);
					switch(modificacion)
                    {
                        case -1:
                        	printf("\nEl libro no existe, no se puede modificar.\n");
                    	break;
                        case 0:
                        	printf("\nOperacion cancelada.\n");
                    	break;
                        case 1:
                        	printf("\nEl titulo se modifico con exito.\n");
                    	break;
                    }
				break;
				case 2:
					modificacion=modificarFecha(libros, size, id);
					switch(modificacion)
                    {
                        case -1:
                        	printf("\nEl libro no existe, no se puede modificar.\n");
                    	break;
                        case 0:
                        	printf("\nOperacion cancelada.\n");
                    	break;
                        case 1:
                        	printf("\nLa fecha se modifico con exito.\n");
                    	break;
                    }
				break;
				case 3:
					modificacion=modificarImporte(libros, size, id);
					switch(modificacion)
                    {
                        case -1:
                        	printf("\nEl libro no existe, no se puede modificar.\n");
                    	break;
                        case 0:
                        	printf("\nOperacion cancelada.\n");
                    	break;
                        case 1:
                        	printf("\nEl importe se modifico con exito.\n");
                    	break;
                    }
				break;
				case 4:
				    modificacion=modificarAutor(libros, size, id, autores, paises);
				    switch(modificacion)
                    {
                        case -1:
                        	printf("\nEl libro no existe, no se puede modificar.\n");
                    	break;
                        case 0:
                        	printf("\nOperacion cancelada.\n");
                    	break;
                        case 1:
                        	printf("\nEl autor se modifico con exito.\n");
                    	break;
                    }
				break;
				case 5:
				    modificacion=modificarEditorial(libros, size, id, editoriales,  sizeEditoriales);
				    switch(modificacion)
                    {
                        case -1:
                        	printf("\nEl libro no existe, no se puede modificar.\n");
                    	break;
                        case 0:
                        	printf("\nOperacion cancelada.\n");
                    	break;
                        case 1:
                        	printf("\nLa editorial se modifico con exito.\n");
                    	break;
                    }
				break;
				case 6:
					modificacion=modificarGenero(libros, size, id, generos, 5);
					switch(modificacion)
					{
						case -1:
							printf("\nEl libro no existe, no se puede modificar.\n");
						break;
						case 0:
							printf("\nOperacion cancelada.\n");
						break;
						case 1:
							printf("\nEl genero se modifico con exito.\n");
						break;
					}
				break;
				default:
					printf("\nOpcion invalida\n");
				break;
			}
		}
	}

	return modificacion;
}

int modificarGenero(eLibro libros[], int size, int codigoLibro, eGenero generos[], int sizeGeneros)
{
	 int generoAModificar;
	 int generoModificado;
	 int indiceAModificar;
	 int confirmacion;
	 int retorno;
	 retorno = -1;

	 generoAModificar=codigoLibro;
	 indiceAModificar = buscarLibro(libros,100, generoAModificar);

	 if(indiceAModificar > -1)
	 {
	   mostrarGeneros(generos, sizeGeneros);
	   generoModificado=getNumberInt("\nSeleccione el codigo del genero: \n", "\nCodigo invalido\n", 1, 5);
	   retorno = 0;
	   confirmacion = getChar("\nLibro encontrado ¿Desea modificar el genero? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   libros[indiceAModificar].genero=generoModificado;
		   retorno = 1;
	   }
	}

	return retorno;
}

int modificarTitulo(eLibro libros[], int size, int codigoLibro)
{
	int tituloAModificar;
	char tituloModificado[51];
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;


	tituloAModificar=codigoLibro;
	indiceAModificar = buscarLibro(libros,100, tituloAModificar);

	if(indiceAModificar > -1)
	{
	   GetString(tituloModificado,51,"Ingrese el nuevo titulo: ");
	   retorno = 0;
	   confirmacion = getChar("\nLibro encontrado ¿Desea modificar el titulo? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   strcpy(libros[indiceAModificar].titulo,tituloModificado);
		   retorno = 1;
	   }
	}

	return retorno;
}

int modificarFecha(eLibro libros[], int size, int codigoLibro)
{
    int fechaAModificar;
	eLibro fechaModificada;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;

	fechaAModificar=codigoLibro;
	indiceAModificar = buscarLibro(libros,100, fechaAModificar);

	if(indiceAModificar > -1)
	{
	   fechaModificada.fecha.dia=getNumberInt("\nIngrese el dia en el que se publico el libro: ", "Dia invalido", 1, 31);
	   fechaModificada.fecha.mes=getNumberInt("\nIngrese el mes en el que se publico el libro: ", "Mes invalido", 1, 12);
	   fechaModificada.fecha.anio=getNumberInt("\nIngrese el año en el que se publico el libro: ", "Año invalido", 1950, 2022);
	   retorno = 0;
	   confirmacion = getChar("\nLibro encontrado ¿Desea modificar la fecha? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   libros[indiceAModificar].fecha=fechaModificada.fecha;
		   retorno = 1;
	   }
	}

	return retorno;
}

int modificarImporte(eLibro libros[], int size, int codigoLibro)
{
    int importeAModificar;
	float importeModificado;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;

	importeAModificar=codigoLibro;
	indiceAModificar = buscarLibro(libros, 100, importeAModificar);

	if(indiceAModificar > -1)
	{
	   importeModificado=getNumberFloat("\nIngrese el nuevo importe: ", "\nImporte invalido", 1000, 20000);
	   retorno = 0;
	   confirmacion = getChar("\nLibro encontrado ¿Desea modificar el importe? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   libros[indiceAModificar].importe=importeModificado;
		   retorno = 1;
	   }
	}

	return retorno;
}

int modificarAutor(eLibro libros[], int size, int codigoLibro, eAutor autores[], ePais paises[])
{
    int autorAModificar;
	int autorModificado;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;

	autorAModificar=codigoLibro;
	indiceAModificar = buscarLibro(libros,100, autorAModificar);

	if(indiceAModificar > -1)
	{
       mostrarAutores(autores, 10, paises, 5);
	   autorModificado=getNumberInt("\nSeleccione el ID del autor: \n", "\nID invalido\n", 1, 10);
	   retorno = 0;
	   confirmacion = getChar("\nLibro encontrado ¿Desea modificar el autor? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   libros[indiceAModificar].autor=autorModificado;
		   retorno = 1;
	   }
	}

	return retorno;
}

int modificarEditorial(eLibro libros[], int size, int codigoLibro, sEditorial editoriales[], int sizeEditoriales)
{
    int editorialAModificar;
	int editorialModificada;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1;

	editorialAModificar=codigoLibro;
	indiceAModificar = buscarLibro(libros,100, editorialAModificar);

	if(indiceAModificar > -1)
	{
       MostrarEditoriales(editoriales, sizeEditoriales);
	   editorialModificada=getNumberInt("\nSeleccione el ID de la editorial: \n", "\nID invalido\n", 1, 5);
	   retorno = 0;
	   confirmacion = getChar("\nLibro encontrado ¿Desea modificar la editorial? s para si, n para no\n");
	   if(confirmacion == 's')
	   {
		   libros[indiceAModificar].editorial=editorialModificada;
		   retorno = 1;
	   }
	}

	return retorno;
}

int bajaLibro(eLibro libros[], int size)
{
	int libroABorrar;
	int retorno;
	int indiceDelLibro;

	libroABorrar = getInt("\nIngrese el codigo del libro a borrar: ");
	indiceDelLibro = buscarLibro(libros, size, libroABorrar);

	retorno = 0;

	if(indiceDelLibro > -1)
	{
		libros[indiceDelLibro].estado=BAJA;
		retorno = 1;
	}

    return retorno;
}

int buscarLibro(eLibro libros[],int size,int variableAModificar)
{
	int indice;
	int i;
	indice = -1;

	for(i=0; i<size; i++)
    {
	   if(libros[i].estado==OCUPADO && libros[i].codigoLibro==variableAModificar)
	   {
		   indice = i;
		   break;
	   }
    }

	return indice;
}

void listarLibrosOrdenadosPorCriterios(eLibro libros[], int size, eAutor autores[], sEditorial editoriales[], eGenero generos[])
{
	eLibro aux;
	eLibro auxLibros[size];
	int i;
	int j;

	for(i=0; i<size; i++)
	{
		auxLibros[i]=libros[i];
	}

	for(i=0; i<size-1; i++)
	{
		for(j=i+1; j<size; j++)
		{
			if(auxLibros[i].importe<auxLibros[j].importe)
			{
				aux=auxLibros[i];
				auxLibros[i]=auxLibros[j];
				auxLibros[j]=aux;
			}
			else
			{
				if(auxLibros[i].importe==auxLibros[j].importe)
				{
					if(strcmp(auxLibros[i].titulo, auxLibros[j].titulo)>0)
					{
						aux=auxLibros[i];
						auxLibros[i]=auxLibros[j];
						auxLibros[j]=aux;
					}
				}
			}
		}
	}

	mostrarAltaLibro(auxLibros, 100, autores, 10, editoriales, 5, generos, 5);
}

void listarLibrosPorFecha(eLibro libros[], int size)
{
	printf("\nLibros del siglo pasado: \n%-15s%-50s%-20s\t%-20s%-20s%-15s\n", "ID del libro", "Titulo", "Fecha de publicacion", "Importe", "Autor", "Editorial");
    int i;
	for(i=0; i<size; i++)
    {
        if(libros[i].fecha.anio<2000 && libros[i].estado==OCUPADO)
        {
        	printf("%-15d%-50s%02d/%02d/%d\t\t%-15.2f\t\t%-15d\t%-15d\n", libros[i].codigoLibro, libros[i].titulo,
        						libros[i].fecha.dia, libros[i].fecha.mes, libros[i].fecha.anio,
        						libros[i].importe, libros[i].autor, libros[i].editorial);
        }
    }
}

int calcularPromedioImportes(eLibro libros[], int size)
{
	float acumulador=0;
	int contador=0;
	float promedio;
	int i;

	for(i=0; i<size; i++)
	{
		if(libros[i].estado==OCUPADO)
		{
			acumulador+=libros[i].importe;
			contador++;
		}
	}
	promedio=(float)acumulador/contador;

	printf("\nTotal de importes: %f\nPromedio de importes: %f\n", acumulador, promedio);

	return promedio;
}

void mostrarPromedioYTotalImportes(eLibro libros[], int size)
{
	int promedio;
	int i;
	promedio=calcularPromedioImportes(libros, size);

	printf("\nLibro/s que superan el promedio de importes: \n");
	printf("%-15s%-50s%-20s\t%-20s%-20s%-15s\n", "ID del libro", "Titulo", "Fecha de publicacion", "Importe", "Autor", "Editorial");

	for(i=0; i<size; i++)
	{
		if(libros[i].importe>promedio && libros[i].estado==OCUPADO)
		{
			printf("%-15d%-50s%02d/%02d/%d\t\t%-15.2f\t\t%-15d\t%-15d\n", libros[i].codigoLibro, libros[i].titulo,
					libros[i].fecha.dia, libros[i].fecha.mes, libros[i].fecha.anio,
					libros[i].importe, libros[i].autor, libros[i].editorial);
		}
	}
}
