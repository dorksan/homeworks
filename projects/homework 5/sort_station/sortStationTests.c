#include "sortStationTests.h"
#include <stdbool.h>

#define SIZE 100

bool sortStationTest(void)
{
    char string[SIZE] = "";
    char stringTest1[] = "(1 + 1) * 2";
    int* errorCode1 = -1;
    char stringTest2[] = "(5 * 2 - 4) + 3";
    int* errorCode2 = -1;
    char stringTest3[] = "2 * (1 + 1)";
    int* errorCode3 = -1;
    char stringTest4[] = "1 + 1) * 2";
    int* errorCode4 = -1;
    char stringTest5[] = "(1 + 1 * 2";
    int* errorCode5 = -1;
    sortStation(stringTest1, string, &errorCode1);
    sortStation(stringTest2, string, &errorCode2);
    sortStation(stringTest3, string, &errorCode3);
    sortStation(stringTest4, string, &errorCode4);
    sortStation(stringTest5, string, &errorCode5);
    return (errorCode1 == 0) && (errorCode2 == 0)
        && (errorCode3 == 0) && (errorCode4 == 1)
        && (errorCode5 == 2);
}