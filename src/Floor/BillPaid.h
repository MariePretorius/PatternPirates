#ifndef BILLPAID_H
#define BILLPAID_h

#include "CustomerState.h"

class BillPaid : public CustomerState {
public:
    CustomerState* getNextState() override;
};

#endif
