#include "conversion.h"
#include "testConversion.h"
#include "binaryAddition.h"
#include "testBinaryAddition.h"
#include <stdio.h>

#define SIZE 8

int main()
{
    if (!testDecimalToBinary() || !testBinaryAddition() || !testBinaryToDecimal())
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
    printf("\nДвоичное представление суммы двух чисел: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", sum[i]);
    }
    printf("\nДесятичное представление суммы двух чисел: %d", (binaryToDecimal(sum)));
}