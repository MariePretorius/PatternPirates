/**
 * @class OrderPlaced
 * @brief This class is a state the customer will be in when they have placed their order.
 */

#ifndef ORDERPLACED_H
#define ORDERPLACED_H

#include "CustomerState.h"
#include "Eating.h"

class OrderPlaced : public CustomerState {
public:
    CustomerState* getNextState() override;
    string getName() override;
};

#endif
