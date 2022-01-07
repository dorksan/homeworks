#include "sortStation.h"
#include "../stack/stack.h"
#include <stdlib.h>

void sortStation(const char* infixString, char* postfixString, int* errorCode)
{
    Stack* stack = NULL;
    int pointer = 0;
    for (int i = 0; infixString[i] != '\0'; i++)
    {
        switch (infixString[i])
        {
        case '(':
            stack = push(stack, infixString[i], errorCode);
            break;
        case ')':
            while (top(stack, errorCode) != '(')
            {
                postfixString[pointer] = top(stack, errorCode);
                pointer++;
                stack = pop(stack, errorCode);
                if (stack == NULL)
                {
                    *errorCode = 1;
                    return;
                }
            }
            if (top(stack, errorCode) == '(')
            {
                stack = pop(stack, errorCode);
            }
            break;
        case '*':
        case '/':
            stack = push(stack, infixString[i], errorCode);
            break;
        case '+':
        case '-':
            while (top(stack, errorCode) == '*' || top(stack, errorCode) == '/')
            {
                char operation = top(stack, errorCode);
                stack = pop(stack, errorCode);
                postfixString[pointer] = operation;
                pointer++;
            }
            stack = push(stack, infixString[i], errorCode);
            break;
        case ' ':
            break;
        default:
            postfixString[pointer] = infixString[i];
            pointer++;
            break;
        }
    }
    while (stack != NULL)
    {
        if (top(stack, errorCode) == '(')
        {
            *errorCode = 2;
            return;
        }
        postfixString[pointer] = top(stack, errorCode);
        stack = pop(stack, errorCode);
        pointer++;
    }
    *errorCode = 0;
    deleteStack(stack);
}