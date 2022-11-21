/*
 * calculos.h
 *
 *  Created on: 16 sep. 2022
 *      Author: braian
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @brief Suma todos los salarios de los jugadores
///
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param pTotalSalarios Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int acumularSalariosJugadores(eJugador aJugadores[], int longitudJugadores, float* pTotalSalarios);

/// @brief Obtiene el salario promedio
///
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param contadorJugadores Cantidad total de jugadores
/// @param pPromedio Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int calcularPromedioSalarios(eJugador aJugadores[], int longitudJugadores, int contadorJugadores, float* pPromedio);

/// @brief Obtiene la cantidad de jugadores que superan el salario promedio
///
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param pCantidadSalarios Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param promedioSalarios Salario promedio
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int salariosMayorPromedio(eJugador aJugadores[], int longitudJugadores, int* pCantidadSalarios, float promedioSalarios);

/// @brief Suma los anios de contrato de cada jugador
///
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param idBuscada ID que se usa para obtener la cantidad de anios
/// @param pTotalAnios Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int acumularAniosContratoConfederaciones(eJugador aJugadores[], int longitudJugadores, int idBuscada, int* pTotalAnios);

/// @brief Obtiene la confederacion que suma mas anios de contrato
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param pCantidadAnios Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param aNombreConfederacion Array donde se dejara el nombre de la confederacion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int confederacionMasAniosContrato(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores, int* pCantidadAnios, char aNombreConfederacion[]);

/// @brief Obtiene el porcentaje de jugadores por confederacion
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param idBuscada ID que se usa para obtener los jugadores de una confederacion
/// @param contadorJugadores Cantidad total de jugadores
/// @param pPorcentaje Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int calcularPorcentajeJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores, int idBuscada, int contadorJugadores, float* pPorcentaje);

/// @brief Suma la cantidad de jugadores en cada region
///
/// @param aJugadores Variable en la que estan las confederaciones
/// @param longitudJugadores Tamaño del array
/// @param idBuscada ID que se usa para obtener los jugadores de una region
/// @param pTotalJugadores Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int acumularJugadoresRegion(eJugador aJugadores[], int longitudJugadores, int idBuscada, int* pTotalJugadores);

/// @brief Obtiene la region que posee una mayor cantidad de jugadores
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan las confederaciones
/// @param longitudJugadores Tamaño del array
/// @param pContadorJugadores Puntero al espacio de memoria donde se dejara la cantidad de jugadores de la region
/// @param pIdRegion Puntero al espacio de memoria donde se dejara la ID de la region
/// @param aNombreRegion Array donde se dejara el nombre de la region
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int regionMasJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores, int* pContadorJugadores, int* pIdRegion, char aNombreRegion[]);

#endif /* CALCULOS_H_ */
