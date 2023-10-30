#include "ReadyToOrder.h"

CustomerState *ReadyToOrder::getNextState()
{
    return new OrderPlaced();
}