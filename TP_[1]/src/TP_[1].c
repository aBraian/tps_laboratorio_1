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

#define PORCENTAJE_INTERES 35

#define MENSAJE_CORRECTO "   \nDATOS CARGADOS CORRECTAMENTE\n"
#define MENSAJE_LIMITE_JUGADORES "   \nSE ALCANZO EL LIMITE DE JUGADORES EN ESTA POSICION\n"

int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int submenuCostos;
	int retornoMenu;
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
	int flagCostoHospedaje;
	int flagCostoComida;
	int flagCostoTransporte;
	int flagJugadores;
	int flagCalculos;
	float costoHospedaje;
	float costoComida;
	float costoTransporte;
	float costoMantenimiento;
	float porcentajeAfc;
	float porcentajeCaf;
	float porcentajeConcacaf;
	float porcentajeConmebol;
	float porcentajeUefa;
	float porcentajeOfc;
	float promedioAfc;
	float promedioCaf;
	float promedioConcacaf;
	float promedioConmebol;
	float promedioUefa;
	float promedioOfc;
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
	flagCostoHospedaje = 0;
	flagCostoComida = 0;
	flagCostoTransporte = 0;
	flagJugadores = 0;
	flagCalculos = 0;
	do{
		printf("-----------------------------------------------------\n"
			   "Menu Principal\n\n"
			   "1. Ingreso de los costos de mantenimiento\n"
			   "   -Costo de hospedaje -> $%.2f\n"
			   "   -Costo de comida -> $%.2f\n"
			   "   -Costo de transporte -> $%.2f\n"
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
							   "1. Costo de hospedaje (MAX: $5000000 - MIN: $50000) -> $%.2f\n"
							   "2. Costo de comida (MAX: $50000 - MIN: $50) -> $%.2f\n"
							   "3. Costo de transporte (MAX: $5000000 - MIN: $50000) -> $%.2f\n"
							   "4. Volver\n"
							   ,costoHospedaje, costoComida, costoTransporte);
						if(!utn_getInt(&submenuCostos, "   Ingrese opcion: ", "   \nOPCION NO VALIDA\n",
								       MIN_MENU_COSTOS, MAX_MENU_COSTOS, REINTENTOS_MENU_COSTOS)){
							switch(submenuCostos){
								case 1:
									if(!utn_getFloat(&costoHospedaje, "   Ingrese precio: $", "   \nMONTO INCORRECTO\n",
												   MIN_COSTOS_HOSPEDAJE, MAX_COSTOS_HOSPEDAJE, REINTENTOS_COSTOS_HOSPEDAJE)){
										printf(MENSAJE_CORRECTO);
										flagCostoHospedaje = 1;
									}
									break;
								case 2:
									if(!utn_getFloat(&costoComida, "   Ingrese precio: $", "   \nMONTO INCORRECTO\n",
												   MIN_COSTOS_COMIDA, MAX_COSTOS_COMIDA, REINTENTOS_COSTOS_COMIDA)){
										printf(MENSAJE_CORRECTO);
										flagCostoComida = 1;
									}
									break;
								case 3:
									if(!utn_getFloat(&costoTransporte, "   Ingrese precio: $", "   \nMONTO INCORRECTO\n",
												   MIN_COSTOS_TRANSPORTE, MAX_COSTOS_TRANSPORTE, REINTENTOS_COSTOS_TRANSPORTE)){
										printf(MENSAJE_CORRECTO);
										flagCostoTransporte = 1;
									}
									break;
								case 4:
									break;
							}
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
					if(flagCostoHospedaje && flagCostoComida && flagCostoTransporte && flagJugadores){
						acumuladorJugadores = confederacionAfc + confederacionCaf + confederacionConcacaf +
											  confederacionConmebol + confederacionUefa + confederacionOfc;
						calcularPromedio(confederacionAfc, acumuladorJugadores, &promedioAfc);
						calcularPromedio(confederacionCaf, acumuladorJugadores, &promedioCaf);
						calcularPromedio(confederacionConcacaf, acumuladorJugadores, &promedioConcacaf);
						calcularPromedio(confederacionConmebol, acumuladorJugadores, &promedioConmebol);
						calcularPromedio(confederacionUefa, acumuladorJugadores, &promedioUefa);
						calcularPromedio(confederacionOfc, acumuladorJugadores, &promedioOfc);
						calcularPorcentaje(acumuladorJugadores, confederacionAfc, &porcentajeAfc);
						calcularPorcentaje(acumuladorJugadores, confederacionCaf, &porcentajeCaf);
						calcularPorcentaje(acumuladorJugadores, confederacionConcacaf, &porcentajeConcacaf);
						calcularPorcentaje(acumuladorJugadores, confederacionConmebol, &porcentajeConmebol);
						calcularPorcentaje(acumuladorJugadores, confederacionUefa, &porcentajeUefa);
						calcularPorcentaje(acumuladorJugadores, confederacionOfc, &porcentajeOfc);
						costoMantenimiento = costoHospedaje + costoComida + costoTransporte;
						if(porcentajeUefa > porcentajeAfc && porcentajeUefa > porcentajeCaf && porcentajeUefa > porcentajeConcacaf &&
						   porcentajeUefa > porcentajeConmebol && porcentajeUefa > porcentajeOfc){
							calcularInteres(costoMantenimiento, PORCENTAJE_INTERES, &aumento, &costoConInteres);
							flagInteres = 1;
						}
						else{
							flagInteres = 0;
						}
						printf(MENSAJE_CORRECTO);
						flagCalculos = 1;
					}
					else{
						printf("\nSE DEBE INGRESAR ANTES TODOS LOS COSTOS (HOSPEDAJE\n"
							   ", COMIDA, TRANSPORTE) Y JUGADORES\n");
					}
					break;
				case 4:
					if(flagCalculos){
						printf("\nMenu Resultados\n\n"
							   "   -Promedio AFC -> %.2f / Porcentaje AFC -> %.2f\n"
							   "   -Promedio CAF -> %.2f /  Porcentaje CAF -> %.2f\n"
							   "   -Promedio CONCACAF -> %.2f /  Porcentaje CONCACAF -> %.2f\n"
							   "   -Promedio CONMEBOL -> %.2f /  Porcentaje CONMEBOL -> %.2f\n"
							   "   -Promedio UEFA -> %.2f /  Porcentaje UEFA -> %.2f\n"
							   "   -Promedio OFC -> %.2f /  Porcentaje OFC -> %.2f\n"
							   "   -Costo de mantenimiento -> $%.2f\n"
							   , promedioAfc, porcentajeAfc, promedioCaf, porcentajeCaf, promedioConcacaf, porcentajeConcacaf
							   , promedioConmebol, porcentajeConmebol, promedioUefa, porcentajeUefa, promedioOfc, porcentajeOfc
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
