#include "testBinaryAddition.h"
#include "binaryAddition.h"
#include <stdbool.h>

#define SIZE 8

bool testBinaryAddition(void)
{
    int arrayTest1[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest2[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arrayTest3[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int array2[SIZE] = { 0, 0, 0, 0, 0, 0, 1, 0 };
    int array8[SIZE] = { 0, 0, 0, 0, 1, 0, 0, 0 };
    int array5[SIZE] = { 0, 0, 0, 0, 0, 1, 0, 1 };
    int arrayMinus5[SIZE] = { 1, 1, 1, 1, 1, 0, 1, 1 };
    int arraySum0[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int arraySum13[SIZE] = { 0, 0, 0, 0, 1, 1, 0, 1 };
    int arraySum7[SIZE] = { 0, 0, 0, 0, 0, 1, 1, 1 };
    binaryAddition(array5, arrayMinus5, arrayTest1);
    binaryAddition(array5, array8, arrayTest2);
    binaryAddition(array2, array5, arrayTest3);
    for (int i = 0; i < SIZE; i++)
    {
        if (arrayTest1[i] != arraySum0[i] || arrayTest2[i] != arraySum13[i] ||
            arrayTest3[i] != arraySum7[i])
        {
            return false;
        }
    }
    return true;
}