#include "WaitingForTable.h"

CustomerState *WaitingForTable::getNextState()
{
    return new Seated();
}

string WaitingForTable::getName()
{
    return "Waiting For Table";
}
