//
// Created by Tristan on 2023/10/23.
//

#include "Waiter.h"
#include "Customer.h"
#include "Bill.h"

#include <vector>
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
    tables = std::vector<Table*>();
    orders = std::vector<Order*>();
}

void Waiter::addTableToWait(Table *newTable)
{
    tables.push_back(newTable);
}

void Waiter::addOrder(Order *newOrder)
{
    orders.push_back(newOrder);
}

std::vector<Order *> *Waiter::giveOrders() {
    return &(this->orders);
}

void Waiter::createBill(bool split, Table *table) {
    if(split)
    {
        //creates a bill based on orders
    }
    else
    {

    }
}
