#include "Productos.h"

void InicializarProductos(eProducto lista[], int size) {
	for(int i=0 ; i<size ; i++) {
		lista[i].isEmpty= LIBRE;
	}
}

int BuscarEspacioLibre(eProducto lista[], int size) {
	int retorno= -1;

	for(int i=0 ; i<size ; i++) {
		if(lista[i].isEmpty == LIBRE) {
			retorno= i;
			break;
		}
	}

	return retorno;
}

int CargarProducto(eProducto lista[], int size, int id) {
	int auxiliar;

	auxiliar= BuscarEspacioLibre(lista, size);
	if(auxiliar != -1) {
		lista[auxiliar]= PedirDatosProducto(id);
		lista[auxiliar].isEmpty= OCUPADO;
	}

	return auxiliar;
}

eProducto PedirDatosProducto(int id) {
	eProducto unProducto;

	unProducto.idProducto= id;
	getString("\nIngrese la descripcion del producto: ", unProducto.descripcion);
	unProducto.nacionalidad= getNumberInt("\n1. EEUU\n2. CHINA\n3. OTRO\nIngrese la nacionalidad: ", "Error!!! La nacionalidad ingresada es incorrecta...", 1, 3);
	unProducto.tipoProducto= getNumberInt("\n1. IPHONE\n2. MAC\n3. IPAD\n4. ACCESORIOS\nIngrese el tipo de producto: ", "Error!!! El tipo de producto ingresado es incorrecta...", 1, 4);
	unProducto.precio= getNumberFloat("\nIngrese el precio del producto: ", "Error!!! El precio ingresado es incorrecto...", 1, 100000);

	return unProducto;
}

void ListarUnProducto(eProducto unProducto) {
	//------------------------
	printf("%4d | %-20s | %.2f |", unProducto.idProducto, unProducto.descripcion, unProducto.precio);
	//------------------------
	if(unProducto.nacionalidad == 1) {
		printf(" EEUU  |");
	}
	else {
		if(unProducto.nacionalidad == 2) {
			printf(" CHINA |");
		}
		else {
			printf(" OTRO  |");
		}
	}
	//------------------------
	if(unProducto.tipoProducto == 1) {
		printf(" IPHONE\n");
	}
	else {
		if(unProducto.tipoProducto == 2) {
			printf(" MAC\n");
		}
		else {
			if(unProducto.tipoProducto == 3) {
				printf(" IPAD\n");
			}
			else {
				printf(" ACCESORIOS\n");
			}
		}
	}
	//------------------------
}

void ListarProductos(eProducto lista[], int size) {
	printf("\n--------------------> LISTA PRODUCTOS <--------------------"
		   "\n___________________________________________________________\n\n");
	for(int i=0 ; i<size ; i++) {
		if(lista[i].isEmpty == OCUPADO) {
			ListarUnProducto(lista[i]);
		}
	}
	printf("___________________________________________________________\n\n");
}

int ModificarUnProducto(eProducto lista[], int size, int posicion) {
	int retorno= -1;
	int opcion;

	do{
		printf("\nMenu Modificar\n"
			   "1. Descripcion\n"
			   "2. Nacionalidad\n"
			   "3. Tipo producto\n"
			   "4. Precio\n"
			   "5. Salir\n");
		opcion= getNumberInt("Ingrese una opcion: ", "\nError!!! La opcion ingresada es incorrecta", 1, 5);

		switch(opcion) {
			case 1:
				getString("\nIngrese la descripcion del producto: ", lista[posicion].descripcion);
				retorno= 0;
				break;
			case 2:
				lista[posicion].nacionalidad= getNumberInt("\n1. EEUU\n2. CHINA\n3. OTRO\nIngrese la nacionalidad: ", "Error!!! La nacionalidad ingresada es incorrecta...", 1, 3);
				retorno= 0;
				break;
			case 3:
				lista[posicion].tipoProducto= getNumberInt("\n1. IPHONE\n2. MAC\n3. IPAD\n4. ACCESORIOS\nIngrese el tipo de producto: ", "Error!!! El tipo de producto ingresado es incorrecta...", 1, 4);
				retorno= 0;
				break;
			case 4:
				lista[posicion].precio= getNumberFloat("\nIngrese el precio del producto: ", "Error!!! El precio ingresado es incorrecto...", 1, 100000);
				retorno= 0;
				break;
			default:
				printf("\nSaliendo del SubMenu Modificar...");
				break;
		}
	}while(opcion != 5);

	return retorno;
}

//void listadoOrdenadoPorPrecio (eProducto lista[], int size)
//{
//	eProducto aux;
//	for(int i; i<size-1; i++)
//	{
//		for(int j=0; j<size; j++)
//		{
//			if(lista[j].precio<lista[i].precio)
//			{
//				aux=lista[i];
//				lista[i]=lista[j];
//				lista[j]=aux;
//			}
//		}
//	}
//}

void mostrarListaProductosPorPrecio(eProducto lista[], int size)
{
	eProducto aux;

	for(int i=0; i<size-1; i++)
	{
		for(int j=i+1; j<size ;j++)
		{
			if(lista[i].precio < lista[j].precio)
			{
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	}
	for(int i=0; i<size; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				mostrarUnProducto(lista[i]);
			}
		}
}

void MostrarListadoPorDescripcion(eProducto lista[], int size)
{
	eProducto aux;
	for(int i=0; i<size-1; i++)
	{
		for(int j=0; i<size; j++)
		{
			if(strcmp(lista[i]<lista[j])==1)
			{
				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;
			}
		}
	}
}

