#include "../stack/stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define SIZE 100
#define TEST_SIZE 10

bool balance(char* string, int size)
{
    Stack* stack = createStack(string[0]);
    for (int i = 0; i < size; i++)
    {
        switch (string[i])
        {
        case '(':
            push(&stack, ')');
            break;
        case '{':
            push(&stack, '}');
            break;
        case '[':
            push(&stack, ']');
            break;
        case ')':
        case '}':
        case ']':
            if (isEmpty(stack) || (peek(stack) != string[i]))
            {
                return false;
            }
            pop(&stack);
            break;
        default:
            break;
        }
    }
    return isEmpty(stack);
}

bool testBalance(void)
{
    char stringTest1[TEST_SIZE] = "{[}]";
    if (balance(stringTest1, TEST_SIZE) == false)
    {
        return true;
    }
    return false;
}

int main()
{
    if (!testBalance())
    {
        return -1;
    }
    printf("Введите выражение : ");
    char string[SIZE] = { 0 };
    scanf_s("%s", &string);
    if (balance(string, SIZE))
    {
        printf("Скобки сбалансированы.");
    }
    else
    {
        printf("Скобки не сбалансированы.");
    }
}