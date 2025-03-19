/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ángela Costa Trigo         LOGIN 1: angela.costa
 * AUTHOR 2: Antón González Domínguez   LOGIN 2: anton.gonzalezd
 * GROUP: 3.2
 * DATE: 07 / 03 / 25
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif


char* enumToString (tConsoleBrand brand){ //función para poder imprimir la marca de un usuario
    if (brand == nintendo)
        return "nintendo";
    else
        return "sega";
}

tConsoleBrand stringToEnum (char * brand){
    if(strcmp(brand, "nintendo") == 0)
        return nintendo;
    else
        return sega;

}

void new(tList *L, tConsoleId consoleId, tUserId seller, tConsoleBrand brand, tConsolePrice consolePrice){
   /*
    * Objetivo: Dar de alta una nueva consola en la lista
    * Entrada: La lista, el identificador de la consola, el identificador de usuario, la marca de la consola y el precio
    * Salida: Si pudo añadir, imprime los datos de la nueva consola. Si ya existe una con los mismos daros o no se ha
    *         podido realizar la inerción, devolverá un mensaje de Error
    * Precondición: La lista a insertar debe estar inicializada
    */

   if(findItem(consoleId, *L) == LNULL){ //Comprobamos que no existe ya la consola en la lista

       tItemL newConsole; //Creamos una nueva consola auxiliar

       strcpy(newConsole.consoleId, consoleId); //Copio el identificador de la consola en la auxiliar
       strcpy(newConsole.seller, seller);
       newConsole.consoleBrand = brand;
       newConsole.consolePrice = consolePrice;
       newConsole.bidCounter = 0;

       if(insertItem(newConsole, LNULL, L)) //Si se puede insertar
           printf("* New: console %s seller %s brand %s price %f\n",consoleId,seller, enumToString(brand),consolePrice);
       else
           printf("+ Error: New not possible\n");
   }else
       printf("+ Error: New not possible\n");
}

void delete(tList *L, tConsoleId consoleId){
    /*
     * Objetivo: Dar de baja una consola
     * Entrada: La lista en la que buscamos la consola y el identificador de la misma
     * Salida: Error si no se encuentra la consola o si la lista está vacía. Si se encuentra imprime la información de
     *         la consola eliminada.
     * Precondición: La lista está inicializada
     */

    if(isEmptyList(*L)) // Si la lista está vacía no hay nada que borrar
        printf("+ Error: Delete not possible\n");
    else {
        tPosL i;
        i = findItem(consoleId, *L); //i es la posición del elemento que queremos borrar
        if (i == LNULL){ // Si el usuario no existe no podemos borrarlo
            printf("+ Error: Delete not possible\n");
        } else {
            //Usando la función deleteAtPosition bastaría, pero necesitamos guardar la info del borrado en uan variable auxiliar para poder imprimir el mensaje de éxito
            tItemL deletedConsole, console;
            console = getItem(i, *L); //Para obtener todos los datos de la consola
            strcpy(deletedConsole.consoleId, console.consoleId);
            strcpy(deletedConsole.seller, console.seller);
            deletedConsole.consoleBrand = console.consoleBrand;
            deletedConsole.consolePrice = console.consolePrice;
            deletedConsole.bidCounter = console.bidCounter;

            deleteAtPosition(i, L);

            printf("* Delete: console %s seller %s brand %s price %f bids %d\n", deletedConsole.consoleId, deletedConsole.seller,
                   enumToString(deletedConsole.consoleBrand), deletedConsole.consolePrice, deletedConsole.bidCounter);
        }
    }
}

void bid(tList *L, tConsoleId consoleId, const tUserId bidder, tConsolePrice consolePrice){ //me manda poner const para evitar warnings, por qu e?
    /*
     * Objetivo: Modificar el precio de una determinada consola tras una puja
     * Entrada: La lista, el identificador de la consola, el pujaor y el precio de la consola
     * Salida: Si no existiese dicha consola, el vendedor fuese el pujador o si el precio de la puja es menor al actual,
     *         dará error, si no imprimirá la lista con el precio y el contador de pujas actualizados de dicha consola
     * Precondición: La lista está inicializada
     */

    if(isEmptyList(*L)) // Si la lista está vacía
        printf ("+ Error: Bid not possible\n");
    else {
        tPosL i;
        tItemL console;
        i = findItem(consoleId, *L);
        if (i == LNULL) //Si la consola no existiese en la lista
            printf ("+ Error: Bid not possible\n");
        else {
            console = getItem(i, *L);
            if(console.seller == bidder) //Si el vendedor es el mismo que el pujador
                printf ("+ Error: Bid not possible\n");
            else {
                if(consolePrice <= console.consolePrice) // El enunciado pone menor, pero si es igual tampoco tiene sentido actualizarlo
                    printf ("+ Error: Bid not possible\n");
                else{
                    console.bidCounter++;
                    console.consolePrice = consolePrice;
                    updateItem(console, i, L);
                    printf("* Bid: console %s seller %s brand %s price %.2f bids %d", console.consoleId, console.seller,
                           enumToString(console.consoleBrand),console.consolePrice, console.bidCounter);
                }
            }
        }
    }
}

void stats(tList *L){


    /*
     * Objetivo: mostrar un listado de consolas actuales y sus datos
     * Entrada: La lista de consolas
     * Salida: La lista de las consolas con sus datos, y error si la lista está vacía
     * Precondición: La lista está inicializada
     */
}


void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {
    printf("********************\n");
    switch (command) {
        case 'N':
            printf("%s %c: console %s seller %s brand %s price %.2f\n", commandNumber, command, param1, param2);
            new(L, param1,param2, stringToEnum(param3), atof(param4));
            break;
        case 'D':
            printf("%s %c: console %s\n", commandNumber, command, param1);
            delete(L, param1);
            break;
        case 'B':
            printf("%s %c: console %s bidder %s price %.2f\n", commandNumber, command, param1, param2, atof(param4));
            bid(L, param1, param2, atof(param4));
            break;
        case 'S':
            printf("%s %c:\n", commandNumber, command);
            stats(L);
            break;
        default:
            //Damos por hecho que no se va a pasar una letra diferente
            break;
    }
}

void readTasks(char *filename, tList *L) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4, L);
        }
        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    tList L;
    createEmptyList(&L); //creo lalista
    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name, &L);

    return 0;
}






