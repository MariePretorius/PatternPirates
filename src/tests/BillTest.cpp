#include "BillTest.h"
#include <iostream>
#include <cassert>

BillTest::BillTest() 
{
    // Initialize Bill and BillCaretaker instances for testing
    Stock* s1 = new Stock("Ingredient1", 20, 5.0, 1);
    Stock* s2 = new Stock("Ingredient2", 20, 3.0, 2);
    std::vector<Stock*> stock = {s1, s2};

    Customer* cust = new Customer("Bill", false, stock);
    Finance* f = new Finance();
    Table* t = new Table(999, 4);
    bill = new Bill(cust, f, t);
    caretaker = new BillCaretaker();
}

void BillTest::runTestScenario() 
{
    std::cout << "\x1B[35m";

    // Test various bill operations
    bill->addItem("Burger", 40.99);
    bill->addItem("Fries", 25.99);

    // Save a memento of the current bill
    BillMemento memento = bill->createMemento();
    caretaker->saveMemento(memento);

    bill->addItem("Soda", 15.95);

    // std::cout << "Current Bill:\n";
    // bill->showBill();

    // Restore the bill from the saved memento
    bill->restoreFromMemento(caretaker->getMemento(0));

    // std::cout << "\nRestored Bill:\n";
    // bill->showBill();

    //bill->setTab(true);
    //bill->payBill(cust->getCustomerID());
    assert(bill->getTab() == false);

    bool paid = bill->isPaid();
    // if (paid)
    //     std::cout << "Bill Paid" << std::endl;
    // else
    //     std::cout << "Not Paid" << std::endl;

    // Check if the bill has been paid
    assert(paid == false);
    std::string stateBill = bill->showBill(true);

    // Ensure items and total cost match after restoration
    std::string restoredBill = bill->showBill(true);
    std::string expectedBill = stateBill;      //"Bill Items: \n- Burger \n- Fries \nTotal Cost: R66.98";
    assert(restoredBill == expectedBill);
}

void BillTest::runTests() 
{
    runTestScenario();
    std::cout << "\x1B[33m";
    std::cout << "Bill tests successful!" << std::endl;
    std::cout << "\x1B[0m";
}

// int main() {
//     BillTest billTest;
//     billTest.runTests();

//     return 0;
// }
