#include "sortStationTests.h"
#include <stdbool.h>

#define SIZE 100

bool sortStationTest(void)
{
    char string[SIZE] = "";
    int errorCode1 = -1;
    int errorCode2 = -1;
    int errorCode3 = -1;
    int errorCode4 = -1;
    int errorCode5 = -1;
    int errorCode6 = -1;
    sortStation("(1 + 1) * 2", string, &errorCode1);
    sortStation("(5 * 2 - 4) + 3", string, &errorCode2);
    sortStation("2 * (1 + 1)", string, &errorCode3);
    sortStation("1*2*3+4", string, &errorCode4);
    sortStation("1 + 1) * 2", string, &errorCode5);
    sortStation("(1 + 1 * 2", string, &errorCode6);
    return (errorCode1 == 0) && (errorCode2 == 0)
        && (errorCode3 == 0) && (errorCode4 == 0)
        && (errorCode5 == 1) && (errorCode6 == 2);
}