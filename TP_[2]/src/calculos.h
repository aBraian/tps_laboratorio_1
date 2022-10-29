/*
 * calculos.h
 *
 *  Created on: 16 sep. 2022
 *      Author: braian
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

#include "jugador.h"

/// @brief Recibe la suma de varias cantidades y lo divide por el número de sumandos
/// 	   y devuelve por referencia el promedio calculado
///
/// @param sumaCantidades Suma de varias cantidades
/// @param divisor Numero de sumandos
/// @param promedio Puntero al espacio de memoria donde se guardara el resultado
/// @return Retorna 0 (EXITO) si obtiene un promedio o -1 (ERROR) si no
int calcularPromedio(int sumaCantidades, int divisor, float *promedio);

/// @brief Recibe dos valores, uno representa el total, el otro representa la proporcionalidad de una parte
/// 	   respecto del total, y devuelve por referencia el porcentaje calculado
///
/// @param cantidadTotal Valor total de una parte
/// @param cantidadPromedio Valor proporcional de una parte
/// @param porcentaje Puntero al espacio de memoria donde se guardara el resultado
/// @return Retorna 0 (EXITO) si obtiene un porcentaje o -1 (ERROR) si no
int calcularPorcentaje(int cantidadTotal, int cantidadPromedio, float *porcentaje);

/// @brief Recibe un precio y le calcula un aumento
///
/// @param precio Valor sobre el que se calcula el aumento
/// @param porcentajeInteres Valor del aumento que se va a aplicar
/// @param aumento Puntero al espacio de memoria donde se guardara el valor del aumento
/// @param precioConInteres Puntero al espacio de memoria donde se guardara el valor del precio con el aumento aplicado
/// @return Retorna 0 (EXITO) si obtiene el aumento y el precio con interes o -1 (ERROR) si no
int calcularInteres(float precio, int porcentajeInteres, float *aumento, float *precioConInteres);
int acumularSalarios(float salarios, float *total);

int acumularSalariosJugadores(eJugador jugadores[], int longitudJugadores, float *pTotalSalarios);
int contadorJugadores(eJugador jugadores[], int longitudJugadores, int *pContador);
int calcularPromedioSalarios(eJugador jugadores[], int longitudJugadores, float *pPromedio);
int salariosMayorPromedio(eJugador jugadores[], int longitudJugadores, int *pCantidadSalarios);
int acumularAniosContratoConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, int *pTotalAnios);
int confederacionMasAniosContrato(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int *pCantidadAnios);
int acumularAniosContratoConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, int *pTotalAnios);
int contadorJugadoresConfederacion(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, int *pContador);
int calcularPorcentajeJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, float *pPorcentaje);
int contadorJugadoresRegion(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, int *pContador);
int regionMasJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

#endif /* CALCULOS_H_ */
