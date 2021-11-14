#include "list.h"
#include <stdio.h>

int main()
{
    List* list = createList();
    printf("\n0 – выйти\n1 – добавить значение в сортированный список");
    printf("\n2 – удалить значение из списка\n3 – распечатать список\n");
    while (1)
    {
        Position* position = createPosition(list);
        printf("\nВведите команду: ");
        int input = 0;
        scanf_s("%d", &input);
        int value = 0;
        switch (input)
        {
        case 0:
            printf("\nВы вышли из программы.\n");
            deleteList(list);
            return -1;
            break;
        case 1:
            printf("Введите значение: ");
            scanf_s("%d", &value);
            addElement(list, value);
            break;
        case 2:
            printf("Введите значение: ");
            scanf_s("%d", &value);
            deleteElement(list, value);
            break;
        case 3:
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
            break;
        default:
            printf("\nНеправильный ввод команды.\n");
            break;
        }
    }
}