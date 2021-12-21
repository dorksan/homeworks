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
    return (symbol >= '0' && symbol <= '9');
}

bool lexer(const char* number)
{
    int index = 0;
    bool result = true;
    char currentSymbol = number[index];
    State state = DIGIT;
    int length = strlen(number) - 1;
    while (currentSymbol != '\0')
    {
        currentSymbol = number[index];
        switch (state)
        {
        case DIGIT:
            state = (isDigit(currentSymbol)) ? DIGIT_ONE : -1;
            index++;
            break;
        case DIGIT_ONE:
            state = (isDigit(currentSymbol)) ? DIGIT_ONE : POINT;
            if (state == DIGIT_ONE)
            {
                index++;
            }
            break;
        case POINT:
            state = (currentSymbol == '.') ? DIGIT_TWO : EXPONENT;
            if (index == length)
            {
                return !result;
            }
            if (state == DIGIT_TWO)
            {
                index++;
            }
            break;
        case DIGIT_TWO:
            state = (isDigit(currentSymbol)) ? DIGIT_TWO : EXPONENT;
            if (state == DIGIT_TWO)
            {
                index++;
            }
            break;
        case EXPONENT:
            state = (currentSymbol == 'E') ? SIGN : DIGIT_THREE;
            if (index == length)
            {
                return !result;
            }
            index++;
            break;
        case SIGN:
            state = (currentSymbol == '+' || currentSymbol == '-') ? DIGIT_THREE : -1;
            index++;
            break;
        case DIGIT_THREE:
            state = (isDigit(currentSymbol)) ? DIGIT_THREE : 10;
            if (state == DIGIT_THREE)
            {
                index++;
            }
            break;
        case -1:
            return !result;
        default:
            break;
        }
    }
    return result;
}