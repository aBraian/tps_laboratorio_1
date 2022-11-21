/*
 * jugador.h
 *
 *  Created on: 18 oct. 2022
 *      Author: braian
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#define VACIO 1
#define LLENO 0
#define LONG_NOMBRE 50
#define LONG_POSICION 50
#define MENSAJE_EXITO "\nSE DIO DE ALTA - DATOS BIEN INGRESADOS\n"
#define MENSAJE_ERROR "NO SE DIO DE ALTA - DATOS MAL INGRESADOS\n"
#define LIMITE_JUGADORES 3000
#define ADVERTENCIA_JUGADORES "ANTES SE DEBE DAR DE ALTA UN JUGADOR\n"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

/// @brief Incrementa de a uno la id jugador
///
/// @return Retorna la id
int incrementarIdJugadores();

/// @brief Inicializa los jugadores como vacios
///
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitud Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int inicializarJugadores(eJugador aJugadores[], int longitud);

/// @brief Busca una posicion que este vacia
///
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitud Tamaño del array
/// @return Retorna la posicion vacia (EXITO) y -1 (ERROR)
int buscarVacioJugadores(eJugador aJugadores[], int longitud);

/// @brief Da de alta el jugador ingresado por el usuario
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int altaJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores);

/// @brief Ordena por ID los jugadores
///
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitud Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int ordenarIdJugadores(eJugador aJugadores[], int longitud);

/// @brief Imprime cada jugador con sus datos
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores);

/// @brief Busca la posicion de una ID determinada
///
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitud Tamaño del array
/// @param idBuscada ID que se busca
/// @return Retorna la posicion de la ID (EXITO) y -1 (ERROR)
int buscarIdJugadores(eJugador aJugadores[], int longitud, int idBuscada);

/// @brief Busca la ultima ID
///
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitud Tamaño del array
/// @return Retorna la ID (EXITO) y -1 (ERROR)
int buscarIdMaximaJugadores(eJugador aJugadores[], int longitud);

/// @brief Da de baja el jugador ingresado por el usuario
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int bajaJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores);

/// @brief Permite modificar el jugador ingresado por el usuario
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @param aJugadores Variable en la que estan los jugadores
/// @param longitudJugadores Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int modificarJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores);

#endif /* JUGADOR_H_ */
