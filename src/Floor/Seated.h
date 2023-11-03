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
    /**
     * @brief Get the next state of the customer after being seated.
     * @return A pointer to the next state of the customer.
     * This function is used to determine the state that the customer should
     * transition to after being seated at the restaurant.
     */
    CustomerState* getNextState() override;

    /**
     * @brief Get the name of the "Seated" state.
     * @return A string containing the name of the state.
     * This function returns the name of the "Seated" state, which helps
     * identify the current state of the customer.
     */
    string getName() override;
};

#endif
