/*
 * calculosArray.c
 *
 *  Created on: Sep 8, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * \brief Calcula el numro maximo del array recibido como parametro
 * \param int pArray[], Array a ser procesado
 * \param int cantidadElementos, cantidad de elementos a ser procesador
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \return (-1) Error / (0) Ok
 *
 */
int calcularMaximo(int pArray[], int cantidadElementos,int *pResultado)
{
	int retorno=-1;
	int maximo;
	if(pArray != NULL && cantidadElementos > 0 && pResultado != NULL)
	{
		for(int i=0; i < cantidadElementos; i++)
		{
			if(i==0 || pArray[i] > maximo)
			{
				maximo = pArray[i];
			}
		}
		*pResultado = maximo;
		retorno = 0;
	}
	return retorno;
}
