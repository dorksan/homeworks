#include "testConversion.h"
#include "conversion.h"
#include <stdbool.h>

#define SIZE 8

bool testBinaryToDecimal(void)
{
    int array0[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int array5[SIZE] = { 0, 0, 0, 0, 0, 1, 0, 1 };
    int array8[SIZE] = { 0, 0, 0, 0, 1, 0, 0, 0 };
    int array15[SIZE] = { 0, 0, 0, 0, 1, 1, 1, 1 };
    return binaryToDecimal(array15) == 15 && binaryToDecimal(array8) == 8 &&
        binaryToDecimal(array5) == 5 && binaryToDecimal(array0) == 0;
}

bool testDecimalToBinary(void)
{
    int arrayTest15[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest8[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest5[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTestMinus5[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest0[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int array15[SIZE] = { 0, 0, 0, 0, 1, 1, 1, 1 };
    int array8[SIZE] = { 0, 0, 0, 0, 1, 0, 0, 0 };
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