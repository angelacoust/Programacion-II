/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Costa Trigo         LOGIN 1: angela.costa
 * GROUP: 3.2
 * DATE: 28 / 03 / 25
 */

#include "bid_stack.h"

void createEmptyStack (tStack *S){
    S->top = SNULL;
}

bool push (tItemS d, tStack *S){
    if (S->top == SMAX -1) //si la pila está llena no podemos insertar
        return false;
    else {
        S->top ++; //Hacemos un hueco arriba para poder insertar
        S->data[S->top] = d; //En el campo data de la primera posición insertamos
        return true;
    }
}

void pop(tStack *S){
    S->top--; //Decrementamos la pila para que la cima se vaya fuera (eliminarla)
}

tItemS peek (tStack S){
    return (S.data[S.top]); //Accedemos al campo data del primer elemento de la lista
}

bool isEmptyStack (tStack S){
    return (S.top == SNULL);
}