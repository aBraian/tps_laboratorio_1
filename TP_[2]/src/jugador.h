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
#define ALTA 1
#define BAJA 0
#define LONGITUD_NOMBRE 30
#define MENSAJE_EXITO "SE DIO DE ALTA - DATOS BIEN INGRESADOS\n"
#define MENSAJE_ERROR "NO SE DIO DE ALTA - DATOS MAL INGRESADOS\n"

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

int incrementarIdJugadores();
int contadorIdJugadores(int opcion);
int inicializarJugadores(eJugador jugadores[], int longitud);
int listarJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);
int buscarVacioJugadores(eJugador jugadores[], int longitud);
int buscarIdJugadores(eJugador jugadores[], int longitud, int idBuscada);
int ordenarIdJugadores(eJugador jugadores[], int longitud);
int altaJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);
int bajaJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);
int modificarJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

#endif /* JUGADOR_H_ */
