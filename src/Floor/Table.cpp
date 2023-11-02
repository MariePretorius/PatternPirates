#include "Table.h"

Table::Table(int tableNumber, int capacity)
{
    this->tableNumber = tableNumber;
    this->capacity = capacity;
}

void Table::assignCustomers(list<Customer> customers)
{
    this->customers = customers;
    occupied = true;
}

void Table::removeCustomers(list<Customer> customers)
{
    for (list<Customer>::iterator it = customers.begin(); it != customers.end(); ) {
        Customer customer = *it;
        this->customers.erase(it);
    }
    if (customers.size() == 0) {
        occupied = false;
    }
    if (customers.size() == 0) {
        occupied = false;
    }
}

list<Customer> Table::getCustomers()
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
