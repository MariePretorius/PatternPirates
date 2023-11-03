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
    /**
     * @brief Get the next state of the customer after waiting for a table.
     * @return A pointer to the next state of the customer.
     * This function is used to determine the state that the customer should
     * transition to after waiting for a table to become available.
     */
    CustomerState* getNextState() override;

    /**
     * @brief Get the name of the "WaitingForTable" state.
     * @return A string containing the name of the state.
     * This function returns the name of the "WaitingForTable" state, which helps
     * identify the current state of the customer.
     */
    string getName() override;
};

#endif
