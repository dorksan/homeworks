#include "circularList.h"
#include <stdio.h>

int main()
{
    int numberOfWarriors = 0;
    printf("В отряде n воинов.\nВведите n: ");
    scanf_s("%d", &numberOfWarriors);
    int murderedWarrior = 0;
    printf("Убивают каждого m-го воина.\nВведите m: ");
    scanf_s("%d", &murderedWarrior);
    List* list = createList();
    Position* position = createPosition(list);
    for (int i = 1; i <= numberOfWarriors; i++)
    {
        addElement(list, position, i);
    }
    positionToHead(list, position);
    if (isPositionNull(position))
    {
        printf("\nСписок пуст.");
    }
    int count = 1;
    while (true)
    {
        count++;
        positionToNext(list, position);
        if (count == murderedWarrior - 1)
        {
            deleteElement(list, position);
            count = 1;
            if (isLastOne(list))
            {
                break;
            }
        }
    }
    printf("Номер начальной позиции оставшегося воина: %d ", getValue(position));
    deleteList(list);
    deletePosition(position);
}