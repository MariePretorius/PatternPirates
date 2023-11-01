#include "Bill.h"
#include <sstream>

//comment added somewhere

Bill :: Bill()  //(Customer& customer)
{
    totalCost = 0.0;
    tab = false;
    paid = false;
    //this->customer = customer;
    //custID = customer->getID();
}

void Bill :: addItem(const std::string& item, double cost)
{
    items.push_back(item);
    totalCost += cost;
}

BillMemento Bill :: createMemento() const
{
    return BillMemento(items, totalCost);
}

void Bill :: restoreFromMemento(const BillMemento& memento)
{
    items = memento.getItems();
    totalCost = memento.getTotalCost();
}

void Bill :: showBill() const
{
    std::cout << "\x1B[35m";  //Change color to purple

    std::cout << "Bill Items:" << std::endl;
    for (const std::string& item : items)
    {
        std::cout << "- " << item << std::endl;
    }
    std::cout << "Total Cost: R" << totalCost << std::endl;

    std::cout << "\x1B[0m";  //Change color back to normal
}

void Bill :: setTab(bool tab)
{
    this->tab = tab;

    std::cout << "\x1B[35m";

    std::cout << "This bill has been set to a tab." << std::endl;
    //std::cout << "Customer " << custID << " has set their bill to a tab." << std::endl;

    std::cout << "\x1B[0m";
}

void Bill :: payBill(double amount)
{
    double costPaid = totalCost;
    std::stringstream ss;
    std::stringstream os;
    std::string cost = "", owe = "";

    std::cout << "\x1B[35m";
    
    // std::string split = "";
    // int numSplit = 1;
    // double splitSingleTotal = 0.0;

    // std::cout << "Do you wan to spit the bill? (y/n)";
    // std::cin >> split;

    // if (split == "y")
    // {
    //     std::cout << "How many are splitting?";
    //     std::cin >> numSplit;
    //     splitSingleTotal = totalCost / numSplit;
    //     std::cout << "Everyone should pay " << splitSingleTotal << std::endl;
    // }

    if (totalCost - amount > 0)
    {
        ss << totalCost;
        ss >> owe;
        std::cout << "Not enough money given! You owe " << owe << std::endl;
    }
    else
    {
        totalCost = 0.0;
        
        //call finances function to add money

        paid = true;

        ss << costPaid;
        ss >> cost;

        std::cout << "Customer's bill has been paid. Total was: R" << cost << std::endl;
        //std::cout << "Customer " << custID << " bill has been paid." << std::endl;
    }


    std::cout << "\x1B[0m";
}

bool Bill :: isPaid()
{
    return paid;
}

// example usage
// std::cout << "\x1B[35m"; 

// Bill bill;
// BillCaretaker caretaker;

// bill.addItem("Burger", 40.99);
// bill.addItem("Fries", 25.99);

// caretaker.saveMemento(bill.createMemento());

// bill.addItem("Soda", 15.95);

// std::cout << "Current Bill:\n";
// bill.showBill();

// bill.restoreFromMemento(caretaker.getMemento(0));

// std::cout << "\nRestored Bill:\n";
// bill.showBill();

// bill.setTab(true);
// bill.payBill(100.00);

// bool paid = bill.isPaid();
// if (paid)
//     std::cout << "Bill Paid" << std::endl;
// else
//     std::cout << "Not Paid" << std::endl;

// std::cout << "\x1B[0m"; 
