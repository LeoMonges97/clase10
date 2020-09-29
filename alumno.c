/*
 * alumno.c
 *
 *  Created on: Sep 22, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "alumno.h"

static int generarIdNuevo(void);

/**
 * \brief Inicializa el array de alumnos
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_initArray(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			pArrayAlumnos[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Realiza el alta de un alumno solo si el indice que se busca corresponde en Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_alta(Alumno* pArrayAlumnos,int limite)
{
	int retorno = -1;
	int indice;
	Alumno bufferAlumno;

	if(	pArrayAlumnos != NULL && limite > 0)
	{
		if(alumno_buscarLibreRef(pArrayAlumnos, limite,&indice) == 0) // Busca un lugar libre
		{
			if(	utn_getInt("\n . Legajo: ","\n > Error!",&bufferAlumno.legajo,2,MAX_LEGAJO,MIN_LEGAJO) == 0 &&
					utn_getNombre("\n . Nombre: ","\n > Error!",bufferAlumno.nombre,2,LONG_NOMBRE) == 0)
			{
				//bufferAlumno.isEmpty = FALSE;
				bufferAlumno.id = generarIdNuevo();
				pArrayAlumnos[indice] = bufferAlumno;
				pArrayAlumnos[indice].isEmpty = FALSE;

				retorno = 0;
			}
			else
			{
				printf("\n Error en la carga de datos!\n");
			}
		}
		else
		{
			printf("\n Lo sentimos, no hay posiciones libres!\n");
		}
	}
	return retorno;
}

/**
 * \brief Realiza el alta de un alumno solo si el indice que le paso corresponde a un Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_altaConIndice(Alumno* pArrayAlumnos,int limite,int indice)
{
	int retorno = -1;
	Alumno bufferAlumno;

	if(	pArrayAlumnos != NULL && limite > 0 &&
			indice >=0 &&
			indice < limite &&
			pArrayAlumnos[indice].isEmpty == TRUE)
	{
		if(	utn_getInt("\nLegajo?","\nError",&bufferAlumno.legajo,2,MAX_LEGAJO,MIN_LEGAJO) == 0 &&
				utn_getNombre("\n Nombre?","\nError",bufferAlumno.nombre,2,LONG_NOMBRE) == 0)
		{
			//bufferAlumno.isEmpty = FALSE;
			bufferAlumno.id = generarIdNuevo();
			pArrayAlumnos[indice] = bufferAlumno;
			pArrayAlumnos[indice].isEmpty = FALSE;

			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Modifica los datos de un alumno solo si el indice corresponde a un NO Empty
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el alumno
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_modificar(Alumno* pArrayAlumnos,int limite)
{
	int retorno = -1;
	int indice;
	int idModificar;
	Alumno bufferAlumno;

	if(utn_getInt(" . Ingrese el ID a modificar:"," Error!", &idModificar,5,1000,1) == 0)
	{
		if(alumno_buscarId(pArrayAlumnos, limite, &indice, idModificar) == 0)
		{
			if(	pArrayAlumnos != NULL && limite > 0 && indice >= 0 && indice < limite &&
					pArrayAlumnos[indice].isEmpty == FALSE)
			{
				if(	utn_getInt("\n . Legajo: ","\nError",&bufferAlumno.legajo,2,MAX_LEGAJO,MIN_LEGAJO) == 0 &&
						utn_getNombre("\n . Nombre: ","\nError",bufferAlumno.nombre,2,LONG_NOMBRE) == 0)
				{
					//bufferAlumno.isEmpty = FALSE;
					bufferAlumno.id = pArrayAlumnos[indice].id; //generarIdNuevo(); // NOOOOOOOOO
					// Al entrar ne la funcion, no puede tocar el campo de id.
					// Es por eso que antes de que se modifiquen todos los campos,
					// le asigno nuevamente el id que ya traia.
					// Es el unico dato que puede cambiar nunca.
					// Si se modificara el id, se estaria llamando a eliminar
					// y daria de alta uno de nuevo.
					pArrayAlumnos[indice] = bufferAlumno;
					pArrayAlumnos[indice].isEmpty = FALSE;

					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int alumno_baja(Alumno* pArrayAlumnos,int limite,int indice)
{
	// Tipo de baja: Logica
	int retorno = -1;
	int idBajar;

	if(utn_getInt(" . Ingrese el ID a bajar:"," Error! ", &idBajar,2,1000,1) == 0)
	{
		if(alumno_buscarId(pArrayAlumnos, limite, &indice, idBajar) == 0)
		{
			if(	pArrayAlumnos != NULL && limite > 0 && indice >= 0 && indice < limite &&
					pArrayAlumnos[indice].isEmpty == FALSE)
			{
				pArrayAlumnos[indice].isEmpty = TRUE;
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Imprime los alumnos cargados
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int alumno_imprimir(Alumno* pArrayAlumnos, int limite)
{
	int retorno = -1;
	if(pArrayAlumnos != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(pArrayAlumnos[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - Legajo: %d - ID:%d",
						pArrayAlumnos[i].nombre,
						pArrayAlumnos[i].legajo,
						pArrayAlumnos[i].id);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int alumno_printById(Alumno* pArrayAlumnos, int limit, int index)
{
	int retorno = -1;

	if(pArrayAlumnos != NULL && limit > 0 && index < limit)
	{
		if(pArrayAlumnos[index].isEmpty == FALSE)
		{
			printf(" Nombre: %s - Legajo: %d\n\n",pArrayAlumnos[index].nombre, pArrayAlumnos[index].legajo);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * Como lo implemento?
 * int posicionLibre;
 * if(alumno_buscarLibre(alumno,QTY_ALUMNOS,&posicionLibre) == 0)
 * {
 *   posicionLibre -> alta
 * }
 */
