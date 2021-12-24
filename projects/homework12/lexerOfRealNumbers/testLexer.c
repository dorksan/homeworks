#include "lexer.h"
#include "testLexer.h"
#include <stdbool.h>

bool areTestsPassed(void)
{
    return !analyze("1E") && !analyze("1.") && !analyze("ad55d5")
        && !analyze("1.4E-") && analyze("111.123E+10") && analyze("11E+5");
}