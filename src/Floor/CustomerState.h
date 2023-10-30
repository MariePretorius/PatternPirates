#ifndef CUSTOMERSTATE_H
#define CUSTOMERSTATE_H

class CustomerState {
private:

public:
	void handle(Customer customer);
	virtual CustomerState* getNextState() = 0;
};

#endif
