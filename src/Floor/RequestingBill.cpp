#include "RequestingBill.h"

CustomerState *RequestingBill::getNextState()
{
    return new BillPaid();
}