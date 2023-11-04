//
// Created by Tristan on 2023/10/23.
//

#include "Floor.h"
#include "Waiter.h"
#include "Host.h"
#include "Table.h"
#include "../Restaurant/Finance.h"
#include <random>

Floor::Floor(Finance * finance)
{
    this->stashedOrders = vector<FoodOrder*>();
    this->finance = finance;
    this->numberOfTables = 0;
    this->numberOfWaiters = 0;
}

int Floor::getCapacity()
{
    //will iterate through tables list and add up the number of potentail customers
    int tempTotal = 0;
    list<Table*>::iterator it = tables.begin();
    while(it != tables.end())
    {
        tempTotal += (*it)->getCapacity();
        it++;
    }
    return tempTotal;
}

Host *Floor::createHost()
{
    return new Host(this);
}

int Floor::getNumWaiters()
{
    return numberOfWaiters;
}

int Floor::setNumWaiters() {
    return 0;
}

void Floor::addTable(int capacity)
{
    // add table to list
    Table * temp = new Table(numberOfTables,capacity);
    tables.push_back(temp);

    //randomly assign the table to a waiter

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(0, numberOfWaiters);

    // Generate a random integer
    int randomInteger = distribution(generator);
    if(randomInteger >= numberOfWaiters)
    {
        randomInteger -= 1;
    }
    std::list<Waiter*>::iterator it = waiters.begin();
    int i = 0;
    //std::cout << randomInteger << std::endl;
    while(i < randomInteger)
    {
        if(i != numberOfWaiters)
        {
            it++;
            i++;
        }
    }

    (*it)->addTableToWait(temp);


    numberOfTables++;
}

void Floor::addWaiter()
{
    waiters.push_back(new Waiter(this->finance));
    numberOfWaiters++;
    std::cout << "\033[35mAdded new Waiter\033[0m" << std::endl;
}

void Floor::addCustomers(const vector<Customer *>& newCustomers)
{
    for(Customer * c : newCustomers)
    {
        customers.push_back(c);
    }
}

std::list<Table *> Floor::getTables()
{
    std::list<Table*> temp = std::list<Table*>();
    std::list<Table*>::iterator it = tables.begin();
    while(it != tables.end())
    {
        temp.push_front(*it);

        it++;

    }

    return temp;
}

void Floor::waitersGetOrders() {
    for(std::list<Waiter*>::iterator it = waiters.begin(); it != waiters.end();it++)
    {
        (*it)->getOrders();
    }

    vector<FoodOrder *> * allOrders = new vector<FoodOrder *>();
    for(std::list<Waiter*>::iterator it = waiters.begin(); it != waiters.end();it++)
    {
        vector<FoodOrder*> * temp = (*it)->fetchOrders();
        vector<FoodOrder *>::iterator ij = temp->begin();
        for(int i = 0; i < temp->size(); i++)
        {
            allOrders->push_back((*ij));
            ij++;
        }
    }

    stashedOrders = *allOrders;
}

vector<FoodOrder *> *Floor::fetchOrders() {
    return &stashedOrders;
}

// when waiter gives finished orders to customers, change their state - should be eating state
void Floor::waitersDoRounds() {

}
