#include "testBinaryAddition.h"
#include "binaryAddition.h"
#include <stdbool.h>

#define TEST_SIZE 8

bool testBinaryAddition(void)
{
    int arrayTest1[TEST_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest2[TEST_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest3[TEST_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int array2[TEST_SIZE] = { 0, 1, 0, 0, 0, 0, 0, 0 };
    int array8[TEST_SIZE] = { 0, 0, 0, 1, 0, 0, 0, 0 };
    int array5[TEST_SIZE] = { 1, 0, 1, 0, 0, 0, 0, 0 };
    int arrayMinus5[TEST_SIZE] = { 1, 1, 0, 1, 1, 1, 1, 1 };
    int arraySum0[TEST_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arraySum13[TEST_SIZE] = { 1, 0, 1, 1, 0, 0, 0, 0 };
    int arraySum7[TEST_SIZE] = { 1, 1, 1, 0, 0, 0, 0, 0 };
    binaryAddition(array5, arrayMinus5, arrayTest1, TEST_SIZE);
    binaryAddition(array5, array8, arrayTest2, TEST_SIZE);
    binaryAddition(array2, array5, arrayTest3, TEST_SIZE);
    for (int i = 0; i < TEST_SIZE; i++)
    {
        if (arrayTest1[i] != arraySum0[i] || arrayTest2[i] != arraySum13[i] ||
            arrayTest3[i] != arraySum7[i])
        {
            return false;
        }
    }
    return true;
}