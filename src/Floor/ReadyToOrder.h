/**
 * @class ReadyToOrder
 * @brief This class is a state the customer is in when they are ready to order food.
 */

#ifndef READYTOORDER_H
#define READYTOORDER_H

#include "CustomerState.h"
#include "OrderPlaced.h"

class ReadyToOrder : public CustomerState {
public:
    CustomerState* getNextState() override;
    string getName() override;
};

#endif
