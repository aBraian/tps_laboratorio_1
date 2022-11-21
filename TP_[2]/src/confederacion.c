/*
 * confederacion.c
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

int incrementarIdConfederaciones(){
	static int idConfederacion = 99;
	idConfederacion++;
	return idConfederacion;
}

int cargaForzadaConfederaciones(eConfederacion aConfederaciones[], int longitud){
	int retorno;
	int i;
	retorno = -1;
	if(aConfederaciones != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			aConfederaciones[i].id = incrementarIdConfederaciones();
			aConfederaciones[i].isEmpty = LLENO;
			switch(i){
				case 0:
					aConfederaciones[i].anioCreacion = 1916;
					strcpy(aConfederaciones[i].nombre, "CONMEBOL");
					strcpy(aConfederaciones[i].region, "Sudamerica");
					break;
				case 1:
					aConfederaciones[i].anioCreacion = 1954;
					strcpy(aConfederaciones[i].nombre, "UEFA");
					strcpy(aConfederaciones[i].region, "Europa");
					break;
				case 2:
					aConfederaciones[i].anioCreacion = 1954;
					strcpy(aConfederaciones[i].nombre, "AFC");
					strcpy(aConfederaciones[i].region, "Asia");
					break;
				case 3:
					aConfederaciones[i].anioCreacion = 1957;
					strcpy(aConfederaciones[i].nombre, "CAF");
					strcpy(aConfederaciones[i].region, "Africa");
					break;
				case 4:
					aConfederaciones[i].anioCreacion = 1961;
					strcpy(aConfederaciones[i].nombre, "CONCACAF");
					strcpy(aConfederaciones[i].region, "Norte y Centro America");
					break;
				case 5:
					aConfederaciones[i].anioCreacion = 1966;
					strcpy(aConfederaciones[i].nombre, "OFC");
					strcpy(aConfederaciones[i].region, "Oceania");
					break;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int listarConfederaciones(eConfederacion aConfederaciones[], int longitud){
	int retorno;
	int i;
	retorno = -1;
	if(aConfederaciones != NULL && longitud > 0){
		printf("==========================================================="
			   "\n"
			   "|%-57s|"
			   "\n"
			   "-----------------------------------------------------------"
			   "\n"
			   "|%-5s|%-10s|%-24s|%-15s|\n"
			   , "Listado Confederaciones","ID", "NOMBRE", "REGION", "ANIO CREACION");
		for(i = 0; i < longitud; i++){
			if(aConfederaciones[i].isEmpty == LLENO){
				printf("|%-5d|%-10s|%-24s|%-15d|\n"
					   , aConfederaciones[i].id, aConfederaciones[i].nombre
					   , aConfederaciones[i].region, aConfederaciones[i].anioCreacion);
			}
		}
		retorno = 0;
		printf("==========================================================="
			   "\n");
	}
	return retorno;
}

int obtenerNombreConfederacion(eConfederacion aConfederaciones[], int longitud, int idBuscada, char aNombreConfederacion[]){
	int retorno;
	int i;
	retorno = -1;
	if(aConfederaciones != NULL && longitud > 0 && idBuscada >= 100 && aNombreConfederacion != NULL){
		for(i = 0; i < longitud; i++){
			if(aConfederaciones[i].id == idBuscada){
				strncpy(aNombreConfederacion, aConfederaciones[i].nombre, LONG_NOMBRE);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int obtenerRegionConfederacion(eConfederacion aConfederaciones[], int longitud, int idBuscada, char aRegionConfederacion[]){
	int retorno;
	int i;
	retorno = -1;
	if(aConfederaciones != NULL && longitud > 0 && idBuscada >= 100 && aRegionConfederacion != NULL){
		for(i = 0; i < longitud; i++){
			if(aConfederaciones[i].id == idBuscada){
				strncpy(aRegionConfederacion, aConfederaciones[i].region, LONG_REGION);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

//Funciones para ABM Confederaciones

int buscarIdMaximaConfederaciones(eConfederacion aConfederaciones[], int longitud){
	int retorno;
	int i;
	int flagMaximo;
	retorno = -1;
	flagMaximo = 0;
	if(aConfederaciones != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			if(aConfederaciones[i].isEmpty == LLENO && flagMaximo == 0){
				retorno = aConfederaciones[i].id;
				flagMaximo = 1;
			}
			else if(aConfederaciones[i].isEmpty == LLENO && aConfederaciones[i].id > retorno){
				retorno = aConfederaciones[i].id;
			}
		}
	}
	return retorno;
}

int inicializarConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones){
	int retorno;
	int i;
	retorno = -1;
	if(aConfederaciones != NULL && longitudConfederaciones > 0){
		for(i = 0; i < longitudConfederaciones; i++){
			aConfederaciones[i].id = 0;
			strncpy(aConfederaciones[i].nombre, "", LONG_NOMBRE);
			strncpy(aConfederaciones[i].region, "", LONG_REGION);
			aConfederaciones[i].anioCreacion = 0;
			aConfederaciones[i].isEmpty = VACIO;
		}
		retorno = 0;
	}
	return retorno;
}

int buscarVacioConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones){
	int retorno;
	int i;
	retorno = -1;
	if(aConfederaciones != NULL && longitudConfederaciones > 0){
		for(i = 0; i < longitudConfederaciones; i++){
			if(aConfederaciones[i].isEmpty == VACIO){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int buscarIdConfederacion(eConfederacion aConfederaciones[], int longitud, int idBuscada){
	int retorno;
	int i;
	retorno = -1;
	if(aConfederaciones != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			if(aConfederaciones[i].id == idBuscada){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones){
	int retorno;
	int indiceVacio;
	int bufferAnioCreacion;
	char bufferNombre[LONG_NOMBRE];
	char bufferRegion[LONG_REGION];
	retorno = -1;
	if(aConfederaciones != NULL && longitudConfederaciones > 0){
		indiceVacio = buscarVacioConfederaciones(aConfederaciones, longitudConfederaciones);
		if(indiceVacio != -1 &&
		   utn_getString(bufferNombre, LONG_NOMBRE, "Ingrese nombre: ", "ERROR\n", 2) == 0 &&
		   utn_getString(bufferRegion, LONG_REGION, "Ingrese region: ", "ERROR\n", 2) == 0 &&
		   utn_getInt(&bufferAnioCreacion, "Ingrese anio de creacion (MINIMO 1900 - MAXIMO 2022): ", "ANIO NO VALIDO (MINIMO 1900 - MAXIMO 2022)\n", 1900, 2022, 2) == 0){
			aConfederaciones[indiceVacio].isEmpty = LLENO;
			aConfederaciones[indiceVacio].id = incrementarIdConfederaciones();
			aConfederaciones[indiceVacio].anioCreacion = bufferAnioCreacion;
			strcpy(aConfederaciones[indiceVacio].nombre, bufferNombre);
			strcpy(aConfederaciones[indiceVacio].region, bufferRegion);
			retorno = 0;
			printf(MENSAJE_EXITO);
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

int bajaConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones){
	int retorno;
	int idBuscada;
	int idMaxima;
	int indiceIdBuscada;
	retorno = -1;
	if(aConfederaciones != NULL && longitudConfederaciones > 0){
		idMaxima = buscarIdMaximaConfederaciones(aConfederaciones, longitudConfederaciones);
		if(idMaxima != -1 &&
		   listarConfederaciones(aConfederaciones, longitudConfederaciones) == 0 &&
		   utn_getInt(&idBuscada, "Ingrese ID a dar de baja: ", "NO SE ENCONTRO LA ID INGRESADA\n", 1, idMaxima, 2) == 0){
			indiceIdBuscada = buscarIdConfederacion(aConfederaciones, longitudConfederaciones, idBuscada);
			if(indiceIdBuscada != -1){
				aConfederaciones[indiceIdBuscada].isEmpty = VACIO;
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

int modificarConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones){
	int retorno;
		int idBuscada;
		int idMaxima;
		int indiceIdBuscada;
		int submenuModificar;
		int bufferAnioCreacion;
		char bufferNombre[LONG_NOMBRE];
		char bufferRegion[LONG_REGION];
		retorno = -1;
		if(aConfederaciones != NULL && longitudConfederaciones > 0){
			printf("Submenu Modificar Confederaciones\n"
				   "\n"
				   "1. MODIFICAR NOMBRE\n"
				   "2. MODIFICAR REGION\n"
				   "3. MODIFICAR ANIO CREACION\n"
				   "\n");
			idMaxima = buscarIdMaximaConfederaciones(aConfederaciones, longitudConfederaciones);
			if(utn_getInt(&submenuModificar, "OPCION: ", "OPCION NO VALIDA\n", 1, 3, 2) == 0 &&
			   idMaxima > 0 &&
			   listarConfederaciones(aConfederaciones, longitudConfederaciones) == 0 &&
			   utn_getInt(&idBuscada, "Ingrese ID a modificar: ", "NO SE ENCONTRO LA ID INGRESADA\n", 1, idMaxima, 2) == 0){
				indiceIdBuscada = buscarIdConfederacion(aConfederaciones, longitudConfederaciones, idBuscada);
				printf("\n");
				if(indiceIdBuscada != -1){
					switch(submenuModificar){
						case 1:
							if(utn_getString(bufferNombre, LONG_NOMBRE, "Ingrese nombre: ", "ERROR\n", 2) == 0){
								strcpy(aConfederaciones[indiceIdBuscada].nombre, bufferNombre);
								printf("\nCAMBIOS APLICADOS\n");
							}
							else{
								printf("\nCAMBIOS NO APLICADOS\n");
							}
							break;
						case 2:
							if(utn_getString(bufferRegion, LONG_REGION, "Ingrese region: ", "ERROR\n", 2) == 0){
								strcpy(aConfederaciones[indiceIdBuscada].region, bufferRegion);
								printf("\nCAMBIOS APLICADOS\n");
							}
							else{
								printf("\nCAMBIOS NO APLICADOS\n");
							}
							break;
						case 3:
							if(utn_getInt(&bufferAnioCreacion, "Ingrese anio de creacion: ", "ANIO NO VALIDO (MINIMO 1900 - MAXIMO 2022)\n", 1900, 2022, 2) == 0){
								aConfederaciones[indiceIdBuscada].anioCreacion = (short)bufferAnioCreacion;
								printf("\nCAMBIOS APLICADOS\n");
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
