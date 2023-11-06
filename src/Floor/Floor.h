//
// Created by Tristan on 2023/10/23.
//
/**
 * @file Floor.h
 * @brief Declaration of Floor class
 */
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
/**
 * @class Floor
 * @brief Floor acts as the gateway to the "Service" portion of the restaurant.
*/
class Floor
{
public:
    Floor(Finance * finance);
    ~Floor();
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

    Host * host; ///> The Host object
    Ratings * ratings; ///> The Ratings object
    Finance * finance; ///> The Finance object
    std::list<Table*> tables; ///> The list of tables currently on the floor
    int numberOfTables; ///> The number of tables
    int numberOfWaiters; ///> The number of waiters
    std::vector<Customer *> customers; ///> The vector of Customers currently at the "Door"
    std::list<Waiter *> waiters; ///> The list of waiters currently active on the floor
    vector<FoodOrder *> stashedOrders; ///> The Orders to be handed over to the kitchen
    vector<Dish *> finishedOrders; ///> The Orders that have been completed and passed back to the floor
};


#endif //PROJ_FLOOR_H
