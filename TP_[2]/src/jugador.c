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
#include "ingresoDatos.h"

int incrementarIdJugadores(){
	static int idJugadores = 0;
	idJugadores++;
	return idJugadores;
}

int inicializarJugadores(eJugador aJugadores[], int longitud){
	int retorno;
	int i;
	retorno = -1;
	if(aJugadores != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			aJugadores[i].id = 0;
			strcpy(aJugadores[i].nombre, "");
			strcpy(aJugadores[i].posicion, "");
			aJugadores[i].numeroCamiseta = 0;
			aJugadores[i].idConfederacion = 0;
			aJugadores[i].salario = 0;
			aJugadores[i].aniosContrato = 0;
			aJugadores[i].isEmpty = VACIO;
		}
		retorno = 0;
	}
	return retorno;
}

int buscarVacioJugadores(eJugador aJugadores[], int longitud){
	int retorno;
	int i;
	retorno = -1;
	if(aJugadores != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			if(aJugadores[i].isEmpty == VACIO){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores){
	short bufferCamiseta;
	short bufferContrato;
	int retorno;
	int indiceVacio;
	int bufferConfederacion;
	int flagPosicion;
	float bufferSalario;
	char bufferNombre[LONG_NOMBRE];
	char bufferPosicion[LONG_POSICION];
	retorno = -1;
	if(aJugadores != NULL && longitudJugadores > 0 && aConfederaciones != NULL && longitudConfederaciones > 0){
		indiceVacio = buscarVacioJugadores(aJugadores, longitudJugadores);
		if(indiceVacio != -1 &&
		   utn_getString(bufferNombre, LONG_NOMBRE, "Ingrese nombre: ", "ERROR - CARACTER NO VALIDO\n", 2) == 0){
			do{
				if(utn_getString(bufferPosicion, LONG_POSICION, "Ingrese posicion (ARQUERO, DEFENSOR, MEDIOCAMPISTA o DELANTERO): ", "ERROR - CARACTER NO VALIDO\n", 1) == 0 &&
				   convertirEnMinuscula(bufferPosicion, LONG_POSICION) == 0){
					flagPosicion = 0;
					if(strcmp(bufferPosicion, "arquero") != 0 &&
					   strcmp(bufferPosicion, "defensor") != 0 &&
					   strcmp(bufferPosicion, "mediocampista") != 0 &&
					   strcmp(bufferPosicion, "delantero") != 0){
						flagPosicion = 1;
						printf("\nINGRESE: ARQUERO, DEFENSOR, MEDIOCAMPISTA o DELANTERO\n\n");
					}
				}
			}while(flagPosicion);
			if(utn_getShort(&bufferCamiseta, "Ingrese numero de camiseta (MINIMO 1 - MAXIMO 99): ", "NUMERO NO VALIDO (MINIMO 1 - MAXIMO 99)\n", 1, 99, 2) == 0 &&
			   listarConfederaciones(aConfederaciones, longitudConfederaciones) == 0 &&
			   utn_getInt(&bufferConfederacion, "Ingrese ID confederacion: ", "ID NO VALIDA\n", 100, 105, 2) == 0 &&
			   utn_getFloat(&bufferSalario, "Ingrese salario (MINIMO 1 - MAXIMO 5000000): $", "SALARIO NO VALIDO (MINIMO 1 - MAXIMO 5000000)\n", 1, 5000000, 2) == 0 &&
			   utn_getShort(&bufferContrato, "Ingrese anios de contrato (MINIMO 1 - MAXIMO 10): ", "ANIO NO VALIDO (MINIMO 1 - MAXIMO 10)\n", 1, 10, 2) == 0){
				aJugadores[indiceVacio].id = incrementarIdJugadores();
				strcpy(aJugadores[indiceVacio].nombre, bufferNombre);
				strcpy(aJugadores[indiceVacio].posicion, bufferPosicion);
				aJugadores[indiceVacio].numeroCamiseta = bufferCamiseta;
				aJugadores[indiceVacio].idConfederacion = bufferConfederacion;
				aJugadores[indiceVacio].salario = bufferSalario;
				aJugadores[indiceVacio].aniosContrato = bufferContrato;
				aJugadores[indiceVacio].isEmpty = LLENO;
				retorno = 0;
				printf(MENSAJE_EXITO);
			}
			else{
				printf(MENSAJE_ERROR);
				}
			}
		else if(indiceVacio == -1){
			printf("LIMITE DE JUGADORES ALCANZADO\n");
		}
		else{
			printf("\n");
			printf(MENSAJE_ERROR);
		}
	}
	return retorno;
}

int ordenarIdJugadores(eJugador aJugadores[], int longitud){
	int retorno;
	int i;
	int flagSwap;
	eJugador buffer;
	retorno = -1;
	if(aJugadores != NULL && longitud > 0){
		do{
			flagSwap = 0;
			for(i = 0; i < longitud - 1; i++){
				if(aJugadores[i].id > aJugadores[i + 1].id){
					buffer = aJugadores[i];
					aJugadores[i] = aJugadores[i + 1];
					aJugadores[i + 1] = buffer;
					flagSwap = 1;
				}
			}
			longitud--;
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}

int listarJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores){
	int retorno;
	int i;
	char auxNombreConfederacion[LONG_NOMBRE];
	retorno = -1;
	if(aConfederaciones != NULL && longitudConfederaciones > 0 && aJugadores != NULL && longitudJugadores > 0){
		printf("======================================================================================================================"
			   "\n"
			   "|%-116s|"
			   "\n"
			   "----------------------------------------------------------------------------------------------------------------------"
			   "\n"
			   "|%-6s|%-30s|%-15s|%-13s|%-12s|%-15s|%-19s|\n"
			   , "Listado Jugadores","ID", "NOMBRE", "POSICION", "N° CAMISETA", "SUELDO", "CONFEDERACION", "ANIOS de CONTRATO");
		for(i = 0; i < longitudJugadores; i++){
			if(aJugadores[i].isEmpty == LLENO &&
			   obtenerNombreConfederacion(aConfederaciones, longitudConfederaciones, aJugadores[i].idConfederacion, auxNombreConfederacion) == 0){
				printf("|%-6d|%-30s|%-15s|%-13d|%-12.2f|%-15s|%-19d|\n"
					   , aJugadores[i].id, aJugadores[i].nombre, aJugadores[i].posicion
					   , aJugadores[i].numeroCamiseta, aJugadores[i].salario, auxNombreConfederacion, aJugadores[i].aniosContrato);
			}
		}
		retorno = 0;
		printf("======================================================================================================================"
			   "\n");
	}
	return retorno;
}

int buscarIdJugadores(eJugador aJugadores[], int longitud, int idBuscada){
	int retorno;
	int i;
	retorno = -1;
	if(aJugadores != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			if(aJugadores[i].isEmpty == LLENO && aJugadores[i].id == idBuscada){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int buscarIdMaximaJugadores(eJugador aJugadores[], int longitud){
	int retorno;
	int i;
	int flagMaximo;
	retorno = -1;
	flagMaximo = 0;
	if(aJugadores != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			if(aJugadores[i].isEmpty == LLENO && flagMaximo == 0){
				retorno = aJugadores[i].id;
				flagMaximo = 1;
			}
			else if(aJugadores[i].isEmpty == LLENO && aJugadores[i].id > retorno){
				retorno = aJugadores[i].id;
			}
		}
	}
	return retorno;
}

int bajaJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores){
	int retorno;
	int bufferIdBuscada;
	int idMaxima;
	int indiceIdBuscada;
	retorno = -1;
	if(aJugadores != NULL && longitudJugadores > 0){
		idMaxima = buscarIdMaximaJugadores(aJugadores, longitudJugadores);
		if(idMaxima != -1 &&
		   ordenarIdJugadores(aJugadores, longitudJugadores) == 0 &&
		   listarJugadores(aConfederaciones, longitudConfederaciones, aJugadores, longitudJugadores) == 0 &&
		   utn_getInt(&bufferIdBuscada, "Ingrese ID a dar de baja: ", "NO SE ENCONTRO LA ID INGRESADA\n", 1, idMaxima, 2) == 0){
			indiceIdBuscada = buscarIdJugadores(aJugadores, longitudJugadores, bufferIdBuscada);
			printf("\n");
			if(indiceIdBuscada != -1){
				aJugadores[indiceIdBuscada].isEmpty = VACIO;
				retorno = 0;
				printf("SE DIO DE BAJA - SE ENCONTRO LA ID INGRESADA\n");
			}
			else{
				printf("\nNO SE DIO DE BAJA - NO SE ENCONTRO LA ID INGRESADA\n");
			}
		}
		else{
			printf("\nNO SE DIO DE BAJA - NO SE ENCONTRO LA ID INGRESADA\n");
		}
	}
	return retorno;
}

int modificarJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores){
	short bufferCamiseta;
	short bufferContrato;
	int retorno;
	int idBuscada;
	int idMaxima;
	int indiceIdBuscada;
	int submenuModificar;
	int bufferConfederacion;
	int flagPosicion;
	float bufferSalario;
	char bufferNombre[LONG_NOMBRE];
	char bufferPosicion[LONG_POSICION];
	retorno = -1;
	if(aJugadores != NULL && longitudJugadores > 0 && aConfederaciones != NULL && longitudConfederaciones > 0){
		idMaxima = buscarIdMaximaJugadores(aJugadores, longitudJugadores);
		if(idMaxima != -1){
			printf("Submenu Modificar Jugadores\n"
				   "\n"
				   "1. MODIFICAR NOMBRE\n"
				   "2. MODIFICAR POSICION\n"
				   "3. MODIFICAR NUMERO DE CAMISETA\n"
				   "4. MODIFICAR CONFEDERACION\n"
				   "5. MODIFICAR SALARIO\n"
				   "6. MODIFICAR ANIOS DE CONTRATO\n"
				   "\n");
			if(utn_getInt(&submenuModificar, "OPCION: ", "OPCION NO VALIDA\n", 1, 6, 2) == 0
			   && ordenarIdJugadores(aJugadores, longitudJugadores) == 0 &&
			   listarJugadores(aConfederaciones, longitudConfederaciones, aJugadores, longitudJugadores) == 0 &&
			   utn_getInt(&idBuscada, "Ingrese ID a modificar: ", "NO SE ENCONTRO LA ID INGRESADA\n", 1, idMaxima, 2) == 0){
				indiceIdBuscada = buscarIdJugadores(aJugadores, longitudJugadores, idBuscada);
				if(indiceIdBuscada != -1){
					printf("\n");
					switch(submenuModificar){
						case 1:
							if(utn_getString(bufferNombre, LONG_NOMBRE, "Ingrese nombre: ", "ERROR - CARACTER NO VALIDO\n", 2) == 0){
								strcpy(aJugadores[indiceIdBuscada].nombre, bufferNombre);
							}
							else{
								printf("\nCAMBIOS NO APLICADOS\n");
							}
							break;
						case 2:
							do{
								if(utn_getString(bufferPosicion, LONG_POSICION, "Ingrese posicion (ARQUERO, DEFENSOR, MEDIOCAMPISTA o DELANTERO): ", "ERROR - CARACTER NO VALIDO\n", 1) == 0 &&
								   convertirEnMinuscula(bufferPosicion, 15) == 0){
									flagPosicion = 0;
									if(strcmp(bufferPosicion, "arquero") != 0 && strcmp(bufferPosicion, "defensor") != 0 &&
									   strcmp(bufferPosicion, "mediocampista") != 0 && strcmp(bufferPosicion, "delantero") != 0){
										flagPosicion = 1;
										printf("\nINGRESE: ARQUERO, DEFENSOR, MEDIOCAMPISTA o DELANTERO\n\n");
									}
									else{
										strcpy(aJugadores[indiceIdBuscada].posicion, bufferPosicion);
									}
								}
								else{
									printf("\nCAMBIOS NO APLICADOS\n\n");
								}
							}while(flagPosicion);
							break;
						case 3:
							if(utn_getShort(&bufferCamiseta, "Ingrese numero de camiseta (MINIMO 1 - MAXIMO 99): ", "NUMERO NO VALIDO (MINIMO 1 - MAXIMO 99)\n", 1, 99, 2) == 0){
								aJugadores[indiceIdBuscada].numeroCamiseta = bufferCamiseta;
							}
							else{
								printf("\nCAMBIOS NO APLICADOS\n");
							}
							break;
						case 4:
							if(listarConfederaciones(aConfederaciones, longitudConfederaciones) == 0 &&
							   utn_getInt(&bufferConfederacion, "Ingrese ID confederacion: ", "ID NO VALIDA\n", 100, 105, 2) == 0){
								aJugadores[indiceIdBuscada].idConfederacion = bufferConfederacion;
							}
							else{
								printf("\nCAMBIOS NO APLICADOS\n");
							}
							break;
						case 5:
							if(utn_getFloat(&bufferSalario, "Ingrese salario (MINIMO 1 - MAXIMO 5000000): $", "SALARIO NO VALIDO (MINIMO 1 - MAXIMO 5000000)\n", 1, 5000000, 2) == 0){
								aJugadores[indiceIdBuscada].salario = bufferSalario;
							}
							else{
								printf("\nCAMBIOS NO APLICADOS\n");
							}
							break;
						case 6:
							if(utn_getShort(&bufferContrato, "Ingrese anios de contrato (MINIMO 1 - MAXIMO 10): ", "ANIO NO VALIDO (MINIMO 1 - MAXIMO 10)\n", 1, 10, 2) == 0){
								aJugadores[indiceIdBuscada].aniosContrato = bufferContrato;
							}
							else{
								printf("\nCAMBIOS NO APLICADOS\n");
							}
							break;
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}
