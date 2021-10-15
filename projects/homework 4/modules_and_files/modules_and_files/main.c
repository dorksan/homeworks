#include "sort.h"
#include "test.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 100

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