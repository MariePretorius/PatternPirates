/**
 * @class RequestingBill
 * @brief This class is the state the customer will be in when they are ready to receive the bill.
 */

#ifndef REQUESTINGBILL_H
#define REQUESTINGBILL_H

#include "CustomerState.h"
#include "BillPaid.h"

class RequestingBill : public CustomerState {
    CustomerState* getNextState() override;
    string getName() override;
};

#endif
