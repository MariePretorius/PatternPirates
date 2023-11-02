//
// Created by Tristan on 2023/10/23.
//

#include "Waiter.h"

void Waiter::moveToNext()
{
    //will iterate to the next table in the tables list
    //foreach

}

void Waiter::getOrdersFromCurrTable()
{
    //call getter for each customer
    //call getter for each element of an order
    //create a foodorder object and put it into list with reference to customer that ordered it
    //repeat for all customers in table
    //repeat for all tables
    //call execute once all tables have been served
    //repeat for all waiters
}

Waiter::Waiter()
{
    tables = std::list<Table*>();
    orders = std::list<Order*>();
}

void Waiter::addTableToWait(Table *newTable)
{
    tables.push_front(newTable);
}

void Waiter::addOrder(Order *newOrder)
{
    orders.push_front(newOrder);
}

std::list<Order *> *Waiter::giveOrders() {
    return &(this->orders);
}
