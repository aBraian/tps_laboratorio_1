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
#include "ingresoDatos.h"
#include "jugador.h"

int incrementarIdJugadores(){
	static int idJugadores = 0;
	idJugadores++;
	return idJugadores;
}

int contadorIdJugadores(int opcion){
	static int contadorJugadoresId = 0;
	if(opcion == 1){
		contadorJugadoresId++;
	}
	return contadorJugadoresId;
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

int listarJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int i;
	int x;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0){
		printf("======================================================================================================================"
			   "\n"
			   "|%-116s|"
			   "\n"
			   "----------------------------------------------------------------------------------------------------------------------"
			   "\n"
			   "|%-6s|%-30s|%-15s|%-13s|%-12s|%-15s|%-19s|\n"
			   , "Listado Jugadores","ID", "NOMBRE", "POSICION", "N° CAMISETA", "SUELDO", "CONFEDERACION", "ANIOS de CONTRATO");
		for(i = 0; i < longitudJugadores; i++){
			for(x = 0; x < longitudConfederaciones; x++){
				if(jugadores[i].isEmpty == LLENO && jugadores[i].idConfederacion == confederaciones[x].id){
					printf("|%-6d|%-30s|%-15s|%-13d|%-12.2f|%-15s|%-19d|\n"
						   , jugadores[i].id, jugadores[i].nombre, jugadores[i].posicion
						   , jugadores[i].numeroCamiseta, jugadores[i].salario, confederaciones[x].nombre, jugadores[i].aniosContrato);
				}
			}
		}
		retorno = 0;
		printf("======================================================================================================================"
			   "\n");
	}
	return retorno;
}

