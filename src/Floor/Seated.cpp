#include "Seated.h"

CustomerState *Seated::getNextState()
{
    return new ReadyToOrder();
}