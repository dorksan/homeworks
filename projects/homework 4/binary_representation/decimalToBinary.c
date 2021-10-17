#include "decimalToBinary.h"

#define SIZE 8

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