//
// Created by Tristan on 2023/10/23.
//
using namespace std;
#include "Waiter.h"
#include "Customer.h"
#include "Bill.h"
#include "../Restaurant/FoodOrder.h"
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
    std::list<Customer*> temp = table->getCustomers();
    list<Customer*>::iterator it = table->getCustomers().begin();
    if((*it)->getPaymentMethod())
    {
        //if split

        //creates a bill based on orders
    }
    else
    {

    }
}

void Waiter::getOrders() {
    //call getter for each customer
    for(vector<Table*>::iterator it = tables.begin(); it != tables.end(); it++)
    {
        list<Customer*>::iterator ir = (*it)->getCustomers().begin();
        while(ir != (*it)->getCustomers().end())
        {
            list<Ingredient> tempIngredient = (*ir)->getIngredients();
            list<double> tempPrices = (*ir)->getPrices();
            string method = (*ir)->getCookingMethod();
            FoodOrder * tempFoodOrder = new FoodOrder();
        }
    }
    //call getter for each element of an order
    //create a foodorder object and put it into list with reference to customer that ordered it
    //repeat for all customers in table
    //repeat for all tables
    //call execute once all tables have been served
    //repeat for all waiters
}
