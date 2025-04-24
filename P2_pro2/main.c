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

void New (tList *L, tConsoleId consoleId, tUserId seller, tConsoleBrand consoleBrand, tConsolePrice consolePrice){
    /*
     * Objetivo: Dar de alta una nueva consola en la lista
     * Entrada: La lista, el identificador de la consola, el id de usuario, la marca de la consola y el precio
     * Salida: Si pudo añadir, imprime los datos de la nueva consola. Si ya existe una con los mismos datos o no se ha
     *         podido realizar la inserción, devolverá un mensaje de Error
     * PreCD: La lista a insertar debe estar inicializada
     * PostCD: El contenido de la lista puede haber cambiado
     */

    if(findItem(consoleId, *L) != LNULL) //Comprobamos que no existe ya la consola en la lista
        printf("+ Error: New not possible\n");

    else {
        tItemL newConsole; //Creamos una nueva consola auxiliar

        strcpy(newConsole.consoleId, consoleId); //Copiamos los datos de la consola en la auxiliar
        strcpy(newConsole.seller, seller);
        newConsole.consoleBrand = consoleBrand;
        newConsole.consolePrice = consolePrice;
        newConsole.bidCounter = 0;
        createEmptyStack(&newConsole.bidStack); //Creamos la pila de pujas que recibira la consola

        if(insertItem(newConsole, L)) //Si se puede insertar, insertamos e imprimimos mensaje de éxito
            printf("* New: console %s seller %s brand %s price %.2f\n",consoleId,seller, enumToString(consoleBrand),consolePrice);

        else
            printf("+ Error: New not possible\n"); //Si no se ha podido realizar la inserción
    }
}

void Delete (tList *L, tConsoleId consoleId){
    /*
     * Objetivo: Dar de baja una consola
     * Entrada: La lista en la que buscamos la consola y el identificador de la consola
     * Salida: Error si no se encuentra la consola o si la lista está vacía. Si se encuentra imprime la información de
     *         la consola eliminada.
     * PreCD: La lista está inicializada
     * PostCD: El contenido de la lista puede haber cambiado
     */

    if(isEmptyList(*L))
        printf("+ Error: Delete not possible\n"); //Si la lista está vacía no hay nada que borrar

    else {
        tPosL p;
        p = findItem(consoleId, *L);

        if (p == LNULL)
            printf("+ Error: Delete not possible\n"); // Si no se encontró el elemento (no está en la lista), da error

        else {
            tItemL console;
            console = getItem(p, *L);
            console.bidCounter = 0;

            if(!isEmptyStack(console.bidStack)) { //Si no está vacía la lista de pujas, vamos a vaciarla :)
                while (!isEmptyStack(console.bidStack)) {
                    pop(&console.bidStack);
                    console.bidCounter++;
                }
            }
            deleteAtPosition(p, L);
            printf("* Delete: console %s seller %s brand %s price %.2f bids %d\n", console.consoleId,
                   console.seller, enumToString(console.consoleBrand), console.consolePrice, console.bidCounter);
        }
    }
}

void Bid (tList *L, tConsoleId consoleId, tUserId bidder, tConsolePrice consolePrice){
    /*
     * Objetivo: Pujar por una determinada consola modificando así su precio
     * Entradas: La lista de consolas, el identificador de la consola, el
     * Entrada: La lista, el identificador de la consola, el pujaor y el precio de la consola
     * Salida: Si no existiese la consola, el vendedor fuese el pujador o si el precio de la puja es inferior al actual
               o al de la puja anterior, dará error, si no imprimirá la lista con el precio y el contador de pujas
               actualizados de dicha consola.
     * PreCD: La lista está inicializada
     * PostCD: La información de los elementos de la lista puede haber cambiado
     */


    //Creo que debería borrar el isEmptyList pq con el findItem ya compruebo q la lista no este vacía y sería comprobarlo dos veces
    //if(isEmptyList(*L)) // Si la lista está vacía
      //  printf("+ Error: Bid not possible\n");

    // else {
        tItemL console; //Creamos variable auxiliar
        tPosL i = findItem(consoleId, *L); //Buscamos la posición de la consola en la lista

        if (i == LNULL)  //Si la consola no existiese en la lista da error
            printf("+ Error: Bid not possible\n");

        else {
            console = getItem(i, *L); //Buscamos la consola en la lista
            //Si pujador = vendedor o si el precio la puja actual es inferior al de la puja anterior o al de la consola
            if ((strcmp(console.seller, bidder) == 0) ||
               (consolePrice <= console.consolePrice) || (consolePrice <= peek(console.bidStack).consolePrice))
                printf("+ Error: Bid not possible\n");

            else {
                tItemS bid;
                strcpy(bid.bidder, bidder);
                bid.consolePrice = consolePrice;

                //Si no se puede insertar en la pila de pujas
                if (!push(bid, &console.bidStack))
                    printf("+ Error: Bid not possible\n");

                else {
                    console.bidCounter++; //Aumentamos el número de veces que se ha pujado
                    updateItem(console, i, L); //Actualizamos  datos de la consola e imprimimos mensaje de exito
                    printf("* Bid: console %s bidder %s brand %s price %.2f bids %d\n",console.consoleId,bid.bidder,
                           enumToString(console.consoleBrand), consolePrice, console.bidCounter);
                }
            }
        }
    //}
}

void Award(tList L, tConsoleId consoleId){
    /*
     * Objetivo: Asignar el ganador de la puja de una consola
     * Entradas: La lista y el identificador de la consola ganadora
     * Salidas:
     * PreCD:
     * PostCD:
     */
}

