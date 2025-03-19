/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ángela Costa Trigo         LOGIN 1: angela.costa
 * AUTHOR 2: Antón González Domínguez   LOGIN 2: anton.gonzalezd
 * GROUP: 3.2
 * DATE: 27 / 02 / 25
 */

#include "dynamic_list.h"
#include <string.h>
#include <stdlib.h>

void createEmptyList(tList *L){
    *L = LNULL;
}

bool isEmptyList(tList L){
    return L == LNULL;
}

tPosL first(tList L){
    return L; //L apunta al primer elemento
}

tPosL last(tList L){
    tPosL p;
    for(p = L; p->next != LNULL; p=p->next);//Como no hay lastpos, recorre toda la lista hasta llegar al último elemento
    return p;
}

tPosL next(tPosL p, tList L){
    return p->next;
}

tPosL previous(tPosL p, tList L){
    tPosL q;
    if (p == L)
        return LNULL; //Si p es la primera posición, no tiene anterior
    else {
        for (q=L; q->next != p; q=q->next); //Buscamos en la lista con una nueva variable llamada q, si su siguiente es p, q es el anterior a p
        return q;
    }
}

bool createNode(tPosL *p){ //Funcion auxiliar para el InsertItem
    *p=malloc(sizeof(**p)); //*p = malloc(sizeof(struct tNode));
    return *p != LNULL;
}

bool insertItem(tItemL d, tPosL p, tList *L){ //Pasamos la lista por referencia porq la vamos a modificar
    tPosL q,r;
    if(!createNode(&q)) //Si no podemos crear nodo nuevo, no hay nada que insertar
        return false;
    else{
        q->data = d;
        q->next = LNULL; //Asignamos los valores de q, que como no está aun en la lista apunta a LNULL
        if(*L == LNULL){ //Caso 1: Lista vacia
            *L = q;
        }else if(p == LNULL){// Caso 2: Insertar al final
            for (r = *L; r->next != LNULL; r=r->next);
            r->next = q;
        }else if(p == *L){ // Caso 3: Insertar al inicio
            q->next = p;
            *L = q;
        }else{ //Caso 4: Insertar en el medio
            q->data = p->data;
            p->data = d;
            q->next = p->next;
            p->next = q;
        }return true;
    }
}

void deleteAtPosition (tPosL p, tList* L) {
    tPosL q;
    if (p == *L) //Si tenemos que borrar el primer elemento
        *L = (*L)->next;
    else {
        if (p->next == LNULL) { // Eliminar último elemento
            for (q = *L; q->next != p; q = q->next);
            q->next = LNULL;
        } else { //Eliminar elemento en posición intermedia
            q = p->next; //ponemos q como siguiente de la posición que queremos borrar
            p->data = q->data;//Cambiamos el campo data de p por el de q, para sustituirlo
            p->next = q->next;
            p = q; //Hemos transformado p en q, y el nodo q que habíamos creado ahora es p, a continuación lo eliminamos
        }
    } free (p); //Liberamos memoria
}

tItemL getItem(tPosL p, tList L){
    return p->data; //Devuelve el campo data de p
}

void updateItem(tItemL d, tPosL p, tList *L){
    p->data = d; //Accedes al campo data de p y lo cambias por el tItemL que dan
}

tPosL findItem(tConsoleId d, tList L){
    tPosL p;
    for (p = L; (p != LNULL) && strcmp(p->data.consoleId, d) != 0; p=p->next); //Se para o en NULL, pq llegó al final, o cuando encuentra el mismo consoleId
    return p;
}