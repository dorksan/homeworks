#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define TEST_SIZE 25
#define SIZE 100

void sort(int* array, int size)
{
    int j = SIZE;
    for (int i = 0; i < i + j; i++)
    {
        int i = 0;
        for (j = SIZE; i + j < SIZE; j--)
        {
            if (array[i] > array[i + j])
            {
                const int temp = array[j + i];
                array[j + i] = array[i];
                array[i] = temp;
            }
        }
    }

}

bool testSort(void)
{
    int array[TEST_SIZE] = { 17, 34, 121, 18, 61, 58, 235, 104, 674, 19, 38, 33, 410, 20, 9, 12, 4, 11, 6, 27, 1, 42, 8, 31, 26 };
    int array1[TEST_SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    int sortArray[TEST_SIZE] = { 1, 4, 6, 8, 9, 11, 12, 17, 18, 19, 20, 26, 27, 31, 33, 34, 38, 42, 58, 61, 104, 121, 235, 410, 674 };
    sort(array, TEST_SIZE);
    sort(array1, TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        if (array[i] != sortArray[i] || array1[i] != sortArray[i])
        {
            return false;
        }
    }
    return true;
}


int main(int argc, char* argv[])
{
    if (!testSort())
    {
        return 111;
    }
    if (argc > 1)
    {
        return 0;
    }
    srand((unsigned)time(NULL));
    int* array = calloc(SIZE, sizeof(int));
    printf("\nИсходный массив: ");
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    sort(array, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    free(array);
}