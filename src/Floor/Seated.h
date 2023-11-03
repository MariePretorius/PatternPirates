/**
 * @class Seated
 * @brief This class is a state the customer will be in when they have been seated at a table.
 */

#ifndef SEATED_H
#define SEATED_H

#include "CustomerState.h"
#include "ReadyToOrder.h"

class Seated : public CustomerState {
public:
    CustomerState* getNextState() override;
    string getName() override;
};

#endif
