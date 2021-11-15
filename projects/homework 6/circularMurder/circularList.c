#include "circularList.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListElement
{
    int value;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
} List;

typedef struct Position
{
    ListElement* position;
} Position;

List* createList()
{
    return calloc(1, sizeof(List));
}

Position* createPosition(List* list)
{
    Position* position = calloc(1, sizeof(Position));
    position->position = list->head;
    return position;
}

void positionToHead(List* list, Position* position)
{
    if (list == NULL || position == NULL)
    {
        return;
    }
    position->position = list->head;
}

void positionToNext(List* list, Position* position)
{
    position->position = position->position->next;
}

bool isPositionNull(Position* position)
{
    return position == NULL || position->position == NULL;
}

void deletePosition(Position* position)
{
    free(position);
}

int getValue(Position* position)
{
    if (position == NULL || position->position == NULL)
    {
        return 0;
    }
    return position->position->value;
}

void addElement(List* list, Position* position, const int value)
{
    if (list == NULL || position == NULL)
    {
        return;
    }
    ListElement* newElement = calloc(1, sizeof(ListElement));
    newElement->value = value;
    if (list->head == NULL)
    {
        list->head = newElement;
        newElement->next = newElement;
        position->position = newElement;
        return;
    }
    newElement->next = position->position->next;
    position->position->next = newElement;
    position->position = newElement;
    return;
}

void deleteElement(List* list, Position* position)
{
    if (list == NULL || position == NULL || position->position == NULL)
    {
        return;
    }
    ListElement* element = list->head;
    while (element->next != position->position)
    {
        element = element->next;
    }
    if (list->head == position->position)
    {
        ListElement* oldHead = list->head;
        list->head = list->head->next;
        free(oldHead);
        position->position = list->head;
        element->next = list->head;
        return;
    }
    element->next = position->position->next;
    free(position->position);
    position->position = element->next;
    return;
}

void deleteList(List* list)
{
    if (list == NULL)
    {
        return;
    }
    while (list->head != list->head->next)
    {
        ListElement* newListElement = list->head->next;
        free(list->head);
        list->head = newListElement;
    }
    free(list->head);
    free(list);
    return;
}