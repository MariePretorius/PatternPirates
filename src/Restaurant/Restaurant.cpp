#include "Restaurant.h"

Restaurant* Restaurant::uniqueInstance=0;
/**
 * instance checks if uniqueInstance is null. If it is, it then initiates uniqueInstance and then returns it.
 * @return returns the uniqueInstance
 */
Restaurant *Restaurant::instance()
{
    if(uniqueInstance==0){
        uniqueInstance = new Restaurant();
    }
    return uniqueInstance;
}

/**
 * Default constructor initialises the funds,kitchen and floor. It is protected and only accessed in the instance function.
 */
Restaurant::Restaurant()
{
    //Singleton function
    funds = new Finance();
    floor = new Floor(funds);
    kitchen = new Kitchen(funds);
}

/**
 * Copy constructor doesn't do anything, its just declared and protected so that no other class can initialise another restaurant object
 * @param restaurant object which should be copied
 */
Restaurant::Restaurant(Restaurant &restaurant)
{
    //Singleton function

}

/**
 * Overloading operator= and since it is protected, ensures that no other class can call this and creating another instance of restaurant
 * @param restaurant object that needs to be created
 */
void Restaurant::operator=(Restaurant &restaurant)
{
    //Singleton function
}

/**
 * Setup part of Restaurant gets user input to set funds,buy stock and set the number of waiters employed
 */

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
void Restaurant::CleanUp() {
    delete funds;
    delete floor;
    delete kitchen;

    delete uniqueInstance;
    uniqueInstance=nullptr;


}

/**
 * Simulation part of Restaurant creates the customers waiting to be seated,all the tables on the floor and tells the host to
 * seat all the customers.Then sends the waiters to wait on the occupied tables.Simulation is also responsible for
 * the transferring of orders from waiters to the kitchen and finished orders back from the kitchen to the waiters
 */


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
        Shelf*shelf = kitchen->getShelf();
        vector<Stock*> stockList = shelf->getStockListVector();
        Customer* newCustomer = new Customer(pay,split,stockList);
        cout<<"\033[1;34m Customer state is:"<<newCustomer->getState()->getName()<<"\033[0m"<<endl;
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

    floor->waitersGetOrders();

    //Loop added to call execute for all the foodorders. it moves them to the kitchen so it has someting to work with.
    vector<FoodOrder*> * temp = floor->fetchOrders();
    for(FoodOrder * foodOrder : *temp)
    {
        (*foodOrder).setKitchen(this->kitchen);
        (*foodOrder).execute();
    }

    kitchen->startKitchenProcess();

    std::vector<Dish*> finishedOrder =kitchen->takeDishes();
    floor->giveFinishedOrders(finishedOrder);

    floor->waitersPassOrdersToTables();

    floor->waitersDoRounds();  // this is to set the customers' state to RequestingBill - if they want a bill!

    //waiter brings bill - call waiter.bill // change customer state to billPaid
    //customer pays with waiter - call pay function in waiter
    //customer leaves - remove all customers from their table
    
    // tabs pay at end of round - at end of round call pay tabs

    cout << "\033[1;32mSimulation phase is now done!\033[0m" << endl;
    //cout << "\033[1;32mThe average rating for this round is:\033[0m"<< getOverallRating << endl;

    cout << "\033[1;32m\"You have made R "<<funds->getFunds()<< " in this simulation round.\033[0m" << endl;


    //tables and host need to be deleted in floor
    // Part of cleanUp , don't touch! And don't add code under this
    for (Customer* c: customers) {
        delete c;
    }
    CleanUp();

}




