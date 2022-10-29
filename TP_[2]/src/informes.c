/*
 * informes.c
 *
 *  Created on: 22 oct. 2022
 *      Author: braian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculos.h"
#include "confederacion.h"
#include "informes.h"
#include "ingresoDatos.h"
#include "jugador.h"

int vincularIdEstructuras(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores, int indiceRelacion){
	int retorno;
	int i;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0){
		for(i = 0; i < longitudConfederaciones; i++){
			if(confederaciones[i].id == jugadores[indiceRelacion].idConfederacion){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int ordenarNombres(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int i;
	int primerIndice;
	int segundoIndice;
	int flagSwap;
	eJugador buffer;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0){
		do{
			flagSwap = 0;
			for(i = 0; i < longitudJugadores - 1; i++){
				primerIndice = vincularIdEstructuras(confederaciones, longitudConfederaciones, jugadores, longitudJugadores, i);
				segundoIndice = vincularIdEstructuras(confederaciones, longitudConfederaciones, jugadores, longitudJugadores, i + 1);
				if(primerIndice != -1 && segundoIndice != -1){
					if(strcmp(confederaciones[primerIndice].nombre, confederaciones[segundoIndice].nombre) > 0){
						buffer = jugadores[i];
						jugadores[i] = jugadores[i + 1];
						jugadores[i + 1] = buffer;
						flagSwap = 1;
					}
					else if(strcmp(confederaciones[primerIndice].nombre, confederaciones[segundoIndice].nombre) == 0){
						if(strcmp(jugadores[i].nombre, jugadores[i + 1].nombre) > 0){
							buffer = jugadores[i];
							jugadores[i] = jugadores[i + 1];
							jugadores[i + 1] = buffer;
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

int listarConfederacionesConJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int i;
	int x;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0){
		printf("========================================================================================="
			   "\n"
			   "|%-87s|"
			   "\n"
			   "-----------------------------------------------------------------------------------------"
			   "\n"
			   "|%-5s|%-10s|%-24s|%-14s|%-30s|\n"
			   , "Listado Confederaciones con sus Jugadores", "ID", "NOMBRE", "REGION", "ANO CREACION", "NOMBRE JUGADOR");
		for(i = 0; i < longitudJugadores; i++){
			for(x = 0; x < longitudConfederaciones; x++){
				if(jugadores[i].isEmpty == LLENO && confederaciones[x].id == jugadores[i].idConfederacion){
					printf("|%-5d|%-10s|%-24s|%-14d|%-30s|\n"
						   , confederaciones[x].id, confederaciones[x].nombre
						   , confederaciones[x].region, confederaciones[x].anioCreacion
						   , jugadores[i].nombre);
					break;
				}
			}
		}
		retorno = 0;
		printf("========================================================================================="
			   "\n");
	}
	return retorno;
}

int listarSalarios(eJugador jugadores[], int longitudJugadores){
	int retorno;
	int cantidadSalarios;
	float totalSalarios;
	float promedioSalarios;
	retorno = -1;
	cantidadSalarios = 0;
	totalSalarios = 0;
	promedioSalarios = 0;
	if(jugadores != NULL && longitudJugadores > 0 &&
	   acumularSalariosJugadores(jugadores, longitudJugadores, &totalSalarios) == 0 &&
	   calcularPromedioSalarios(jugadores, longitudJugadores, &promedioSalarios) == 0 &&
	   salariosMayorPromedio(jugadores, longitudJugadores, &cantidadSalarios) == 0){
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

int listarConfederacionMasAniosContrato(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int auxIndice;
	int cantidadAnios;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0){
		auxIndice = confederacionMasAniosContrato(confederaciones, longitudConfederaciones, jugadores, longitudJugadores, &cantidadAnios);
		if(auxIndice != -1){
			printf("================================================="
				   "\n"
				   "|%-47s|"
				   "\n"
				   "-------------------------------------------------"
				   "\n"
				   "|%-15s|%-31s|\n"
				   "|%-15s|%-31d|\n"
				   , "Listado Confederacion con mas Anios de Contrato", "CONFEDERACION", "CANTIDAD ANIOS"
				   , confederaciones[auxIndice].nombre, cantidadAnios);
			printf("================================================="
				   "\n");
			retorno = 0;
		}
	}
	return retorno;
}

int listarPorcentajeConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int i;
	float bufferPorcentaje;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0){
		printf("======================================================"
			   "\n"
			   "|%-52s|"
			   "\n"
			   "------------------------------------------------------"
			   "\n"
			   "|%-15s|%-36s|\n"
			   , "Listado de Porcentaje de Jugadores por Confederacion", "CONFEDERACION", "PORCENTAJE");
		for(i = 0; i < longitudConfederaciones; i++){
			if(calcularPorcentajeJugadores(confederaciones, longitudConfederaciones, jugadores, longitudJugadores, i, &bufferPorcentaje) == 0){
				printf("|%-15s|%%%-35.2f|\n", confederaciones[i].nombre, bufferPorcentaje);
			}
		}
		retorno = 0;
		printf("======================================================"
			   "\n");
	}
	return retorno;
}

int listarRegionMasJugadores(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int i;
	int auxIndice;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0){
		printf("======================================================"
			   "\n"
			   "|%-52s|"
			   "\n"
			   "------------------------------------------------------"
			   "\n"
			   "|%-24s|%-27s|\n"
			   , "Listado de Region con mas Jugadores", "REGION", "NOMBRE JUGADOR");
		auxIndice = regionMasJugadores(confederaciones, longitudConfederaciones, jugadores, longitudJugadores);
		if(auxIndice != -1){
			for(i = 0; i < longitudJugadores; i++){
				if(jugadores[i].isEmpty == LLENO && confederaciones[auxIndice].id == jugadores[i].idConfederacion){
					printf("|%-24s|%-27s|\n", confederaciones[auxIndice].region, jugadores[i].nombre);
				}
			}
		}
		retorno = 0;
		printf("======================================================"
			   "\n");
	}
	return retorno;
}

int submenuInformes(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int submenu;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0){
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
						ordenarIdJugadores(jugadores, longitudJugadores);
						ordenarNombres(confederaciones, longitudConfederaciones, jugadores, longitudJugadores);
						listarJugadores(confederaciones, longitudConfederaciones, jugadores, longitudJugadores);
						printf("\n");
						break;
					case 2:
						printf("\n");
						listarConfederacionesConJugadores(confederaciones, longitudConfederaciones, jugadores, longitudJugadores);
						printf("\n");
						break;
					case 3:
						printf("\n");
						listarSalarios(jugadores, longitudJugadores);
						printf("\n");
						break;
					case 4:
						printf("\n");
						listarConfederacionMasAniosContrato(confederaciones, longitudConfederaciones, jugadores, longitudJugadores);
						printf("\n");
						break;
					case 5:
						printf("\n");
						listarPorcentajeConfederaciones(confederaciones, longitudConfederaciones, jugadores, longitudJugadores);
						printf("\n");
						break;
					case 6:
						printf("\n");
						listarRegionMasJugadores(confederaciones, longitudConfederaciones, jugadores, longitudJugadores);
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
