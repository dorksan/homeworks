#include "lexer.h"
#include <stdbool.h>
#include <string.h>

typedef enum State
{
    FIRST_SYMBOL_NAME,
    NAME_SIGN,
    NAME_LETTER,
    DOG,
    FIRST_SYMBOL_ADDRESS,
    ADDRESS,
    POINT,
    FIRST_SYMBOL_DOMAIN,
    DOMAIN,
} State;

bool isSign(char symbol)
{
    int result = 0;
    if (symbol == '%' || symbol == '+' ||
        symbol == '-' || symbol == '_' ||
        symbol == '.')
    {
        result = 1;
    }
    return result == 1;
}

bool isLetter(char symbol)
{
    return (symbol >= 'a' && symbol <= 'z');
}

bool isDigit(char symbol)
{
    return (symbol >= '0' && symbol <= '9');
}

bool lexer(const char* email)
{
    int index = 0;
    bool result = true;
    int length = strlen(email);
    char currentSymbol = email[index];
    State state = FIRST_SYMBOL_NAME;
    while (currentSymbol != '\0')
    {
        currentSymbol = email[index];
        switch (state)
        {
        case FIRST_SYMBOL_NAME:
            state = ((isLetter(currentSymbol) || isDigit(currentSymbol)) && !(isSign(currentSymbol))) ? NAME_LETTER : -1;
            index++;
            break;
        case NAME_LETTER:
            state = (isLetter(currentSymbol) || isDigit(currentSymbol) || isSign(currentSymbol)) ? NAME_LETTER : DOG;
            if (index == length)
            {
                return !result;
            }
            if (state == NAME_LETTER)
            {
                index++;
            }
            break;
        case NAME_SIGN:
            state = (isSign(currentSymbol)) ? NAME_SIGN : NAME_LETTER;
            break;
        case DOG:
            state = (currentSymbol == '@') ? FIRST_SYMBOL_ADDRESS : -1;
            index++;
            break;
        case FIRST_SYMBOL_ADDRESS:
            state = (isLetter(currentSymbol) || isDigit(currentSymbol)) ? ADDRESS : -1;
            index++;
            break;
        case ADDRESS:
            state = (isLetter(currentSymbol) || isDigit(currentSymbol) || (currentSymbol == '-')) ? ADDRESS : POINT;
            if (state == ADDRESS)
            {
                index++;
            }
            break;
        case POINT:
            state = (currentSymbol == '.') ? DOMAIN : -1;
            index++;
            break;
        case DOMAIN:
            state = (isLetter(currentSymbol)) ? DOMAIN : 10;
            index++;
            break;
        case -1:
            return !result;
        default:
            break;
        }
    }
    return result;
}