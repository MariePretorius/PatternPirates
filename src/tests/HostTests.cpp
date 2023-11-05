//
// Created by HP PC on 05/11/2023.
//

#include "HostTests.h"

HostTests::HostTests() {
    Finance* funds = new Finance(10000);
    f = new Floor(funds);
    Kitchen* kitchen = new Kitchen(funds);
    int numTables = 10;
    int numCustomers=5;
    srand(1234);
    int r;
    int maxCap=4;
    for (int i = 0; i < numTables; ++i) {
        r = rand()% maxCap+1;
        f->addTable(r);
    }
    bool split;
    int paymentMethod;
    string pay="";
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
    host = new Host(f);
}

void HostTests::TestScenario() {
    host->setTables(tables);
    host->setCustomers(customers);
    assert(host->first() != nullptr);
    assert(host->first() == tables.front());
    assert(host->next(host->first())!= nullptr);
    assert(host->isFull()== false);
    assert(host->getNextOpenTable() != nullptr);
    assert(host->assignCustomer()== true);
}
