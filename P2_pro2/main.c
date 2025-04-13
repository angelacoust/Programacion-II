/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Ángela Costa Trigo         LOGIN 1: angela.costa
 * AUTHOR 2: Antón González Domínguez   LOGIN 2: anton.gonzalezd
 * GROUP: 3.2
 * DATE: 05 / 04 / 25
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "console_list.h"

#define MAX_BUFFER 255

char* enumToString (tConsoleBrand brand){ //función para poder imprimir por pantalla la marca de un usuario
    if (brand == nintendo)
        return "nintendo";
    else
        return "sega";
}

tConsoleBrand stringToEnum (char * brand){ //f auxiliar para pasar la marca por parametro en el processCommand
    if(strcmp(brand, "nintendo") == 0)
        return nintendo;
    else
        return sega;
}

void new (tList *L, tConsoleId consoleId, tUserId userId, tConsoleBrand consoleBrand, tConsolePrice consolePrice){
    /*
     * Objetivo: Dar de alta una nueva consola en la lista
     * Entrada: La lista, el identificador de la consola, el id de usuario, la marca de la consola y el precio
     * Salida: Si pudo añadir, imprime los datos de la nueva consola. Si ya existe una con los mismos datos o no se ha
     *         podido realizar la inserción, devolverá un mensaje de Error
     * PreCD: La lista a insertar debe estar inicializada
     */

}

void delete (tList *L, tConsoleId consoleId){
    /*
     * Objetivo: Dar de baja una consola
     * Entrada: La lista en la que buscamos la consola y el identificador de la consola
     * Salida: Error si no se encuentra la consola o si la lista está vacía. Si se encuentra imprime la información de
     *         la consola eliminada.
     * PreCD: La lista está inicializada
     */
}

void bid (tList *L, tConsoleId consoleId, tUserId bidder, tConsolePrice consolePrice){
    /*
     * Objetivo: Pujar por una determinada consola modificando así su precio
     * Entradas: La lista de consolas, el identificador de la consola, el
     * Salidas:
     * PreCD:
     * PostCD:
     */
}

void award(tList L, tConsoleId consoleId){
    /*
     * Objetivo:
     * Entradas:
     * Salidas:
     * PreCD:
     * PostCD:
     */
}

void invalidateBids(tList *L){
    /*
     * Objetivo:
     * Entradas:
     * Salidas:
     * PreCD:
     * PostCD:
     */
}

void Remove(tList *L){
    /*
     * Objetivo:
     * Entradas:
     * Salidas:
     * PreCD:
     * PostCD:
     */
}

void stats(tList L){
    /*
     * Objetivo:
     * Entrada:
     * Salida:
     * PrecD:
     * PostCD:
     */
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {

    switch (command) {
        case 'N': //NEW: Dar de alta una nueva consola
            new(L, param1, param2, stringToEnum(param3), atof(param4));
            break;
        case 'D': //DELETE: Dar de baja una consola
            delete(L, param1);
            break;
        case 'B'://BID: Puja por una determinada consola
            bid(L, param1, param2, atof(param3));
            break;
        case 'A': //AWARD: Asignamos el ganador de la puja de una consola
            award(*L, param1);
            break;
        case 'R': //REMOVE: Elimina las consojas sin pujas
            Remove(L);
            break;
        case 'S': //STATS: Mostrar un listado de consolas y sus datos
            stats(*L);
            break;
        case 'I': //INVALIDATEBITS: Se eliminan las pujas de una consola con un número de pujas excesivo
            invalidateBids(L);
            break;
        default:
            //Damos por hecho que no se va a introducir una letra diferente
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
    createEmptyList(&L);
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