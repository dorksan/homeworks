#include "lexer.h"
#include <stdbool.h>
#include <string.h>

typedef enum State
{
    DIGIT,
    DIGIT_ONE,
    POINT,
    DIGIT_TWO,
    EXPONENT,
    SIGN,
    DIGIT_THREE,
} State;

bool isDigit(char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

bool analyze(const char* number)
{
    int index = -1;
    char currentSymbol = number[index];
    State state = DIGIT;
    int length = strlen(number);
    for (int i = 0; i < length; i++)
    {
        index++;
        currentSymbol = number[index];
        switch(state)
        {
        case DIGIT:
            state = (isDigit(currentSymbol)) ? DIGIT_ONE : -1;
            break;
        case DIGIT_ONE:
            state = (isDigit(currentSymbol)) ? DIGIT_ONE : POINT;
            if (state == POINT)
            {
                state = (currentSymbol == '.') ? DIGIT_TWO : EXPONENT;
                if (state == EXPONENT)
                {
                    state = (currentSymbol == 'E') ? SIGN : -1;
                }
                if (index + 1 == length)
                {
                    return false;
                }
            }
            break;
        case DIGIT_TWO:
            state = (isDigit(currentSymbol)) ? DIGIT_TWO : EXPONENT;
            if (state == EXPONENT)
            {
                state = (currentSymbol == 'E') ? SIGN : -1;
                if (index + 1 == length)
                {
                    return false;
                }
            }
            break;
        case SIGN:
            state = (currentSymbol == '+' || currentSymbol == '-') ? DIGIT_THREE : -1;
            if (index + 1 == length)
            {
                return false;
            }
            break;
        case DIGIT_THREE:
            state = (isDigit(currentSymbol)) ? DIGIT_THREE : -1;
            break;
        case -1:
            return false;
        default:
            break;
        }
    }
    return true;
}