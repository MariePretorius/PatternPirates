#include <iostream>

#include "../Kitchen/Kitchen.h"
#include "../Floor/Customer.h"


#include "Restaurant.h"
#include "../tests/CustomerTests.h"
#include "../tests/FinanceTests.h"
#include "../tests/StockTests.h"
#include "../tests/WaiterTests.h"
#include "../tests/FloorTests.h"


using namespace std;
int main(){
    Restaurant::instance()->setup();
    // CUSTOMER TESTS
    CustomerTests* customerTests = new CustomerTests();
    //customerTests->runTests();

    //Finance Tests
    //Tests Finanance class
    //Has No Dependencies
    FinanceTests * financeTests = new FinanceTests();

    delete financeTests;

    //Stock Tests
    //Tests stock, shelf and ingredient classes
    //has no dependencies
    StockTests * stockTests = new StockTests();

    delete stockTests;

    //Waiter Tests
    //tests the waiter class
    //
    WaiterTests * waiterTests = new WaiterTests();

    delete waiterTests;

    //Floor Tests
    FloorTests * floorTests = new FloorTests();

    delete floorTests;

    return 0;
}

