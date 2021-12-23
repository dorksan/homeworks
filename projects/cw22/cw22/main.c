#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

int main()
{
    List* list = createList();
    Position* position = createPosition(list);
    FILE* file = fopen("file.txt", "r");
    if (file == NULL)
    {
        return 1;
    }
    char string[SIZE] = { 0 };
    int pointer = 0;
    while (!feof(file))
    {
        fscanf(file, "%s", &string);
        addElement(list, position, string);
        pointer++;
    }
    fclose(file);
    deleteSameString(list, position);
    char array[SIZE] = { 0 };
    printList(list, array);
    for (int i = 0; i < pointer; i++)
    {
        if (array != NULL)
        {
            printf("%s ", array[i]);
        }
    }
}