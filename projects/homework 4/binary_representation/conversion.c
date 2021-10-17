#include "conversion.h"
#include <math.h>

#define SIZE 8

int binaryToDecimal(int* array)
{
    int result = 0;
    for (int i = SIZE; i > 0; i--)
    {
        if (array[i] == 1)
        {
            result = pow(2, SIZE - i - 1) + result;
        }
    }
    return result;
}

void decimalToBinary(int number, int* array)
{
    int decimalNumber = number;
    int mask = 0b10000000;
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = ((decimalNumber & mask) ? 1 : 0);
        mask = mask >> 1;
    }
}