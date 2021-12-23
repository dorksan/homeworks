#include "testBinaryToDecimal.h"
#include <stdbool.h>

#define TEST_SIZE 8

bool areTestsPassed(void)
{
    const char array0[TEST_SIZE] = "00000000";
    const char array5[TEST_SIZE] = "00000101";
    const char array8[TEST_SIZE] = "00001000";
    const char array15[TEST_SIZE] = "00001111";
    return binaryToDecimal(array15, TEST_SIZE) == 15 && binaryToDecimal(array8, TEST_SIZE) == 8 &&
        binaryToDecimal(array5, TEST_SIZE) == 5 && binaryToDecimal(array0, TEST_SIZE) == 0;
}