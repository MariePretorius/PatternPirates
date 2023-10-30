#include "OrderPlaced.h"

CustomerState *OrderPlaced::getNextState()
{
    return new Eating();
}