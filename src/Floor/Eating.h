/**
 * @class Eating
 * @brief This class is a state a customer is in while they are eating.
 */

#ifndef EATING_H
#define EATING_H

#include "CustomerState.h"
#include "RequestingBill.h"

class Eating : public CustomerState {
public:
    CustomerState* getNextState() override;
    string getName() override;
};

#endif
