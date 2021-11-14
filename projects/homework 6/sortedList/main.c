#include "list.h"
#include <stdio.h>

int main()
{
    printf("\n0 – выйти\n1 – добавить значение в сортированный список");
    printf("\n2 – удалить значение из списка\n3 – распечатать список\n");
    printf("\nВведите команду: ");
    int input = 0;
    scanf_s("%d", &input);
    switch (input)
    {
    case 0:
        printf("\nВы вышли из программы.\n");
        return -1;
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        printf("\nНеправильный ввод команды.\n");
        break;
    }
}