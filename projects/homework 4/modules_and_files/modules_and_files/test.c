#include "test.h"
#include <stdbool.h>

#define SIZE_ONE 25
#define SIZE_TWO 10

bool testQSort(void)
{
    int array[SIZE_ONE] = { 17, 34, 121, 18, 61, 58, 235, 104, 674, 19, 38, 33, 410, 20, 9, 12, 4, 11, 6, 27, 1, 42, 8, 31, 26 };
    int array1[SIZE_ONE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    int sortArray[SIZE_ONE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    qSort(array, SIZE_ONE);
    qSort(array1, SIZE_ONE);
    for (int i = 0; i < SIZE_ONE; i++)
    {
        if (array[i] != sortArray[i] || array1[i] != sortArray[i])
        {
            return false;
        }
    }
    return true;
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