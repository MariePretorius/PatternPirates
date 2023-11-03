#include "CustomerTests.h"

CustomerTests::CustomerTests()
{
    
}

void CustomerTests::runTests()
{
    cout << "\033[34mCUSTOMER CLASS TESTS\033[0m" << endl;
    cout << endl;

    Customer customer("bill", false);
    
    cout << "Expected Output:" << endl;
    cout << endl;

    cout << "Customer ID: 1" << endl;
    cout << "Customer State: Waiting For Table" << endl;
    cout << "Payment Method: bill" << endl;
    cout << "Cooking Method: grilled / fried (Randomly generated)" << endl;
    cout << "Splt: 0" << endl;
    cout << "Rating: 5" << endl;

    cout << endl;
    cout << "Generated Output:" << endl;
    cout << endl;

    cout << "Customer ID: " << customer.getCustomerID() << endl;
    cout << "Customer State: " << customer.getStateName() << endl;
    cout << "Payment Method: " << customer.getPaymentName() << endl;
    cout << "Cooking Method: " << customer.getCookingMethod() << endl;
    cout << "Split: " << customer.getSplit() << endl;
    cout << "Rating: " << customer.getRating() << endl;
}