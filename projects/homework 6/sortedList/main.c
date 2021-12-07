#include "list.h"
#include <stdio.h>

int main()
{
    List* list = createList();
    printf("\n0 – выйти");
    printf("\n1 – добавить значение в сортированный список");
    printf("\n2 – удалить значение из списка");
    printf("\n3 – распечатать список\n");
    while (true)
    {
        printf("\nВведите команду: ");
        int input = 0;
        scanf_s("%d", &input);
        int value = 0;
        int pointer = 0;
        switch (input)
        {
        case 0:
            printf("\nВы вышли из программы.\n");
            deleteList(list);
            return -1;
        case 1:
            printf("Введите значение: ");
            scanf_s("%d", &value);
            addElement(list, value);
            pointer++;
            break;
        case 2:
            printf("Введите значение: ");
            scanf_s("%d", &value);
            deleteElement(list, value);
            pointer--;
            break;
        case 3:
        {
            int array[] = { 0 };
            printList(list, array);
            for (int i = 0; i < pointer; i++)
            {
                printf("%d ", array[i]);
            }
            break;
        }
        default:
            printf("\nНеправильный ввод команды.\n");
            break;
        }
    }
}