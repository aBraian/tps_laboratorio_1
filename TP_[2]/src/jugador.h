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
#define LONGITUD_NOMBRE 1019
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
int inicializarJugadores(eJugador jugadores[], int longitud);
int encontrarVacioJugadores(eJugador jugadores[], int longitud);
int altaJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores);

#endif /* JUGADOR_H_ */
