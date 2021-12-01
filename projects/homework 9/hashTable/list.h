#pragma once

#include <stdbool.h>

typedef struct List List;

typedef struct Position Position;

// Создает список
List* createList();

// Создает позицию
Position* createPosition(List* list);

// Сдвигает позицию на начало списка
void positionToHead(List* list, Position* position);

// Сдвигает позицию на следующий элемент
void positionToNext(Position* position);

// Проверяет позицию на NULL
bool isPositionNull(Position* position);

// Удаляет позицию
void deletePosition(Position* position);

// Получает значение по текущей позиции
int getValue(Position* position);

// Добавляет элемент в список
void addElement(List* list, const int value);

// Удаляет элемент из списка
void deleteElement(List* list, const int value);

// Удаляет список
void deleteList(List* list);