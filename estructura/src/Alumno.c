#include <string.h>
#include "Alumno.h"

void InicializarListaAlumnos(eAlumno listaAlumnos[])
{
	eAlumno auxiliar[]={{10,"Pedro",7.5,3, OCUPADO},{99, "Ana", 9,1, OCUPADO},{14,"Luis",5,3, OCUPADO}, {25, "Mariano", 9.5,1, OCUPADO}, {33, "Ezequiel", 8,2, OCUPADO}};
	for(int i=0; i<5; i++)
	{
		listaAlumnos[i]=auxiliar[i];
	}
}

void MostrarCursos(eCurso listaCursos[], int sizeCursos)
{
	for(int i=0; i<sizeCursos; i++)
	{
		printf("%d - %10s\n", listaCursos[i].idCurso, listaCursos[i].descripcion);
	}
}

eAlumno PedirUnAlumno()
{
	eAlumno miAlumno;

	printf("Ingrese el legajo: ");
	scanf("%d", &miAlumno.legajo);
	printf("Ingrese el nombre: ");
	fflush(stdin);
	gets(miAlumno.nombre);//scanf("%[^\n]", miAlumno.nombre); ... fgets
	printf("Ingrese el promedio: ");
	scanf("%f", &miAlumno.promedio);

	printf("Selecione el curso: ");
	scanf("%d", &miAlumno.idCurso);

	return miAlumno;
}

void MostrarUnAlumno(eAlumno miAlumno)
{

	printf("%4d %10s %4.2f\n", miAlumno.legajo, miAlumno.nombre, miAlumno.promedio);
}

int BuscarEspacioLibre(eAlumno listaAlumnos[], int sizeAlumnos)
{
	int index;

	index=-1;

	for(int i=0; i<sizeAlumnos; i++)
	{
		if(listaAlumnos[i].estado==LIBRE)
		{
			index=i;
			break;
		}
	}

	return index;
}

int CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos)
{
	int index;

	index=BuscarEspacioLibre(listaAlumnos, sizeAlumnos);

	if(index!=-1)
	{
		listaAlumnos[index]=PedirUnAlumno();
	}

	return index;
}

void MostrarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos)
{
	for(int i=0; i<sizeAlumnos; i++)
	{
		if(listaAlumnos[i].estado==OCUPADO)
		{
			MostrarUnAlumno(listaAlumnos[i]);
		}
	}

}

void OrdenarListaDeAlumnosPorNombre(eAlumno listaAlumnos[], int sizeAlumnos)
{
	eAlumno auxiliarAlumno;
	for(int i = 0; i < sizeAlumnos-1; i++)
	{
		for(int j = i+1; j<sizeAlumnos; j++)
		{
			if(strcmp(listaAlumnos[i].nombre,listaAlumnos[j].nombre)<0)
			{
				auxiliarAlumno = listaAlumnos[i];
				listaAlumnos[i] = listaAlumnos[j];
				listaAlumnos[j] = auxiliarAlumno;
			}
		}
	}
}

int ModificarAlumno(eAlumno listaAlumnos[], int sizeAlumnos)
{
	int legajo;
	int modifico;
	int i;
	i=0;
	modifico=-1;//No existe el legajo
	MostrarListaDeAlumnos(listaAlumnos[i].legajo);
	printf("Ingrese el legajo a modificar: ");
	scanf("%d", &legajo);

	for(int i=0; i<sizeAlumnos; i++)
	{
		if(listaAlumnos[i].estado==OCUPADO && listaAlumnos[i].legajo==legajo)
		{
			printf("Ingrese el nuevo promedio");
			scanf("%f", &listaAlumnos[i].promedio);
			modifico=1;
			break;
		}
	}

	return modifico;
}

int EliminarAlumno(eAlumno listaAlumnos[], int sizeAlumnos)
{
	int legajo;
	int elimino;
	elimino=-1;//No existe el legajo
	printf("Ingrese el legajo a modificar: ");
	scanf("%d", &legajo);

	for(int i=0; i<sizeAlumnos; i++)
	{
		if(listaAlumnos[i].estado==OCUPADO && listaAlumnos[i].legajo==legajo)
		{
			listaAlumnos[i].estado=LIBRE;
			elimino=1;
			break;
		}
	}

	return elimino;
}

void ListarAlumnosAprobados(eAlumno listaAlumnos[], int sizeAlumnos)
{
	for(int i=0; i<sizeAlumnos; i++)
	{
		if(listaAlumnos[i].promedio>6)
		{
			MostrarUnAlumno(listaAlumnos[i]);
		}
	}
}

void ListarAlumnoPorPromedio(eAlumno listaAlumnos[], int sizeAlumnos)
{
	eAlumno auxiliarAlumno;
	for(int i=0; i<sizeAlumnos-1; i++)
	{
		for(int j=i+1; j<sizeAlumnos; j++)
		{
			if(listaAlumnos[i].promedio<listaAlumnos[j].promedio)
			{
				auxiliarAlumno = listaAlumnos[i];
				listaAlumnos[i] = listaAlumnos[j];
				listaAlumnos[j] = auxiliarAlumno;
			}
			else
			{
				if(listaAlumnos[i].promedio==listaAlumnos[j].promedio)
				{
					if(strcmp(listaAlumnos[i].nombre, listaAlumnos[j].nombre)>0)
					{
						auxiliarAlumno = listaAlumnos[i];
						listaAlumnos[i] = listaAlumnos[j];
						listaAlumnos[j] = auxiliarAlumno;
					}
				}
			}
		}
	}
}
