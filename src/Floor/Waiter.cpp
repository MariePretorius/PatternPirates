//
// Created by Tristan on 2023/10/23.
//

#include "Waiter.h"

void Waiter::moveToNext()
{
    //will iterate to the next table in the tables list
}

Waiter::Waiter()
{

}

void Waiter::addTableToWait(Table *newTable)
{
    tables.push_front(newTable);
}

void Waiter::addOrder(Order *newOrder)
{
    orders.push_front(newOrder);
}
