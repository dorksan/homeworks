#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int value;
    struct Stack* next;
} Stack;

Stack* push(Stack* stack, int element)
{
    Stack* newStack = calloc(1, sizeof(Stack));
    if (newStack == NULL)
    {
        return NULL;
    }
    newStack->value = element;
    newStack->next = stack;
    return newStack;
}

Stack* pop(Stack* stack, int* value)
{
    if (stack == NULL)
    {
        return NULL;
    }
    *value = stack->value;
    Stack* newStack = stack->next;
    free(stack);
    return newStack;
}

int top(Stack* stack, int* errorCode)
{
    if (stack != NULL)
    {
        *errorCode = 0;
        return stack->value;
    }
    *errorCode = 1;
    return 0;
}

Stack* deleteStack(Stack* stack)
{
    while (stack != NULL)
    {
        Stack* newStack = stack->next;
        free(stack);
        stack = newStack;
    }
    return NULL;
}