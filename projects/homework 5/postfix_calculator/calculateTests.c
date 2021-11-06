#include "calculateTests.h"
#include <stdbool.h>

bool testCalculate(void)
{
    char stringTest1[] = "96-12+*";
    int* errorCode1 = -1;
    char stringTest2[] = "56+";
    int* errorCode2 = -1;
    char stringTest3[] = "35+2*67+89-/-";
    int* errorCode3 = -1;
    char stringTest4[] = "50*";
    int* errorCode4 = -1;
    char stringTest5[] = "2+";
    int* errorCode5 = -1;
    char stringTest6[] = "++";
    int* errorCode6 = -1;
    char stringTest7[] = "55";
    int* errorCode7 = -1;
    char stringTest8[] = "54-55-/";
    int* errorCode8 = -1;
    calculate(stringTest1, &errorCode1);
    calculate(stringTest2, &errorCode2);
    calculate(stringTest3, &errorCode3);
    calculate(stringTest4, &errorCode4);
    calculate(stringTest5, &errorCode5);
    calculate(stringTest6, &errorCode6);
    calculate(stringTest7, &errorCode7);
    calculate(stringTest8, &errorCode8);
    return (errorCode1 == 0) && (errorCode2 == 0) && (errorCode3 == 0)
        && (errorCode4 == 0) && (errorCode5 == 1) && (errorCode6 == 1)
        && (errorCode7 == 2) && (errorCode8 == 3);
}