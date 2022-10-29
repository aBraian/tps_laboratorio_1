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
int listarSalarios(eJugador jugadores[], int longitudJugadores);
int listarConfederacionMasAniosContrato(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);
int listarPorcentajeConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);
int listarRegionMasJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);
int submenuInformes(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

#endif /* INFORMES_H_ */
