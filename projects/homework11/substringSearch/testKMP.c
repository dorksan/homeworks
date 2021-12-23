#include "testKMP.h"
#include "kmp.h"
#include <stdbool.h>

#define SIZE 20
#define SIZE_OF_SUBSTRING 5

bool isTestPassed(void)
{
    const char substring[SIZE_OF_SUBSTRING] = "abca";
    const char string[SIZE] = "abcabbcaabcabca";
    int array[SIZE] = { 0, 8, 11 };
    int arrayTest[SIZE] = { 0 };
    kmp(substring, string, arrayTest);
    for (int i = 0; i < SIZE; i++)
    {
        if (arrayTest[i] != array[i])
        {
            return false;
        }
    }
    return true;
}