/*
 * nac.c
 *
 *  Created on: 29 sep. 2020
 *      Author: Leo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "nac.h"

static int generarIdNuevo(void);

/**
 * \brief Inicializa el array de Nacionalidades.
 * \param Alumno arrayAlumnos[], Es el puntero al array de alumnos
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int nac_initArray(Nacionalidad* pArray, int limite)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			pArray[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Realiza el alta de una Nacionalidad solo si el indice que se busca corresponde en Empty
 * \param Nacionalidad pArray, Es el puntero al array de Nacionalidades
 * \param int limite, es el limite de array
 * \return (-1) Error / (0) Ok
 *
 */
int nac_alta(Nacionalidad* pArray,int limite)
{
	int retorno = -1;
	int indice;
	Nacionalidad bufferNacionalidad;

	if(	pArray != NULL && limite > 0)
	{
		if(alumno_buscarLibreRef(pArray, limite,&indice) == 0) // Busca un lugar libre
		{
			if(utn_getNombre("\n . Nombre: ","\n > Error!",bufferNacionalidad.nombre,2,LONG_NOMBRE) == 0)
			{
				//bufferAlumno.isEmpty = FALSE;
				bufferNacionalidad.id = generarIdNuevo();
				pArray[indice] = bufferNacionalidad;
				pArray[indice].isEmpty = FALSE;
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
 * \brief Realiza el alta de una Nacionalidad solo si el indice que le paso corresponde a un Empty
 * \param Nacionalidad arrayNacionalidads[], Es el puntero al array de Nacionalidads
 * \param int limite, es el limite de array
 * \param int indice, es el indice donde se cargara el Nacionalidad
 * \return (-1) Error / (0) Ok
 *
 */
int nac_altaConIndice(Nacionalidad* pArray,int limite,int indice)
{
	int retorno = -1;
	Nacionalidad bufferNacionalidad;

	if(	pArray != NULL && limite > 0 &&
			indice >=0 &&
			indice < limite &&
			pArray[indice].isEmpty == TRUE)
	{
		if(utn_getNombre("\n Nombre?","\nError",bufferNacionalidad.nombre,2,LONG_NOMBRE) == 0)
		{
			//bufferAlumno.isEmpty = FALSE;
			bufferNacionalidad.id = generarIdNuevo();
			pArray[indice] = bufferNacionalidad;
			pArray[indice].isEmpty = FALSE;

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
int nac_modificar(Nacionalidad* pArray,int limite)
{
	int retorno = -1;
	int indice;
	int idModificar;
	Nacionalidad bufferNacionalidad;

	if(utn_getInt(" . Ingrese el ID a modificar:"," Error!", &idModificar,5,1000,1) == 0)
	{
		if(alumno_buscarId(pArray, limite, &indice, idModificar) == 0)
		{
			if(	pArray != NULL && limite > 0 && indice >= 0 && indice < limite &&
					pArray[indice].isEmpty == FALSE)
			{
				if(utn_getNombre("\n . Nombre: ","\nError",bufferNacionalidad.nombre,2,LONG_NOMBRE) == 0)
				{
					//bufferAlumno.isEmpty = FALSE;
					bufferNacionalidad.id = pArray[indice].id; //generarIdNuevo(); // NOOOOOOOOO
					// Al entrar ne la funcion, no puede tocar el campo de id.
					// Es por eso que antes de que se modifiquen todos los campos,
					// le asigno nuevamente el id que ya traia.
					// Es el unico dato que puede cambiar nunca.
					// Si se modificara el id, se estaria llamando a eliminar
					// y daria de alta uno de nuevo.
					pArray[indice] = bufferNacionalidad;
					pArray[indice].isEmpty = FALSE;

					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int nac_baja(Nacionalidad* pArray,int limite,int indice)
{
	// Tipo de baja: Logica
	int retorno = -1;
	int idBajar;

	if(utn_getInt(" . Ingrese el ID a bajar:"," Error! ", &idBajar,2,1000,1) == 0)
	{
		if(alumno_buscarId(pArray, limite, &indice, idBajar) == 0)
		{
			if(	pArray != NULL && limite > 0 && indice >= 0 && indice < limite &&
					pArray[indice].isEmpty == FALSE)
			{
				pArray[indice].isEmpty = TRUE;
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
int nac_imprimir(Nacionalidad* pArray, int limite)
{
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		for(int i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				printf("\nNombre: %s - ID:%d",
						pArray[i].nombre,
						pArray[i].id);
			}
		}
		retorno = 0;
	}
	return retorno;
}

int nac_printById(Nacionalidad* pArray, int limit, int index)
{
	int retorno = -1;

	if(pArray != NULL && limit > 0 && index < limit)
	{
		if(pArray[index].isEmpty == FALSE)
		{
			printf(" Nombre: %s - ID: %d\n\n",pArray[index].nombre, pArray[index].id);
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * Como lo implemento?
 * int posicionLibre;
 * if(alumno_buscarLibre(alumno,QTY_NAC,&posicionLibre) == 0)
 * {
 *   posicionLibre -> alta
 * }
 */
int nac_buscarLibreRef(Nacionalidad* pArray, int limit, int *pIndex)
{
	int retornar = -1;
	if(pArray != NULL && pIndex != NULL && limit > 0)
	{
		for(int i = 0; i < limit; i++)
		{
			if(pArray[i].isEmpty == TRUE)
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
 * posicionLibre = alumno_buscarLibre(alumno,QTY_NAC);
 * if(posicionLibre >=0)
 * {
 *   posicionLibre -> alta
 * }
 */
int nac_buscarLibreValor(Nacionalidad* pArray, int limit)
{
	int retornar = -1;
	if(pArray != NULL && limit > 0)
	{
		for(int i = 0; i < limit; i++)
		{
			if(pArray[i].isEmpty == TRUE)
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

int nac_buscarId(Nacionalidad* pArray, int limite, int* pIndex, int id)
{
	int retorno = -1;
	//*pIndex = -1;
	if (pArray != NULL && limite > 0 && id >= 0)
	{
		for (int i = 0; i < limite; i++)
		{
			if(pArray[i].isEmpty == FALSE)
			{
				if(pArray[i].id == id)
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

int nac_ordenarPorNombre(Nacionalidad* pArray, int limite)
{
	int respuesta = -1;

	return respuesta;
}

