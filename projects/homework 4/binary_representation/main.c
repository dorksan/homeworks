#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 4

void decimalToBinary(int number, int* array, int size)
{
    int decimalNumber = abs(number);
    while (decimalNumber != 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (decimalNumber % 2 == 0)
            {
                array[i] = 0;
            }
            else
            {
                array[i] = 1;
            }
            decimalNumber /= 2;
        }
    }
}

void binaryAddition(int* array1, int* array2, int* array3, int size)
{
    int temp = 0;
    for (int i = 0; i < size+1; i++)
    {
        temp = array1[i] + array2[i] + temp;
        if (temp == 2)
        {
            array3[i] = 0;
            temp = 1;
        }
        if (temp == 3)
        {
            array3[i] = 1;
            temp = 1;
        }
    }
}

bool test(void)
{
    int arrayTest15[SIZE] = { 0, 0, 0, 0 };
    int arrayTest8[SIZE] = { 0, 0, 0, 0 };
    int array15[SIZE] = { 1, 1, 1, 1 };
    int array8[SIZE] = { 0, 0, 0, 1 };
    decimalToBinary(15, arrayTest15, SIZE);
    decimalToBinary(8, arrayTest8, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if (arrayTest15[i] != array15[i] || arrayTest8[i] != array8[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    if (!test())
    {
        printf("Ошибка");
        return -1;
    }
    int firstNumber = 0;
    printf("Введите первое число: ");
    scanf_s("%d", &firstNumber);
    int secondNumber = 0;
    printf("Введите второе число: ");
    scanf_s("%d", &secondNumber);
    const int sizeFirst = log2(firstNumber) + 1;
    int* arrayFirst = calloc(sizeFirst, sizeof(int));
    decimalToBinary(firstNumber, arrayFirst, sizeFirst);
    printf("\nДвоичное представление первого числа: ");
    for (int i = 0; i < sizeFirst; i++)
    {
        printf("%d", arrayFirst[sizeFirst - i - 1]);
    }
    const int sizeSecond = log2(secondNumber) + 1;
    int* arraySecond = calloc(sizeSecond, sizeof(int));
    decimalToBinary(secondNumber, arraySecond, sizeSecond);
    printf("\nДвоичное представление второго числа: ");
    for (int i = 0; i < sizeSecond; i++)
    {
        printf("%d", arraySecond[sizeSecond - i - 1]);
    }
    int maxSize = max(sizeFirst, sizeSecond);
    int* arrayThird = calloc(maxSize, sizeof(int));
    binaryAddition(arrayFirst, arraySecond, arrayThird, maxSize);
    printf("\nСумма двух чисел: ");
    for (int i = 0; i < maxSize; i++)
    {
        printf("%d", arrayThird[i]);
    }
    free(arrayFirst);
    free(arraySecond);
    free(arrayThird);
}