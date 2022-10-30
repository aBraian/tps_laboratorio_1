/*
 * confederacion.h
 *
 *  Created on: 18 oct. 2022
 *      Author: braian
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#define LIMITE_CONFEDERACIONES 6

typedef struct{
	short isEmpty;
	int id;
	int anioCreacion;
	char nombre[50];
	char region[50];
}eConfederacion;

/// @brief Incrementa de a uno la id confederaciones
///
/// @return Retorna la id
int incrementarIdConfederaciones();

/// @brief Realiza una carga forzada de datos
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitud Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int hardcodearConfederaciones(eConfederacion confederaciones[], int longitud);

/// @brief Imprime cada confederacion con sus datos
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitud Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int listarConfederaciones(eConfederacion confederaciones[], int longitud);

/// @brief Busca la posicion de una ID determinada
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitud Tamaño del array
/// @param idBuscada ID que se busca
/// @return Retorna la posicion de la ID (EXITO) y -1 (ERROR)
int buscarIdConfederacion(eConfederacion confederaciones[], int longitud, int idBuscada);

/// @brief Permite ingresar la ID de confederacion a utilizar
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitud Tamaño del array
/// @return Retorna la posicion de la ID (EXITO) y -1 (ERROR)
int selecionarConfederacion(eConfederacion confederaciones[], int longitud);

//Funciones para ABM Confederaciones

/// @brief Acumula la cantidad de confederaciones dadas de alta
///
/// @param opcion Permite aumentar o devolver la cantidad de confederaciones dadas de alta
/// @return Retorna la cantidad de ID de confederacion
int contadorIdConfederaciones(int opcion);

/// @brief Inicializa las confederaciones como vacias
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int inicializarConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones);

/// @brief Busca una posicion que este vacia
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @return Retorna la posicion vacia (EXITO) y -1 (ERROR)
int buscarVacioConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones);

/// @brief Da de alta la confederacion ingresada por el usuario
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int altaConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones);

/// @brief Da de baja la confederacion ingresada por el usuario
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int bajaConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones);

/// @brief Permite modificar la confederacion ingresada por el usuario
///
/// @param confederaciones Variable en la que estan las confederaciones
/// @param longitudConfederaciones Tamaño del array
/// @return Retorna 0 (EXITO) y -1 (ERROR)
int modificarConfederaciones(eConfederacion confederaciones[], int longitudConfederaciones);

#endif /* CONFEDERACION_H_ */
