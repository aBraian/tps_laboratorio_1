/*
  Trabajo Practico 2
*/

#include <stdio.h>
#include <stdlib.h>
#include "confederacion.h"
#include "jugador.h"
#include "informes.h"
#include "ingresoDatos.h"

int main(void) {
	setbuf(stdout, NULL);
	int menuPrincipal;
	int respuesta;
	int contadorJugadores;
	eConfederacion aConfederaciones[LIMITE_CONFEDERACIONES];
	eJugador aJugadores[LIMITE_JUGADORES];
	contadorJugadores = 0;
	cargaForzadaConfederaciones(aConfederaciones, LIMITE_CONFEDERACIONES);
	inicializarJugadores(aJugadores, LIMITE_JUGADORES);
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
					if(altaJugadores(aConfederaciones, LIMITE_CONFEDERACIONES, aJugadores, LIMITE_JUGADORES) == 0){
						contadorJugadores++;
					}
					printf("\n");
					break;
				case 2:
					printf("\n");
					if(contadorJugadores > 0 && bajaJugadores(aConfederaciones, LIMITE_CONFEDERACIONES, aJugadores, LIMITE_JUGADORES) == 0){
						contadorJugadores--;
					}
					else if(contadorJugadores == 0){
						printf(ADVERTENCIA_JUGADORES);
					}
					printf("\n");
					break;
				case 3:
					printf("\n");
					if(contadorJugadores > 0 && modificarJugadores(aConfederaciones, LIMITE_CONFEDERACIONES, aJugadores, LIMITE_JUGADORES) == 0){
						printf("\nCAMBIOS APLICADOS\n");
					}
					else if(contadorJugadores == 0){
						printf(ADVERTENCIA_JUGADORES);
					}
					printf("\n");
					break;
				case 4:
					printf("\n");
					if(contadorJugadores > 0 && submenuInformes(aConfederaciones, LIMITE_CONFEDERACIONES, aJugadores, LIMITE_JUGADORES, contadorJugadores) == 0){
						printf("\n");
						printf("REGRESO CORRECTAMENTE");
						printf("\n");
					}
					else if(contadorJugadores == 0){
						printf(ADVERTENCIA_JUGADORES);
					}
					printf("\n");
					break;
				case 5:
					printf("\n");
					respuesta = salirMenu();
					printf("\n");
					break;
			}
		}
	}while(menuPrincipal != 5 || respuesta == -1);
	printf("SALIO CORRECTAMENTE");
	return EXIT_SUCCESS;
}
