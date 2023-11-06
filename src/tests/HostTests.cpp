//
// Created by HP PC on 05/11/2023.
//

#include "HostTests.h"

HostTests::HostTests() {
    Finance* funds = new Finance(10000);
    f = new Floor(funds);
    for (int i = 0; i < 2; ++i) {
        f->addWaiter();
    }
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
        Shelf*shelf = new Shelf();
        shelf->addStock(new Ingredient("testHost",2,20.10,0));
        vector<Stock*> stockList = shelf->getStockListVector();
        Customer* newCustomer = new Customer(pay,split,stockList);
        customers.push_back(newCustomer);
        delete shelf;
    }
    f->addCustomers(customers);
    host = new Host(f);
    delete funds;
}

void HostTests::TestScenario() {
    tables = f->getTables();
    //copy(temp.begin(),temp.end(),tables.begin());
    host->setTables(tables);
    host->setCustomers(customers);
    assert(host->first() != nullptr);
    assert(host->first() == tables.front());
    assert(host->next(host->first())!= nullptr);
    assert(host->isFull()== false);
    assert(host->getNextOpenTable() != nullptr);
    assert(host->assignCustomer()== true);
}

HostTests::~HostTests() {
    delete host;
    for (Customer* c: customers) {
        delete c;
    }
    delete f;

}
