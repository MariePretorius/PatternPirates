#include "Host.h"

Host::Host(Floor *fl)
{
    this->f = fl;
}

void Host::setCustomers(vector<Customer *> c) {
    customers = c;
}


void Host::setTables(list<Table *> t) {
    tables = t;
}


void Host::getAllTables(list<Table*> table)
{
    tables = table;
}

Table *Host::first()
{
    return tables.front();
}


Table *Host::next(Table * curr)
{
    bool found = false;
    list<Table*>::iterator it = tables.begin();
    for (it; it != tables.end(); ) {
        Table* temp = *it;
        if (found)
        {
            return *it;
            break;
        }
        //waiting for Marie to implement getter for tableNumber
        if (temp->getTableNumber() == curr->getTableNumber())
        {
            found = true;
        }

    }
    return nullptr;
}

bool Host::isFull()
{   ///See if there are any tables that are still open
    //true = full
    list<Table*>::iterator it = tables.begin();
    bool full = true;
    for (it; it != tables.end(); it++)
    {
        Table* temp = *it;
        if (!temp->isOccupied())
        {
            full = false;
        }
    }
    return full;
}

Table *Host::getNextOpenTable()
{
    // make function search for the next open table rather than returning the current table
    // loop through tables until open table found

    list<Table*>::iterator it = tables.begin();

    for (it; it != tables.end(); ) {
        Table* temp = *it;
        if (!temp->isOccupied())
        {
            return *it;
        }

    }
    return nullptr;
}

bool Host::assignCustomer() {
    //function variables:
    Table* openTable; // has the next open table
    int amount;        // capacity of open table
    list<Customer*> seatedCustomers;
    string paymentMethod;

   ///Find an open table and then seat the table's capacity amount of customers
    while (!customers.empty())
    {
        if (isFull())
        {
            cout << "\033[1;32mHost couldn't seat the customers,unfortunately the restaurant is full033[0m" << endl;
            return false;
        }
        openTable =getNextOpenTable();
        amount = openTable->getCapacity();

        for (int i = 0; i < amount; ++i) {
            Customer* CustomerToBeSeated= customers.back();
            customers.pop_back();
            seatedCustomers.push_back(CustomerToBeSeated);
        }
        //  add all necessary customers to a list and call openTable.assignCustomers() and remove from floor list
        openTable->assignCustomers(seatedCustomers);

        cout << "\033[1;32mHost has seated a party of "+ to_string(amount)+" at table"+
        to_string(openTable->getTableNumber())+"\033[0m" << endl;

        //GET INFO FROM MARIE
        //getPaymentMethod :true = ;false=
        if ( seatedCustomers.back()->getPaymentMethod())
        {
            paymentMethod ="tab";
        } else
            paymentMethod="bill";

        cout<< "\033[1;34m" + to_string(openTable->getTableNumber())+" has decided to request a"+
        paymentMethod+" \033[0m";

        return true;
    }
}





