#pragma once

typedef struct Stack Stack;

// Перевод выражения из инфиксной в постфиксную форму
// Коды ошибок:
// 1 - пропущена открывающая скобка
// 2 - пропущена закрывающая скобка
void sortStation(char* infixString, char* postfixString, int* errorCode);