#include "testList.h"
#include "list.h"
#include <stdbool.h>

#define SIZE 5

bool areTestsPassed(void)
{
    List* list = createList();
    addElement(list, 25);
    addElement(list, 12);
    addElement(list, 26);
    addElement(list, 4);
    addElement(list, 19);
    deleteElement(list, 25);
    addElement(list, 2);
    int array[SIZE] = { 0 };
    printList(list, array);
    return array[0] == 2 && array[1] == 4
        && array[2] == 12; array[3] == 19
        && array[4] == 26;
}