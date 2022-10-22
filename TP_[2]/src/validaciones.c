/*
 * validaciones.c
 *
 *  Created on: 18 oct. 2022
 *      Author: braian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief Solicita un numero al usuario y verifica que sea de tipo entero
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int getInt(int *pResultado);

/// @brief Valida que lo ingresado sea de tipo entero
///
/// @param cadena Cadena que se recorre validando que sean caracteres permitidos por un entero
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int isInt(char *cadena);

/// @brief Solicita un numero al usuario y verifica que sea de tipo flotante
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int getFloat(float *pResultado);

/// @brief Valida que lo ingresado sea de tipo flotante
///
/// @param cadena Cadena que se recorre validando que sean caracteres permitidos por un flotante
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int isFloat(char *cadena);

/// @brief Solicita una cadena de caracteres al usuario y verifica que sea de tipo caracter
///
/// @param pResultado Array donde se dejara el resultado de la funcion
/// @param longitudArray Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int getString(char * pResultado, int longitudArray);

/// @brief Valida que lo ingresado sea de tipo cadena de caracteres
///
/// @param cadena Cadena que se recorre validando que sean caracteres permitidos por una cadena de caracteres
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int isString(char * cadena);

/// @brief Toma los datos de manera segura
///
/// @param cadena Cadena que toma los datos ingresados
/// @param longitud Tamaño de la cadena
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int myGets(char *cadena, int longitud);

int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos){
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

static int getInt(int *pResultado){
	int retorno;
	char buffer[64];
	retorno = -1;
	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) == 0 && isInt(buffer) == 0){
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static int isInt(char *cadena){
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

int utn_getFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos){
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

static int getFloat(float *pResultado){
	int retorno;
	char buffer[64];
	retorno = -1;
	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) == 0 && isFloat(buffer) == 0){
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static int isFloat(char *cadena){
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

int utn_getString(char pResultado[], int longitudArray, char * mensaje, char * mensajeError, int reintentos){
	int retorno;
	char nombreIngresado[longitudArray];
	retorno = -1;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && longitudArray > 0){
		do{
			printf(mensaje);
			if(getString(nombreIngresado, longitudArray) == 0){
				strcpy(pResultado, nombreIngresado);
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

static int getString(char * pResultado, int longitudArray){
	int retorno;
	char buffer[longitudArray];
	retorno = -1;
	if(pResultado != NULL){
		if(myGets(buffer, longitudArray) == 0 && isString(buffer) == 0){
			strcpy(pResultado, buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static int isString(char * cadena){
	int i;
	int retorno;
	retorno = 0;
	if(cadena != NULL && strlen(cadena) > 0){
		for(i = 0; cadena[i] != '\0'; i++){
			if(cadena[i] == ' '){
				continue;
			}
			if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z')){
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

static int myGets(char *cadena, int longitud){
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

void convertirEnMinuscula(char cadena[], int longitud){
	int i;
	for(i = 0; i < longitud; i++){
		cadena[i] = tolower(cadena[i]);
	}
}
