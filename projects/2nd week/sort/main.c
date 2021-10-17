#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>

#define SIZE 100000
#define TEST_SIZE 25
#define MAX_NUMBER 674

void bubbleSort(int* array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (array[j - 1] > array[j])
            {
                const int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void countingSort(int* array, int size, int maxNumber)
{
    int* newArray = calloc(maxNumber + 1, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        newArray[array[i]]++;
    }
    int temp = 0;
    for (int i = 0; i < maxNumber + 1; i++)
    {
        for (int j = 0; j < newArray[i]; j++)
        {
            array[temp++] = i;
        }
    }

}

bool testBubbleSort(void)
{
    int array[TEST_SIZE] = { 17, 34, 121, 18, 61, 58, 235, 104, 674, 19, 38, 33, 410, 20, 9, 12, 4, 11, 6, 27, 1, 42, 8, 31, 26 };
    int array1[TEST_SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    int sortArray[TEST_SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    bubbleSort(array, TEST_SIZE);
    bubbleSort(array1, TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        if (array[i] != sortArray[i] || array1[i] != sortArray[i])
        {
            return false;
        }
    }
    return true;
}

bool testCountingSort(void)
{
    int arrayTest1[TEST_SIZE] = { 17, 34, 121, 18, 61, 58, 235, 104, 674, 19, 38, 33, 410, 20, 9, 12, 4, 11, 6, 27, 1, 42, 8, 31, 26 };
    int arrayTest2[TEST_SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    int sortArray[TEST_SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    countingSort(arrayTest1,TEST_SIZE, MAX_NUMBER);
    countingSort(arrayTest2,TEST_SIZE, MAX_NUMBER);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        if (arrayTest1[i] != sortArray[i] || arrayTest2[i] != sortArray[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    if (!testBubbleSort() || !testCountingSort())
    {
        printf("Ошибка");
        return -1;
    }
    int* array = calloc(SIZE, sizeof(int));
    int* copyArray = calloc(SIZE, sizeof(int));
    int maxNumber = 0;
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 1000;
        copyArray[i] = array[i];
        if (array[i] > maxNumber)
        {
            maxNumber = array[i];
        }
    }
    const clock_t start = clock();
    bubbleSort(array, SIZE);
    const clock_t end = clock();
    const double seconds = (const double)(end - start) / CLOCKS_PER_SEC;
    printf("Время работы сортировки пузырьком: %lf", seconds);
    const clock_t start1 = clock();
    countingSort(copyArray, SIZE, maxNumber);
    const clock_t end1 = clock();
    const double seconds1 = (const double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("\nВремя работы сортировки подсчетом: %lf", seconds1);
    free(array);
    free(copyArray);
}