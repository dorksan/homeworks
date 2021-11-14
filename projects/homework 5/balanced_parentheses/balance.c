#include "balance.h"
#include "../stack/stack.h"
#include <stdlib.h>
#include <stdbool.h>

bool balance(char* string, int size, int* errorCode)
{
    Stack* stack = NULL;
    for (int i = 0; i < size; i++)
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
                return false;
            }
            stack = pop(stack, errorCode);
            break;
        default:
            break;
        }
    }
    bool isEmpty = stack == NULL;
    deleteStack(stack);
    return isEmpty;
}