//
// Created by Tristan on 2023/10/23.
//

#include "Floor.h"
#include "Waiter.h"
#include "Host.h"
#include "Table.h"
#include <random>

Floor::Floor()
{
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
    std::cout << randomInteger << std::endl;
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
    waiters.push_back(new Waiter());
    numberOfWaiters++;
    std::cout << "Added new Waiter" << std::endl;
}

void Floor::addCustomers(vector<Customer *> newCustomers)
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
}
