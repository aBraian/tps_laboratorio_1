/*
 * validaciones.c
 *
 *  Created on: 16 sep. 2022
 *      Author: braian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getInt(int * pResultado);
static int esNumerica(char * cadena);
static int getFloat(float * pResultado);
static int esFlotante(char * cadena);
static int myGets(char * cadena, int longitud);

int utn_getInt(int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	int numeroIngresado;
	retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo >= minimo){
		do{
			printf(mensaje);
			if(getInt(&numeroIngresado) == 0 && (numeroIngresado <= maximo && numeroIngresado >= minimo)){
				*pResultado = numeroIngresado;
				retorno = 0;
				break;
			}
			else{
				printf(mensajeError);
				reintentos--;
			}
			fflush(stdin);
		}while(reintentos > 0);
	}
	return retorno;
}

static int getInt(int * pResultado){
	int retorno;
	char buffer[64];
	retorno = -1;
	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer) == 0){
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static int esNumerica(char * cadena){
	int i;
	int retorno;
	i = 0;
	retorno = 0;
	if(cadena != NULL && strlen(cadena) > 0){
		if(cadena[0] == '-'){
				i = 1;
		}
		for(; cadena[i] != '\0'; i++){
			if(cadena[i] < '0' || cadena[i] > '9'){
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int utn_getFloat(float * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	float numeroIngresado;
	retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo >= minimo){
		do{
			printf(mensaje);
			if(getFloat(&numeroIngresado) == 0 && (numeroIngresado <= maximo && numeroIngresado >= minimo)){
				*pResultado = numeroIngresado;
				retorno = 0;
				break;
			}
			else{
				printf(mensajeError);
				reintentos--;
			}
			fflush(stdin);
		}while(reintentos > 0);
	}
	return retorno;
}

static int getFloat(float * pResultado){
	int retorno;
	char buffer[64];
	retorno = -1;
	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) == 0 && esFlotante(buffer) == 0){
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static int esFlotante(char * cadena){
	int i;
	int retorno;
	int flagParteDecimal;
	i = 0;
	retorno = 0;
	flagParteDecimal = 0;
	if(cadena != NULL && strlen(cadena) > 0){
		if(cadena[0] == '-'){
			i = 1;
		}
		for(; cadena[i] != '\0'; i++){
			if(cadena[i] == '.' && flagParteDecimal == 0){
				flagParteDecimal = 1;
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9'){
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

static int myGets(char * cadena, int longitud){
	int retorno = -1;
	if(cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena){
		fflush(stdin);
		if(cadena[strlen(cadena) - 1] == '\n'){
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}
