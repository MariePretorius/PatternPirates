#include "Eating.h"

CustomerState *Eating::getNextState()
{
    return new RequestingBill();
}

string Eating::getName()
{
    return "Eating";
}
