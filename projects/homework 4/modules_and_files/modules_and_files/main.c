#include "sort.h"
#include "mostFrequentElementSearch.h"
#include "testQSort.h"
#include "testMostFrequentElementSearch.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 100

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