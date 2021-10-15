#include "sort.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 100
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
    FILE* fileIn = fopen("arrayFile.txt", "r");
    if (fileIn == NULL)
    {
        printf("Файл не найден");
        return -1;
    }
    int* array = calloc(SIZE, sizeof(int));
    for (int i = 0; i < SIZE; i++)
    {
        fscanf_s(fileIn, "%d ", &array[i]);
        printf("%d ", array[i]);
    }
    qSort(array, SIZE);
    printf("\nCамый частый элемент: %d", mostFrequentElementSearch(array, SIZE));
    fclose(fileIn);
    free(array);
}