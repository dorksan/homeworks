#include "monkeySort.h"
#include <time.h>

int checkSort(int* array, int size)
{
    int counter = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] <= array[i + 1])
        {
            counter++;
        }
    }
    return counter;
}

void monkeySort(int* array, int size)
{
    //srand((unsigned)time(NULL)); //оно падает раз через раз, особенно на значениях, больших 8
    int counter = checkSort(array, size);
    if (counter != size - 1)
    {
        for (int i = 0; i < size; i++)
        {
            int index = rand() % size;
            int temp = array[i];
            array[i] = array[index];
            array[index] = temp;
        }
        counter = 0;
        counter = checkSort(array, size);
        if (counter != size - 1)
        {
            monkeySort(array, size);
        }
    }
}