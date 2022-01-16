#include "../stack/stack.h"
#include "calculate.h"
#include <stdlib.h>

Stack* performOperation(Stack* stack, char operation, int* errorCode)
{
    int firstDigit = top(stack, errorCode);
    stack = pop(stack, errorCode);
    int secondDigit = top(stack, errorCode);
    if (*errorCode == 1)
    {
        return NULL;
    }
    stack = pop(stack, errorCode);
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
            deleteStack(stack);
            return NULL;
        }
        break;
    }
    return push(stack, result, errorCode);
}

int calculate(const char* string, int* errorCode)
{
    Stack* stack = NULL;
    int result = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        switch (string[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
            stack = performOperation(stack, string[i], errorCode);
            if (stack == NULL)
            {
                return 0;
            }
            break;
        default:
            result = string[i] - '0';
            stack = push(stack, result, errorCode);
            break;
        }
    }
    int finalResult = top(stack, errorCode);
    stack = pop(stack, errorCode);
    if (stack != NULL)
    {
        deleteStack(stack);
        *errorCode = 2;
    }
    else
    {
        *errorCode = 0;
    }
    return finalResult;
}