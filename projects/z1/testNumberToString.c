#include "testNumberToString.h"
#include "numberToString.h"

#include <stdbool.h>
#include <string.h>

bool testLengthOfNumber(void)
{
    return lengthOfNumber(7) == 1 && lengthOfNumber(10) == 2
        && lengthOfNumber(145) == 3;
}

bool testNumberToString(void)
{
    int number = 12;
    char numberString = "12";
    char temp = "";
    int length = lengthOfNumber(number);
    numberToString(temp, number, length);
    return strcmp(temp, numberString) == 0;
}

bool areTestsNumberOfStringModulePassed(void)
{
    return testLengthOfNumber && testNumberToString;
}