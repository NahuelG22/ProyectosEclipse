#include <stdlib.h>
#include "Alumno.h"
#define T 10

//LiSTADO ALUMNOS APROBADOS ORDENADO POR PROMEDIO DE MAYOR A MENOR
//ANTE IGUALDAD DE PROMEDIO ORDENAR ALFABETICAMENTE
int main(void) {
	setbuf(stdout, NULL);

	eAlumno listaAlumnos[T];
	eCurso listaCursos[3]={{1, "Javascript",5},{2, "Phyton",8},{3,"Angular", 7}};
	eAuxiliar auxiliar[3];
	int opcion;
	int retorno;
	int contadorTotal;
	int contadorPorCurso;
	float porcentaje;
	int maximo;

	contadorTotal=0;

	for(int i=0; i<T; i++)
	{
		listaAlumnos[i].estado=LIBRE;
	}

	InicializarListaAlumnos(listaAlumnos);

	do
	{
		printf("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Lista de alumnos aprobados\n5Lista de promedios\n6.Modificaciones\n7.Bajas\n10.Salir\nElija una opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				retorno=CargarListaDeAlumnos(listaAlumnos, T);
				switch(retorno)
				{
					case -1:
						printf("\nNo hay mas espacio\n");
					break;
					default:
						printf("\nSe cargo exitosamente al alumno\n");
					break;
				}
			break;
			case 2:
				MostrarListaDeAlumnos(listaAlumnos, T);
			break;
			case 3:
				OrdenarListaDeAlumnosPorNombre(listaAlumnos, T);
			break;
			case 4:
				ListarAlumnosAprobados(listaAlumnos, T);
			break;
			case 5:
				ListarAlumnoPorPromedio(listaAlumnos, T);
			break;
			case 6:
				retorno=ModificarAlumno(listaAlumnos, T);
				switch(retorno)
				{
					case -1:
						printf("\nNo se encontro el legajo\n");
					break;
					default:
						printf("\nAlumno modificado\n");
					break;
				}//hacer funcion para no repetir el switch
			break;
			case 7:
				retorno=EliminarAlumno(listaAlumnos, T);
				switch(retorno)
				{
					case -1:
						printf("\nNo se encontro el legajo\n");
					break;
					default:
						printf("\nAlumno eliminado\n");
					break;
				}//hacer funcion para no repetir el switch
			break;
			case 8:
				for(int i=0;i<T;i++)
				{
					for(int j=0; j<3; j++)
					{
						if(listaAlumnos[i]. estado == OCUPADO && listaAlumnos[i].idCurso==listaCursos[j].idCurso)
						{
							printf("%4d %10s %2.2f %10s\n", listaAlumnos[i].legajo,listaAlumnos[i].nombre, listaAlumnos[i].promedio, listaCursos[j].descripcion);
						}
					}
				}
			break;
			case 9:
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<T; j++)
					{
						if(listaAlumnos[j].estado==OCUPADO && listaCursos[i].idCurso)//PK==FK
						{
							printf("%10s %4d %10s", listaCursos[i].descripcion, listaAlumnos[j].nombre);
						}
					}
				}
			break;
			case 10:
			for(int i=0; i<T; i++)
			{
				if(listaAlumnos[i].estado==OCUPADO)
				{
					contadorTotal++;
				}
			}

			for(int i=0; i<3; i++)
			{
				contadorPorCurso=0;
				for(int j=0; j<T; j++)
				{
					if(listaAlumnos[j].estado==OCUPADO && listaCursos[i].idCurso==listaAlumnos[j].idCurso)
			  		{
			  			contadorPorCurso++;
			  		}
				}
				porcentaje=(float)(contadorPorCurso*100)/contadorTotal;
				printf("%s: %f%%", listaCursos[i].descripcion, porcentaje);
			}
			break;
			case 11:
				for(int i=0; i<3; i++)
				{
					auxiliar[i].id=listaCursos[i].idCurso;
					auxiliar[i].contador=0;
				}
				for(int i=0; i<3; i++)
				{
					for(int j=0; j<T; j++)
					{
						if(listaAlumnos[j].estado==OCUPADO && listaCursos[i].idCurso==listaAlumnos[j].idCurso)
						{
							auxiliar[i].contador++;
						}
					}
				}
				for(int i=0; i<3; i++)
				{
					if(i==0 || auxiliar[i].contador>maximo)
					{
						maximo=auxiliar[i].contador;
					}
				}

				for(int i=0; i<3; i++)
				{
					if(auxiliar[i].contador==maximo)
					{
						printf("%s\n", listaCursos[i].descripcion);
					}
				}
//				for(int i=0; i<3; i++)
//				{
//					printf("%d %d\n", auxiliar[i].id, auxiliar[i].contador);
//				}

			break;
		}
	}while(opcion!=15);

	return EXIT_SUCCESS;
}
