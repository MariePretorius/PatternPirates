#include "CustomerTests.h"
#include <cassert>

CustomerTests::CustomerTests()
{
}

void CustomerTests::runTests()
{
    vector<Stock *> stockVector = vector<Stock*>();
    Customer customer("bill", false, stockVector);
    assert(customer.getStateName() == "Waiting For Table");
    assert(customer.getPaymentName() == "bill");
    assert(customer.getSplit() == false);

    // Test nextState() method
    customer.nextState();
    assert(customer.getStateName() == "Seated"); // Replace "NextState" with the expected next state name


    // Test getCustomerID() method
    assert(customer.getCustomerID() == 1); // Assuming nextID starts at 1

    cout << "All Customer tests passed" << endl;

}