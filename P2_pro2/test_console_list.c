#include <stdio.h>
#include <string.h>

#include "types.h"
#include "console_list.h"


void print_list(tList list) {
    tPosL pos;
    tItemL item;

    printf("(");
    if (!isEmptyList(list)) {
        pos = first(list);
        while (pos != LNULL) {
            item = getItem(pos, list);
            printf(" %s price %.2f", item.consoleId, item.consolePrice);
            pos = next(pos, list);
        }
    }
    printf(" )\n");
}

int main() {

    tList list;
    tPosL pos;
    tItemL item1, item2;

    /* init */
    item1.consoleBrand = nintendo;
    strcpy(item1.seller, "user1");
    item1.bidCounter = 0;


    /* create */
    createEmptyList(&list);
    print_list(list);


    /* insert */
    strcpy(item1.consoleId, "c3");
    item1.consolePrice = 30;
    insertItem(item1, &list);
    print_list(list);

    strcpy(item1.consoleId, "c1");
    item1.consolePrice = 10;
    insertItem(item1, &list);
    print_list(list);

    strcpy(item1.consoleId, "c5");
    item1.consolePrice = 50;
    insertItem(item1, &list);
    print_list(list);

    strcpy(item1.consoleId, "c2");
    item1.consolePrice = 20;
    insertItem(item1, &list);
    print_list(list);

    strcpy(item1.consoleId, "c4");
    item1.consolePrice = 40;
    insertItem(item1, &list);
    print_list(list);


    /* find */
    pos = findItem("c33", list);
    if (pos == LNULL) {
        printf("c33 Not found\n");
    }

    pos = findItem("c1", list);
    item2 = getItem(pos, list);
    printf("%s %.2f\n", item2.consoleId, item2.consolePrice);

    pos = findItem("c5", list);
    item2 = getItem(pos, list);
    printf("%s %.2f\n", item2.consoleId, item2.consolePrice);

    pos = findItem("c3", list);
    item2 = getItem(pos, list);
    printf("%s %.2f\n", item2.consoleId, item2.consolePrice);


    /* update */
    item2.consolePrice = 300;
    updateItem(item2, pos, &list);
    item2 = getItem(pos, list);
    printf("%s %.2f\n", item2.consoleId, item2.consolePrice);
    print_list(list);


    /* remove */
    deleteAtPosition(next(first(list),list), &list);  //remove c2
    print_list(list);

    deleteAtPosition(previous(last(list),list), &list);  //remove c4
    print_list(list);

    deleteAtPosition(first(list),&list);  //remove c1
    print_list(list);

    deleteAtPosition(last(list),&list);  //remove c5
    print_list(list);

    deleteAtPosition(first(list),&list);  //remove c3
    print_list(list);


    /* insert */
    insertItem(item1, &list);
    print_list(list);

    return 0;

}