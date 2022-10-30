/*
 * informes.h
 *
 *  Created on: 22 oct. 2022
 *      Author: braian
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "jugador.h"

/// @brief Relaciona la estructura de confederacion y jugador a traves de su id
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param indiceRelacion Posicion de la ID a comparar
/// @return Retorna la posicion en que se relacionan ambas estructuras (EXITO) y -1 (ERROR)
int vincularIdEstructuras(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceRelacion);

/// @brief Ordena por el nombre de la confederacion y en caso de igualdad, ordena por el nombre de los jugadores
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int ordenarNombres(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

/// @brief Imprime cada confederacion con sus datos y agrega a los jugadores
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarConfederacionesConJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

/// @brief Imprime el total y promedio de todos los salarios y cuantos jugadores cobran mas del salario promedio
///
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarSalarios(eJugador jugadores[], int longitudJugadores);

/// @brief Imprime la confederacion con mayor cantidad de anios de contratos total
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarConfederacionMasAniosContrato(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

/// @brief Imprime el porcentaje de jugadores por cada confederacion
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarPorcentajeConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

/// @brief Imprime cual es la region con mas jugadores y el listado de los mismos
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarRegionMasJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

/// @brief Submenu de informes
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int submenuInformes(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

#endif /* INFORMES_H_ */
