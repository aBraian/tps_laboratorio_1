/*
 * jugador.h
 *
 *  Created on: 18 oct. 2022
 *      Author: braian
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "confederacion.h"

#define VACIO 1
#define LLENO 0
#define ALTA 1
#define BAJA 0
#define LONGITUD_NOMBRE 30
#define MENSAJE_EXITO "SE DIO DE ALTA - DATOS BIEN INGRESADOS\n"
#define MENSAJE_ERROR "\nNO SE DIO DE ALTA - DATOS MAL INGRESADOS\n"
#define LIMITE_JUGADORES 3000
#define ADVERTENCIA_JUGADORES "ANTES SE DEBE DAR DE ALTA UN JUGADOR\n"

typedef struct{
	short isEmpty;
	short numeroCamiseta;
	short aniosContrato;
	int id;
	int idConfederacion;
	float salario;
	char nombre[50];
	char posicion[50];
}eJugador;

/// @brief Incrementa de a uno la id jugador
///
/// @return Retorna la id
int incrementarIdJugadores();

/// @brief Acumula la cantidad de jugadores dados de alta
///
/// @param opcion Permite aumentar o devolver la cantidad de jugadores dados de alta
/// @return Retorna la cantidad de ID de confederacion
int contadorIdJugadores(int opcion);

/// @brief Inicializa los jugadores como vacios
///
/// @param jugadores Variable en la que estan los jugadores
/// @param longitud Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int inicializarJugadores(eJugador jugadores[], int longitud);

/// @brief Imprime cada jugador con sus datos
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

/// @brief Busca una posicion que este vacia
///
/// @param jugadores Variable en la que estan los jugadores
/// @param longitud Tamaño del array
/// @return Retorna la posicion vacia (EXITO) y -1 (ERROR)
int buscarVacioJugadores(eJugador jugadores[], int longitud);

/// @brief Busca la posicion de una ID determinada
///
/// @param jugadores Variable en la que estan los jugadores
/// @param longitud Tamaño del array
/// @param idBuscada ID que se busca
/// @return Retorna la posicion de la ID (EXITO) y -1 (ERROR)
int buscarIdJugadores(eJugador jugadores[], int longitud, int idBuscada);

/// @brief Ordena por ID los jugadores
///
/// @param jugadores Variable en la que estan los jugadores
/// @param longitud Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int ordenarIdJugadores(eJugador jugadores[], int longitud);

/// @brief Da de alta el jugador ingresado por el usuario
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int altaJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

/// @brief Da de baja el jugador ingresado por el usuario
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int bajaJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

/// @brief Permite modificar el jugador ingresado por el usuario
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param jugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int modificarJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

#endif /* JUGADOR_H_ */
