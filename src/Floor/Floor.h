//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_FLOOR_H
#define PROJ_FLOOR_H

#include <list>

class Customer;
class Host;
class Waiter;
class Dish;
#include "Table.h"
#include "../Restaurant/FoodOrder.h"

class Finance;

class Floor
{
public:
    Floor(Finance * finance);
    void addCustomers(const vector<Customer*>& newCustomers);
    void waitersGetOrders();
    Host * createHost();
    int getCapacity();
    std::list<Table*> getTables();
    int getNumWaiters();
    int setNumWaiters();

    void addTable(int capacity);
    void addWaiter();

    vector<FoodOrder *> *fetchOrders();
    void waitersPassOrdersToTables();
    void waitersDoRounds();
    void giveFinishedOrders(vector<Dish*> finishedOrders);

private:

    Finance * finance;
    std::list<Table*> tables;
    int numberOfTables;
    int numberOfWaiters;
    std::vector<Customer *> customers;
    std::list<Waiter *> waiters;
    vector<FoodOrder *> stashedOrders;
    vector<Dish *> finishedOrders;
};


#endif //PROJ_FLOOR_H
