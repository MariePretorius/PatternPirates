//
// Created by Tristan on 2023/10/23.
//

#include "Floor.h"
#include "Waiter.h"
#include "Host.h"
#include "Table.h"
#include "../Restaurant/Finance.h"
#include <random>
#include <algorithm>
/**
 * @brief Constructor for the Floor class
 * @param finance a pointer to a finance object
 */
Floor::Floor(Finance * finance)
{
    this->stashedOrders = vector<FoodOrder*>();
    this->finance = finance;
    this->numberOfTables = 0;
    this->numberOfWaiters = 0;
    this->ratings = new Ratings();
}
/**
 * @brief Gets the maximum number of Customers that can be seated
 * @return Max Capacity
 */
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
/**
 * Instantiates a new host for the Floor
 * @return A host object pointer
 */
Host *Floor::createHost()
{
    return new Host(this);
}
/**
 * @brief returns the number of waiters on the floor
 * @return
 */
int Floor::getNumWaiters()
{
    return numberOfWaiters;
}

/**
 *@brief Sets the number of waiters
 * @return
 */
int Floor::setNumWaiters() {
    return 0;
}

/**
 * @brief Adds a table of a given capacity to the Floor
 * @param capacity Number of seats at this specific table
 */
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

/**
 * @brief Adds a waiter to the Floor
 */
void Floor::addWaiter()
{
    waiters.push_back(new Waiter(this->finance, this->ratings));
    numberOfWaiters++;
    std::cout << "\033[35mAdded new Waiter\033[0m" << std::endl;
}

/**
 * @brief Adds a vector of new customers to the Queue in floor
 * @param newCustomers vector of customer pointers
 */
void Floor::addCustomers(const vector<Customer *>& newCustomers)
{
    for(Customer * c : newCustomers)
    {
        customers.push_back(c);
    }
}

/**
 * @brief Gets the tables list in floor
 * @return Table list
 */
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

/**
 * @brief All waiters go to their tables and fetch their orders. Once all their orders are fetched, they pass it through
 * to floor's allOrders list
 */
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
/**
 * @brief Returns all the orders collected by the waiters
 * @return vector of FoodOrder pointers
 */
vector<FoodOrder *> *Floor::fetchOrders() {
    return &stashedOrders;
}

// when waiter gives finished orders to customers, change their state - should be eating state
void Floor::waitersDoRounds() {
    for(Waiter*w: waiters)
    {
        w->doRounds();
    }
}
/**
 * @brief Takes in finished orders and places them in the finishedOrders vector in Floor
 *
 * @param finishedOrders A vector of Dish pointers
 */
void Floor::giveFinishedOrders(vector<Dish *> finishedOrders) {
    for(Dish*d: finishedOrders)
    {
        this->finishedOrders.push_back(d);
    }
}
/**
 * @brief Tells all waiters to pass the orders to their respective tables
 */
void Floor::waitersPassOrdersToTables() {
    //for each dish in the finished orders...
    while (!finishedOrders.empty())
    {
        Dish * d = finishedOrders.front();
        //go through each waiter...
        for(Waiter * w: waiters)
        {
            //then go through each waiter's tables
            for(Table * t: *w->getTables())
            {
                //if the dish's table ID is equal to the table
                if(d->getTableId() == t->getTableNumber())
                {
                    //add it to the waiter's hand
                    w->addDishToHand(d);
                    //and remove it from the finished orders
                    vector<Dish*>::iterator it = std::find(finishedOrders.begin(), finishedOrders.end(), d);
                    finishedOrders.erase(it);
                    //then continue for the whole list.
                }
            }
        }
    }

    //then tell each waiter to drop their orders to tables
    for(Waiter * w: waiters)
    {
        w->passOrdersToTables();
    }

}
