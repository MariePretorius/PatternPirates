/**
 * @File RequestingBill.h
 * @brief Declaration of the RequestingBill state
*/

/**
 * @class RequestingBill
 * @brief This class is the state the customer will be in when they are ready to receive the bill.
 */

#ifndef REQUESTINGBILL_H
#define REQUESTINGBILL_H

#include "CustomerState.h"
#include "BillPaid.h"

class RequestingBill : public CustomerState {
    /**
     * @brief Get the next state of the customer after requesting the bill.
     * @return A pointer to the next state of the customer.
     * This function is used to determine the state that the customer should
     * transition to after requesting the bill.
     */
    CustomerState* getNextState() override;

    /**
     * @brief Get the name of the "RequestingBill" state.
     * @return A string containing the name of the state.
     * This function returns the name of the "RequestingBill" state, which helps
     * identify the current state of the customer.
     */
    string getName() override;
};

#endif
