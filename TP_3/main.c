#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Inputs.h"

int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int banderaTexto=0;
    int banderaBinario=0;
    LinkedList* listaJugadores = ll_newLinkedList();
    int retorno;
    do{
    	option=getNumberInt("Menu principal\n1.Carga de archivos\n2.Alta de jugador\3.Modificacion de jugador\n4.Baja de jugador\n5.Listados\n6.Convocatoria"
    			"\n7.Ordenar y listar\n8.Generar archivo binario\n9.Cargar archivo binario\n10.Guardar archivos\11.Salir\nIngresar: ",
    			"\nOpcion invalida\n", 1, 11);
        switch(option)
        {
            case 1:
            	if(ll_isEmpty(listaJugadores) || (banderaTexto==0 && banderaBinario==0))
            	{
            		retorno=controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
            		if(retorno==1)
            		{
            			printf("\nSe leyeron los archivos correctamente.");
            		}
            		else
            		{
            			printf("\nNo se pudo leer.");
            		}
            	}

                break;
            case 2:
            	retorno=controller_agregarJugador(listaJugadores);
            	if(retorno==1)
            	{
            		printf("\nSe dio de alta al jugador con exito.");
            	}
            	break;
            case 3:
            	if(!ll_isEmpty(listaJugadores))
            	{
            		retorno=controller_editarJugador(listaJugadores);
            	}
            	break;
            case 4:
            	if(!ll_isEmpty(listaJugadores))
            	{
            		retorno=controller_removerJugador(listaJugadores);
            	}
            	break;
            case 5:

            	break;
            case 6:

            	break;
            case 7:

            	break;
            case 8:

            	break;
            case 9:

            	break;
            case 10:

            	break;
            case 11:
            	retorno=getChar("\n¿Seguro que desea salir? s para si, n para no\n");
				if(retorno=='s')
				{
				   option=0;
				}
            	break;
        }
    }while(option != 11);

    return 0;
}

