//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_WAITER_H
#define PROJ_WAITER_H

#include <list>

class Table;
class Order;

class Waiter
{
public:
    Waiter();
    void moveToNext();
    void addTableToWait(Table * newTable);
    void addOrder(Order * newOrder);

private:
    std::list<Table *> tables;
    std::list<Order *> orders;
    Table * curr;
};


#endif //PROJ_WAITER_H
