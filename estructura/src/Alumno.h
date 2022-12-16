#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int legajo;
	char nombre[20];
	float promedio;
	int estado;
	int nota1;
	int nota2;
	int idCurso;
}eAlumno;

typedef struct
{
	int idCurso;
	char descripcion[20];
	int duracion;
}eCurso;

typedef struct
{
	int id;
	int contador;
}eAuxiliar;

eAlumno PedirUnAlumno(eCurso[], int sizeCursos);
void MostrarCursos(eCurso[], int sizeCursos);
int BuscarEspacioLibre(eAlumno listaAlumnos[], int sizeAlumnos);
void MostrarUnAlumno(eAlumno miAlumno);//POR VALOR
int CargarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos);//POR REFERENCIA
void MostrarListaDeAlumnos(eAlumno listaAlumnos[], int sizeAlumnos);
void OrdenarListaDeAlumnosPorNombre(eAlumno listaAlumnos[], int sizeAlumnos);
void ListarAlumnoPorPromedio(eAlumno listaAlumnos[], int sizeAlumnos);
void ListarAlumnosAprobados(eAlumno listaAlumnos[], int sizeAlumnos);
void InicializarListaAlumnos(eAlumno listaAlumnos[]);
int ModificarAlumno(eAlumno listaAlumnos[], int sizeAlumnos);
int EliminarAlumno(eAlumno listaAlumnos[], int sizeAlumnos);

