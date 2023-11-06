/**
 * @class CustomerState
 * @brief This class covers all states a customer can be in.
 */

#ifndef CUSTOMERSTATE_H
#define CUSTOMERSTATE_H

#include <string>
#include <iostream>

using namespace std;

class CustomerState {
private:

public:
	/**
     * @brief Get the next state of the customer.
     * @return A pointer to the next state of the customer.
     * This pure virtual function must be implemented by derived classes.
     * It is used to determine the state that the customer should transition to.
     */
	virtual CustomerState* getNextState() = 0;

	/**
     * @brief Get the name of the customer state.
     * @return A string containing the name of the state.
     * This pure virtual function must be implemented by derived classes.
     * It returns the name of the specific customer state, helping to identify
     * the current state of the customer.
     */
	virtual string getName() = 0;
};

#endif
