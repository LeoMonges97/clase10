/*
 * nac.h
 *
 *  Created on: 29 sep. 2020
 *      Author: Leo
 */

#ifndef NAC_H_
#define NAC_H_

#define TRUE 1
#define FALSE 0
#define LONG_NOMBRE 50
#define QTY_NAC 5
#define MIN_LEGAJO 1
#define MAX_LEGAJO 100

typedef struct
{
	char nombre[LONG_NOMBRE];
	int isEmpty;
	int id;
}Nacionalidad;

int nac_initArray(Nacionalidad* pArray, int limite);

int nac_alta(Nacionalidad* pArray,int limite);
int nac_altaConIndice(Nacionalidad* pArray,int limite,int indice);
int nac_modificar(Nacionalidad* pArray,int limite);
int nac_baja(Nacionalidad* pArray,int limite,int indice);

int nac_imprimir(Nacionalidad* pArray, int limite);
int nac_printById(Nacionalidad* pArray, int limit, int index);

int nac_buscarId(Nacionalidad* pArray, int limite, int* pIndex, int id);
int nac_buscarLibreRef(Nacionalidad* pArray, int limit, int *pIndex);
int nac_buscarLibreValor(Nacionalidad* pArray, int limit);

int nac_ordenarPorNombre(Nacionalidad* pArray, int limite);

#endif /* NAC_H_ */
