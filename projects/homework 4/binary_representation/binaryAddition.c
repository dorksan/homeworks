#include "binaryAddition.h"

#define SIZE 8

void binaryAddition(int* firstBinaryNumber, int* secondBinaryNumber, int* sum)
{
    int temp = 0;
    for (int i = SIZE; i > 0; i--)
    {
        int sum = firstBinaryNumber[i] + secondBinaryNumber[i] + temp;
        if (sum == 0)
        {
            sum[i] = 0;
            temp = 0;
        }
        if (sum == 1)
        {
            sum[i] = 1;
            temp = 0;
        }
        if (sum == 2)
        {
            sum[i] = 0;
            temp = 1;
        }
        if (sum == 3)
        {
            sum[i] = 1;
            temp = 1;
        }
    }
}