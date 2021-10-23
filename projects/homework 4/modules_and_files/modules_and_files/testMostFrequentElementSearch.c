#include "testMostFrequentElementSearch.h"
#include "mostFrequentElementSearch.h"
#include <stdbool.h>

#define SIZE_TWO 10

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