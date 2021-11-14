#pragma once

typedef struct List List;

void addElement(List* list, const int value);

void deleteElement(List* list, const int value);

void deleteList(List* list);