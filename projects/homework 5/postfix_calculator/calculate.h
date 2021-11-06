#pragma once

typedef struct Stack Stack;

// Выполняет действия над выражением в постфиксной форме
// Коды ошибок:
// 0 - выполнено без ошибок
// 1 - недостаточно цифр
// 2 - недостаточно операторов
// 3 - деление на 0
int calculate(char* string, int* errorCode);