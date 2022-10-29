/*
 * confederacion.h
 *
 *  Created on: 18 oct. 2022
 *      Author: braian
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#define LIMITE_CONFEDERACIONES 6

typedef struct{
	int id;
	int anioCreacion;
	char nombre[50];
	char region[50];
}eConfederacion;

int incrementarIdConfederaciones();
int inicializarConfederaciones(eConfederacion confederaciones[], int longitud);
int listarConfederaciones(eConfederacion confederaciones[], int longitud);
int buscarIdConfederacion(eConfederacion confederaciones[], int longitud, int idBuscada);
int selecionarConfederacion(eConfederacion confederaciones[], int longitud);

#endif /* CONFEDERACION_H_ */
