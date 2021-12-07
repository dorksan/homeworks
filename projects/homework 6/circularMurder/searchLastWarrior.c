#include "searchLastWarrior.h"
#include "circularList.h"

int searchLastWarrior(int numberOfWarriors, int murderedWarrior)
{
    List* list = createList();
    Position* position = createPosition(list);
    for (int i = 1; i <= numberOfWarriors; i++)
    {
        addElement(list, position, i);
    }
    positionToHead(list, position);
    if (isPositionNull(position))
    {
        return 2;
    }
    int count = 1;
    while (true)
    {
        count++;
        positionToNext(list, position);
        if (count == murderedWarrior - 1)
        {
            deleteElement(list, position);
            count = 1;
            if (isLastOne(list))
            {
                break;
            }
        }
    }
    int lastWarrior = getValue(position);
    deleteList(list);
    deletePosition(position);
    return lastWarrior;
}