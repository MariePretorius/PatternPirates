#ifndef BILLTEST_H
#define BILLTEST_H

#include "../Floor/Bill.h"
#include "../Floor/BillCaretaker.h"
#include "../Floor/BillMemento.h"

#include "../Floor/Customer.h"
#include "../Restaurant/Finance.h"
#include "../Floor/Table.h"
#include "../Kitchen/Stock.h"

class BillTest 
{
    public:
        BillTest();
        ~BillTest();
        void runTestScenario();
        void runTests();
    private:
        Bill* bill;
        BillCaretaker* caretaker;
        Customer* cust;
        Finance* f;
        Table* t;
        Stock* s1;
        Stock* s2;
};

#endif
