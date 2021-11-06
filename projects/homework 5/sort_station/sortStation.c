#include "sortStation.h"
#include "../stack/stack.h"
#include <stdlib.h>
#include <string.h>

void sortStation(char* infixString, char* postfixString, int* errorCode)
{
    Stack* stack = NULL;
    int temp = 0;
    int pointer = 0;
    for (int i = 0; i < strlen(infixString); i++)
    {
        switch (infixString[i])
        {
        case '(':
            stack = push(stack, infixString[i]);
            break;
        case ')':
            while (top(stack, errorCode) != '(')
            {
                postfixString[pointer] = top(stack, errorCode);
                pointer++;
                stack = pop(stack, &temp);
                if (stack == NULL)
                {
                    *errorCode = 1;
                    return;
                }
            }
            if (top(stack, errorCode) == '(')
            {
                stack = pop(stack, &temp);
            }
            break;
        case '*':
        case '/':
            stack = push(stack, infixString[i]);
            break;
        case '+':
        case '-':
            if (top(stack, errorCode) == '*' || top(stack, errorCode) == '/')
            {
                char operation = top(stack, errorCode);
                stack = pop(stack, &temp);
                postfixString[pointer] = operation;
                pointer++;
            }
            stack = push(stack, infixString[i]);
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
        stack = pop(stack, &temp);
        pointer++;
    }
    *errorCode = 0;
    deleteStack(stack);
}