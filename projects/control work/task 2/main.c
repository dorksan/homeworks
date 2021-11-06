#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25

void insertionSort(int* array, int left, int right)
{
    for (int i = left + 1; i < right; i++)
    {
        int j = i;
        while (j > left && array[j - 1] > array[j])
        {
            const int temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}

void shellSort(int* array, int size)
{
    for (int i = size / 2; i > 0; i /= 2)
    {
        for (int j = 0; j <= size; j++)
        {
            insertionSort(array, i - 1, j);
        }
    }
}

bool testInsertionSort(void)
{
    int array[SIZE] = { 17, 34, 121, 18, 61, 58, 235, 104, 674, 19, 38, 33, 410, 20, 9, 12, 4, 11, 6, 27, 1, 42, 8, 31, 26 };
    int array1[SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    int sortArray[SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    insertionSort(array, 0, SIZE);
    insertionSort(array1, 0, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] != sortArray[i] || array1[i] != sortArray[i])
        {
            return false;
        }
    }
    return true;
}

bool testShellSort(void)
{
    int array[SIZE] = { 17, 34, 121, 18, 61, 58, 235, 104, 674, 19, 38, 33, 410, 20, 9, 12, 4, 11, 6, 27, 1, 42, 8, 31, 26 };
    int array1[SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    int sortArray[SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    shellSort(array, SIZE);
    shellSort(array1, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] != sortArray[i] || array1[i] != sortArray[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    if (!testInsertionSort() || !testShellSort())
    {
        printf("Ошибка");
        return -1;
    }
    srand((unsigned)time(NULL));
    printf("Введите длину массива: ");
    int size = 0;
    scanf_s("%d", &size);
    int* array = calloc(size, sizeof(int));
    if (array == NULL)
    {
        printf("Ошибка создания массива");
        return -1;
    }
    printf("\nИсходный массив: ");
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    shellSort(array, size);
    printf("\nОтсортированный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    free(array);
}