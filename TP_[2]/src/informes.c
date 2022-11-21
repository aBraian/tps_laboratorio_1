/*
 * informes.c
 *
 *  Created on: 22 oct. 2022
 *      Author: braian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"
#include "jugador.h"
#include "calculos.h"
#include "informes.h"
#include "ingresoDatos.h"

int ordenarNombres(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores){
	int retorno;
	int i;
	int flagSwap;
	char auxConfederacionUno[LONG_NOMBRE];
	char auxConfederacionDos[LONG_NOMBRE];
	eJugador bufferSwap;
	retorno = -1;
	if(aConfederaciones != NULL && longitudConfederaciones > 0 && aJugadores != NULL && longitudJugadores > 0){
		do{
			flagSwap = 0;
			for(i = 0; i < longitudJugadores - 1; i++){
				if(obtenerNombreConfederacion(aConfederaciones, longitudConfederaciones, aJugadores[i].idConfederacion, auxConfederacionUno) == 0 &&
				   obtenerNombreConfederacion(aConfederaciones, longitudConfederaciones, aJugadores[i + 1].idConfederacion, auxConfederacionDos) == 0){
					if(strcmp(auxConfederacionUno, auxConfederacionDos) > 0){
						bufferSwap = aJugadores[i];
						aJugadores[i] = aJugadores[i + 1];
						aJugadores[i + 1] = bufferSwap;
						flagSwap = 1;
					}
					else if(strcmp(auxConfederacionUno, auxConfederacionDos) == 0){
						if(strcmp(aJugadores[i].nombre, aJugadores[i + 1].nombre) > 0){
							bufferSwap = aJugadores[i];
							aJugadores[i] = aJugadores[i + 1];
							aJugadores[i + 1] = bufferSwap;
							flagSwap = 1;
						}
					}
				}
			}
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}

int existenJugadores(eJugador aJugadores[], int longitudJugadores, int idConfederacion){
	int retorno;
	int i;
	retorno = -1;
	if(aJugadores != NULL && longitudJugadores > 0 && idConfederacion >= 100){
		for(i = 0; i < longitudJugadores; i++){
			if(aJugadores[i].idConfederacion == idConfederacion){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int listarConfederacionesConJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores){
	int retorno;
	int i;
	int x;
	retorno = -1;
	if(aConfederaciones != NULL && longitudConfederaciones > 0 && aJugadores != NULL && longitudJugadores > 0){
		for(i = 0; i < longitudConfederaciones; i++){
			if(existenJugadores(aJugadores, longitudJugadores, aConfederaciones[i].id) == 0){
				printf("======================================================================================================"
					   "\n"
					   "|Listado Jugadores de %-79s|"
					   "\n"
					   "------------------------------------------------------------------------------------------------------"
					   "\n"
					   "|%-6s|%-30s|%-15s|%-13s|%-12s|%-19s|\n"
					   , aConfederaciones[i].nombre,"ID", "NOMBRE", "POSICION", "N° CAMISETA", "SUELDO", "ANIOS de CONTRATO");
				for(x = 0; x < longitudJugadores; x++){
					if(aJugadores[x].isEmpty == LLENO &&
					   aConfederaciones[i].id == aJugadores[x].idConfederacion){
						printf("|%-6d|%-30s|%-15s|%-13d|%-12.2f|%-19d|\n"
							   , aJugadores[x].id, aJugadores[x].nombre, aJugadores[x].posicion
							   , aJugadores[x].numeroCamiseta, aJugadores[x].salario, aJugadores[x].aniosContrato);
					}
				}
				printf("======================================================================================================"
					   "\n");
			}
		}
		retorno = 0;
	}
	return retorno;
}

int listarSalarios(eJugador aJugadores[], int longitudJugadores, int cantidadSalarios, float totalSalarios, float promedioSalarios){
	int retorno;
	retorno = -1;
	if(aJugadores != NULL && longitudJugadores > 0){
		printf("====================================================================================="
			   "\n"
			   "|%-83s|"
			   "\n"
			   "-------------------------------------------------------------------------------------"
			   "\n"
			   "|%-19s|%-22s|%-40s|\n"
			   "|$%-18.2f|$%-21.2f|%-40d|\n"
			   , "Listado Salarios", "TOTAL DE SALARIOS", "PROMEDIO DE SALARIOS", "CANTIDAD DE SALARIOS MAYOR AL PROMEDIO"
			   , totalSalarios, promedioSalarios, cantidadSalarios);
		printf("====================================================================================="
			   "\n");
		retorno = 0;
	}
	return retorno;
}

int listarConfederacionMasAniosContrato(int cantidadAnios, char aNombreConfederacion[]){
	int retorno;
	retorno = -1;
	if(aNombreConfederacion != NULL && cantidadAnios > 0){
		printf("==================================================="
			   "\n"
			   "|%-49s|"
			   "\n"
			   "---------------------------------------------------"
			   "\n"
			   "|%-15s|%-33s|\n"
			   "|%-15s|%-33d|\n"
			   , "Listado Confederacion con mas Anios de Contrato", "CONFEDERACION", "CANTIDAD ANIOS"
			   , aNombreConfederacion, cantidadAnios);
		printf("==================================================="
			   "\n");
		retorno = 0;
	}
	return retorno;
}

int listarPorcentajeConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores, int contadorJugadores){
	int retorno;
	int i;
	float bufferPorcentaje;
	retorno = -1;
	if(aConfederaciones != NULL && longitudConfederaciones > 0 && aJugadores != NULL && longitudJugadores > 0){
		printf("========================================================"
			   "\n"
			   "|%-54s|"
			   "\n"
			   "--------------------------------------------------------"
			   "\n"
			   "|%-15s|%-38s|\n"
			   , "Listado de Porcentaje de Jugadores por Confederacion", "CONFEDERACION", "PORCENTAJE");
		for(i = 0; i < longitudConfederaciones; i++){
			if(calcularPorcentajeJugadores(aConfederaciones, longitudConfederaciones, aJugadores, longitudJugadores, aConfederaciones[i].id, contadorJugadores, &bufferPorcentaje) == 0){
				printf("|%-15s|%%%-37.2f|\n", aConfederaciones[i].nombre, bufferPorcentaje);
			}
		}
		retorno = 0;
		printf("========================================================"
			   "\n");
	}
	return retorno;
}

int listarRegionMasJugadores(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores){
	int retorno;
	int i;
	int auxContadorJugadores;
	int auxId;
	char auxNombreRegion[LONG_REGION];
	retorno = -1;
	if(aConfederaciones != NULL && longitudConfederaciones > 0 && aJugadores != NULL && longitudJugadores > 0){
		if(regionMasJugadores(aConfederaciones, longitudConfederaciones, aJugadores, longitudJugadores, &auxContadorJugadores, &auxId, auxNombreRegion) == 0){
			printf("======================================================"
				   "\n"
				   "|%s%-26s|"
				   "\n"
				   "------------------------------------------------------"
				   "\n"
				   "|%-6s|%-45s|\n"
				   , "Region con mas Jugadores: ", auxNombreRegion, "ID", "NOMBRE JUGADOR");
			for(i = 0; i < longitudJugadores; i++){
				if(aJugadores[i].isEmpty == LLENO && aJugadores[i].idConfederacion == auxId){
					printf("|%-6d|%-45s|\n", aJugadores[i].id, aJugadores[i].nombre);
				}
			}
		}
		retorno = 0;
		printf("======================================================"
			   "\n");
	}
	return retorno;
}

int submenuInformes(eConfederacion aConfederaciones[], int longitudConfederaciones, eJugador aJugadores[], int longitudJugadores, int contadorJugadores){
	int retorno;
	int submenu;
	int auxContadorSalariosMayores;
	int auxCantidadAnios;
	float auxTotalSalarios;
	float auxPromedio;
	char auxNombreConfederacion[50];
	retorno = -1;
	if(aConfederaciones != NULL && longitudConfederaciones > 0 && aJugadores != NULL && longitudJugadores > 0){
		do{
			printf("FIFA - Submenu Informes\n"
				   "\n"
				   "1. Listado de los jugadores ordenados alfabeticamente por nombre de confederacion y nombre de jugador\n"
				   "2. Listado de confederaciones con sus jugadores\n"
				   "3. Total y promedio de todos los salarios y cuantos jugadores cobran mas del salario promedio\n"
				   "4. Informar la confederacion con mayor cantidad de anios de contratos total\n"
				   "5. Informar porcentaje de jugadores por cada confederacion\n"
				   "6. Informar cual es la region con mas jugadores y el listado de los mismos\n"
				   "7. Volver al menu principal\n"
				   "\n");
			if(utn_getInt(&submenu, "OPCION: ", "OPCION NO VALIDA\n", 1, 7, 2) == 0){
				switch(submenu){
					case 1:
						printf("\n");
						ordenarIdJugadores(aJugadores, longitudJugadores);
						ordenarNombres(aConfederaciones, longitudConfederaciones, aJugadores, longitudJugadores);
						listarJugadores(aConfederaciones, longitudConfederaciones, aJugadores, longitudJugadores);
						printf("\n");
						break;
					case 2:
						printf("\n");
						listarConfederacionesConJugadores(aConfederaciones, longitudConfederaciones, aJugadores, longitudJugadores);
						printf("\n");
						break;
					case 3:
						printf("\n");
						acumularSalariosJugadores(aJugadores, longitudJugadores, &auxTotalSalarios);
						calcularPromedioSalarios(aJugadores, longitudJugadores, contadorJugadores, &auxPromedio);
						salariosMayorPromedio(aJugadores, longitudJugadores, &auxContadorSalariosMayores, auxPromedio);
						listarSalarios(aJugadores, longitudJugadores, auxContadorSalariosMayores, auxTotalSalarios, auxPromedio);
						printf("\n");
						break;
					case 4:
						printf("\n");
						confederacionMasAniosContrato(aConfederaciones, longitudConfederaciones, aJugadores, longitudJugadores, &auxCantidadAnios, auxNombreConfederacion);
						listarConfederacionMasAniosContrato(auxCantidadAnios, auxNombreConfederacion);
						printf("\n");
						break;
					case 5:
						printf("\n");
						listarPorcentajeConfederaciones(aConfederaciones, longitudConfederaciones, aJugadores, longitudJugadores, contadorJugadores);
						printf("\n");
						break;
					case 6:
						printf("\n");
						listarRegionMasJugadores(aConfederaciones, longitudConfederaciones, aJugadores, longitudJugadores);
						printf("\n");
						break;
					case 7:
						break;
				}
			}
		}while(submenu != 7);
		retorno = 0;
	}
	return retorno;
}
