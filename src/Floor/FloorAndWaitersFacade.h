//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_FLOORANDWAITERSFACADE_H
#define PROJ_FLOORANDWAITERSFACADE_H

#include "Waiter.h"
#include "Floor.h"

class FloorAndWaitersFacade
{
public:
    FloorAndWaitersFacade();
    int floorGetCapacity();
    void waitersCheckTables();
};


#endif //PROJ_FLOORANDWAITERSFACADE_H
