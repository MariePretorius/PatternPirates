#ifndef CUSTOMERSTATE_H
#define CUSTOMERSTATE_H

#include <string>
#include <iostream>

using namespace std;

class CustomerState {
private:

public:
	virtual CustomerState* getNextState() = 0;
	virtual string getName() = 0;
};

#endif
