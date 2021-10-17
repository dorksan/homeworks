#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#define SIZE 8

void decimalToBinary(int number, int* array)
{
    int decimalNumber = number;
    int mask = 0b10000000;
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = ((decimalNumber & mask) ? 1 : 0);
        mask = mask >> 1;
    }

}

void binaryAddition(int* array1, int* array2, int* array3)
{
    int temp = 0;
    for (int i = SIZE; i > 0; i--)
    {
        int sum = array1[i] + array2[i] + temp;
        if (sum == 0)
        {
            array3[i] = 0;
            temp = 0;
        }
        if (sum == 1)
        {
            array3[i] = 1;
            temp = 0;
        }
        if (sum == 2)
        {
            array3[i] = 0;
            temp = 1;
        }
        if (sum == 3)
        {
            array3[i] = 1;
            temp = 1;
        }
    }
}

bool test(void)
{
    int arrayTest15[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest8[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest5[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTestMinus5[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest0[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int array15[SIZE] = { 0, 0, 0, 0, 1, 1, 1, 1 };
    int array8[SIZE] = { 0, 0, 0, 0, 1, 0, 0, 0};
    int array5[SIZE] = { 0, 0, 0, 0, 0, 1, 0, 1 };
    int arrayMinus5[SIZE] = { 1, 1, 1, 1, 1, 0, 1, 1 };
    int array0[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    decimalToBinary(15, arrayTest15, SIZE);
    decimalToBinary(8, arrayTest8, SIZE);
    decimalToBinary(5, arrayTest5, SIZE);
    decimalToBinary(-5, arrayTestMinus5, SIZE);
    decimalToBinary(0, arrayTest0, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if (arrayTest15[i] != array15[i] || arrayTest8[i] != array8[i] ||
            arrayTest5[i] != array5[i] || arrayTestMinus5[i] != arrayMinus5[i] ||
            arrayTest0[i] != array0[i])
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
    int firstArray[SIZE] = { 0 };
    decimalToBinary(firstNumber, firstArray);
    printf("\nДвоичное представление первого числа: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", firstArray[i]);
    }
    int secondArray[SIZE] = { 0 };
    decimalToBinary(secondNumber, secondArray);
    printf("\nДвоичное представление второго числа: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", secondArray[i]);
    }
    int sum[SIZE] = { 0 };
    binaryAddition(firstArray, secondArray, sum);
    printf("\nСумма двух чисел: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", sum[i]);
    }
}