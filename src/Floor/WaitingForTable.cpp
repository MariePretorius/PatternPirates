#include "WaitingForTable.h"

CustomerState *WaitingForTable::getNextState()
{
    return new Seated();
}