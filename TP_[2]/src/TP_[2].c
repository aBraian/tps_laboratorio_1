/*
  Trabajo Practico 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"
#include "jugador.h"
#include "validaciones.h"

int main(void) {
	setbuf(stdout, NULL);
	int menuPrincipal;
	int flagSalida;
	char respuesta[3];
	eConfederacion confederaciones[6];
	eJugador jugadores[6];
	inicializarConfederaciones(confederaciones, 6);
	inicializarJugadores(jugadores, 6);
	do{
		printf("FIFA - Menu Principal\n"
			   "\n"
			   "1. ALTA DE JUGADOR\n"
			   "2. BAJA DE JUGADOR\n"
			   "3. MODIFICACION DE JUGADOR\n"
			   "4. INFORMES\n"
			   "5. SALIR\n"
			   "\n");
		if(utn_getInt(&menuPrincipal, "OPCION: ", "OPCION NO VALIDA\n\n", 1, 5, 1) == 0){
			switch(menuPrincipal){
				case 1:
					printf("\n");
					if(altaJugadores(confederaciones, 6, jugadores, 6) == 0){
						contadorIdJugadores(ALTA);
					}
					printf("\n");
					break;
				case 2:
					printf("\n");
					bajaJugadores(confederaciones, 6, jugadores, 6);
					printf("\n");
					break;
				case 3:
					printf("\n");
					modificarJugadores(confederaciones, 6, jugadores, 6);
					printf("\n");
					break;
				case 4:
					printf("\n");
					listarJugadores(confederaciones, 6,jugadores, 6);
					printf("\n");
					break;
				case 5:
					printf("\n");
					do{
						flagSalida = 0;
						if(utn_getString(respuesta, 3, "Desea salir (SI/NO): ", "ERROR\n", 1) == 0){
							convertirEnMinuscula(respuesta, 3);
							if(strcmp(respuesta, "si") != 0 && strcmp(respuesta, "no") != 0){
								flagSalida = 1;
								printf("INGRESE 'SI' O 'NO'\n");
							}
						}
					}while(flagSalida);
					printf("\n");
					break;
			}
		}
	}while(menuPrincipal != 5 || strcmp(respuesta, "no") == 0);
	printf("SALIO CORRECTAMENTE");
	return EXIT_SUCCESS;
}
