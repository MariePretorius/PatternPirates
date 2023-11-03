/**
 * @class WaitingForTable
 * @brief This class is a state the customer can be in when they are waiting to be seated at a table.
 */

#ifndef WAITINGFORTABLE_H
#define WAITINGFORTABLE_H

#include "CustomerState.h"
#include "Seated.h"

class WaitingForTable : public CustomerState {
public:
    CustomerState* getNextState() override;
    string getName() override;
};

#endif
