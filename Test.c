#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"
#include "alumno.h"

/* Anotaciones
 * ~ Clase 9
 * 00:17: Si no existieran las estructuras, se usarian arrays
 * 22:30: Defincion de estructuras
 * 25:00: Asignacion de strutc
 * 37:00: Declaracion
 * 38:25: 1er modo de declaracion
 * 40:15: acceder/escribir a una posicion(int,cadenas)
 * 44:38: usando sprintf para cadenas
 * 46:05: llamar el array de estructuras desde otra funcion
 * 51:00: estructuras dentro de estructuras (ej:fechas)
 * 57:50: 2do modo de declaracion (typedef)
 * 1:00:00: las entidades van en mayuscula
 * 1:01:30: tema de los colores
 * 1:07:30: modo mas compacto del 2do modo
 *
 * Coreccion: 1:34:50 - 2:13:10
 * https://drive.google.com/file/d/1Qh-gcIQQndfpvIT-D8rqRlXw4AVnuuRE/edit
 *
 * 2:38:40: inicia menu con alta y imprimir array
 * 2:44:05: agrega indice a la funcion alta
 * 2:47:08: crea funcion Alta
 * 2:53:00: & en el array (por que es un int) error frecuente
 * 2:58:50: +3 ifs anidados puede ser complicado
 * 2:59:30: concatenar las preguntas &&
 * 3:02:50: implementacion correcta de asignacion de  datos
 * 3:04:10: explicacion de & en int y sin & para strings
 * 3:06:00: asignacion en ultima linea (junto al indice)
 *
 * 3:07:40: crea funcion Imprimir
 * 3:12:50: variables para imprimir (modo disney y modo elegante)
 * 3:20:20: inicializar el array de estructuras (TRUE o FALSE)
 * 3:22:30: crea funcion inicializar
 * 3:27:45: campo isEmpty
 * 3:30:15: cuando la llama la funcion alta, se le asigna FALSE
 * 3:33:00: implementa el init en el for de imprimir
 * 3:38:20: organizar en bibliotecas
 * 3:41:30: nombre de funciones abreviadas
 * 3:53:20: isEmpty para cargar dato en alta
 */

/* Declaracion de Estructuras:
 * 1 - Hacer un .c y un .h
 * En el .h vamos a declararlo y en el .c todo el desarrollo o
 * funciones que procecen es tipo de dato.
 *
 * typedef:
 * Redefinir tipos de datos que ya existen.
 * Ejemplo:
 * typedef int juan
 * juan auxiliar;
 *
 */

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
			alumno_ordenarPorNombre(arrayAlumnos,QTY_ALUMNOS);
			break;
		case 5:
			alumno_imprimir(arrayAlumnos,QTY_ALUMNOS);
			break;
		}
	}while(op != 6);
	return EXIT_SUCCESS;
}



