#include "sort.h"
#include <stdbool.h>

#define SIZE_ONE 25

void qSort(int* array, int size)
{
    int left = 0;
    int right = size - 1;
    const int pivot = array[(left + right) / 2];
    while (left <= right)
    {
        while (array[left] < pivot)
        {
            left++;
        }
        while (array[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            const int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
    if (right > 0)
    {
        qSort(array, right + 1);
    }
    if (left < size)
    {
        qSort(&array[left], size - left);
    }
}

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