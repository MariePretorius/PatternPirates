#include "CustomerTests.h"

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
    cout << "Cooking Method: grilled / fried" << endl;
    cout << "Splt: false" << endl;
    cout << "Rating: 5.0" << endl;

    cout << endl;
    cout << "Generated Output:" << endl;

    cout << "Customer ID: " << customer.getCustomerID() << endl;
    cout << "Customer State: " << customer.getState() << endl;
    cout << "Payment Method: " << customer.getPaymentMethod() << endl;
    cout << "Cooking Method: " << customer.getCookingMethod() << endl;
    cout << "Split: " << customer.getSplit() << endl;
    cout << "Rating: " << customer.getRating() << endl;
}