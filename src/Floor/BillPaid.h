/**
 * @file BillPaid.h
 * @brief Declaration of the BillPaid state
*/

/**
 * @class BillPaid
 * @brief This class is a state the customer will be in after paying the bill.
 */

#ifndef BILLPAID_H
#define BILLPAID_h

#include "CustomerState.h"

class BillPaid : public CustomerState {
public:
    /**
     * @brief Get the next state of the customer.
     * This function returns the next state that the customer transitions to
     * after their bill has been paid.
     * @return A pointer to the next customer state.
     */
    CustomerState* getNextState() override;

    /**
     * @brief Get the name of the customer state.
     * This function returns the name of the customer state, which is "BillPaid."
     * @return The name of the customer state.
     */
    string getName() override;
};

#endif
