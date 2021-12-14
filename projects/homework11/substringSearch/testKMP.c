#include "testKMP.h"
#include "kmp.h"
#include <stdbool.h>

#define SIZE 20
#define SIZE_OF_SUBSTRING 5

bool testPrefixFunction(void)
{
    const char string[SIZE] = "abcaabcabbcaabcabcaa";
    int prefix[SIZE] = { 0, 0, 0, 1, 1, 2, 3, 4, 2, 0, 0, 1, 1, 2, 3, 4, 2, 3, 4, 1 };
    int prefixTest[SIZE] = { 0 };
    prefixFunction(string, prefixTest, 4, 16);
    for (int i = 0; i < SIZE; i++)
    {
        if (prefixTest[i] != prefix[i])
        {
            return false;
        }
    }
    return true;
}

bool testKMP(void)
{
    const char substring[SIZE_OF_SUBSTRING] = "abca";
    const char string[SIZE] = "abcabbcaabcabca";
    int array[SIZE] = { 3, 11, 14 };
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

bool areTestsPassed(void)
{
    return testPrefixFunction() && testKMP();
}