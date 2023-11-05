//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_WAITER_H
#define PROJ_WAITER_H

#include <list>

#include "Table.h"
#include "../Restaurant/Finance.h"
#include "Bill.h"
class FoodOrder;
class Order;
class Waiter
{
public:
    Waiter(Finance * finance, Ratings * ratings);
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
    Ratings * ratings;
    Finance * finance;
    std::vector<Table *> tables;
    std::vector<FoodOrder *> orders;
    std::vector<Bill*> bills;
    std::vector<Dish*> dishesInHand;
    //Table * curr;
};


#endif //PROJ_WAITER_H
