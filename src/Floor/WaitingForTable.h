#ifndef WAITINGFORTABLE_H
#define WAITINGFORTABLE_H

#include "CustomerState.h"
#include "Seated.h"

class WaitingForTable : public CustomerState {
public:
    CustomerState* getNextState() override;
};

#endif