int alumno_buscarLibreRef(Alumno* pArrayAlumnos, int limit, int *pIndex)
{
	int retornar = -1;
	if(pArrayAlumnos != NULL && pIndex != NULL && limit > 0)
	{
		for(int i = 0; i < limit; i++)
		{
			if(pArrayAlumnos[i].isEmpty == TRUE)
			{
				*pIndex = i;
				retornar = 0;
				break;
			}
		}
	}
	return retornar;
}

/**
 * Como lo implemento?
 * int posicionLibre;
 * posicionLibre = alumno_buscarLibre(alumno,QTY_ALUMNOS);
 * if(posicionLibre >=0)
 * {
 *   posicionLibre -> alta
 * }
 */
int alumno_buscarLibreValor(Alumno* pArrayAlumnos, int limit)
{
	int retornar = -1;
	if(pArrayAlumnos != NULL && limit > 0)
	{
		for(int i = 0; i < limit; i++)
		{
			if(pArrayAlumnos[i].isEmpty == TRUE)
			{
				retornar = i;
				break;
			}
		}
	}
	return retornar;
}

/* Cada vez que la llamo me devuelve un ID nuevo
 * que nunca me devolvio antes
 */
static int generarIdNuevo(void)
{
	static int id = 0; // es global para solo la fn puede usarla

	//guardar el ultimo que asigne (ultimo que devolvi)
	//para devolver 1+
	id = id + 1;
	return id;
}

int alumno_buscarId(Alumno* pArrayAlumnos, int limite, int* pIndex, int id)
{
	int retorno = -1;
	//*pIndex = -1;
	if (pArrayAlumnos != NULL && limite > 0 && id >= 0)
	{
		for (int i = 0; i < limite; i++)
		{
			if(pArrayAlumnos[i].isEmpty == FALSE)
			{
				if(pArrayAlumnos[i].id == id)
				{
					*pIndex = i;
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int alumno_ordenarPorNombre(Alumno* pArrayAlumnos, int limite)
{
	int respuesta = -1;
	
	return respuesta;
}
