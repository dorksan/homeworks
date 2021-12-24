#include "matrix.h"
#include <math.h>

void spiralMatrix(int* matrix, int* elements, int length, int height, int pointer)
{
    int countOfElements = 0;
    int lineHigh = 0;
    int lineLow = pointer - 1;
    int columnRight = length * (length - 1);
    int columnLeft = height;
    int count = 0;
    for (int a = 1; a <= pointer; a++)
    {
        for (lineHigh; lineHigh < (length * a) - count; lineHigh++)
        {
            elements[countOfElements] = matrix[lineHigh];
            countOfElements++;
            if (countOfElements == pointer)
            {
                return;
            }
        }
        lineHigh = (length * a) + a;
        for (columnRight = (length + 1) * a - count; columnRight < length * (height - count); columnRight++)
        {
            if ((columnRight + 1 * a) % length == 0)
            {
                elements[countOfElements] = matrix[columnRight];
                countOfElements++;
                if (countOfElements == pointer)
                {
                    return;
                }
            }
        }
        for (lineLow = pointer - 1 - a - count * length; lineLow > (pointer - length * a); lineLow--)
        {
            elements[countOfElements] = matrix[lineLow];
            countOfElements++;
            if (countOfElements == pointer)
            {
                return;
            }
        }
        for (columnLeft = length * height - (a * length) - a * count; columnLeft >= length * a; columnLeft--)
        {
            if ((columnLeft - count) % height == 0)
            {
                elements[countOfElements] = matrix[columnLeft];
                countOfElements++;
                if (countOfElements == pointer)
                {
                    return;
                }
            }
        }
        count++;
    }
}