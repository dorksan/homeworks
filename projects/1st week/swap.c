#include <stdio.h>

int main()
{
    int firstVariable = 56;
    int secondVariable = 4;
    firstVariable ^= secondVariable;
    secondVariable ^= firstVariable;
    firstVariable ^= secondVariable;
    printf("%d %d\n", firstVariable, secondVariable);
}