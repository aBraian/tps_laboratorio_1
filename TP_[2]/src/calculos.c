/*
 * calculos.c
 *
 *  Created on: 16 sep. 2022
 *      Author: braian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"
#include "jugador.h"
#include "calculos.h"

int acumularSalariosJugadores(eJugador aJugadores[], int longitudJugadores, float* pTotalSalarios){
	int retorno;
	int i;
	float bufferSalarios;
	retorno = -1;
	bufferSalarios = 0;
	if(aJugadores != NULL && longitudJugadores > 0 && pTotalSalarios != NULL){
		for(i = 0; i < longitudJugadores; i++){
			if(aJugadores[i].isEmpty == LLENO){
				bufferSalarios += aJugadores[i].salario;
			}
		}
		*pTotalSalarios = bufferSalarios;
		retorno = 0;
	}
	return retorno;
}

int calcularPromedioSalarios(eJugador aJugadores[], int longitudJugadores, int contadorJugadores, float* pPromedio){
	int retorno;
	float bufferSalario;
	retorno = -1;
	bufferSalario = 0;
	if(aJugadores != NULL && longitudJugadores > 0 && pPromedio != NULL && contadorJugadores > 0){
		if(acumularSalariosJugadores(aJugadores, longitudJugadores, &bufferSalario) == 0 &&
		   contadorJugadores > 0){
			*pPromedio = bufferSalario / contadorJugadores;
			retorno = 0;
		}
	}
	return retorno;
}

int salariosMayorPromedio(eJugador aJugadores[], int longitudJugadores, int* pCantidadSalarios, float promedioSalarios){
	int retorno;
	int contadorSalarios;
	int i;
	retorno = -1;
	contadorSalarios = 0;
	if(aJugadores != NULL && longitudJugadores > 0 && pCantidadSalarios != NULL){
		for(i = 0; i < longitudJugadores; i++){
			if(aJugadores[i].isEmpty == LLENO &&
			   aJugadores[i].salario > promedioSalarios){
				contadorSalarios++;
			}
		}
		*pCantidadSalarios = contadorSalarios;
		retorno = 0;
	}
	return retorno;
}

int acumularAniosContratoConfederaciones(eJugador aJugadores[], int longitudJugadores, int idBuscada, int* pTotalAnios){
	int retorno;
	int i;
	int bufferAnios;
	retorno = -1;
	bufferAnios = 0;
	if(aJugadores != NULL && longitudJugadores > 0 && pTotalAnios != NULL){
		for(i = 0; i < longitudJugadores; i++){
			if(aJugadores[i].isEmpty == LLENO && aJugadores[i].idConfederacion == idBuscada){
				bufferAnios += aJugadores[i].aniosContrato;
			}
		}
		*pTotalAnios = bufferAnios;
		retorno = 0;
	}
	return retorno;
}

int confederacionMasAniosContrato(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores, int* pCantidadAnios, char aNombreConfederacion[]){
	int retorno;
	int i;
	int bufferTotal;
	int flag;
	int cantidadMayor;
	char auxNombreConfederacion[LONG_NOMBRE];
	retorno = -1;
	flag = 0;
	if(aConfederaciones != NULL && longitudConfederaciones > 0 && pCantidadAnios != NULL){
		for(i = 0; i < longitudConfederaciones; i++){
			if(acumularAniosContratoConfederaciones(aJugadores, longitudJugadores, aConfederaciones[i].id, &bufferTotal) == 0 &&
			   flag == 0){
				cantidadMayor = bufferTotal;
				obtenerNombreConfederacion(aConfederaciones, longitudConfederaciones, aConfederaciones[i].id, auxNombreConfederacion);
				flag = 1;
			}
			else if(bufferTotal > cantidadMayor){
				cantidadMayor = bufferTotal;
				obtenerNombreConfederacion(aConfederaciones, longitudConfederaciones, aConfederaciones[i].id, auxNombreConfederacion);
			}
		}
		retorno = 0;
		*pCantidadAnios = cantidadMayor;
		strncpy(aNombreConfederacion, auxNombreConfederacion, LONG_NOMBRE);
	}
	return retorno;
}

int calcularPorcentajeJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores, int idBuscada, int contadorJugadores, float* pPorcentaje){
	int retorno;
	int i;
	int bufferPorcentaje;
	retorno = -1;
	bufferPorcentaje = 0;
	if(aConfederaciones != NULL && longitudConfederaciones > 0 &&
	   aJugadores != NULL && longitudJugadores > 0 && contadorJugadores > 0 && pPorcentaje != NULL){
		for(i = 0; i < longitudJugadores; i++){
			if(aJugadores[i].isEmpty == LLENO && aJugadores[i].idConfederacion == idBuscada){
				bufferPorcentaje++;
			}
		}
		*pPorcentaje = (float)bufferPorcentaje * 100 / contadorJugadores;
		retorno = 0;
	}
	return retorno;
}

int acumularJugadoresRegion(eJugador aJugadores[], int longitudJugadores, int idBuscada, int* pTotalJugadores){
	int retorno;
	int i;
	int bufferJugadores;
	retorno = -1;
	bufferJugadores = 0;
	if(aJugadores != NULL && longitudJugadores > 0 && pTotalJugadores != NULL){
		for(i = 0; i < longitudJugadores; i++){
			if(aJugadores[i].isEmpty == LLENO && aJugadores[i].idConfederacion == idBuscada){
				bufferJugadores++;
			}
		}
		*pTotalJugadores = bufferJugadores;
		retorno = 0;
	}
	return retorno;
}

int regionMasJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores, int* pContadorJugadores, int* pIdRegion, char aNombreRegion[]){
	int retorno;
	int i;
	int bufferContador;
	int cantidadMayor;
	int flag;
	int auxId;
	char auxNombreRegion[LONG_REGION];
	retorno = -1;
	cantidadMayor = 0;
	flag = 0;
	if(aConfederaciones != NULL && longitudConfederaciones > 0 &&
	   aJugadores != NULL && longitudJugadores > 0){
		for(i = 0; i < longitudConfederaciones; i++){
			if(acumularJugadoresRegion(aJugadores, longitudJugadores, aConfederaciones[i].id, &bufferContador) == 0 &&
			   flag == 0){
				cantidadMayor = bufferContador;
				auxId = aConfederaciones[i].id;
				obtenerRegionConfederacion(aConfederaciones, longitudConfederaciones, aConfederaciones[i].id, auxNombreRegion);
				flag = 1;
			}
			else if(flag == 1 && bufferContador > cantidadMayor){
				cantidadMayor = bufferContador;
				auxId = aConfederaciones[i].id;
				obtenerRegionConfederacion(aConfederaciones, longitudConfederaciones, aConfederaciones[i].id, auxNombreRegion);
			}
		}
		retorno = 0;
		*pContadorJugadores = cantidadMayor;
		*pIdRegion = auxId;
		strncpy(aNombreRegion, auxNombreRegion, LONG_NOMBRE);
	}
	return retorno;
}
