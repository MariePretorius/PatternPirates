#ifndef SEATED_H
#define SEATED_H

#include "CustomerState.h"
#include "ReadyToOrder.h"

class Seated : public CustomerState {
public:
    CustomerState* getNextState() override;
    string getName() override;
};

#endif
