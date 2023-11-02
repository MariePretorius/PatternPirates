#include "Host.h"

Host::Host(Floor *fl)
{
    this->f = fl;
    //could do a while loop - while there are still customers in the list who havent been seated.
    bool seated = assignCustomer();
    // if success print cout << "\033[1;32mHost has seated a party of _num of people_ at table _tablenum_\033[0m" << endl;
    // also print out whether decided to split the bill

}

void Host::getAllTables(list<Table*> table)
{
    tables = table;
}

Table *Host::first()
{
    // Host must hold a list of all the tables in floor and customers
    // Table must have a way of showing it is full


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
        /*if (temp->tableNumber == curr->tableNumber)
        {
            found = true;
        }*/

    }
    return nullptr;
}

bool Host::isFull()
{
    //loop through tables + check whether they are all occupied - return true if so
    //Wait for Marie to add a bool variable to show occupation
    return false;
}

Table *Host::getNextOpenTable()
{
    // make function search for the next open table rather than returning the current table
    // loop through tables until open table found
    //wait for occupied bool value
    list<Table*>::iterator it = tables.begin();

    for (it; it != tables.end(); ) {
        Table* temp = *it;
        /*if (!temp.isOccupied)
        {
            return *it;
        }*/

    }
    return nullptr;
}

bool Host::assignCustomer() {
    //check if there is space
    if (isFull())
    {
        return false;// customers couldnt be seated
    }
    Table* openTable =getNextOpenTable();
    int amount = openTable->getCapacity();
    // either add all necessary customers to a list and call openTable.assignCustomers() and remove from floor list
    // OR add bool var to customer to show they have been seated.
    // discuss!
    return true;
}




