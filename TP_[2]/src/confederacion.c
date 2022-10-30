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
#include "ingresoDatos.h"
#include "jugador.h"

int incrementarIdConfederaciones(){
	static int idConfederacion = 99;
	idConfederacion++;
	return idConfederacion;
}

int hardcodearConfederaciones(eConfederacion confederaciones[], int longitud){
	int retorno;
	int i;
	retorno = -1;
	if(confederaciones != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			confederaciones[i].id = incrementarIdConfederaciones();
			confederaciones[i].isEmpty = LLENO;
			switch(i){
				case 0:
					confederaciones[i].anioCreacion = 1954;
					strcpy(confederaciones[i].nombre, "AFC");
					strcpy(confederaciones[i].region, "Asia");
					break;
				case 1:
					confederaciones[i].anioCreacion = 1957;
					strcpy(confederaciones[i].nombre, "CAF");
					strcpy(confederaciones[i].region, "Africa");
					break;
				case 2:
					confederaciones[i].anioCreacion = 1966;
					strcpy(confederaciones[i].nombre, "OFC");
					strcpy(confederaciones[i].region, "Oceania");
					break;
				case 3:
					confederaciones[i].anioCreacion = 1954;
					strcpy(confederaciones[i].nombre, "UEFA");
					strcpy(confederaciones[i].region, "Europa");
					break;
				case 4:
					confederaciones[i].anioCreacion = 1961;
					strcpy(confederaciones[i].nombre, "CONCACAF");
					strcpy(confederaciones[i].region, "Norte y Centro America");
					break;
				case 5:
					confederaciones[i].anioCreacion = 1916;
					strcpy(confederaciones[i].nombre, "CONMEBOL");
					strcpy(confederaciones[i].region, "Sudamerica");
					break;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int listarConfederaciones(eConfederacion confederaciones[], int longitud){
	int retorno;
	int i;
	retorno = -1;
	if(confederaciones != NULL && longitud > 0){
		printf("==========================================================="
			   "\n"
			   "|%-56s|"
			   "\n"
			   "-----------------------------------------------------------"
			   "\n"
			   "|%-5s|%-10s|%-24s|%-15s|\n"
			   , "Listado Confederaciones","ID", "NOMBRE", "REGION", "ANIO CREACION");
		for(i = 0; i < longitud; i++){
			if(confederaciones[i].isEmpty == LLENO){
				printf("|%-5d|%-10s|%-24s|%-15d|\n"
					   , confederaciones[i].id, confederaciones[i].nombre
					   , confederaciones[i].region, confederaciones[i].anioCreacion);
			}
		}
		retorno = 0;
		printf("==========================================================="
			   "\n");
	}
	return retorno;
}

int buscarIdConfederacion(eConfederacion confederaciones[], int longitud, int idBuscada){
	int retorno;
	int i;
	retorno = -1;
	if(confederaciones != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			if(confederaciones[i].id == idBuscada){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int selecionarConfederacion(eConfederacion confederaciones[], int longitud){
	int retorno;
	int bufferId;
	int validacionId;
	retorno = -1;
	if(confederaciones != NULL && longitud > 0 && listarConfederaciones(confederaciones, longitud) == 0 &&
	   utn_getInt(&bufferId, "Ingrese ID confederacion: ", "ID ERRONEA\n", 100, 105, 2) == 0){
		validacionId = buscarIdConfederacion(confederaciones, longitud, bufferId);
		if(validacionId != -1){
			retorno = validacionId;
		}
	}
	return retorno;
}

//Funciones para ABM Confederaciones

int contadorIdConfederaciones(int opcion){
	static int contadorConfederacionesId = 0;
	if(opcion == 1){
		contadorConfederacionesId++;
	}
	return contadorConfederacionesId;
}

int inicializarConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones){
	int retorno;
	int i;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0){
		for(i = 0; i < longitudConfederaciones; i++){
			confederaciones[i].isEmpty = VACIO;
		}
		retorno = 0;
	}
	return retorno;
}

int buscarVacioConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones){
	int retorno;
	int i;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0){
		for(i = 0; i < longitudConfederaciones; i++){
			if(confederaciones[i].isEmpty == VACIO){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones){
	int retorno;
	int indiceVacio;
	int bufferAnioCreacion;
	char bufferNombre[50];
	char bufferRegion[50];
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0){
		indiceVacio = buscarVacioConfederaciones(confederaciones, longitudConfederaciones);
		if(indiceVacio != -1 &&
		   utn_getInt(&bufferAnioCreacion, "Ingrese anio de creacion: ", "ANIO NO VALIDO (MINIMO 1900 - MAXIMO 2022)\n", 1900, 2022, 2) == 0 &&
		   utn_getString(bufferNombre, 50, "Ingrese nombre: ", "ERROR\n", 2) == 0 &&
		   utn_getString(bufferRegion, 50, "Ingrese region: ", "ERROR\n", 2) == 0){
			confederaciones[indiceVacio].isEmpty = LLENO;
			confederaciones[indiceVacio].id = incrementarIdConfederaciones();
			confederaciones[indiceVacio].anioCreacion = bufferAnioCreacion;
			strcpy(confederaciones[indiceVacio].nombre, bufferNombre);
			strcpy(confederaciones[indiceVacio].region, bufferRegion);
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

int bajaConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones){
	int retorno;
	int idBuscada;
	int idMaxima;
	int indiceIdBuscada;
	retorno = -1;
	if(confederaciones != NULL && longitudConfederaciones > 0){
		idMaxima = contadorIdConfederaciones(BAJA);
		if(idMaxima > 0 &&
		   listarConfederaciones(confederaciones, longitudConfederaciones) == 0 &&
		   utn_getInt(&idBuscada, "Ingrese ID a dar de baja: ", "NO SE ENCONTRO LA ID INGRESADA\n", 1, idMaxima, 2) == 0){
			indiceIdBuscada = buscarIdConfederacion(confederaciones, longitudConfederaciones, idBuscada);
			if(indiceIdBuscada != -1){
				confederaciones[indiceIdBuscada].isEmpty = VACIO;
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

int modificarConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones){
	int retorno;
		int idBuscada;
		int idMaxima;
		int indiceIdBuscada;
		int submenuModificar;
		int bufferAnioCreacion;
		char bufferNombre[50];
		char bufferRegion[50];
		retorno = -1;
		if(confederaciones != NULL && longitudConfederaciones > 0){
			printf("Submenu Modificar Confederaciones\n"
				   "\n"
				   "1. MODIFICAR ANIO CREACION\n"
				   "2. MODIFICAR NOMBRE\n"
				   "3. MODIFICAR REGION\n"
				   "\n");
			idMaxima = contadorIdConfederaciones(BAJA);
			if(utn_getInt(&submenuModificar, "OPCION: ", "OPCION NO VALIDA\n", 1, 3, 2) == 0 &&
			   idMaxima > 0 &&
			   listarConfederaciones(confederaciones, longitudConfederaciones) == 0 &&
			   utn_getInt(&idBuscada, "Ingrese ID a modificar: ", "NO SE ENCONTRO LA ID INGRESADA\n", 1, idMaxima, 2) == 0){
				indiceIdBuscada = buscarIdConfederacion(confederaciones, longitudConfederaciones, idBuscada);
				printf("\n");
				if(indiceIdBuscada != -1){
					switch(submenuModificar){
						case 1:
							if(utn_getInt(&bufferAnioCreacion, "Ingrese anio de creacion: ", "ANIO NO VALIDO (MINIMO 1900 - MAXIMO 2022)\n", 1900, 2022, 2) == 0){
								confederaciones[indiceIdBuscada].anioCreacion = (short)bufferAnioCreacion;
								printf("\nCAMBIOS APLICADOS\n");
							}
							else{
								printf("\nCAMBIOS NO APLICADOS\n");
							}
							break;
						case 2:
							if(utn_getString(bufferNombre, 50, "Ingrese nombre: ", "ERROR\n", 2) == 0){
								strcpy(confederaciones[indiceIdBuscada].nombre, bufferNombre);
								printf("\nCAMBIOS APLICADOS\n");
							}
							else{
								printf("\nCAMBIOS NO APLICADOS\n");
							}
							break;
						case 3:
							if(utn_getString(bufferRegion, 50, "Ingrese region: ", "ERROR\n", 2) == 0){
								strcpy(confederaciones[indiceIdBuscada].region, bufferRegion);
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
