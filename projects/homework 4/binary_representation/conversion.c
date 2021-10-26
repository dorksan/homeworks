#include "conversion.h"

int binaryToDecimal(int* array, int size)
{
    int result = 0;
    int temp = 1;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == 1)
        {
            result += temp;
        }
        temp *= 2;
    }
    return result;
}

void decimalToBinary(int number, int* array, int size)
{
    int decimalNumber = number;
    int mask = 0b1;
    for (int i = 0; i < size; i++)
    {
        array[i] = ((decimalNumber & mask) ? 1 : 0);
        mask = mask << 1;
    }
}