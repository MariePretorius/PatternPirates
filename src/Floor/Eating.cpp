#include "Eating.h"

CustomerState *Eating::getNextState()
{
    return new RequestingBill();
}