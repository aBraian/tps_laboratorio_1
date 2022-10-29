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

int inicializarConfederaciones(eConfederacion confederaciones[], int longitud){
	int retorno;
	int i;
	retorno = -1;
	if(confederaciones != NULL && longitud > 0){
		for(i = 0; i < longitud; i++){
			confederaciones[i].id = incrementarIdConfederaciones();
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
			printf("|%-5d|%-10s|%-24s|%-15d|\n"
				   , confederaciones[i].id, confederaciones[i].nombre
				   , confederaciones[i].region, confederaciones[i].anioCreacion);
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
