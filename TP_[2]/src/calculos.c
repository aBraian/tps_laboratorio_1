/*
 * calculos.c
 *
 *  Created on: 16 sep. 2022
 *      Author: braian
 */

#include <stdio.h>
#include <stdlib.h>
#include "informes.h"
#include "jugador.h"

int acumularSalariosJugadores(eJugador jugadores[], int longitudJugadores, float *pTotalSalarios){
	int retorno;
	int i;
	float bufferSalarios;
	retorno = -1;
	if(jugadores != NULL && longitudJugadores > 0 && pTotalSalarios != NULL){
		for(i = 0; i < longitudJugadores; i++){
			if(jugadores[i].isEmpty == LLENO){
				bufferSalarios += jugadores[i].salario;
			}
		}
		*pTotalSalarios = bufferSalarios;
		retorno = 0;
	}
	return retorno;
}

int contadorJugadores(eJugador jugadores[], int longitudJugadores, int *pContador){
	int retorno;
	int i;
	int bufferContador;
	retorno = -1;
	bufferContador = 0;
	if(jugadores != NULL && longitudJugadores > 0 && pContador != NULL){
		for(i = 0; i < longitudJugadores; i++){
			if(jugadores[i].isEmpty == LLENO){
				bufferContador++;
			}
		}
		*pContador = bufferContador;
		retorno = 0;
	}
	return retorno;
}

int calcularPromedioSalarios(eJugador jugadores[], int longitudJugadores, float *pPromedio){
	int retorno;
	int bufferContador;
	float bufferSalario;
	retorno = -1;
	if(jugadores != NULL && longitudJugadores > 0 && pPromedio != NULL &&
	   acumularSalariosJugadores(jugadores, longitudJugadores, &bufferSalario) == 0 &&
	   contadorJugadores(jugadores, longitudJugadores, &bufferContador) == 0 &&
	   bufferSalario > 0 && bufferContador > 0){
		*pPromedio = bufferSalario / bufferContador;
		retorno = 0;
	}
	return retorno;
}

int salariosMayorPromedio(eJugador jugadores[], int longitudJugadores, int *pCantidadSalarios){
	int retorno;
	int contadorSalarios;
	int i;
	int auxiliar;
	float promedioSalarios;
	retorno = -1;
	contadorSalarios = 0;
	if(jugadores != NULL && longitudJugadores > 0 && pCantidadSalarios != NULL &&
	   calcularPromedioSalarios(jugadores, longitudJugadores, &promedioSalarios) == 0){
		for(i = 0; i < longitudJugadores; i++){
			if(jugadores[i].isEmpty == LLENO &&
			   jugadores[i].salario > promedioSalarios){
				contadorSalarios++;
			}
		}
		auxiliar = contadorSalarios;
		*pCantidadSalarios = auxiliar;
		retorno = 0;
	}
	return retorno;
}

int acumularAniosContratoConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, int *pTotalAnios){
	int retorno;
	int i;
	int bufferAnios;
	int auxIndice;
	retorno = -1;
	bufferAnios = 0;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0 && pTotalAnios != NULL){
		for(i = 0; i < longitudJugadores; i++){
			auxIndice = vincularIdEstructuras(confederaciones, longitudConfederaciones, jugadores, longitudJugadores, i);
			if(jugadores[i].isEmpty == LLENO && auxIndice != -1 && indiceConfederacion == auxIndice){
				bufferAnios += jugadores[i].aniosContrato;
			}
		}
		*pTotalAnios = bufferAnios;
		retorno = 0;
	}
	return retorno;
}

int confederacionMasAniosContrato(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int *pCantidadAnios){
	int retorno;
	int i;
	int bufferTotal;
	int flag;
	int cantidadMayor;
	int auxiliar;
	retorno = -1;
	flag = 0;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0 && pCantidadAnios != NULL){
		for(i = 0; i < longitudConfederaciones; i++){
			if(acumularAniosContratoConfederaciones(confederaciones, longitudConfederaciones, jugadores, longitudJugadores, i, &bufferTotal) == 0 &&
			   flag == 0){
				cantidadMayor = bufferTotal;
				retorno = i;
				flag = 1;
			}
			else if(flag == 1 && bufferTotal > cantidadMayor){
				cantidadMayor = bufferTotal;
				retorno = i;
			}
			auxiliar = cantidadMayor;
			*pCantidadAnios = auxiliar;
		}
	}
	return retorno;
}

int contadorJugadoresConfederacion(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, int *pContador){
	int retorno;
	int i;
	int bufferContador;
	int auxIndice;
	retorno = -1;
	bufferContador = 0;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0 && pContador != NULL){
		for(i = 0; i < longitudJugadores; i++){
			auxIndice = vincularIdEstructuras(confederaciones, longitudConfederaciones, jugadores, longitudJugadores, i);
			if(jugadores[i].isEmpty == LLENO && auxIndice != -1 && indiceConfederacion == auxIndice){
				bufferContador++;;
			}
		}
		*pContador = bufferContador;
		retorno = 0;
	}
	return retorno;
}

int calcularPorcentajeJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, float *pPorcentaje){
	int retorno;
	int cantidadTotal;
	int cantidadPorcentaje;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0 &&
	   jugadores != NULL && longitudJugadores > 0 && pPorcentaje != NULL &&
	   contadorJugadores(jugadores, longitudJugadores, &cantidadTotal) == 0 &&
	   contadorJugadoresConfederacion(confederaciones, longitudConfederaciones, jugadores, longitudJugadores, indiceConfederacion, &cantidadPorcentaje) == 0 &&
	   cantidadTotal != 0){
		*pPorcentaje = (float)cantidadPorcentaje * 100 / cantidadTotal;
		retorno = 0;
	}
	return retorno;
}

int contadorJugadoresRegion(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceConfederacion, int *pContador){
	int retorno;
	int i;
	int bufferContador;
	int auxIndice;
	retorno = -1;
	bufferContador = 0;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0 && pContador != NULL){
		for(i = 0; i < longitudJugadores; i++){
			auxIndice = vincularIdEstructuras(confederaciones, longitudConfederaciones, jugadores, longitudJugadores, i);
			if(jugadores[i].isEmpty == LLENO && auxIndice != -1 &&
			   confederaciones[indiceConfederacion].region == confederaciones[auxIndice].region){
				bufferContador++;
			}
		}
		*pContador = bufferContador;
		retorno = 0;
	}
	return retorno;
}

int regionMasJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int i;
	int bufferContador;
	int cantidadMayor;
	int flag;
	retorno = -1;
	cantidadMayor = 0;
	flag = 0;
	if(confederaciones != NULL && longitudConfederaciones > 0 &&
	   jugadores != NULL && longitudJugadores > 0){
		for(i = 0; i < longitudConfederaciones; i++){
			if(contadorJugadoresRegion(confederaciones, longitudConfederaciones, jugadores, longitudJugadores, i, &bufferContador) == 0 &&
			   flag == 0){
				cantidadMayor = bufferContador;
				retorno = i;
				flag = 1;
			}
			else if(flag == 1 && bufferContador > cantidadMayor){
				cantidadMayor = bufferContador;
				retorno = i;
			}
		}
	}
	return retorno;
}
