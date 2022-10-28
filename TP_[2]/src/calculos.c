/*
 * calculos.c
 *
 *  Created on: 16 sep. 2022
 *      Author: braian
 */

#include <stdio.h>
#include <stdlib.h>

int calcularPromedio(int sumaCantidades, int divisor, float *promedio){
	int retorno;
	float bufferPromedio;
	retorno = -1;
	if(promedio != NULL && divisor != 0){
		bufferPromedio = (float)sumaCantidades / divisor;
		*promedio = bufferPromedio;
		retorno = 0;
	}
	return retorno;
}

int calcularPorcentaje(int cantidadTotal, int cantidadPromedio, float *porcentaje){
	int retorno;
	retorno = -1;
	if(porcentaje != NULL && cantidadTotal != 0){
		*porcentaje = (float)cantidadPromedio * 100 / cantidadTotal;
		retorno = 0;
	}
	return retorno;
}

int calcularInteres(float precio, int porcentajeInteres, float *aumento, float *precioConInteres){
	int retorno;
	float aumentoNoAplicado;
	float precioConAumento;
	retorno = -1;
	if(aumento != NULL && precioConInteres != NULL){
		aumentoNoAplicado = precio * porcentajeInteres / 100;
		precioConAumento = precio + aumentoNoAplicado;
		*aumento = aumentoNoAplicado;
		*precioConInteres = precioConAumento;
		retorno = 0;
	}
	return retorno;
}

int acumularSalarios(float salarios, float *total){
	int retorno;
	retorno = -1;
	if(salarios > 0 && total != NULL){
		*total += salarios;
		retorno = 0;
	}
	return retorno;
}
