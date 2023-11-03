#include "TableTests.h"

TableTests::TableTests()
{
}

void TableTests::runTests()
{
    cout << "\033[34mTABLE CLASS TESTS\033[0m" << endl;
    cout << endl;

    Table* table = new Table(1, 4);

    cout << "Expected Output:" << endl;
    cout << endl;

    cout << endl;
    cout << "Table Number: 1" << endl;
    cout << "Capacity: 4" << endl;
    cout << "Customers After Adding: " << endl;
    cout << "Customer After Removing: " << endl;
    cout << endl;

    cout << "Generated Output:" << endl;
    cout << endl;

    cout << "Table Number: " << table->getTableNumber() << endl;
    cout << "Capcity: " << table->getCapacity() << endl;

    list<Customer*> customers;
    Customer* customer1 = new Customer("bill", false);
    Customer* customer2 = new Customer("bill", false);
    customers.push_back(customer1);
    customers.push_back(customer2);
    table->assignCustomers(customers);
    cout << "Customers After Adding: ";
    list<Customer*> listed = table->getCustomers();
    for (list<Customer*>::iterator it = listed.begin(); it != listed.end(); ) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Customers After Removing: ";
    list<Customer*> other;
    other.push_back(customer1);
    table->removeCustomers(other);
    list<Customer*> more = table->getCustomers();
    for (list<Customer*>::iterator iter = more.begin(); iter != more.end(); ) {
        cout << *iter << " ";
    }
    cout << endl;

}
