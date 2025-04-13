/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Costa Trigo         LOGIN 1: angela.costa
 * AUTHOR 2: Antón González Domínguez   LOGIN 2: anton.gonzalezd
 * GROUP: 3.2
 * DATE: 28 / 03 / 25
 */

#ifndef CONSOLE_LIST_H
#define CONSOLE_LIST_H

#define LNULL NULL

#include "types.h"
#include "bid_stack.h"

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct tItemL{ //Estos son todos los datos de una consola
    tUserId seller;
    tConsoleId consoleId;
    tConsoleBrand consoleBrand;
    tConsolePrice consolePrice;
    tBidCounter bidCounter;
    tStack bidStack; //Pila con las pujas recibidas por la consola
} tItemL;

typedef struct tNode *tPosL;

struct tNode{
    tItemL data;
    tPosL next;
};
typedef tPosL tList;


void createEmptyList(tList *L);
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

tPosL first(tList L);
/*
 * Objetivo: Devolver la posición del primer elemento de una lista
 * Entradas: Una lista
 * Salidas: La posición del primer elemento de dicha lista
 * Precondiciín: La lista está inicializada y no vacía
 */

tPosL last(tList L);
/*
 * Objetivo: Devolver la posición del último elemento de una lista
 * Entradas: Una lista
 * Salidas: La posición del último elemento de dicha lista
 * Precondición: La lista está inicializada y no vacía
 */

tPosL next(tPosL p, tList L);
/*
 * Objetivo: Devolver la posición siguiente a una dada en una lista
 * Entradas: Una lista y una posición de la misma
 * Salidas: La posición siguiente a la dada o LNULL si esta no tiene siguiente
 * Precondición: La lista está inicializada, no vacía y la posición dada es válida
 */

tPosL previous(tPosL p, tList L);
/*
 * Objetivo: Devolver la posición anterior a una dada en una lista
 * Entradas: Una lista y una posición de la misma
 * Salidas: La posición anterior a la dada o LNULL si esta no tiene anterior
 * Precondición: La lista está inicializada, no vacía y la posición dada es válida
 */

bool insertItem(tItemL d, tList *L);
/*
 * Objetivo: Insertar un elemento en la lista, antes de la posición dada. Si la posición es LNULL, insertamos al final
 * Entradas: Una, lista, una posición de la misma y un elemento a insertar
 * Salidas: Verdadero si el elemento pudo insertarse, falso en caso contrario
 * Precondición: La lista está inicializada, la posición dada es válida o LNULL y el elemento a insertar es válido
 * Postcondición: Las posiciones de los elementos posteriores al insertado pueden haber cambiado
 */

void deleteAtPosition (tPosL p, tList *L);
/*
 * Objetivo: Borrar de la lista el elemento que ocupa la posición dada
 * Entradas: Una lista y una posición de la misma
 * Salidas: La lista sin el elemento en la posición que se indicaba
 * Precondición: La lista está inicalizada, la posición dada es váliday la consola en dicha
                 posición tiene una pila de pujas vacía
 * Postcondición: Las posiciones de los elementos posteriores al insertado pueden haber cambiado
 */

tItemL getItem(tPosL p, tList L);
/*
 * Objetivo: Conocer el contenido del elemento de la posición dada
 * Entradas: La lista y una posición da la misma
 * Salidas: Devuelve el contenido del elemento que ocupa la posición indicada
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

bool createNode(tPosL *p);
/*
 * Objetivo: Crear un nuevo nodo para meter en una lista
 * Entrada: La posición en la que vamos a crear el nodo
 * Salida: Verdadero si se crea el nodo, falso si no se pudo
 */


#endif