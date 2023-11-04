#ifndef BILLTEST_H
#define BILLTEST_H

#include "../Floor/Bill.h"
#include "../Floor/BillCaretaker.h"
#include "../Floor/BillMemento.h"

#include "../Floor/Customer.h"
#include "../Restaurant/Finance.h"
#include "../Floor/Table.h"

class BillTest 
{
    public:
        BillTest();
        void runTestScenario();
        void runTests();
    private:
        Bill* bill;
        BillCaretaker* caretaker;
        Customer* cust;
};

#endif
