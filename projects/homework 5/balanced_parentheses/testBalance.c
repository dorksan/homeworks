#include "testBalance.h"
#include "balance.h"
#include <stdbool.h>

bool testBalance(void)
{
    int errorCode1 = -1;
    int errorCode2 = -1;
    int errorCode3 = -1;
    int errorCode4 = -1;
    int errorCode5 = -1;
    int errorCode6 = -1;
    int errorCode7 = -1;
    int errorCode8 = -1;
    balance("{[}]", &errorCode1);
    balance(":(", &errorCode2);
    balance("((())", &errorCode3);
    balance(")", &errorCode4);
    balance("[]{}()", &errorCode5);
    balance("{{{(([]))}}}", &errorCode6);
    balance("(ab)/[aa{10}bb]", &errorCode7);
    balance("()", &errorCode8);
    return (errorCode1 == 1) && (errorCode2 == 1) && (errorCode3 == 1)
        && (errorCode4 == 1) && (errorCode5 == 0) && (errorCode6 == 0)
        && (errorCode7 == 0) && (errorCode8 == 0);
}