#ifndef CUSTOMERSTATE_H
#define CUSTOMERSTATE_H

#include "Customer.h"

class CustomerState {
private:

public:
	void handle(Customer customer);
	virtual CustomerState* getNextState() = 0;
};

#endif
