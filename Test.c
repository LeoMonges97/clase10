#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"
#include "alumno.h"

int main(void)
{
	int op;
	//int indiceVacio;
	//int idModificar;
	int indiceModificar;
	Alumno arrayAlumnos[QTY_ALUMNOS];

	alumno_initArray(arrayAlumnos,QTY_ALUMNOS);
	do
	{
		utn_getInt("\n **************************\n ABM Generico\n\n 1 - Alta\n 2 - Modificacion\n 3 - Baja\n 4 - Ordenar\n 5 - Imprimir\n 6 - Salir\n\n ~ Ingrese opcion: ",
				" > Error!\n",&op,2,6,1);
		switch(op)
		{
		case 1:
			if(alumno_alta(arrayAlumnos,QTY_ALUMNOS) == 0)
			{
				printf("\n Datos cargados correctamente!\n");
			}
			else
			{
				printf(" > Error!\n");
			}
			//Buscar por indice en main:
			/*if(alumno_buscarLibreRef(arrayAlumnos, QTY_ALUMNOS, &indiceVacio)==0)
				{
					alumno_altaConIndice(arrayAlumnos, QTY_ALUMNOS, indiceVacio);
				}*/
			break;
		case 2:
			if(alumno_modificar(arrayAlumnos,QTY_ALUMNOS) == 0)
			{
				printf("\n Datos modificados correctamente!\n");
			}
			else
			{
				printf(" > Error!\n");
			}
			// MODIFICAR POR ID
			/*if(utn_getInt(" . Ingrese el ID a modificar:","e!",&idModificar,5,1000,1)==0)
			{
				if(alumno_buscarId(arrayAlumnos, QTY_ALUMNOS, &indice, idModificar)==0)
				{
					alumno_modificar(arrayAlumnos,QTY_ALUMNOS,indice);
				}
			}*/
			break;
		case 3:
			if(alumno_baja(arrayAlumnos,QTY_ALUMNOS,indiceModificar) == 0)
			{
				printf("\n Baja realizada correctamente!\n");
			}
			else
			{
				printf(" > Error!\n");
			}
			break;
		case 4:
                        printf("me falta");
			//alumno_ordenarPorNombre(arrayAlumnos,QTY_ALUMNOS);
			break;
		case 5:
			alumno_imprimir(arrayAlumnos,QTY_ALUMNOS);
			break;
		}
	}while(op != 6);
	return EXIT_SUCCESS;
}



