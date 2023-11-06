#include "ReadyToOrder.h"

CustomerState *ReadyToOrder::getNextState()
{
    return new OrderPlaced();
}

string ReadyToOrder::getName()
{
    return "Ready To Order";
}
