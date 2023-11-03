#include "OrderPlaced.h"

CustomerState *OrderPlaced::getNextState()
{
    return new Eating();
}

string OrderPlaced::getName()
{
    return "Order Placed";
}
