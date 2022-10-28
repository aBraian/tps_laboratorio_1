/*
 * informes.h
 *
 *  Created on: 22 oct. 2022
 *      Author: braian
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "jugador.h"

int vincularIdEstructuras(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceRelacion);
int ordenarNombres(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);
int listarConfederacionesConJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);
int acumularSalariosJugadores(eJugador jugadores[], int longitudJugadores, float *totalSalarios);
int contadorJugadores(eJugador jugadores[], int longitudJugadores, int *contador);
int calcularPromedioSalarios(eJugador jugadores[], int longitudJugadores, float *pPromedio);
int salariosMayorPromedio(eJugador jugadores[], int longitudJugadores, int *pCantidadSalarios);
int submenuInformes(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

#endif /* INFORMES_H_ */
