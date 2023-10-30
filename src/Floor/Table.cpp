#include "Table.h"

Table::Table(int tableNumber, int capacity)
{
    this->tableNumber = tableNumber;
    this->capacity = capacity;
}

void Table::assignCustomers(list<Customer> customers)
{
    this->customers = customers;
}

void Table::removeCustomers(list<Customer> customers)
{
    for (auto it = customers.begin(); it != customers.end(); ) {
        auto customer = *it;
        this->customers.remove(customer);
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
