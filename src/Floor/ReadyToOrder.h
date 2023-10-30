#ifndef READYTOORDER_H
#define READYTOORDER_H

#include "CustomerState.h"
#include "OrderPlaced.h"

class ReadyToOrder : public CustomerState {
public:
    CustomerState* getNextState() override;
};

#endif
