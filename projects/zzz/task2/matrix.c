#include "matrix.h"

void spiralMatrix(int* matrix, int* elements, int length, int height, int pointer)
{
    int countOfElements = 0;
    int lineHigh = 0;
    int lineLow = pointer - 1;
    int columnLeft = length * (length - 1);
    int columnRight = height;
    for (int a = 1; a <= pointer; a++)
    {
        for (lineHigh; lineHigh < length * a; lineHigh++)
        {
            elements[countOfElements] = matrix[lineHigh];
            countOfElements++;
            if (countOfElements == pointer)
            {
                return 0;
            }
        }
        lineHigh = length + 1;
        for (columnLeft = columnLeft - a; columnLeft < pointer; columnLeft++)
        {
            if ((columnLeft + a) % length == 0)
            {
                elements[countOfElements] = matrix[columnLeft];
                countOfElements++;
                if (countOfElements == pointer)
                {
                    return 0;
                }
            }
        }
        for (lineLow -= a; lineLow > (pointer - length); lineLow--)
        {
            elements[countOfElements] = matrix[lineLow];
            countOfElements++;
            if (countOfElements == pointer)
            {
                return 0;
            }
        }
        for (columnRight = height * (a + 1); columnRight >= length * a; columnRight--)
        {
            if (columnRight % height == 0)
            {
                elements[countOfElements] = matrix[columnRight];
                countOfElements++;
                if (countOfElements == pointer)
                {
                    return 0;
                }
            }
        }
        a++;
    }
}