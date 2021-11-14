#pragma once

#include <stdbool.h>

typedef struct List List;

typedef struct Position Position;

List* createList();

Position* createPosition(List* list);

void positionToHead(List* list, Position* position);

void positionToNext(Position* position);

bool isPositionNull(Position* position);

void deletePosition(Position* position);

int getValue(Position* position);

void addElement(List* list, const int value);

void deleteElement(List* list, const int value);

void deleteList(List* list);