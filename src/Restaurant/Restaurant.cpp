#include "Restaurant.h"
//test
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
    double f;
    cout << "\033[1;32mSetup Phase:\033[0m" << endl;
    cout << "\033[1;32mAmount of finances for this round:\033[0m"<< endl;
    cin>> f;
    funds->setFunds(f);

    //buy stock with finances - in shelf - use addStock - call kitchen's setup function # wait for Franco


    //assign waiters - floor? # wait for Tristan
}

void Restaurant::simulate()
{
    //spawn floor + kitchen - constructors for floor + kitchen+waiter+customer
    // host assigns customers to tables - call host - assignCustomer under floor
    //decide whether bill is split/not - customer- not for me
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