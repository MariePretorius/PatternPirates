#include "Table.h"

Table::Table(int tableNumber, int capacity)
{
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

list<Customer*> Table::getCustomers()
{
    return customers;
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
