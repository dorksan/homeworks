#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#define TEST_SIZE 10

void halfQSort(int* array, int size)
{
    int left = 0;
    int right = size - 1;
    int firstElement = array[0];
    while (left <= right)
    {
        while (array[left] < firstElement)
        {
            left++;
        }
        while (array[right] >= firstElement)
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
}

bool testHalfQSort(void)
{
    int array[TEST_SIZE] = { 9, 12, 4, 11, 6, 27, 1, 42, 8, 31 };
    int sortArray[TEST_SIZE] = { 8, 1, 4, 6, 11, 27, 12, 42, 9, 31 };
    halfQSort(array, TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        if (array[i] != sortArray[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    if (!testHalfQSort())
    {
        printf("Ошибка");
        return -1;
    }
    srand((unsigned)time(NULL));
    printf("Введите длину массива: ");
    int size = 0;
    scanf_s("%d", &size);
    int* array = calloc(size, sizeof(int));
    printf("\nИсходный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i] = rand() % 10);
    }
    halfQSort(array, size);
    printf("\nОтсортированный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    free(array);
}