#include "binaryToDecimal.h"
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