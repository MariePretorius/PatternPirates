#include "BillTest.h"
#include <iostream>
#include <cassert>

BillTest::BillTest() 
{
    // Initialize Bill and BillCaretaker instances for testing
    Customer* cust = new Customer("Bill", false);
    Finance* f = new Finance();
    bill = Bill(cust, f);
    caretaker = BillCaretaker();
}

void BillTest::runTestScenario() 
{
    // Test various bill operations
    bill.addItem("Burger", 40.99);
    bill.addItem("Fries", 25.99);

    // Save a memento of the current bill
    BillMemento memento = bill.createMemento();
    caretaker.saveMemento(memento);

    bill.addItem("Soda", 15.95);

    std::cout << "Current Bill:\n";
    bill.showBill();

    // Restore the bill from the saved memento
    bill.restoreFromMemento(caretaker.getMemento(0));

    std::cout << "\nRestored Bill:\n";
    bill.showBill();

    bill.setTab(true);
    bill.payBill(100.00);

    bool paid = bill.isPaid();
    if (paid)
        std::cout << "Bill Paid" << std::endl;
    else
        std::cout << "Not Paid" << std::endl;

    // Check if the bill has been paid
    assert(paid == true);

    // Ensure items and total cost match after restoration
    std::string restoredBill = bill.showBill();
    std::string expectedBill = "Burger $40.99\nFries $25.99\n";
    assert(restoredBill == expectedBill);
}

void BillTest::runTests() 
{
    runTestScenario();
}

// int main() {
//     BillTest billTest;
//     billTest.runTests();

//     return 0;
// }
