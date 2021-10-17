#include "decimalToBinary.h"
#include "testDecimalToBinary.h"
#include "binaryAddition.h"
#include "testBinaryAddition.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 8

int main()
{
    if (!testDecimalToBinary() || !testBinaryAddition())
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