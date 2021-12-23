#include "monkeySort.h"
#include "testMonkeySort.h"
#include <stdio.h>
#include <time.h>

int main()
{
    if (!areTestsPassed())
    {
        return 111;
    }
    srand((unsigned)time(NULL));
    printf("Введите длину массива: ");
    int size = 0;
    scanf_s("%d", &size);
    int* array = calloc(size, sizeof(int));
    if (array == NULL)
    {
        return 11;
    }
    printf("\nИсходный массив: ");
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 20;
        printf("%d ", array[i]);
    }
    monkeySort(array, size);
    printf("\nОтсортированный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    free(array);
}