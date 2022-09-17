/*
 ============================================================================
 Name        : TP_[1].c
 Author      : ACOSTA, Braian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "validaciones.h"

#define MIN_OPCION_MENU 1
#define MAX_OPCION_MENU 5
#define REINTENTOS_MENU 0

#define MIN_MENU_COSTOS 1
#define MAX_MENU_COSTOS 4
#define REINTENTOS_MENU_COSTOS 2

#define MIN_COSTOS_HOSPEDAJE 50000
#define MAX_COSTOS_HOSPEDAJE 5000000
#define REINTENTOS_COSTOS_HOSPEDAJE 2

#define MIN_COSTOS_COMIDA 50
#define MAX_COSTOS_COMIDA 50000
#define REINTENTOS_COSTOS_COMIDA 2

#define MIN_COSTOS_TRANSPORTE 50000
#define MAX_COSTOS_TRANSPORTE 5000000
#define REINTENTOS_COSTOS_TRANSPORTE 2

#define MIN_MENU_JUGADORES 1
#define MAX_MENU_JUGADORES 4
#define REINTENTOS_MENU_JUGADORES 2

#define MIN_CAMISETA_JUGADORES 1
#define MAX_CAMISETA_JUGADORES 99
#define REINTENTOS_CAMISETA_JUGADORES 2

#define MIN_CONFEDERACION_JUGADORES 1
#define MAX_CONFEDERACION_JUGADORES 6
#define REINTENTOS_CONFEDERACION_JUGADORES 2

#define MENSAJE_CORRECTO "   \nDATOS INGRESADOS CORRECTAMENTE\n"
#define MENSAJE_LIMITE_JUGADORES "   \nSE ALCANZO EL LIMITE DE JUGADORES EN ESTA POSICION\n"

int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int submenuCostos;
	int retornoMenu;
	int costoHospedaje;
	int costoComida;
	int costoTransporte;
	int submenuPosicion;
	int arqueros;
	int defensores;
	int mediocampistas;
	int delanteros;
	int numeroCamiseta;
	int submenuConfederacion;
	int afc;
	int caf;
	int concacaf;
	int conmebol;
	int uefa;
	int ofc;
	costoHospedaje = 0;
	costoComida = 0;
	costoTransporte = 0;
	arqueros = 0;
	defensores = 0;
	mediocampistas = 0;
	delanteros = 0;
	afc = 0;
	caf = 0;
	concacaf = 0;
	conmebol = 0;
	uefa = 0;
	ofc = 0;
	do{
		printf("-----------------------------------------------------\n"
			   "Menu Principal\n\n"
			   "1. Ingreso de los costos de mantenimiento\n"
			   "   -Costo de hospedaje -> $%d\n"
			   "   -Costo de comida -> $%d\n"
			   "   -Costo de transporte -> $%d\n"
			   "2. Carga de jugadores\n"
			   "   -Arqueros -> %d\n"
			   "   -Defensores -> %d\n"
			   "   -Mediocampistas -> %d\n"
			   "   -Delanteros -> %d\n"
			   "3. Realizar todos los calculos\n"
			   "4. Informar todos los resultados\n"
			   "5. Salir\n"
			   "-----------------------------------------------------\n"
			   , costoHospedaje, costoComida, costoTransporte
			   , arqueros, defensores, mediocampistas, delanteros);
		retornoMenu = utn_getInt(&menu, "   Ingrese opcion: ", "   \nOPCION NO VALIDA\n\n",
					             MIN_OPCION_MENU, MAX_OPCION_MENU, REINTENTOS_MENU);
		if(!retornoMenu){
			switch(menu){
				case 1:
					do{
						printf("\nMenu Secundario Costos\n\n"
							   "1. Costo de hospedaje -> $%d\n"
							   "2. Costo de comida -> $%d\n"
							   "3. Costo de transporte -> $%d\n"
							   "4. Volver\n"
							   ,costoHospedaje, costoComida, costoTransporte);
						utn_getInt(&submenuCostos, "   Ingrese opcion: ", "   \nOPCION NO VALIDA\n",
								MIN_MENU_COSTOS, MAX_MENU_COSTOS, REINTENTOS_MENU_COSTOS);
						switch(submenuCostos){
							case 1:
								if(!utn_getInt(&costoHospedaje, "   Ingrese precio: $", "   \nMONTO INCORRECTO\n",
										       MIN_COSTOS_HOSPEDAJE, MAX_COSTOS_HOSPEDAJE, REINTENTOS_COSTOS_HOSPEDAJE)){
									printf(MENSAJE_CORRECTO);
								}
								break;
							case 2:
								if(!utn_getInt(&costoComida, "   Ingrese precio: $", "   \nMONTO INCORRECTO\n",
											   MIN_COSTOS_COMIDA, MAX_COSTOS_COMIDA, REINTENTOS_COSTOS_COMIDA)){
									printf(MENSAJE_CORRECTO);
								}
								break;
							case 3:
								if(!utn_getInt(&costoTransporte, "   Ingrese precio: $", "   \nMONTO INCORRECTO\n",
											   MIN_COSTOS_TRANSPORTE, MAX_COSTOS_TRANSPORTE, REINTENTOS_COSTOS_TRANSPORTE)){
									printf(MENSAJE_CORRECTO);
								}
								break;
							case 4:
								break;
						}
					}while(submenuCostos != 4);
					break;
				case 2:
					printf("\nMenu Secundario Jugadores\n\n"
						   "1. Arqueros -> %d\n"
						   "2. Defensores -> %d\n"
						   "3. Mediocampistas -> %d\n"
						   "4. Delanteros -> %d\n"
						   , arqueros, defensores, mediocampistas, delanteros);
					if(!utn_getInt(&submenuPosicion, "   Seleccione su posicion: ", "   \nOPCION NO VALIDA\n\n",
								   MIN_MENU_JUGADORES, MAX_MENU_JUGADORES, REINTENTOS_MENU_JUGADORES)){
						switch(submenuPosicion){
							case 1:
								if(arqueros < 2){
									arqueros++;
								}
								else{
									printf(MENSAJE_LIMITE_JUGADORES);
									continue;
								}
								break;
							case 2:
								if(defensores < 8){
									defensores++;
								}
								else{
									printf(MENSAJE_LIMITE_JUGADORES);
									continue;
								}
								break;
							case 3:
								if(mediocampistas < 8){
									mediocampistas++;
								}
								else{
									printf(MENSAJE_LIMITE_JUGADORES);
									continue;
								}
								break;
							case 4:
								if(delanteros < 4){
									delanteros++;
								}
								else{
									printf(MENSAJE_LIMITE_JUGADORES);
									continue;
								}
								break;
						}
						printf("\n"
							   "1. AFC\n"
							   "2. CAF\n"
							   "3. CONCACAF\n"
							   "4. CONMEBOL\n"
							   "5. UEFA\n"
							   "6. OFC\n");
						if(!utn_getInt(&submenuConfederacion, "   Ingrese numero de confederacion: ", "   \nOPCION NO VALIDA\n\n",
								       MIN_CONFEDERACION_JUGADORES, MAX_CONFEDERACION_JUGADORES, REINTENTOS_CONFEDERACION_JUGADORES)){
							switch(submenuConfederacion){
								case 1:
									afc++;
									break;
								case 2:
									caf++;
									break;
								case 3:
									concacaf++;
									break;
								case 4:
									conmebol++;
									break;
								case 5:
									uefa++;
									break;
								case 6:
									ofc++;
									break;
							}
							utn_getInt(&numeroCamiseta, "   Ingrese numero de camiseta: ", "   \nNUMERO NO VALIDO\n\n",
									   MIN_CAMISETA_JUGADORES, MAX_CAMISETA_JUGADORES, REINTENTOS_CAMISETA_JUGADORES);
							printf(MENSAJE_CORRECTO);
						}
					}
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					printf("   \nSALIO CORRECTAMENTE");
					break;
			}
		}
	}while(menu != 5);
	return EXIT_SUCCESS;
}
