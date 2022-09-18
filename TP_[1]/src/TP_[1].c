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

#define INTERES 35

#define MENSAJE_CORRECTO "   \nDATOS CARGADOS CORRECTAMENTE\n"
#define MENSAJE_LIMITE_JUGADORES "   \nSE ALCANZO EL LIMITE DE JUGADORES EN ESTA POSICION\n"

int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int submenuCostos;
	int retornoMenu;
	int costoHospedaje;
	int costoComida;
	int costoTransporte;
	int costoMantenimiento;
	int submenuPosicion;
	int arqueros;
	int defensores;
	int mediocampistas;
	int delanteros;
	int numeroCamiseta;
	int submenuConfederacion;
	int confederacionAfc;
	int confederacionCaf;
	int confederacionConcacaf;
	int confederacionConmebol;
	int confederacionUefa;
	int confederacionOfc;
	int acumuladorJugadores;
	int flagInteres;
	int flagCostos;
	int flagJugadores;
	int flagCalculos;
	float porcentajeAfc;
	float porcentajeCaf;
	float porcentajeConcacaf;
	float porcentajeConmebol;
	float porcentajeUefa;
	float porcentajeOfc;
	float costoConInteres;
	float aumento;
	costoHospedaje = 0;
	costoComida = 0;
	costoTransporte = 0;
	costoMantenimiento = 0;
	arqueros = 0;
	defensores = 0;
	mediocampistas = 0;
	delanteros = 0;
	confederacionAfc = 0;
	confederacionCaf = 0;
	confederacionConcacaf = 0;
	confederacionConmebol = 0;
	confederacionUefa = 0;
	confederacionOfc = 0;
	acumuladorJugadores = 0;
	flagInteres = 0;
	flagCostos = 0;
	flagJugadores = 0;
	flagCalculos = 0;
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
						if(!utn_getInt(&submenuCostos, "   Ingrese opcion: ", "   \nOPCION NO VALIDA\n",
								       MIN_MENU_COSTOS, MAX_MENU_COSTOS, REINTENTOS_MENU_COSTOS)){
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
						flagCostos = 1;
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
									confederacionAfc++;
									break;
								case 2:
									confederacionCaf++;
									break;
								case 3:
									confederacionConcacaf++;
									break;
								case 4:
									confederacionConmebol++;
									break;
								case 5:
									confederacionUefa++;
									break;
								case 6:
									confederacionOfc++;
									break;
							}
							utn_getInt(&numeroCamiseta, "   Ingrese numero de camiseta: ", "   \nNUMERO NO VALIDO\n\n",
									   MIN_CAMISETA_JUGADORES, MAX_CAMISETA_JUGADORES, REINTENTOS_CAMISETA_JUGADORES);
							flagJugadores = 1;
							printf(MENSAJE_CORRECTO);
						}
					}
					break;
				case 3:
					if(flagCostos && flagJugadores){
						acumuladorJugadores = confederacionAfc + confederacionCaf + confederacionConcacaf +
											  confederacionConmebol + confederacionUefa + confederacionOfc;
						porcentajeAfc = calcularPorcentaje(acumuladorJugadores, confederacionAfc);
						porcentajeCaf = calcularPorcentaje(acumuladorJugadores, confederacionCaf);
						porcentajeConcacaf = calcularPorcentaje(acumuladorJugadores, confederacionConcacaf);
						porcentajeConmebol  = calcularPorcentaje(acumuladorJugadores, confederacionConmebol);
						porcentajeUefa = calcularPorcentaje(acumuladorJugadores, confederacionUefa);
						porcentajeOfc = calcularPorcentaje(acumuladorJugadores, confederacionOfc);
						costoMantenimiento = costoHospedaje + costoComida + costoTransporte;
						if(porcentajeUefa > porcentajeAfc && porcentajeUefa > porcentajeCaf && porcentajeUefa > porcentajeConcacaf &&
						   porcentajeUefa > porcentajeConmebol && porcentajeUefa > porcentajeOfc){
							costoConInteres = calcularInteres(costoMantenimiento, INTERES, &aumento);
							flagInteres = 1;
						}
						else{
							flagInteres = 0;
						}
						printf(MENSAJE_CORRECTO);
					flagCalculos = 1;
					}
					else{
						printf("   \nSE DEBE INGRESAR ANTES LOS COSTOS Y JUGADORES\n");
					}
					break;
				case 4:
					if(flagCalculos){
						printf("\nMenu Resultados\n\n"
							   "   -Porcentaje AFC -> %.2f\n"
							   "   -Porcentaje CAF -> %.2f\n"
							   "   -Porcentaje CONCACAF -> %.2f\n"
							   "   -Porcentaje CONMEBOL -> %.2f\n"
							   "   -Porcentaje UEFA -> %.2f\n"
							   "   -Porcentaje OFC -> %.2f\n"
							   "   -Costo de mantenimiento -> $%d\n"
							   , porcentajeAfc, porcentajeCaf, porcentajeConcacaf, porcentajeConmebol, porcentajeUefa, porcentajeOfc
							   , costoMantenimiento);
						if(flagInteres){
							printf("\nMAYORIA DEL PLANTEL COMPUESTA POR CONFEDERACION\n"
								   "UEFA, SE APLICA UN AUMENTO DE 35(por ciento) EN\n"
								   "EL COSTO DE MANTENIMIENTO\n\n"
								   "   -Aumento -> $%.2f\n"
								   "   -Precio con aumento -> $%.2f\n"
								   , aumento, costoConInteres);
						}
						flagCalculos = 0;
					}
					else{
						printf("   \nSE DEBEN REALIZAR ANTES LOS CALCULOS\n");
					}
					break;
				case 5:
					printf("   \nSALIO CORRECTAMENTE");
					break;
			}
		}
	}while(menu != 5);
	return EXIT_SUCCESS;
}
