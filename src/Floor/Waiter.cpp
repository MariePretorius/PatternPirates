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

Waiter::Waiter(Finance * finance)
{
    this->finance = finance;
    tables = std::vector<Table*>();
    orders = std::vector<FoodOrder*>();
}

void Waiter::addTableToWait(Table *newTable)
{
    tables.push_back(newTable);
}

void Waiter::addOrder(FoodOrder *newOrder)
{
    orders.push_back(newOrder);
}

std::vector<FoodOrder *> *Waiter::giveOrders() {
    return &(this->orders);
}

void Waiter::createBill(bool split, Table *table) {
    std::list<Customer*> * temp = table->getCustomers();
    list<Customer*>::iterator it = table->getCustomers()->begin();
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
    for(vector<Table*>::iterator table = tables.begin(); table != tables.end(); table++)
    {
        list<Customer*>::iterator customers = (*table)->getCustomers()->begin();

        while(customers != (*table)->getCustomers()->end())
        {
            std::cout << "\033[35mCustomer state is:\t\t"<< (*customers)->getState()->getName() <<"!\033[0m" << std::endl;
            if((*customers)->getState()->getName() == "Ready To Order")
            {
                list<Ingredient> * tempIngredient = (*customers)->getIngredients();
                list<double> tempPrices = (*customers)->getPrices();
                string method = (*customers)->getCookingMethod();
                vector<string> vectorIngredients = vector<string>();
                vector<double> vectorDouble = vector<double>();
                for(Ingredient &ingredient : *tempIngredient)
                {
                    vectorIngredients.push_back(ingredient.getName());
                }
                for(double &d : tempPrices)
                {
                    vectorDouble.push_back(d);
                }
                //FoodOrder(std::vector<std::string> ingredients, std::vector<double> prices, int num, std::string method, int tableNumber, Customer& customer, Bill* bill);
                FoodOrder * tempFoodOrder = new FoodOrder(vectorIngredients,vectorDouble,vectorIngredients.size(),
                                                          (*customers)->getCookingMethod(), (*table)->getTableNumber(), **customers,new Bill(*customers,this->finance));
                this->orders.push_back(tempFoodOrder);
                (*customers)->nextState();
                std::cout << "\033[35mCustomer state has changed to:\t\t"<< (*customers)->getState()->getName() <<"!\033[0m" << std::endl;
            }

            customers++;
        }
    }
    //call getter for each element of an order
    //create a foodorder object and put it into list with reference to customer that ordered it
    //repeat for all customers in table
    //repeat for all tables
    //call execute once all tables have been served
    //repeat for all waiters
}

std::vector<FoodOrder *> * Waiter::fetchOrders() {
    return &orders;
}
