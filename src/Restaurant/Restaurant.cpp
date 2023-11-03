#include "Restaurant.h"

Restaurant* Restaurant::uniqueInstance=0;

Restaurant *Restaurant::instance()
{
    if(uniqueInstance==0){
        uniqueInstance = new Restaurant();
    }
    return uniqueInstance;
}

Restaurant::Restaurant()
{
    //Singleton function
    funds = new Finance();
    floor = new Floor();
    kitchen = new Kitchen();
}

Restaurant::Restaurant(Restaurant &restaurant)
{
    //Singleton function

}

void Restaurant::operator=(Restaurant &restaurant)
{
    //Singleton function

}

void Restaurant::setup()
{
    // setting the finance's amount for later use
    double f = 420.69;
    cout << "\033[1;32mSetup Phase:\033[0m" << endl;
    cout << "\033[1;32mAmount of finances for this round:\033[0m"<< endl;
    funds->setFunds(f);

    //buy stock with finances - in shelf - use addStock - call kitchen's setup function # wait for Franco
    cout << "\033[1;32mYour shelf:\033[0m" << endl;
    //kitchen.setup(); //function to allow user to buy stock and save it in shelf

    cout << "\033[1;32mHow many waiters should be employed:\033[0m" << endl;
    int w = 3;
    for(int i = 0; i < w; i++)
    {
        floor->addWaiter();
    }

    cout << "\033[1;32mSetup complete!\033[0m" << endl;
    cout << "\033[1;32mThe restaurant simulation will now begin:\033[0m" << endl;
    simulate();
}

void Restaurant::simulate()
{
    //set variables
    int numCustomers =10;
    int numTables =10;

    //variables to create customers:
    int r; // for random values
    bool split;
    int paymentMethod;
    string pay ="";

    //variables to create tables:
    int maxCap =4;  // capacity of a table can at most be 4

    ///Creating randomized customers to queue to be seated at tables
    srand(1234);
    vector<Customer*> customers;
    for (int i = 0; i < numCustomers; ++i) {
        r = rand()%2;
        split=r ;       // if 0-dont split else if 1 split
        paymentMethod=r; // if 1 - bill, else tab
        if (paymentMethod == 1)
        {
            pay="bill";
        } else
            pay="tab";
       Customer* newCustomer = new Customer(pay,split);
       customers.push_back(newCustomer);
    }

    /// sending customers vector to floor for storing so that host can seat the customers

     floor->addCustomers(customers);

    /// Creating all the tables on the floor so that host and waiter can access the tables
    for (int i = 0; i < numTables; ++i) {
        r = rand()% maxCap+1;
        floor->addTable(r);
    }

    ///Creating Host who will get waiting customers and seating them at tables
    Host* manager = floor->createHost();
    manager->setCustomers(customers);
    manager->setTables(floor->getTables());
    manager->assignCustomer();

    // create function in floor to tell waiters to do rounds
    //spawn floor + kitchen

    // waiters talk to customers - start iteration

    //table orders OR waits - customer-not for me

    // waiter takes order if ready to order -  part of iteration-not for me
    //waiter takes order to kitchen -  get orders + give to kitchen
    //kitchen prepares items - kitchen -not for me
    //waiter takes order to correct table num - get order from kitchen + give to waiter
    // customers eat - waiter+customer - not for me
    //customer requests bill/tab - not sure
    //waiter brings bill - call waiter.bill
    //customer pays with waiter - call pay function in waiter
    //customer leaves rating + tip - at waiter
    //customer leaves - customer
    // tabs pay at end of round - at end of round call pay tabs

}