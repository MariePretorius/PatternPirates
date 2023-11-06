/**
 * @File OrderPlaced.h
 * @brief Declaration of the OrderPlaced state
*/

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
    /**
     * @brief Get the next state of the customer after placing an order.
     * @return A pointer to the next state of the customer.
     * This function is used to determine the state that the customer should
     * transition to after placing their order but before receiving their food.
     */
    CustomerState* getNextState() override;

    /**
     * @brief Get the name of the "OrderPlaced" state.
     * @return A string containing the name of the state.
     * This function returns the name of the "OrderPlaced" state, which helps
     * identify the current state of the customer.
     */
    string getName() override;
};

#endif
