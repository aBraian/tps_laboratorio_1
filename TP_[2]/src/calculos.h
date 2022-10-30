/*
 * calculos.h
 *
 *  Created on: 16 sep. 2022
 *      Author: braian
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

#include "jugador.h"

/// @brief Acumula los salarios de los jugadores
///
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param pTotalSalarios Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int acumularSalariosJugadores(eJugador jugadores[], int longitudJugadores, float *pTotalSalarios);

/// @brief Acumula la cantidad de jugadores dados de alta
///
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param pContador Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int contadorJugadores(eJugador jugadores[], int longitudJugadores, int *pContador);

/// @brief Recibe la suma de los salarios y lo divide por la cantidad de jugadores
///
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param pPromedio Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int calcularPromedioSalarios(eJugador jugadores[], int longitudJugadores, float *pPromedio);

/// @brief Acumula la cantidad de jugadores que superen el salario promedio
///
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param pCantidadSalarios Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int salariosMayorPromedio(eJugador jugadores[], int longitudJugadores, int *pCantidadSalarios);

/// @brief Acumula los anios de contrato de cada jugador de una determinada confederacion
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param indiceConfederacion Indice de la confederacion con la que se quiere comparar
/// @param pTotalAnios Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int acumularAniosContratoConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, int *pTotalAnios);

/// @brief Comprueba la confederacion que tiene mayor cantidad de anios de contrato
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param pCantidadAnios Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna el indice de la confederacion (EXITO) y -1 (ERROR)
int confederacionMasAniosContrato(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int *pCantidadAnios);

/// @brief Acumula la cantidad de jugadores de una determinada confederacion
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param indiceConfederacion Indice de la confederacion con la que se quiere comparar
/// @param pContador Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int contadorJugadoresConfederacion(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, int *pContador);

/// @brief Recibe la cantidad total de jugadores y calcula el porcentaje de jugadores de cada confederacion
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param indiceConfederacion Indice de la confederacion con la que se quiere comparar
/// @param pPorcentaje Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int calcularPorcentajeJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, float *pPorcentaje);

/// @brief Acumula la cantidad de jugadores de una determinada region
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param indiceConfederacion Indice de la confederacion con la que se quiere comparar
/// @param pContador Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int contadorJugadoresRegion(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, int *pContador);

/// @brief Comprueba la region que tiene mayor cantidad de jugadores
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna el indice de la confederacion (EXITO) y -1 (ERROR)
int regionMasJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

#endif /* CALCULOS_H_ */
