#include "Seated.h"

CustomerState *Seated::getNextState()
{
    return new ReadyToOrder();
}

string Seated::getName()
{
    return "Seated";
}
