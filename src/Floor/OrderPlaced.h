#ifndef ORDERPLACED_H
#define ORDERPLACED_H

#include "CustomerState.h"
#include "Eating.h"

class OrderPlaced : public CustomerState {
public:
    CustomerState* getNextState() override;
    string getName() override;
};

#endif
