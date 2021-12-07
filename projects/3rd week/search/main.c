#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define TEST_ONE 25
#define TEST_TWO 10

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

int binarySearch(int* array, int number, int size)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        const int middle = (left + right) / 2;
        if (number < array[middle])
        {
            right = middle - 1;
        }
        else if (number > array[middle])
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}

bool testQSort(void)
{
    int array[TEST_ONE] = { 17, 34, 121, 18, 61, 58, 235, 104, 674, 19, 38, 33, 410, 20, 9, 12, 4, 11, 6, 27, 1, 42, 8, 31, 26 };
    int array1[TEST_ONE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    int sortArray[TEST_ONE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    qSort(array, TEST_ONE);
    qSort(array1, TEST_ONE);
    for (int i = 0; i < TEST_ONE; i++)
    {
        if (array[i] != sortArray[i] || array1[i] != sortArray[i])
        {
            return false;
        }
    }
    return true;
}

bool testBinarySearch()
{
    int array[TEST_TWO] = { 1, 3, 7, 8, 12, 19, 26, 31, 42, 51 };
    return binarySearch(array, 3, TEST_TWO) == 1 && binarySearch(array, 11, TEST_TWO) == -1;
}

int main(int argc, char* argv[])
{
    if (!testQSort() || !testBinarySearch())
    {
        return 111;
    }
    if (argc > 1)
    {
        return 0;
    }
    srand((unsigned)time(NULL));
    printf("Введите длину массива n: ");
    int n = 0;
    scanf_s("%d", &n);
    int* array = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    qSort(array, n);
    printf("\nВведите количество случайных чисел k: ");
    int k = 0;
    scanf_s("%d", &k);
    for (int i = 0; i < k; i++)
    {
        const int number = rand() % 100;
        if (binarySearch(array, number, n) == -1)
        {
            printf("\nЧисло %d не содержится в массиве.", number);
        }
        else
        {
            printf("\nЧисло %d содержится в массиве.", number);
        }
    }
    free(array);
}