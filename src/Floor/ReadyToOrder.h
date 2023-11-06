/**
 * @File ReadyToOrder.h
 * @brief Declaration of the ReadyToOrder state
*/

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
    /**
     * @brief Get the next state of the customer after being ready to order.
     * @return A pointer to the next state of the customer.
     * This function is used to determine the state that the customer should
     * transition to after being ready to place an order.
     */
    CustomerState* getNextState() override;

    /**
     * @brief Get the name of the "ReadyToOrder" state.
     * @return A string containing the name of the state.
     * This function returns the name of the "ReadyToOrder" state, which helps
     * identify the current state of the customer.
     */
    string getName() override;
};

#endif
