#include "sort.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE_TWO 10

int mostFrequentElementSearch(int* array, int size)
{
    int count = 1;
    int maxCount = 1;
    int mostFrequentElement = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] == array[i - 1])
        {
            count++;
            if (count > maxCount)
            {
                maxCount = count;
                count = 1;
                mostFrequentElement = array[i];
            }
        }
        else
        {
            count = 1;
        }
    }
    return mostFrequentElement;
}

bool testMostFrequentElementSearch(void)
{
    int array[SIZE_TWO] = { 1, 1, 3, 7, 8, 8, 8, 11, 11, 11 };
    int array1[SIZE_TWO] = { 1, 2, 2, 2, 3, 4, 5, 6, 7, 8 };
    int identicalElements[SIZE_TWO] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
    int differentElements[SIZE_TWO] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    return mostFrequentElementSearch(array, SIZE_TWO) == 8 &&
        mostFrequentElementSearch(array1, SIZE_TWO) == 2 &&
        mostFrequentElementSearch(identicalElements, SIZE_TWO) == 5 &&
        mostFrequentElementSearch(differentElements, SIZE_TWO) == 1;
}

int main()
{
    if (!testQSort() || !testMostFrequentElementSearch())
    {
        printf("Ошибка");
        return -1;
    }
    srand((unsigned)time(NULL));
    printf("Введите длину массива: ");
    int size = 0;
    scanf_s("%d", &size);
    int* array = calloc(size, sizeof(int));
    FILE* fileOut = fopen("arrayFile.txt", "w");
    if (fileOut == NULL)
    {
        printf("Файл не найден");
        return -1;
    }
    printf("\nИсходный массив: ");
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
        fprintf(fileOut, "%d ", array[i]);
        printf("%d ", array[i]);
    }
    fclose(fileOut);
    FILE* fileIn = fopen("arrayFile.txt", "r");
    if (fileIn == NULL)
    {
        printf("Файл не найден");
        return -1;
    }
    int* newArray = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        fscanf_s(fileIn, "%d ", &newArray[i]);
    }
    qSort(newArray, size);
    printf("\nCамый частый элемент: %d", mostFrequentElementSearch(newArray, size));
    fclose(fileIn);
    free(array);
    free(newArray);
}