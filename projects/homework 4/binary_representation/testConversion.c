#include "testConversion.h"
#include "conversion.h"
#include <stdbool.h>

#define TEST_SIZE 8

bool testBinaryToDecimal(void)
{
    int array0[TEST_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int array5[TEST_SIZE] = { 1, 0, 1, 0, 0, 0, 0, 0 };
    int array8[TEST_SIZE] = { 0, 0, 0, 1, 0, 0, 0, 0 };
    int array15[TEST_SIZE] = { 1, 1, 1, 1, 0, 0, 0, 0 };
    return binaryToDecimal(array15, TEST_SIZE) == 15 && binaryToDecimal(array8, TEST_SIZE) == 8 &&
        binaryToDecimal(array5, TEST_SIZE) == 5 && binaryToDecimal(array0, TEST_SIZE) == 0;
}

bool testDecimalToBinary(void)
{
    int arrayTest15[TEST_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest8[TEST_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest5[TEST_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTestMinus5[TEST_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest0[TEST_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int array15[TEST_SIZE] = { 1, 1, 1, 1, 0, 0, 0, 0 };
    int array8[TEST_SIZE] = { 0, 0, 0, 1, 0, 0, 0, 0 };
    int array5[TEST_SIZE] = { 1, 0, 1, 0, 0, 0, 0, 0 };
    int arrayMinus5[TEST_SIZE] = { 1, 1, 0, 1, 1, 1, 1, 1 };
    int array0[TEST_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    decimalToBinary(15, arrayTest15, TEST_SIZE);
    decimalToBinary(8, arrayTest8, TEST_SIZE);
    decimalToBinary(5, arrayTest5, TEST_SIZE);
    decimalToBinary(-5, arrayTestMinus5, TEST_SIZE);
    decimalToBinary(0, arrayTest0, TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
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