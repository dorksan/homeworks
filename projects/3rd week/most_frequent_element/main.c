#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

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

void qSort(int* array, int size)
{
    int left = 0;
    int right = size - 1;
    int pivot = array[(left + right) / 2];
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
            int temp = array[left];
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
    int array[25] = { 17, 34, 121, 18, 61, 58, 235, 104, 674, 19, 38, 33, 410, 20, 9, 12, 4, 11, 6, 27, 1, 42, 8, 31, 26 };
    int array1[25] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    int sortArray[25] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    qSort(array, 25);
    qSort(array1, 25);
    for (int i = 0; i < 25; i++)
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
    int array[10] = { 1, 1, 3, 7, 8, 8, 8, 11, 11, 11 };
    int array1[10] = { 1, 2, 2, 2, 3, 4, 5, 6, 7, 8 };
    int identicalElements[10] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
    int differentElements[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    return (mostFrequentElementSearch(array, 10) == 8 &&
        mostFrequentElementSearch(array1, 10) == 2 &&
        mostFrequentElementSearch(identicalElements, 10) == 5 &&
        mostFrequentElementSearch(differentElements, 10) == 1);
}

int main()
{
    if (!testQSort() || !testMostFrequentElementSearch())
    {
        printf("Ошибка");
        return -1;
    }
    srand(time(NULL));
    printf("Введите длину массива: ");
    int size = 0;
    scanf_s("%d", &size);
    int* array = calloc(size, sizeof(int));
    printf("\nИсходный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i] = rand() % 100);
    }
    qSort(array, size);
    printf("\nCамый частый элемент: %d", mostFrequentElementSearch(array, size));
    free(array);
}