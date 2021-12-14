#include "binaryAddition.h"

void binaryAddition(int* firstBinaryNumber, int* secondBinaryNumber, int* result, int size)
{
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        int sum = firstBinaryNumber[i] + secondBinaryNumber[i] + temp;
        if (sum == 0)
        {
            result[i] = 0;
            temp = 0;
        }
        if (sum == 1)
        {
            result[i] = 1;
            temp = 0;
        }
        if (sum == 2)
        {
            result[i] = 0;
            temp = 1;
        }
        if (sum == 3)
        {
            result[i] = 1;
            temp = 1;
        }
    }
}