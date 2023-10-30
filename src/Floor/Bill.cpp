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

void Bill :: payBill()
{
    double costPaid = totalCost;
    totalCost = 0.0;
    paid = true;
    std::stringstream ss;
    std::string cost;

    ss << costPaid;
    ss >> cost;

    std::cout << "\x1B[35m";

    std::cout << "Customer's bill has been paid. Total was: R" << cost << std::endl;
    //std::cout << "Customer " << custID << " bill has been paid." << std::endl;

    std::cout << "\x1B[0m";
}

bool Bill :: isPaid()
{
    return paid;
}