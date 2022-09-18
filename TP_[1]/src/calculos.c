/*
 * calculos.c
 *
 *  Created on: 16 sep. 2022
 *      Author: braia
 */

#include <stdio.h>
#include <stdlib.h>

float calcularPorcentaje(int cantidadTotal, int cantidadPromedio){
	float porcentaje;
	porcentaje = (float)cantidadPromedio * 100 / cantidadTotal;
	return porcentaje;
}

float calcularInteres(int precio, int interes, float * aumento){
	float aumentoNoAplicado;
	float precioConAumento;
	aumentoNoAplicado = (float)precio * interes / 100;
	precioConAumento = precio + aumentoNoAplicado;
	*aumento = aumentoNoAplicado;
	return precioConAumento;
}
