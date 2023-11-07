//
// Created by Tristan on 2023/10/23.
//
/**
 * @file Waiter.h
 * @brief The declaration of the waiter class
 */
#ifndef PROJ_WAITER_H
#define PROJ_WAITER_H

#include <list>
#include "Observer.h"
#include "Table.h"
#include "../Restaurant/Finance.h"
#include "Bill.h"
class FoodOrder;
class Order;
/**
 * @class Waiter
 * @brief Acts as the Observer and Iterator for the Observer and Iterator patterns
 */
class Waiter : public Observer
{
public:
    Waiter(Finance * finance, Ratings * ratings);
    ~Waiter();
    void update() override;
    void moveToNext();
    void addTableToWait(Table * newTable);
    void addOrder(FoodOrder * newOrder);
    std::vector<FoodOrder*> * giveOrders();
    void getOrdersFromCurrTable();
    void createBill(bool split, Table * currTable);
    std::vector<FoodOrder *> * fetchOrders();
    void addDishToHand(Dish* dish);
    void getOrders();
    std::vector<Table*> * getTables();
    void passOrdersToTables();

    void doRounds();

private:
    Ratings * ratings; ///< The Ratings object
    Finance * finance; ///< The Finance object
    std::vector<Table *> tables; ///< A vector of all the tables this waiter manages
    std::vector<FoodOrder *> orders; ///< A list of the orders that the waiter currently holds
    std::vector<Bill*> bills; ///< The bills that the waiter currently has
    std::vector<Dish*> dishesInHand; ///< The dishes that the waiter is currently delivering to tables
    std::vector<CustomerState*> tableState; ///< A vector of the state of each table
    //Table * curr;
};


#endif //PROJ_WAITER_H
