#include "testMonkeySort.h"
#include "monkeySort.h"
#include <stdbool.h>

#define SIZE 5

bool testCheckSort(void)
{
    int array[SIZE] = { 8, 7, 3, 2, 1 };
    int array1[SIZE] = { 1, 4, 6, 8, 9 };
    return checkSort(array, SIZE) == 0 && checkSort(array1, SIZE) == 4;
}

bool testMonkeySort(void)
{
    int array[SIZE] = { 8, 1, 4, 9, 6 };
    int array1[SIZE] = { 1, 4, 6, 8, 9 };
    int sortArray[SIZE] = { 1, 4, 6, 8, 9 };
    monkeySort(array, SIZE);
    monkeySort(array1, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if ((array[i] != sortArray[i]) || (array1[i] != sortArray[i]))
        {
            return false;
        }
    }
    return true;
}

bool areTestsPassed(void)
{
    return testCheckSort() && testMonkeySort();
}