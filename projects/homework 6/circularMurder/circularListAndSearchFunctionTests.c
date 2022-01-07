#include "circularListAndSearchFunctionTests.h"
#include "circularList.h"
#include "searchLastWarrior.h"
#include <stdbool.h>

bool testSearchFunction(void)
{
    return searchLastWarrior(41, 3) == 31 && searchLastWarrior(5, 3) == 4;
}

List* listForTests()
{
    List* list = createList();
    Position* position = createPosition(list);
    addElement(list, position, 1);
    addElement(list, position, 2);
    addElement(list, position, 3);
    addElement(list, position, 4);
    addElement(list, position, 5);
    return list;
}

bool testCircularList(void)
{
    List* list = listForTests();
    Position* position = createPosition(list);
    for (int i = 0; i < 4; i++)
    {
        positionToNext(list, position);
    }
    return getValue(position) == 5;
}

bool testIsLastOneFunction(void)
{
    List* list = listForTests();
    Position* position = createPosition(list);
    for (int i = 0; i < 4; i++)
    {
        positionToNext(list, position);
        deleteElement(list, position);
    }
    return isLastOne(list);
}

bool areTestsPassed(void)
{
    return testSearchFunction() && testCircularList()
        && testIsLastOneFunction();
}