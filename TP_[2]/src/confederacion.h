/*
 * confederacion.h
 *
 *  Created on: 18 oct. 2022
 *      Author: braian
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#define LIMITE_CONFEDERACIONES 6
#define LONG_NOMBRE 50
#define LONG_REGION 50

typedef struct{
	int id;
	char nombre[LONG_NOMBRE];
	char region[LONG_REGION];
	int anioCreacion;
	short isEmpty;
}eConfederacion;

/// @brief Incrementa de a uno la id confederaciones
///
/// @return Retorna la id
int incrementarIdConfederaciones();

/// @brief Realiza una carga forzada de datos
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitud Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int cargaForzadaConfederaciones(eConfederacion aConfederaciones[], int longitud);

/// @brief Imprime cada confederacion con sus datos
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitud Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarConfederaciones(eConfederacion aConfederaciones[], int longitud);

/// @brief Obtiene el nombre de una confederacion a traves de su ID
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitud Tamaño del array
/// @param idBuscada ID que se usa para obtener el nombre
/// @param aNombreConfederacion Array donde se dejara el nombre de la confederacion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int obtenerNombreConfederacion(eConfederacion aConfederaciones[], int longitud, int idBuscada, char aNombreConfederacion[]);

/// @brief Obtiene la region de una confederacion a traves de su ID
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitud Tamaño del array
/// @param idBuscada ID que se usa para obtener la region
/// @param aNombreConfederacion Array donde se dejara la region de la confederacion
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int obtenerRegionConfederacion(eConfederacion aConfederaciones[], int longitud, int idBuscada, char aRegionConfederacion[]);

//Funciones para ABM Confederaciones

int buscarIdConfederacion(eConfederacion aConfederaciones[], int longitud, int idBuscada);

/// @brief Inicializa las confederaciones como vacias
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int inicializarConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones);

/// @brief Busca una posicion que este vacia
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @return Retorna la posicion vacia (EXITO) y -1 (ERROR)
int buscarVacioConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones);

/// @brief Da de alta la confederacion ingresada por el usuario
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int altaConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones);

/// @brief Da de baja la confederacion ingresada por el usuario
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int bajaConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones);

/// @brief Permite modificar la confederacion ingresada por el usuario
///
/// @param aConfederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int modificarConfederaciones(eConfederacion aConfederaciones[], int longitudConfederaciones);

#endif /* CONFEDERACION_H_ */
