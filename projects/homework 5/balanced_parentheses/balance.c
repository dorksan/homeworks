#include "balance.h"
#include "../stack/stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool balance(const char* string, int* errorCode)
{
    Stack* stack = NULL;
    for (int i = 0; string[i] != '\0'; i++)
    {
        switch (string[i])
        {
        case '(':
            stack = push(stack, ')', errorCode);
            break;
        case '{':
            stack = push(stack, '}', errorCode);
            break;
        case '[':
            stack = push(stack, ']', errorCode);
            break;
        case ')':
        case '}':
        case ']':
            if (top(stack, errorCode) != string[i])
            {
                deleteStack(stack);
                *errorCode = 1;
                return false;
            }
            stack = pop(stack, errorCode);
            break;
        default:
            break;
        }
    }
    bool isEmpty = stack == NULL;
    if (isEmpty)
    {
        *errorCode = 0;
    }
    else
    {
        *errorCode = 1;
    }
    deleteStack(stack);
    return isEmpty;
}