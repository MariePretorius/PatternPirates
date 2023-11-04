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

void Table::removeCustomers(list<Customer*> customers)
{
    for (list<Customer*>::iterator it = customers.begin(); it != customers.end(); ) {
        Customer* customer = *it;
        it = customers.erase(it);

    }
    if (customers.size() == 0) {
        occupied = false;

    }
    if (customers.size() == 0) {
        occupied = false;
    }
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
