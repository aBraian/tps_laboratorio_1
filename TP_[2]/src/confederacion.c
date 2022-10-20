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
#include "validaciones.h"

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
					strcpy(confederaciones[i].region, "ASIA");
					break;
				case 1:
					confederaciones[i].anioCreacion = 1957;
					strcpy(confederaciones[i].nombre, "CAF");
					strcpy(confederaciones[i].region, "AFRICA");
					break;
				case 2:
					confederaciones[i].anioCreacion = 1966;
					strcpy(confederaciones[i].nombre, "OFC");
					strcpy(confederaciones[i].region, "OCEANIA");
					break;
				case 3:
					confederaciones[i].anioCreacion = 1954;
					strcpy(confederaciones[i].nombre, "UEFA");
					strcpy(confederaciones[i].region, "EUROPA");
					break;
				case 4:
					confederaciones[i].anioCreacion = 1961;
					strcpy(confederaciones[i].nombre, "CONCACAF");
					strcpy(confederaciones[i].region, "NORTE Y CENTRO AMERICA");
					break;
				case 5:
					confederaciones[i].anioCreacion = 1916;
					strcpy(confederaciones[i].nombre, "CONMEBOL");
					strcpy(confederaciones[i].region, "SUDAMERICA");
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
		printf("|========================================================|"
			   "\n"
			   "|%-56s|"
			   "\n"
			   "|--------------------------------------------------------|"
			   "\n"
			   "|%-5s|%-10s|%-24s|%-14s|\n"
			   , "Listado Confederaciones","ID", "NOMBRE", "REGION", "ANO CREACION");
		for(i = 0; i < longitud; i++){
			printf("|%-5d|%-10s|%-24s|%-14d|\n"
				   , confederaciones[i].id, confederaciones[i].nombre
				   , confederaciones[i].region, confederaciones[i].anioCreacion);
		}
		retorno = 0;
		printf("|========================================================|"
			   "\n");
	}
	return retorno;
}

int encontrarIdConfederacion(eConfederacion confederaciones[], int longitud, int idBuscada){
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
	   utn_getInt(&bufferId, "Ingrese ID confederacion: ", "ID ERRONEA", 100, 105, 2) == 0){
		validacionId = encontrarIdConfederacion(confederaciones, longitud, bufferId);
		if(validacionId != -1){
			retorno = validacionId;
		}
	}
	return retorno;
}
