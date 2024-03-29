/*
 * validaciones.h
 *
 *  Created on: 18 oct. 2022
 *      Author: braian
 */

#ifndef INGRESODATOS_H_
#define INGRESODATOS_H_

/// @brief Solicita un numero short al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param pMensaje Es el mensaje a ser mostrado
/// @param pMensajeError Es el mensaje de error a ser mostrado
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el numero maximo a ser aceptado
/// @param reintentos Es la cantidad de veces que se puede equivocar el usuario
/// @return  Retorna 0 si se obtuvo el numero y -1 si no
int utn_getShort(short* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);

/// @brief Solicita un numero entero al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param pMensaje Es el mensaje a ser mostrado
/// @param pMensajeError Es el mensaje de error a ser mostrado
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el numero maximo a ser aceptado
/// @param reintentos Es la cantidad de veces que se puede equivocar el usuario
/// @return  Retorna 0 si se obtuvo el numero y -1 si no
int utn_getInt(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);

/// @brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param pMensaje Es el mensaje a ser mostrado
/// @param pMensajeError Es el mensaje de error a ser mostrado
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el numero maximo a ser aceptado
/// @param reintentos Es la cantidad de veces que se puede equivocar el usuario
/// @return  Retorna 0 si se obtuvo el numero y -1 si no
int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);

/// @brief Solicita una cadena de caracteres al usuario, luego de verificarlo devuelve el resultado
///
/// @param aResultado Array donde se dejara el resultado de la funcion
/// @param longitud Tama�o del array
/// @param pMensaje Es el mensaje a ser mostrado
/// @param pMensajeError Es el mensaje de error a ser mostrado
/// @param reintentos Es la cantidad de veces que se puede equivocar el usuario
/// @return Retorna 0 si se obtuvo la cadena y -1 si no
int utn_getString(char aResultado[], int longitud, char* pMensaje, char* pMensajeError, int reintentos);

/// @brief Transforma una cadena de caracteres en minuscula
///
/// @param aCadena Variable a transformar
/// @param longitud Tama�o del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int convertirEnMinuscula(char aCadena[], int longitud);

/// @brief Pide una confirmacion al usuario para salir del menu
///
/// @return Retorna 0 (SALIR) y -1 (NO SALIR)
int salirMenu(void);

#endif /* INGRESODATOS_H_ */
