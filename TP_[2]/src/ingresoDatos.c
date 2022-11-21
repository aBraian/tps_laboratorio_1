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

/// @brief Solicita un numero al usuario y verifica que sea de tipo short
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int getShort(short* pResultado);

/// @brief Valida que lo ingresado sea de tipo short
///
/// @param pCadena Cadena que se recorre validando que sean caracteres permitidos por un short
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int isShort(char* pCadena);

/// @brief Solicita un numero al usuario y verifica que sea de tipo entero
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int getInt(int* pResultado);

/// @brief Valida que lo ingresado sea de tipo entero
///
/// @param pCadena Cadena que se recorre validando que sean caracteres permitidos por un entero
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int isInt(char* pCadena);

/// @brief Solicita un numero al usuario y verifica que sea de tipo flotante
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int getFloat(float* pResultado);

/// @brief Valida que lo ingresado sea de tipo flotante
///
/// @param pCadena Cadena que se recorre validando que sean caracteres permitidos por un flotante
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int isFloat(char* pCadena);

/// @brief Solicita una cadena de caracteres al usuario y verifica que sea de tipo caracter
///
/// @param pResultado Array donde se dejara el resultado de la funcion
/// @param longitud Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int getString(char* pResultado, int longitud);

/// @brief Valida que lo ingresado sea de tipo cadena de caracteres
///
/// @param pCadena Cadena que se recorre validando que sean caracteres permitidos por una cadena de caracteres
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int isString(char* pCadena);

/// @brief Toma los datos de manera segura
///
/// @param pCadena Cadena que toma los datos ingresados
/// @param longitud Tamaño de la cadena
/// @return Retorna 0 (EXITO) y -1 (ERROR)
static int myGets(char* pCadena, int longitud);

int utn_getShort(short* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	short numeroIngresado;
	retorno = -1;
	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && maximo >= minimo){
		do{
			printf(pMensaje);
			if(getShort(&numeroIngresado) == 0 && (numeroIngresado <= maximo && numeroIngresado >= minimo)){
				*pResultado = numeroIngresado;
				retorno = 0;
				break;
			}
			else{
				reintentos--;
				printf(pMensajeError);
				if(reintentos != 0){
					printf("Cantidad intentos: %d\n\n", reintentos);
				}
			}
			fflush(stdin);
		}while(reintentos > 0);
	}
	return retorno;
}

