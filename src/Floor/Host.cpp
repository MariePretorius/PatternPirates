#include "Host.h"
/**
 * @brief Default constructor called in floor when everything is set up so that customers can be seated
 * @param fl a reference to the floor object
 */
Host::Host(Floor *fl)
{
    this->f = fl;
}

/**
 * @brief setCustomers sets the waiting customers so that the Host can iterate over them and seat them at open tables
 * @param c a reference to the customers
 */

void Host::setCustomers(vector<Customer *> c) {
    customers = c;
}

/**
 * @brief setTables sets the tables on the floor so that the host can iterate over them to seat customers at open tables
 * @param t a reference to the tables on the floor
 */
void Host::setTables(list<Table *> t) {
    tables = t;
}

/**
 * @brief first returns the first table to be accessed on the floor
 * @return returns a reference to the first table
 */
Table *Host::first()
{
    return tables.front();
}

/**
 * next iterates over all the tables to find the table that comes after the current table
 * @param curr a reference to the current table
 * @return returns a reference to the next table
 */
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

/**
 * @brief isFull iterates over all the tables in search of an open table.
 * @return returns true if no poen table was found and returns false if an open table was found
 */
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

/**
 * getNextOpenTable loops over all the tables on the floor in search of an open table.
 * @return returns a reference to the first open table or it returns a null pointer if all tables are occupied
 */

Table *Host::getNextOpenTable()
{
    // make function search for the next open table rather than returning the current table
    // loop through tables until open table found

    list<Table*>::iterator it = tables.begin();

    for (it; it != tables.end(); it++) {
        Table* temp = *it;
        if (!temp->isOccupied())
        {
            return *it;
        }

    }
    return nullptr;
}

/**
 * @brief assignCustomer calls getNextOpenTable and then gets the capacity of that open table and then assigns that many customers to this table
 * @return returns true if all customers were seated or returns false if there are more customers, but the restaurant is full
 */
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
            CustomerToBeSeated->nextState();
            cout<<"\033[1;34mCustomer state is:"<<CustomerToBeSeated->getState()->getName()<<"\033[0m"<<endl;
            CustomerToBeSeated->nextState();
            cout<<"\033[1;34mCustomer state is:"<<CustomerToBeSeated->getState()->getName()<<"\033[0m"<<endl;

        }
        //  add all necessary customers to a list and call openTable.assignCustomers() and remove from floor list
        openTable->assignCustomers(seatedCustomers);

        cout << "\033[1;32mHost has seated a party of "+ to_string(amount)+" at table "+
        to_string(openTable->getTableNumber())+"\033[0m" << endl;

        //getPaymentMethod :true = tab ;false= bill

        if ( seatedCustomers.back()->getPaymentMethod())
        {
            paymentMethod ="tab";
        } else
            paymentMethod="bill";

        cout<< "\033[1;34m" + to_string(openTable->getTableNumber())+" has decided to request a "+
        paymentMethod+" \033[0m"<<endl;

    }
    return true;

}

Host::~Host() {

}





