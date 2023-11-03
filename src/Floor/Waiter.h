//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_WAITER_H
#define PROJ_WAITER_H

#include <list>

#include "Table.h"
class Order;

class Waiter
{
public:
    Waiter();
    void moveToNext();
    void addTableToWait(Table * newTable);
    void addOrder(Order * newOrder);
    std::vector<Order*> * giveOrders();
    void getOrdersFromCurrTable();
    void createBill(bool split, Table * currTable);

private:
    std::vector<Table *> tables;
    std::vector<Order *> orders;
    //Table * curr;
};


#endif //PROJ_WAITER_H
