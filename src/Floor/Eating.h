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
    /**
     * @brief Get the next state of the customer after eating.
     * @return A pointer to the next state of the customer.
     * This function is used to determine the state that the customer should
     * transition to after finishing their meal.
     */
    CustomerState* getNextState() override;

    /**
     * @brief Get the name of the "Eating" state.
     * @return A string containing the name of the state.
     * This function returns the name of the "Eating" state, which helps
     * identify the current state of the customer.
     */
    string getName() override;
};

#endif
