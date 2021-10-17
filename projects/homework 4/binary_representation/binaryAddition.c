#include "binaryAddition.h"

#define SIZE 8

void binaryAddition(int* array1, int* array2, int* array3)
{
    int temp = 0;
    for (int i = SIZE; i > 0; i--)
    {
        int sum = array1[i] + array2[i] + temp;
        if (sum == 0)
        {
            array3[i] = 0;
            temp = 0;
        }
        if (sum == 1)
        {
            array3[i] = 1;
            temp = 0;
        }
        if (sum == 2)
        {
            array3[i] = 0;
            temp = 1;
        }
        if (sum == 3)
        {
            array3[i] = 1;
            temp = 1;
        }
    }
}