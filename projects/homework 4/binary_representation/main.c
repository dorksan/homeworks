#include "conversion.h"
#include "testConversion.h"
#include "binaryAddition.h"
#include "testBinaryAddition.h"
#include <stdio.h>

#define SIZE (sizeof(int) * 8)

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
    decimalToBinary(firstNumber, firstArray, SIZE);
    printf("\nДвоичное представление первого числа: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", firstArray[SIZE - i - 1]);
    }
    int secondArray[SIZE] = { 0 };
    decimalToBinary(secondNumber, secondArray, SIZE);
    printf("\nДвоичное представление второго числа: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", secondArray[SIZE - i - 1]);
    }
    int sum[SIZE] = { 0 };
    binaryAddition(firstArray, secondArray, sum, SIZE);
    printf("\nДвоичное представление суммы двух чисел: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", sum[SIZE - i - 1]);
    }
    printf("\nДесятичное представление суммы двух чисел: %d", (binaryToDecimal(sum, SIZE)));
}