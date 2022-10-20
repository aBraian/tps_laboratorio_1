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
		if(utn_getInt(&menuPrincipal, "OPCION: ", "OPCION NO VALIDA\n", 1, 5, 1) == 0){
			switch(menuPrincipal){
				case 1:
					printf("\n");
					altaJugadores(confederaciones, 6, jugadores, 6);
					printf("\n");
					break;
				case 2:
					printf("\n");
					printf("Numero de Opcion: %d\n", menuPrincipal);
					printf("\n");
					break;
				case 3:
					printf("\n");
					printf("Numero de Opcion: %d\n", menuPrincipal);
					printf("\n");
					break;
				case 4:
					printf("\n");
					printf("Numero de Opcion: %d\n", menuPrincipal);
					printf("\n");
					break;
				case 5:
					printf("\n");
					printf("SALIO CORRECTAMENTE");
					break;
			}
		}
	}while(menuPrincipal != 5);
	return EXIT_SUCCESS;
}
