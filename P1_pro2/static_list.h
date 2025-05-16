/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ANGELA COSTA TRIGO         LOGIN 1: angela.costa
 * GROUP: 3.2
 * DATE: 27 / 02 / 25
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include <stdbool.h>
#include <string.h>

#define LNULL (-1)
#define MAX 25

typedef int tPosL;
typedef struct {
    tItemL data[MAX];
    tPosL lastPos;
} tList;


void createEmptyList (tList *L);
/*
 * Objetivo: Crear una lista vacía
 * Entradas: Una variable tipo tList
 * Salidas: Una lista vacía
 * Postcondición: Obtenemos una lista inicialiada y sin elementos.
 */

bool isEmptyList(tList L);
/*
 * Objetivo: Comprobar si una lista está vacía o no.
 * Entradas: Una lista
 * Salidas: Verdadero si la lista está vacía, falso si no
 * Precondición: La lista está inicializada.
 */

tPosL first (tList L);
/*
 * Objetivo: Devolver la posición del primer elemento de una lista
 * Entradas: Una lista
 * Salidas: La posición del primer elemento de dicha lista
 * Precondiciín: La lista está inicializada y no vacía
 */

tPosL last (tList L);
/*
 * Objetivo: Devolver la posición del último elemento de una lista
 * Entradas: Una lista
 * Salidas: La posición del último elemento de dicha lista
 * Precondición: La lista está inicializada y no vacía
 */

tPosL next (tPosL p, tList L);
/*
 * Objetivo: Devolver la posición siguiente a una dada en una lista
 * Entradas: Una lista y una posición de la misma
 * Salidas: La posición siguiente a la dada o LNULL si esta no tiene siguiente
 * Precondición: La lista está inicializada, no vacía y la posición dada es válida
 */

tPosL previous (tPosL p, tList L);
/*
 * Objetivo: Devolver la posición anterior a una dada en una lista
 * Entradas: Una lista y una posición de la misma
 * Salidas: La posición anterior a la dada o LNULL si esta no tiene anterior
 * Precondición: La lista está inicializada, no vacía y la posición dada es válida
 */

bool insertItem (tItemL d, tPosL p, tList *L);
/*
 * Objetivo: Insertar un elemento en la lista, antes de la posición dada. Si la posición es LNULL, insertamos al final
 * Entradas: Una, lista, una posición de la misma y un elemento a insertar
 * Salidas: Verdadero si el elemento pudo insertarse, falso en caso contrario
 * Precondición: La lista está inicializada, la posición dada es válida o LNULL y el elemento a insertar es válido
 * Postcondición: Las posiciones de los elementos posteriores al insertado pueden haber cambiado
 */

void deleteAtPosition(tPosL p, tList *L);
/*
 * Objetivo: Borrar de la lista el elemento que ocupa la posición dada
 * Entradas: Una lista y una posición de la misma
 * Salidas: La lista sin el elemento en la posición que se indicaba
 * Precondición: La lista está inicalizada y la posición dada es válida
 * Postcondición: Las posiciones de los elementos posteriores al insertado pueden haber cambiado
 */

tItemL getItem(tPosL p, tList L);
/*
 * Objetivo: Conocer el contenido del elemento de la posición dada
 * Entradas: La lista y una posición da la misma
 * Salidas: Devuelve el contenido del elemento de dicha posición
 * Precondición: La lista está inicializada, no vacía y la posición dada es válida
 */

void updateItem(tItemL d, tPosL p, tList *L);
/*
 * Objetivo: Modificar el contenido del elemento contenido en la posición dada
 * Entradas: Una lista, una posición de la misma, y el elemento nuevo por el que se va a cambiar el anterior
 * Salidas: La lista con el nuevo elemento en la posición  indicada.
 * Precondición: La lista está inicializada y la posición dada es válida
 */

tPosL findItem(tConsoleId d, tList L);
/*
 * Objetivo: Encontrar el identificador de una consola en la lista
 * Entradas: La lista y el ID que vamos a buscar en ella
 * Salidas: La posición del primer elemento de la lista cuyo ID se corresponda con el dado, o LNULL si no se encontró
 * Precondición: La lista está inicializada
 */

#endif
