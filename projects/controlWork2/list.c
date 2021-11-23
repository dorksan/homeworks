#include "list.h"
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

List* voidList()
{
    List* list = calloc(1, sizeof(List));
    return list;
}

List* create(int* array, int* length)
{
    List* list = voidList();
    while (array[*length] != NULL)
    {
        addElement(list, array[*length]);
        (*length)++;
    }
    return list;
}

List* createList(int* array)
{
    int index = 0;
    List* list = create(array, &index);
    return list;
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

void positionToNext(Position* position)
{
    if (position == NULL)
    {
        return;
    }
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

void addElement(List* list, const int value)
{
    if (list == NULL)
    {
        return;
    }
    ListElement* element = list->head;
    ListElement* newElement = calloc(1, sizeof(ListElement));
    newElement->value = value;
    if (element == NULL)
    {
        list->head = newElement;
        return;
    }
    while (element->next != NULL)
    {
        element = element->next;
    }
    element->next = newElement;
}

void deleteElement(List* list, const int value)
{
    if (list == NULL)
    {
        return;
    }
    ListElement* element = list->head;
    if (element == NULL)
    {
        return;
    }
    if (element->value == value)
    {
        list->head = element->next;
        free(element);
        return;
    }
    element = element->next;
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
    return;
}

List* reverse(List* list)
{
    List* newList = voidList();
    ListElement* element = list->head;
    while (list->head->next != NULL)
    {
        if (element->next == NULL)
        {
            int temp = element->value;
            element = list->head;
            while (element->next->value != temp)
            {
                addElement(newList, element->next->value);
                deleteElement(list, element->next->value);
                element = element->next;
            }
        }
        element = element->next;
    }
    return newList;
}