static int getShort(short* pResultado){
	int retorno;
	char buffer[64];
	retorno = -1;
	if(pResultado != NULL){
		if(myGets(buffer, sizeof(buffer)) == 0 && isShort(buffer) == 0){
			*pResultado = (short)atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static int isShort(char* pCadena){
	int i;
	int retorno;
	i = 0;
	retorno = 0;
	if(pCadena != NULL && strlen(pCadena) > 0){
		if(pCadena[0] == '-'){
				i = 1;
		}
		for(; pCadena[i] != '\0'; i++){
			if(pCadena[i] < '0' || pCadena[i] > '9'){
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int utn_getInt(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	int numeroIngresado;
	retorno = -1;
	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && maximo >= minimo){
		do{
			printf(pMensaje);
			if(getInt(&numeroIngresado) == 0 && (numeroIngresado <= maximo && numeroIngresado >= minimo)){
				*pResultado = numeroIngresado;
				retorno = 0;
				break;
			}
			else{
				reintentos--;
				printf(pMensajeError);
				if(reintentos != 0){
					printf("Cantidad intentos: %d\n\n", reintentos);
				}
			}
			fflush(stdin);
		}while(reintentos > 0);
	}
	return retorno;
}

static int getInt(int* pResultado){
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

static int isInt(char* pCadena){
	int i;
	int retorno;
	i = 0;
	retorno = 0;
	if(pCadena != NULL && strlen(pCadena) > 0){
		if(pCadena[0] == '-'){
				i = 1;
		}
		for(; pCadena[i] != '\0'; i++){
			if(pCadena[i] < '0' || pCadena[i] > '9'){
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos){
	int retorno;
	float numeroIngresado;
	retorno = -1;
	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && maximo >= minimo){
		do{
			printf(pMensaje);
			if(getFloat(&numeroIngresado) == 0 && (numeroIngresado <= maximo && numeroIngresado >= minimo)){
				*pResultado = numeroIngresado;
				retorno = 0;
				break;
			}
			else{
				reintentos--;
				printf(pMensajeError);
				if(reintentos != 0){
					printf("Cantidad intentos: %d\n\n", reintentos);
				}
			}
			fflush(stdin);
		}while(reintentos > 0);
	}
	return retorno;
}

static int getFloat(float* pResultado){
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

static int isFloat(char* pCadena){
	int i;
	int retorno;
	int flagParteDecimal;
	i = 0;
	retorno = 0;
	flagParteDecimal = 0;
	if(pCadena != NULL && strlen(pCadena) > 0){
		if(pCadena[0] == '-'){
			i = 1;
		}
		for(; pCadena[i] != '\0'; i++){
			if(pCadena[i] == '.' && flagParteDecimal == 0){
				flagParteDecimal = 1;
				continue;
			}
			if(pCadena[i] < '0' || pCadena[i] > '9'){
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

int utn_getString(char aResultado[], int longitud, char* pMensaje, char* pMensajeError, int reintentos){
	int retorno;
	char auxNombre[longitud];
	retorno = -1;
	if(aResultado != NULL && pMensaje != NULL && pMensajeError != NULL && longitud > 0){
		do{
			printf(pMensaje);
			if(getString(auxNombre, longitud) == 0){
				strcpy(aResultado, auxNombre);
				retorno = 0;
				break;
			}
			else{
				reintentos--;
				printf(pMensajeError);
				if(reintentos != 0){
					printf("Cantidad intentos: %d\n\n", reintentos);
				}
			}
			fflush(stdin);
		}while(reintentos > 0);
	}
	return retorno;
}

static int getString(char* pResultado, int longitud){
	int retorno;
	char buffer[longitud];
	retorno = -1;
	if(pResultado != NULL){
		if(myGets(buffer, longitud) == 0 && isString(buffer) == 0){
			strcpy(pResultado, buffer);
			retorno = 0;
		}
	}
	return retorno;
}

static int isString(char* pCadena){
	int i;
	int retorno;
	retorno = 0;
	if(pCadena != NULL && strlen(pCadena) > 0){
		for(i = 0; pCadena[i] != '\0'; i++){
			if(pCadena[i] == ' '){
				continue;
			}
			if((pCadena[i] < 'a' || pCadena[i] > 'z') && (pCadena[i] < 'A' || pCadena[i] > 'Z')){
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}

static int myGets(char* pCadena, int longitud){
	int retorno = -1;
	if(pCadena != NULL && longitud > 0 && fgets(pCadena, longitud, stdin) == pCadena){
		fflush(stdin);
		if(pCadena[strlen(pCadena) - 1] == '\n'){
			pCadena[strlen(pCadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int convertirEnMinuscula(char aCadena[], int longitud){
	int i;
	int retorno;
	retorno = -1;
	if(aCadena != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			aCadena[i] = tolower(aCadena[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int salirMenu(void){
	int retorno;
	int flagSalida;
	char respuesta[2];
	retorno = -1;
	do{
		if(utn_getString(respuesta, 2, "Desea salir (SI/NO): ", "ERROR\n", 1) == 0 &&
		   convertirEnMinuscula(respuesta, 2) == 0){
			flagSalida = 0;
			if(strcmp(respuesta, "s") != 0 && strcmp(respuesta, "n") != 0){
				flagSalida = 1;
				printf("\nINGRESE 'SI' O 'NO'\n\n");
			}
			else if(strcmp(respuesta, "s") == 0){
				retorno = 0;
			}
		}
	}while(flagSalida);
	return retorno;
}