int buscarVacioJugadores(eJugador jugadores[], int longitud){
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

int buscarIdJugadores(eJugador jugadores[], int longitud, int idBuscada){
	int retorno;
	int i;
	retorno = -1;
	if(jugadores != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			if(jugadores[i].isEmpty == LLENO && jugadores[i].id == idBuscada){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int ordenarIdJugadores(eJugador jugadores[], int longitud){
	int retorno;
	int i;
	int flagSwap;
	eJugador buffer;
	retorno = -1;
	if(jugadores != NULL && longitud > 0){
		do{
			flagSwap = 0;
			for(i = 0; i < longitud - 1; i++){
				if(jugadores[i].isEmpty == LLENO && jugadores[i].id > jugadores[i + 1].id){
					buffer = jugadores[i];
					jugadores[i] = jugadores[i + 1];
					jugadores[i + 1] = buffer;
					flagSwap = 1;
				}
			}
			longitud--;
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}

int altaJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int indiceVacio;
	int indiceConfederacion;
	int bufferCamiseta;
	int bufferContrato;
	int flagPosicion;
	float bufferSalario;
	char bufferNombre[LONGITUD_NOMBRE];
	char bufferPosicion[15];
	retorno = -1;
	if(jugadores != NULL && longitudJugadores > 0 && confederaciones != NULL && longitudConfederaciones > 0){
		indiceVacio = buscarVacioJugadores(jugadores, longitudJugadores);
		if(indiceVacio != -1 &&
		   utn_getInt(&bufferCamiseta, "Ingrese numero de camiseta: ", "NUMERO NO VALIDO (MINIMO 1 - MAXIMO 99)\n", 1, 99, 2) == 0 &&
		   utn_getInt(&bufferContrato, "Ingrese anios de contrato: ", "ANIO NO VALIDO (MINIMO 1 - MAXIMO 10)\n", 1, 10, 2) == 0 &&
		   utn_getFloat(&bufferSalario, "Ingrese salario: $", "PRECIO NO VALIDO(MINIMO 37000 - MAXIMO 4750000)\n", 37000, 4750000, 2) == 0 &&
		   utn_getString(bufferNombre, LONGITUD_NOMBRE, "Ingrese nombre: ", "ERROR\n", 2) == 0){
			do{
				if(utn_getString(bufferPosicion, 15, "Ingrese posicion: ", "ERROR\n", 1) == 0 && convertirEnMinuscula(bufferPosicion, 15) == 0){
					flagPosicion = 0;
					if(strcmp(bufferPosicion, "arquero") != 0 && strcmp(bufferPosicion, "defensor") != 0 && strcmp(bufferPosicion, "mediocampista") != 0 &&
					   strcmp(bufferPosicion, "delantero") != 0){
						flagPosicion = 1;
						printf("POSICIONES: ARQUERO-DEFENSOR-MEDIOCAMPISTA-DELANTERO\n");
					}
				}
			}while(flagPosicion);
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
				jugadores[indiceVacio].isEmpty = LLENO;
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
			printf(MENSAJE_ERROR);
		}
	}
	return retorno;
}

int bajaJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int idBuscada;
	int idMaxima;
	int indiceIdBuscada;
	retorno = -1;
	if(jugadores != NULL && longitudJugadores > 0){
		idMaxima = contadorIdJugadores(BAJA);
		if(idMaxima > 0 && ordenarIdJugadores(jugadores, longitudJugadores) == 0 &&
		   listarJugadores(confederaciones, longitudConfederaciones, jugadores, longitudJugadores) == 0 &&
		   utn_getInt(&idBuscada, "Ingrese ID a dar de baja: ", "NO SE ENCONTRO LA ID INGRESADA\n", 1, idMaxima, 2) == 0){
			indiceIdBuscada = buscarIdJugadores(jugadores, longitudJugadores, idBuscada);
			printf("\n");
			if(indiceIdBuscada != -1){
				jugadores[indiceIdBuscada].isEmpty = VACIO;
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

int modificarJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int idBuscada;
	int idMaxima;
	int indiceIdBuscada;
	int indiceConfederacion;
	int submenuModificar;
	int bufferCamiseta;
	int bufferContrato;
	int flagPosicion;
	float bufferSalario;
	char bufferNombre[LONGITUD_NOMBRE];
	char bufferPosicion[15];
	retorno = -1;
	if(jugadores != NULL && longitudJugadores > 0 && confederaciones != NULL && longitudConfederaciones > 0){
		printf("Submenu Modificar Jugadores\n"
			   "\n"
			   "1. MODIFICAR NOMBRE\n"
			   "2. MODIFICAR POSICION\n"
			   "3. MODIFICAR NUMERO DE CAMISETA\n"
			   "4. MODIFICAR CONFEDERACION\n"
			   "5. MODIFICAR SALARIO\n"
			   "6. MODIFICAR ANIOS DE CONTRATO\n"
			   "\n");
		idMaxima = contadorIdJugadores(BAJA);
		if(utn_getInt(&submenuModificar, "OPCION: ", "OPCION NO VALIDA\n", 1, 6, 2) == 0 &&
		   idMaxima > 0 && ordenarIdJugadores(jugadores, longitudJugadores) == 0 &&
		   listarJugadores(confederaciones, longitudConfederaciones, jugadores, longitudJugadores) == 0 &&
		   utn_getInt(&idBuscada, "Ingrese ID a modificar: ", "NO SE ENCONTRO LA ID INGRESADA\n", 1, idMaxima, 2) == 0){
			indiceIdBuscada = buscarIdJugadores(jugadores, longitudJugadores, idBuscada);
			printf("\n");
			if(indiceIdBuscada != -1){
				switch(submenuModificar){
				case 1:
					if(utn_getString(bufferNombre, LONGITUD_NOMBRE, "Ingrese nombre: ", "ERROR\n", 2) == 0){
						strcpy(jugadores[indiceIdBuscada].nombre, bufferNombre);
					}
					else{
						printf("\nCAMBIOS NO APLICADOS\n");
					}
					break;
				case 2:
					do{
						if(utn_getString(bufferPosicion, 15, "Ingrese posicion: ", "ERROR\n", 1) == 0 &&
						   convertirEnMinuscula(bufferPosicion, 15) == 0){
							flagPosicion = 0;
							if(strcmp(bufferPosicion, "arquero") != 0 && strcmp(bufferPosicion, "defensor") != 0 &&
							   strcmp(bufferPosicion, "mediocampista") != 0 && strcmp(bufferPosicion, "delantero") != 0){
								flagPosicion = 1;
								printf("\nPOSICIONES: ARQUERO-DEFENSOR-MEDIOCAMPISTA-DELANTERO\n");
							}
							else{
								strcpy(jugadores[indiceIdBuscada].posicion, bufferPosicion);
							}
						}
						else{
							printf("\nCAMBIOS NO APLICADOS\n\n");
						}
					}while(flagPosicion);
					break;
				case 3:
					if(utn_getInt(&bufferCamiseta, "Ingrese numero de camiseta: ", "NUMERO NO VALIDO (MINIMO 1 - MAXIMO 99)\n", 1, 99, 2) == 0){
						jugadores[indiceIdBuscada].numeroCamiseta = (short)bufferCamiseta;
					}
					else{
						printf("\nCAMBIOS NO APLICADOS\n");
					}
					break;
				case 4:
					indiceConfederacion = selecionarConfederacion(confederaciones, longitudConfederaciones);
					if(indiceConfederacion != -1){
						jugadores[indiceIdBuscada].idConfederacion = confederaciones[indiceConfederacion].id;
					}
					else{
						printf("\nCAMBIOS NO APLICADOS\n");
					}
					break;
				case 5:
					if(utn_getFloat(&bufferSalario, "Ingrese salario: $", "PRECIO NO VALIDO(MINIMO 37000 - MAXIMO 4750000)\n", 37000, 4750000, 2) == 0){
						jugadores[indiceIdBuscada].salario = bufferSalario;
					}
					else{
						printf("\nCAMBIOS NO APLICADOS\n");
					}
					break;
				case 6:
					if(utn_getInt(&bufferContrato, "Ingrese anios de contrato: ", "ANIO NO VALIDO (MINIMO 1 - MAXIMO 10)\n", 1, 10, 2) == 0){
						jugadores[indiceIdBuscada].aniosContrato = (short)bufferContrato;
					}
					else{
						printf("\nCAMBIOS NO APLICADOS\n");
					}
					break;
				}
			}
			retorno = 0;
		}
	}
	return retorno;
}
