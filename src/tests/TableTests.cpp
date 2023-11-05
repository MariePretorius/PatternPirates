#include "TableTests.h"
#include <cassert>

TableTests::TableTests()
{
}

void TableTests::runTests()
{
    Table table(1, 4); // Assuming table number 1 and capacity of 4
    assert(table.getTableNumber() == 1);
    assert(table.getCapacity() == 4);
    assert(table.isOccupied() == false);

    // Create some Customer objects for testing
    Customer customer1("bill", false);
    Customer customer2("tab", true);

    // Test assignCustomers() method
    list<Customer*> customerList;
    customerList.push_back(&customer1);
    customerList.push_back(&customer2);
    table.assignCustomers(customerList);
    assert(table.isOccupied() == true);

    assert(table.getCustomers()->size() == 2);


    // Test removeCustomers() method
    table.removeCustomers();
    assert(table.isOccupied() == false);

    assert(table.getCustomers()->size() == 0);


    std::cout << "All Table tests passed" << std::endl;
}
