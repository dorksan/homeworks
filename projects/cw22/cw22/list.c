#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* addString(char* value)
{
    const int length = strlen(value) + 1;
    char* temp = calloc(length, sizeof(value));
    if (temp == NULL)
    {
        return NULL;
    }
    strcpy_s(temp, length, value);
    return temp;
}

typedef struct ListElement
{
    char* value;
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

char getValue(Position* position)
{
    if (position == NULL || position->position == NULL)
    {
        return 0;
    }
    return position->position->value;
}

void addElement(List* list, Position* position, char* value)
{
    if (list == NULL || position == NULL)
    {
        return;
    }
    ListElement* newElement = calloc(1, sizeof(ListElement));
    newElement->value = addString(value);
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
}

void deleteElement(List* list, Position* position)
{
    if (list == NULL || position == NULL || position->position == NULL)
    {
        return;
    }
    ListElement* element = position->position;
    ListElement* newElement = element->next->next;
    element->next = newElement;
    position->position = newElement;
}

void deleteList(List* list)
{
    if (list == NULL)
    {
        return;
    }
    while (list->head != NULL)
    {
        ListElement* newListElement = list->head->next;
        free(list->head);
        list->head = newListElement;
    }
    free(list);
}

void deleteSameString(List* list, Position* position)
{
    char temp = getValue(position);
    position->position = position->position->next;
    if (strcmp(position->position->value, temp) == 0)
    {
        deleteElement(list, position);
    }
    if (position->position->next != NULL)
    {
        deleteSameString(list, position->position->next);
    }
}

void printList(List* list, char* result)
{
    Position* position = createPosition(list);
    positionToHead(list, position);
    if (isPositionNull(position))
    {
        return 1;
    }
    int pointer = 0;
    while (!isPositionNull(position))
    {
        result[pointer] = getValue(position);
        pointer++;
        positionToNext(list, position);
    }
    deletePosition(position);
}