void InvalidateBids(tList *L){
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
     * PostCD: El contenido de la lista puede haber cambiado
     */
}

void Stats(tList L) {
    /*
     * Objetivo: Mostrar un listado de las consolas actuales y sus respectivos datos
     * Entrada: La lista
     * Salida: La lista de las consolas con sus datos, y error si la lista está vacía. Y se mostrará la consola para la
     *         que el importe de su mejor puja suponga el mayor incremento sobre su precio original o si no existiera
     *         ninguna puja, un mensaje que informe de ello.
     * PreCD: La lista está inicializada
     */

    if (isEmptyList(L))
        printf("+ Error: Stats not possible\n");

    else {
        tPosL posL;
        tItemL console, maximo; //Consola auxiliar que servirá para poder imprimir la información de todas las de la lista
        tItemS bid, mayorBid;

        int cNintendo = 0, cSega = 0, bids = 0;
        float cNintendoPrice = 0, cSegaPrice = 0, averageNintendo, averageSega, aux = 0 ;


        for (posL =first(L); posL != LNULL; posL = next(posL, L)) {
            console = getItem(posL, L); //Usamos el getItem para obtener la info de cada consola que hay en la lista
            //Imprimimos los datos de cada una de las consolas
            printf("Console %s seller %s brand %s price %.2f", console.consoleId, console.seller,
                   enumToString(console.consoleBrand), console.consolePrice);

            if(isEmptyStack(console.bidStack)) { // if(console.bidCounter == 0)
                printf(". No bids\n");
            } else {
                bid = peek(console.bidStack); //Accedemos a la última puja de la consola
                printf(" bids %d top bidder %s\n", console.bidCounter, bid.bidder); //Imprimimos sus datos
                bids++; //
                if (((bid.consolePrice) * 100 / console.consolePrice - 100) > aux) {
                    aux = ((bid.consolePrice * 100 / console.consolePrice) - 100);
                    maximo = console;
                    mayorBid = bid; //Para guardar el mayor porcentaje
                }
            }

            if (console.consoleBrand == nintendo) {
                cNintendo++; //Vamos contando el número de consolas de la marca nintendo por un lado
                cNintendoPrice += console.consolePrice; //Tambien almacenamos el precio de todas para calcular luego la media
            } else {
                cSega++; //Marca sega
                cSegaPrice += console.consolePrice; //Para calcular la media
            }

            if (cNintendoPrice == 0) //Para evitar una división entre 0, que daria indeterminado
                averageNintendo = 0;
            else
                averageNintendo = cNintendoPrice / (float) cNintendo; //Calculamos la media dividiendo el dinero total entre el numero de consolas (Nintendo)

            if (cSega == 0) //Evitar división entre cero
                averageSega = 0;
            else
                averageSega = cSegaPrice / (float) cSega; //Calculamos la media dividiendo el dinero total entre el numero de consolas (Sega)
        }

        printf("\nBrand     Consoles    Price  Average\n"
               "Nintendo  %8d %8.2f %8.2f\n"
               "Sega      %8d %8.2f %8.2f\n", cNintendo,cNintendoPrice,averageNintendo, cSega,cSegaPrice,averageSega);

        if (bids > 0){
            printf("Top bid: console %s seller %s brand %s price %.2f bidder %s top price %.2f increase %.2f%%\n",
                   maximo.consoleId, maximo.seller, enumToString(maximo.consoleBrand), maximo.consolePrice,
                   mayorBid.bidder, mayorBid.consolePrice, aux);
        } else {
            printf("Top bid not possible\n");
        }
    }
}
/*
 * Extraccion respecto a la implementacion dinmámica y estática
 * Hay que implementar como tipo de dato abstracto, no asumir y usar las funciiones hechas
 * Coger programa principal y buscamos corchetes y flechas. Corchetes no debería haber ninguno que sea de acceder a la pila
 * Flechas no debería haber accediendo a ninguna accediendo a la posición a la lista.
 */

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {
    printf("********************\n");
    switch (command) {
        case 'N': //NEW: Dar de alta una nueva consola
            printf("%s %c: console %s seller %s brand %s price %.2f\n", commandNumber,command,param1,param2,param3,atof(param4));
            New(L, param1, param2, stringToEnum(param3), atof(param4));
            break;
        case 'D': //DELETE: Dar de baja una consola
            printf("%s %c: console %s\n", commandNumber, command, param1);
            Delete(L, param1);
            break;
        case 'B'://BID: Puja por una determinada consola
            printf("%s %c: console %s bidder %s price %.2f\n", commandNumber, command, param1, param2, atof(param3));
            Bid(L, param1, param2, atof(param3));
            break;
        case 'A': //AWARD: Asignamos el ganador de la puja de una consola
            printf("%s %c: console %s\n", commandNumber, command, param1);
            Award(*L, param1);
            break;
        case 'R': //REMOVE: Elimina las consojas sin pujas
            printf("%s %c\n", commandNumber, command);
            Remove(L);
            break;
        case 'S': //STATS: Mostrar un listado de consolas y sus datos
            printf("%s %c\n", commandNumber, command);
            Stats(*L);
            break;
        case 'I': //INVALIDATEBITS: Se eliminan las pujas de una consola con un número de pujas excesivo
            printf("%s %c\n", commandNumber, command);
            InvalidateBids(L);
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

    char *file_name = "bid.txt";

    tList L;
    createEmptyList(&L); //Creación de la lista
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