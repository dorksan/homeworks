#include "binaryToDecimal.h"
#include "testBinaryToDecimal.h"
#include "numberToString.h"
#include "testNumberToString.h"
#include <stdio.h>
#include <string.h>

#define SIZE (sizeof(int) * 8)

int main()
{
    if (!areTestsPassed() || !areTestsNumberOfStringModulePassed())
    {
        return 111;
    }
    char binaryNumber[SIZE] = "";
    printf("Введите двоичную строку: ");
    scanf_s("%s", &binaryNumber, SIZE);
    int length = strlen(binaryNumber);
    int decimalNumber = binaryToDecimal(binaryNumber, length);
    if (decimalNumber < 0)
    {
        printf("Некорректный ввод строки.");
    }
    else
    {
        char decimal[SIZE] = "";
        length = lengthOfNumber(decimalNumber);
        numberToString(decimal, decimalNumber, length);
        printf("Десятичное представление строки: %s", decimal);
    }
}