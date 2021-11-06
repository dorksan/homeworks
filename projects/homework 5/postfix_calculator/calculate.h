#pragma once

typedef struct Stack Stack;

// Выполняет действия над выражением в постфиксной форме
int calculate(char* string, int* errorCode);