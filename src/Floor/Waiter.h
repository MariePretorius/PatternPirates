//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_WAITER_H
#define PROJ_WAITER_H

#include <list>

#include "Table.h"
#include "../Restaurant/Finance.h"
class FoodOrder;
class Order;
class Waiter
{
public:
    Waiter(Finance * finance);
    void moveToNext();
    void addTableToWait(Table * newTable);
    void addOrder(FoodOrder * newOrder);
    std::vector<FoodOrder*> * giveOrders();
    void getOrdersFromCurrTable();
    void createBill(bool split, Table * currTable);

    void getOrders();

private:
    Finance * finance;
    std::vector<Table *> tables;
    std::vector<FoodOrder *> orders;
    //Table * curr;
};


#endif //PROJ_WAITER_H
