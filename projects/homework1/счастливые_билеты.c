#include <stdio.h>

int main()
{
    const int maxNumber = 9;
    int array[28] = { 0 };
    for (int firstNumber = 0; firstNumber <= maxNumber; firstNumber++)
    {
        for (int secondNumber = 0; secondNumber <= maxNumber; secondNumber++)
        {
            for (int thirdNumber = 0; thirdNumber <= maxNumber; thirdNumber++)
            {
                const int sum = firstNumber + secondNumber + thirdNumber;
                array[sum]++;
            }
        }
    }
    int finalSum = 0;
    for (int i = 0; i <= 27; i++)
    {
        array[i] *= array[i];
        finalSum += array[i];
    }
    printf("%s %d", "Количество счастливых билетиков:", finalSum);
}