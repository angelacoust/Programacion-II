/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Costa Trigo         LOGIN 1: angela.costa
 * AUTHOR 2: Antón González Domínguez   LOGIN 2: anton.gonzalezd
 * GROUP: 3.2
 * DATE: 28 / 03 / 25
 */

#include "console_list.h"

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

tPosL findPosition(tList L, tItemL d){ //Funcion auxiliar para el insertItem
    tPosL p;

    for (p = L; ((p->next !=  LNULL) && strcmp(p->next->data.consoleId, d.consoleId) < 0); p = p->next);
    return p;
}

bool insertItem(tItemL d, tList *L){ //Pasamos la lista por referencia porq la vamos a modificar
    tPosL p,q;
    if(!createNode(&q)) //Si no podemos crear nodo nuevo, no hay nada que insertar
        return false;
    else{
        q->data = d; //Creamos puntero q
        q->next = LNULL; //Asignamos los valores de q, que como no está aun en la lista apunta a LNULL
        if(*L == LNULL){ //Caso 1: Lista vacia
            *L = q;
        } else if(strcmp(d.consoleId, (*L)->data.consoleId) <0 ){// Caso 2: Colocar antes del primer elemento
            q->next  = *L;
            *L = q;
        } else{ //Caso 3: Insertar en el medio o al final
            p = findPosition(*L, d); //Buscamos la posición en la que queremos insertar con la f auxiliar
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

    for (p = L; (p != LNULL) && strcmp(p->data.consoleId, d) < 0; p=p->next); //Recorremos la lista
    if (p != LNULL && strcmp(p->data.consoleId, d) == 0) //Encontramos el elemento
        return p;
    else
        return LNULL;
}