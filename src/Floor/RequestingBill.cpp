#include "RequestingBill.h"

CustomerState *RequestingBill::getNextState()
{
    return new BillPaid();
}

string RequestingBill::getName()
{
    return "Requesting Bill";
}
