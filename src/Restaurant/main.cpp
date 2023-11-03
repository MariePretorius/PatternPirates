#include <iostream>

#include "../Kitchen/Kitchen.h"
#include "../Floor/Customer.h"


#include "Restaurant.h"
#include "../tests/CustomerTests.h"



using namespace std;
int main(){
    Restaurant::instance()->setup();
    // CUSTOMER TESTS
    CustomerTests* customerTests = new CustomerTests();
    customerTests->runTests();

    return 0;
}

