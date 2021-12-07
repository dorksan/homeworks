#include <stdio.h>
#include <stdbool.h>

#define SIZE 8

int binaryToDecimal(bool* array, int size)
{
    int result = 0;
    int temp = 1;
    for (int i = size - 1; i >= 0; i--)
    {
        if (array[i])
        {
            result += temp;
        }
        temp *= 2;
    }
    return result;
}

int compare(int firstNumber, int secondNumber)
{
    if (firstNumber == secondNumber)
    {
        return 0;
    }
    if (firstNumber > secondNumber)
    {
        return 1;
    }
    if (firstNumber < secondNumber)
    {
        return 2;
    }
}

bool testBinaryToDecimal(void)
{
    bool array0[SIZE] = { false, false, false, false, false, false, false, false };
    bool array5[SIZE] = { false, false, false, false, false, true, false, true };
    bool array8[SIZE] = { false, false, false, false, true, false, false, false };
    bool array15[SIZE] = { false, false, false, false, true, true, true, true, };
    return binaryToDecimal(array15, SIZE) == 15 && binaryToDecimal(array8, SIZE) == 8 &&
        binaryToDecimal(array5, SIZE) == 5 && binaryToDecimal(array0, SIZE) == 0;
}

bool testCompare(void)
{
    int ten = 10;
    int newTen = 10;
    int one = 1;
    if ((compare(ten, newTen) == 0) && (compare(ten, one) == 1) && (compare(one, ten) == 2))
    {
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    if (!testBinaryToDecimal() || !testCompare())
    {
        return 111;
    }
    if (argc > 1)
    {
        return 0;
    }
    bool firstNumber[SIZE] = { true, false, false, false, false, true, true, true };
    bool secondNumber[SIZE] = { true, false, true, false, true, false, false, true };
    int decimalFirstNumber = binaryToDecimal(firstNumber, SIZE);
    int decimalSecondNumber = binaryToDecimal(secondNumber, SIZE);
    printf("%d %d", decimalFirstNumber, decimalSecondNumber);
    switch (compare(decimalFirstNumber, decimalSecondNumber))
    {
    case 0:
        printf("\nЧисла равны.");
        break;
    case 1:
        printf("\nЧисло %d больше.", decimalFirstNumber);
        break;
    case 2:
        printf("\nЧисло %d больше.", decimalSecondNumber);
        break;
    }
}