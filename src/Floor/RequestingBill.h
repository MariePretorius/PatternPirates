#ifndef REQUESTINGBILL_H
#define REQUESTINGBILL_H

#include "CustomerState.h"
#include "BillPaid.h"

class RequestingBill : public CustomerState {
    CustomerState* getNextState() override;
    string getName() override;
};

#endif
