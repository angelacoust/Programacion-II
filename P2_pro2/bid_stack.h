/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Costa Trigo         LOGIN 1: angela.costa
 * AUTHOR 2: Antón González Domínguez   LOGIN 2: anton.gonzalezd
 * GROUP: 3.2
 * DATE: 28 / 03 / 25
 */

#ifndef BID_STACK_H
#define BID_STACK_H

#include "types.h"
#include <stdbool.h>

#define SMAX 25
#define SNULL (-1)

typedef int tPosS;

typedef struct tItemS{
    tUserId bidder;
    tConsolePrice consolePrice;
}tItemS;

typedef struct {
    tItemS data[SMAX];
    tPosS top;
}tStack;


void createEmptyStack(tStack *S);
/*
 * Objetivo: Crear una pila vacia
 * Entrada: Una variable que apunta a la pila
 * Salida: una pila vacía
 * Precondición: la pila no debe estar inicializada
 * Postcondición: la pila queda inicializada sin datos
 */

bool push (tItemS d, tStack *S);
/*
 * Objetivo: añadir el elemento en la pila quedando en la cima
 * Entradas: elemento a insertar en la pila
 * Salida: la pila con el elemento en la cima de la pila. true si se ha podido realizar la operacion, false en caso contrario
 * Precondición: La pila debe estar inicializada
 * Postcondición: la pila con el nuevo elemento en la cima
 */

tItemS peek (tStack S);
/*
 * Objetivo: Recuperar el elemento de la cima
 * Entrada: La pila
 * Salida: El elemento de la cima de salida, true en caso de exito
 * Precondición: La pila debe estar inicializada y no vacía
 */

bool isEmptyStack(tStack S);
/*
 * Objetivo: Determinar si una pila está vacía
 * Entrada: La pila
 * Salida: Devuelve verdadero si pila vacía, falso en caso contrario
 * Precondición: La pila debe estar inicializada
 */


void pop (tStack *S);
/*
 * Objetivo: Eliminar elemento de la cima de la pila
 * Entrada: La pila
 * Salida: La pila sin el elemento de su cima. Devuelve verdadero en caso de exito y falso en caso contrario
 * Precondición: La pila debe estar inicializada y no vacía
 * Postcondición: La pila es el resultado de eliminar el elemento de la cima de la pila.
 */

#endif