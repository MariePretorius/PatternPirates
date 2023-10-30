//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_FLOOR_H
#define PROJ_FLOOR_H

#include <list>

class Customer;
class Host;
class Waiter;

#include "Table.h"

class Floor
{
public:
    Floor();
    Host * createHost();
    int getCapacity();

    int getNumWaiters();
    int setNumWaiters();

private:

    std::list<Table> tables;
    int numberOfTables;
    int numberOfWaiters;
    std::list<Customer *> customers;
    std::list<Waiter *> waiters;
};


#endif //PROJ_FLOOR_H
