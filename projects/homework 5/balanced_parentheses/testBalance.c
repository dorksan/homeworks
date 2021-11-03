#include "testBalance.h"
#include <stdbool.h>

#define TEST_SIZE 15

bool testBalance(void)
{
    char stringTest1[TEST_SIZE] = "{[}]";
    char stringTest2[TEST_SIZE] = ":(";
    char stringTest3[TEST_SIZE] = "((())";
    char stringTest4[TEST_SIZE] = ")";
    char stringTest5[TEST_SIZE] = "[]{}()";
    char stringTest6[TEST_SIZE] = "{{{(([]))}}}";
    char stringTest7[TEST_SIZE] = "(ab)/[aa{10}bb]";
    char stringTest8[TEST_SIZE] = "()";
    if (balance(stringTest1, TEST_SIZE) == false || balance(stringTest2, TEST_SIZE) == false
        || balance(stringTest3, TEST_SIZE) == false || balance(stringTest4, TEST_SIZE) == false
        || balance(stringTest5, TEST_SIZE) == true || balance(stringTest6, TEST_SIZE) == true
        || balance(stringTest7, TEST_SIZE) == true || balance(stringTest8, TEST_SIZE) == true)
    {
        return true;
    }
    return false;
}