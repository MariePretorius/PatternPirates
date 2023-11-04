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
//added gap because it was 11pm and I struggle to read without sleep

    funds = new Finance();
    floor = new Floor(funds);
    kitchen = new Kitchen(funds);
}

Restaurant::Restaurant(Restaurant &restaurant)
{
    //Singleton function

}

void Restaurant::operator=(Restaurant &restaurant)
{
    //Singleton function

}
///
///Setup part of Restaurant: get user input to set funds,buy stock and set thenumber of waiters
void Restaurant::setup()
{
    // setting the finance's amount for later use
    double f;
    cout << "\033[1;32mSetup Phase:\033[0m" << endl;
    cout << "\033[1;32mAmount of finances for this round:\033[0m";
    cin>> f;
    cout<< endl;
    funds->setFunds(f);

    //buy stock with finances - in shelf - use addStock - call kitchen's setup function # wait for Franco
    cout << "\033[1;32mYour shelf is currently empty\033[0m" << endl;
    cout<<endl;
    kitchen->buyStock(); //function to allow user to buy stock and save it in shelf

    cout << "\033[1;32mHow many waiters should be employed:\033[0m" << endl;
    int w;
    cin>>w;
    for(int i = 0; i < w; i++)
    {
        floor->addWaiter();
    }

    cout << "\033[1;32mSetup complete!\033[0m" << endl;
    cout << "\033[1;32mThe restaurant simulation will now begin:\033[0m" << endl;
    simulate();
}
///
///Simulation part of Restaurant: starts the game loop

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


    // use loop for this part:
    floor->waitersGetOrders();

    //Loop added to call execute for all the foodorders. it moves them to the kitchen so it has someting to work with.
    vector<FoodOrder*> * temp = floor->fetchOrders();
    for(FoodOrder * foodOrder : *temp)
    {
        (*foodOrder).setKitchen(this->kitchen);
        (*foodOrder).execute();
    }


    // for each order in foodorder list call foodOrder->execute

    //kitchen prepares items - kitchen -not for me
    kitchen->startKitchenProcess();
    //waiter takes order to correct table num - get order from kitchen + give to waiter

    // customers eat - waiter+customer - not for me
    //customer requests bill/tab - not sure
    //waiter brings bill - call waiter.bill
    //customer pays with waiter - call pay function in waiter
    //customer leaves rating + tip - at waiter
    //customer leaves - customer
    // tabs pay at end of round - at end of round call pay tabs

}

///
