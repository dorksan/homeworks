#include "binaryToDecimal.h"

int binaryToDecimal(const char* string, int size)
{
    int result = 0;
    int temp = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        if (string[i] != '0' && string[i] != '1')
        {
            return -111;
        }
        if (string[i] == '1')
        {
            result += temp;
        }
        temp *= 2;
    }
    return result;
}