/*
 * informes.h
 *
 *  Created on: 22 oct. 2022
 *      Author: braian
 */

#ifndef INFORMES_H_
#define INFORMES_H_

/// @brief Ordena por el nombre de la confederacion y en caso de igualdad, ordena por el nombre de los jugadores
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int ordenarNombres(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores);

/// @brief Busca si existe minimo un jugador en cada confederacion
///
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param idConfederacion ID que se usa para conocer si existe un jugador en esa confederacion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int existenJugadores(eJugador aJugadores[], int longitudJugadores, int idConfederacion);

/// @brief Imprime por separado cada confederacion junto a sus jugadores
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarConfederacionesConJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores);

/// @brief Imprime el total de salarios, promedio de salarios y cuantos jugadores cobran mas del salario promedio
///
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param cantidadSalarios Cantidad de salarios mayores al promedio
/// @param totalSalarios Suma total de salarios
/// @param promedioSalarios Salario promedio
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarSalarios(eJugador aJugadores[], int longitudJugadores, int cantidadSalarios, float totalSalarios, float promedioSalarios);

/// @brief Imprime la confederacion con mayor cantidad de anios de contratos total
///
/// @param cantidadAnios Cantidad total de anios
/// @param aNombreConfederacion Array en el que esta el nombre de la confederacion con mayor cantidad de anios
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarConfederacionMasAniosContrato(int cantidadAnios, char aNombreConfederacion[]);

/// @brief Imprime el porcentaje de jugadores por cada confederacion
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param contadorJugadores Cantidad total de jugadores
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarPorcentajeConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores, int contadorJugadores);

/// @brief Imprime cual es la region con mas jugadores y el listado de los mismos
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarRegionMasJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores);

/// @brief Submenu de informes
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @param contadorJugadores Cantidad total de jugadores
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int submenuInformes(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores, int contadorJugadores);

#endif /* INFORMES_H_ */
