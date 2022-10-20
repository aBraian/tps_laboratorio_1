/*
 * jugador.c
 *
 *  Created on: 18 oct. 2022
 *      Author: braian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"
#include "jugador.h"
#include "validaciones.h"

int incrementarIdJugadores(){
	static int idJugadores = 0;
	idJugadores++;
	return idJugadores;
}

int inicializarJugadores(eJugador jugadores[], int longitud){
	int retorno;
	int i;
	retorno = -1;
	if(jugadores != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			jugadores[i].isEmpty = VACIO;
		}
		retorno = 0;
	}
	return retorno;
}

int encontrarVacioJugadores(eJugador jugadores[], int longitud){
	int retorno;
	int i;
	retorno = -1;
	if(jugadores != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			if(jugadores[i].isEmpty == VACIO){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int indiceVacio;
	int indiceConfederacion;
	int bufferCamiseta;
	int bufferContrato;
	float bufferSalario;
	char bufferNombre[LONGITUD_NOMBRE];
	char bufferPosicion[15];
	retorno = -1;
	if(jugadores != NULL && longitudJugadores > 0 && confederaciones != NULL && longitudConfederaciones > 0){
		indiceVacio = encontrarVacioJugadores(jugadores, longitudJugadores);
		if(indiceVacio != -1 &&
		   utn_getInt(&bufferCamiseta, "Ingrese numero de camiseta: ", "NUMERO NO VALIDO (MINIMO 1 - MAXIMO 99)\n", 1, 99, 2) == 0 &&
		   utn_getInt(&bufferContrato, "Ingrese anios de contrato: ", "ANIO NO VALIDO (MINIMO 1 - MAXIMO 10)\n", 1, 10, 2) == 0 &&
		   utn_getFloat(&bufferSalario, "Ingrese salario: $", "PRECIO NO VALIDO(MINIMO 37000 - MAXIMO 4750000)\n", 37000, 4750000, 2) == 0 &&
		   utn_getString(bufferNombre, LONGITUD_NOMBRE, "Ingrese nombre: ", "ERROR\n", 2) == 0 &&
		   utn_getString(bufferPosicion, 15, "Ingrese posicion: ", "ERROR\n", 2) == 0){
			printf("\n");
			indiceConfederacion = selecionarConfederacion(confederaciones, longitudConfederaciones);
			printf("\n");
			if(indiceConfederacion != -1){
				jugadores[indiceVacio].numeroCamiseta = (short)bufferCamiseta;
				jugadores[indiceVacio].aniosContrato = (short)bufferContrato;
				jugadores[indiceVacio].salario = bufferSalario;
				strcpy(jugadores[indiceVacio].nombre, bufferNombre);
				strcpy(jugadores[indiceVacio].posicion, bufferPosicion);
				jugadores[indiceVacio].id = incrementarIdJugadores();
				jugadores[indiceVacio].idConfederacion = confederaciones[indiceConfederacion].id;
				jugadores[indiceVacio].isEmpty = (short)LLENO;
				retorno = 0;
				printf(MENSAJE_EXITO);
			}
			else{
				printf(MENSAJE_ERROR);
				}
			}
		else if(indiceVacio == -1){
			printf("LIMITE DE RECURSOS ALCANZADO\n");
		}
		else{
			printf(MENSAJE_ERROR);
		}
	}
	return retorno;
}
