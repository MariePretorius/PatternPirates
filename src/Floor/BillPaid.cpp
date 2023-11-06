#include "BillPaid.h"

CustomerState *BillPaid::getNextState()
{
    return nullptr;
}

string BillPaid::getName()
{
    return "Bill Paid";
}
