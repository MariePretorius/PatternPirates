/**
 * @class BillPaid
 * @brief This class is a state the customer will be in after paying the bill.
 */

#ifndef BILLPAID_H
#define BILLPAID_h

#include "CustomerState.h"

class BillPaid : public CustomerState {
public:
    CustomerState* getNextState() override;
    string getName() override;
};

#endif
