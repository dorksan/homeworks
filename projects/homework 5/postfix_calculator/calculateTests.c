#include "calculateTests.h"
#include "calculate.h"
#include <stdbool.h>

bool testCalculate(void)
{
    int errorCode1 = -1;
    int errorCode2 = -1;
    int errorCode3 = -1;
    int errorCode4 = -1;
    int errorCode5 = -1;
    int errorCode6 = -1;
    int errorCode7 = -1;
    int errorCode8 = -1;
    int temp = 0;
    temp = calculate("96-12+*", &errorCode1);
    temp = calculate("56+", &errorCode2);
    temp = calculate("35+2*67+89-/-", &errorCode3);
    temp = calculate("50*", &errorCode4);
    temp = calculate("2+", &errorCode5);
    temp = calculate("++", &errorCode6);
    temp = calculate("55", &errorCode7);
    temp = calculate("54-55-/", &errorCode8);
    return (errorCode1 == 0) && (errorCode2 == 0) && (errorCode3 == 0)
        && (errorCode4 == 0) && (errorCode5 == 1) && (errorCode6 == 1)
        && (errorCode7 == 2) && (errorCode8 == 3);
}