#ifndef CUSTOMERSTATE_H
#define CUSTOMERSTATE_H

class CustomerState {
private:

public:
	virtual CustomerState* getNextState() = 0;
};

#endif
