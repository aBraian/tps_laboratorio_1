/*
 * validaciones.h
 *
 *  Created on: 16 sep. 2022
 *      Author: braian
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int utn_getInt(int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);

#endif /* VALIDACIONES_H_ */
