/*
 * validaciones.h
 *
 *  Created on: 18 oct. 2022
 *      Author: braian
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/// @brief Solicita un numero entero al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el numero maximo a ser aceptado
/// @param reintentos Es la cantidad de veces que se puede equivocar el usuario
/// @return  Retorna 0 si se obtuvo el numero y -1 si no
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

/// @brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el numero maximo a ser aceptado
/// @param reintentos Es la cantidad de veces que se puede equivocar el usuario
/// @return  Retorna 0 si se obtuvo el numero y -1 si no
int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

/// @brief Solicita una cadena de caracteres al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado Array donde se dejara el resultado de la funcion
/// @param longitudArray Tama�o del array
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param reintentos Es la cantidad de veces que se puede equivocar el usuario
/// @return Retorna 0 si se obtuvo la cadena y -1 si no
int utn_getString(char pResultado[], int longitudArray, char * mensaje, char * mensajeError, int reintentos);

void convertirEnMinuscula(char cadena[], int longitud);

#endif /* VALIDACIONES_H_ */
