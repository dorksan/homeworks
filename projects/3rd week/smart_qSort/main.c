#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25

void insertionSort(int* array, int left, int right)
{
    for (int i = left + 1; i < right; i++)
    {
        int j = i;
        while (j > left && (j - 1) > j)
        {
            const int temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}

void qSort(int* array, int size)
{
    int left = 0;
    int right = size - 1;
    const int pivot = array[(left + right) / 2];
    if ((right - left) < 10)
    {
        insertionSort(array, left, right);
    }
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

bool test(void)
{
    int array[SIZE] = { 17, 34, 121, 18, 61, 58, 235, 104, 674, 19, 38, 33, 410, 20, 9, 12, 4, 11, 6, 27, 1, 42, 8, 31, 26 };
    int array1[SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    int sortArray[SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    qSort(array, SIZE);
    qSort(array1, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] != sortArray[i] || array1[i] != sortArray[i])
        {
            return 0;
        }
    }
}

int main()
{
    if (!test())
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
        printf("%d ", array[i] = rand() % 10000);
    }
    qSort(array, size);
    printf("\nОтсортированный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    free(array);
}