#include "../stack/stack.h"
#include "calculate.h"
#include <stdlib.h>
#include <string.h>

Stack* selectOperation(Stack* stack, char operation, int* errorCode)
{
    int firstDigit = top(stack, errorCode);
    stack = pop(stack, &firstDigit);
    int secondDigit = top(stack, errorCode);
    if (*errorCode == 1)
    {
        return NULL;
    }
    stack = pop(stack, &secondDigit);
    int result = 0;
    switch (operation)
    {
    case '+':
        result = secondDigit + firstDigit;
        break;
    case '-':
        result = secondDigit - firstDigit;
        break;
    case '*':
        result = secondDigit * firstDigit;
        break;
    case '/':
        if (firstDigit != 0)
        {
            result = secondDigit / firstDigit;
        }
        else
        {
            *errorCode = 3;
            return deleteStack(stack);
        }
        break;
    }
    return push(stack, result);
}

int calculate(char* string, int* errorCode)
{
    Stack* stack = NULL;
    int result = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        switch (string[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
            stack = selectOperation(stack, string[i], errorCode);
            if (stack == NULL)
            {
                return 0;
            }
            break;
        default:
            result = string[i] - '0';
            stack = push(stack, result);
            break;
        }
    }
    int finalResult = top(stack, errorCode);
    int temp = 0;
    stack = pop(stack, &temp);
    if (stack != NULL)
    {
        stack = deleteStack(stack);
        *errorCode = 2;
    }
    else
    {
        *errorCode = 0;
    }
    return finalResult;
}