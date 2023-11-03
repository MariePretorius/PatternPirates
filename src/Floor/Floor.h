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
    void addCustomers(vector<Customer*> newCustomers);

    Host * createHost();
    int getCapacity();
    std::list<Table*> getTables();
    int getNumWaiters();
    int setNumWaiters();

    void addTable(int capacity);
    void addWaiter();

private:

    std::list<Table*> tables;
    int numberOfTables;
    int numberOfWaiters;
    std::vector<Customer *> customers;
    std::list<Waiter *> waiters;
};


#endif //PROJ_FLOOR_H
