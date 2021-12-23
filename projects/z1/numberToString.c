#include "numberToString.h"

int lengthOfNumber(int decimalNumber)
{
    int lengthOfNumber = 1;
    int temp = decimalNumber;
    while (temp > 10)
    {
        lengthOfNumber++;
        temp /= 10;
    }
    return lengthOfNumber;
}

void numberToString(char* string, int decimalNumber, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        string[i] = (decimalNumber % 10) + '0';
        decimalNumber /= 10;
    }
}