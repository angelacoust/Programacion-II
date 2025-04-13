/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ANGELA COSTA TRIGO         LOGIN 1: angela.costa
 * AUTHOR 2: ANTON GONZALEZ DOMINGUEZ   LOGIN 2: anton.gonzalezd
 * GROUP: 3.2
 * DATE: 27 / 02 / 25
 */

#include "static_list.h"
#include <string.h>

void createEmptyList(tList *L) {
    L->lastPos = LNULL;
}

bool isEmptyList(tList L){
    return (L.lastPos == LNULL);
}

tPosL first(tList L){
    return 0; //El 0 es la primera posición de una lista
}

tPosL last (tList L){
    return L.lastPos; //En una lista estática, el último elemento es lastPos
}

tPosL next (tPosL p, tList L){
    if (p==L.lastPos) //Si la lista está vacía, la posición p no tiene siguiente
        return LNULL;
    else
        return ++p;
}

tPosL previous (tPosL p, tList L){
    if(isEmptyList(L))
        return LNULL; //Vacia: 0-1 = -1 (LNULL)
    else
        return --p;
}

bool insertItem (tItemL d, tPosL p, tList *L){
    tPosL i;
    //Primero comprobamos que haya espacio para insertar
    if(L->lastPos == MAX -1)
        return false;
    else { //Entonces si podemos insertar
        L->lastPos++; //Hacemos un hueco
        if (p == LNULL)
            L->data[L->lastPos] = d; //Condición de insertar el final
        else {
            for (i = L->lastPos; i >= p+1; i--) { //Dejamos un espacio para meter elemento
                L->data[i] = L->data[i - 1];
            }
        } L->data[p] = d;
    } return true;
}

void deleteAtPosition(tPosL p, tList *L){
    tPosL i;
    L->lastPos--;
    for (i = p; i <= L->lastPos; i++) {
        L->data[i] = L->data[i + 1];
    }
}

tItemL getItem(tPosL p, tList L){
    return L.data[p]; //Accedemos al contenido del elemento que hay en la posición p
}

void updateItem(tItemL d, tPosL p, tList *L){
    L->data[p] = d; //Modificamos el contenido del elemento que hay en la posición p
}

tPosL findItem(tConsoleId d, tList L){
    tPosL p;
    if(L.lastPos == LNULL){ // if (isEmptyList(L)
        return LNULL;
    }
    else {
        for (p = 0; (p <= L.lastPos ) && strcmp(L.data[p].consoleId, d)!= 0; p++ );
        if (strcmp(L.data[p].consoleId, d) == 0) //si devuelve 0 son iguales, por lo que devolvemos solo la posición
            return p;
        else
            return LNULL;
    }
}
