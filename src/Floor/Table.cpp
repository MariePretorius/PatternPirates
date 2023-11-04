#include "Table.h"

Table::Table(int tableNumber, int capacity)
{
    //instantiate customers to prevent segfault when pushing to it later
    this->customers = list<Customer*>();
    this->tableNumber = tableNumber;
    this->capacity = capacity;
}

void Table::assignCustomers(list<Customer*> customers)
{
    this->customers = customers;
    occupied = true;
}

void Table::removeCustomers()
{
    customers.clear();
    occupied = false;

}

//idk, c++ just stopped segfaulting when I made it a pointer.
list<Customer*> * Table::getCustomers()
{
    return &customers;
}

int Table::getCapacity()
{
    return capacity;
}

int Table::getTableNumber()
{
    return tableNumber;
}

bool Table::isOccupied()
{
    return occupied;
}

void Table::assignDishes(vector<Dish*> *dishes)
{
    this->dishes = dishes;
}

void Table::checkDishes()
{
    bool allFinished = true;
    for (Customer* customer : customers) {
        if (customer->getStateName() != "Bill Requested") {
            allFinished = false;
            break;
        }
        if (allFinished) {
            dishes->clear();
        }
    }
}

bool Table::doneEating()
{
    bool allFinished = true;
    for (Customer* customer : customers) {
        if (customer->getStateName() != "Bill Requested") {
            allFinished = false;
            break;
        }
        if (allFinished) {
            return true;
        } else return false;
    }
}