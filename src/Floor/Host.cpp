#include "Host.h"

Host::Host(Floor *fl)
{
    this->f = fl;

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
        if (temp->tableNumber == curr->tableNumber)
        {
            found = true;
        }

    }
    return nullptr;
}

bool Host::isFull()
{
    //loop through tables + check whether they are all occupied - return true if so
    return false;
}

Table *Host::currentTable()
{
    // make functionsearch for the next open table rather than returning the current table
    // loop through tables until open table found
    return nullptr;
}




