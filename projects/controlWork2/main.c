#include "list.h"
#include <stdio.h>

#define SIZE 100

int main()
{
    FILE* file = fopen("file.txt", "r");
    if (file == NULL)
    {
        return -1;
    }
    int array[SIZE] = { 0 };
    int i = 0;
    while (!feof(file))
    {
        fscanf(file, "%d", &array[i]);
        i++;
    }
    fclose(file);
    List* list = createList(array);
    reverse(list);
    Position* position = createPosition(list);
    positionToHead(list, position);
    if (isPositionNull(position))
    {
        printf("\nСписок пуст.");
    }
    while (!isPositionNull(position))
    {
        printf("%d ", getValue(position));
        positionToNext(position);
    }
    deletePosition(position);
}