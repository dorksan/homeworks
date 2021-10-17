#include "testBinaryToDecimal.h"
#include "binaryToDecimal.h"
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