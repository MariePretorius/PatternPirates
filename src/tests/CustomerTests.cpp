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
    cout << "Payment Method: Bill" << endl;
    cout << "Splt: false" << endl;

}