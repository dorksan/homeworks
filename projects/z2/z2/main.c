#include "lexer.h"
#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

int main()
{
    char email[SIZE] = { 0 };
    printf("Please enter email\n");
    scanf_s("%s", &email, SIZE);
    bool isEmail = lexer(email);
    if (isEmail)
    {
        printf("It's email");
    }
    else
    {
        printf("It's not email");
    }
}