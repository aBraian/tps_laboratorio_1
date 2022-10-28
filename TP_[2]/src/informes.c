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

int acumularSalariosJugadores(eJugador jugadores[], int longitudJugadores, float *totalSalarios){
	int retorno;
	int i;
	float bufferSalarios;
	retorno = -1;
	if(jugadores != NULL && longitudJugadores > 0 && totalSalarios != NULL){
		for(i = 0; i < longitudJugadores; i++){
			if(jugadores[i].isEmpty == LLENO){
				bufferSalarios += jugadores[i].salario;
			}
		}
		*totalSalarios = bufferSalarios;
		retorno = 0;
	}
	return retorno;
}

int contadorJugadores(eJugador jugadores[], int longitudJugadores, int *contador){
	int retorno;
	int i;
	int bufferContador;
	retorno = -1;
	bufferContador = 0;
	if(jugadores != NULL && longitudJugadores > 0 && contador != NULL){
		for(i = 0; i < longitudJugadores; i++){
			if(jugadores[i].isEmpty == LLENO){
				bufferContador++;
			}
		}
		*contador = bufferContador;
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

int submenuInformes(eConfederacion confederaciones[], int longitudConfederaciones, eJugador jugadores[], int longitudJugadores){
	int retorno;
	int submenu;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0 && jugadores != NULL && longitudJugadores > 0){
		do{
			printf("FIFA - Submenu Informes\n"
				   "\n"
				   "1. Listado de los jugadores ordenados alfabéticamente por nombre de confederación y nombre de jugador\n"
				   "2. Listado de confederaciones con sus jugadores\n"
				   "3. Total y promedio de todos los salarios y cuántos jugadores cobran más del salario promedio\n"
				   "4. Informar la confederación con mayor cantidad de años de contratos total\n"
				   "5. Informar porcentaje de jugadores por cada confederación\n"
				   "6. Informar cual es la región con más jugadores y el listado de los mismos\n"
				   "7. Volver al menu principal\n"
				   "\n");
			if(utn_getInt(&submenu, "OPCION: ", "OPCION NO VALIDA\n", 1, 7, 2) == 0){
				switch(submenu){
					case 1:
						printf("\n");
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

						printf("\n");
						break;
					case 5:
						printf("\n");

						printf("\n");
						break;
					case 6:
						printf("\n");

						printf("\n");
						break;
					case 7:
						printf("\n");
						printf("REGRESO CORRECTAMENTE");
						printf("\n");
						break;
				}
			}
		}while(submenu != 7);
		retorno = 0;
	}
	return retorno;
}
