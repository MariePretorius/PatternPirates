#include "Bill.h"

Bill :: Bill()
{
    totalCost = 0.0;
    tab = false;
    paid = false;
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

void Bill :: isTab(bool tab)
{
    // this->tab = tab;

    // std::cout << "\x1B[35m";

    // int tableNum = 1;  //change to set to appropriate table

    // std::cout << "Table " << tableNum << "'s bill has been set to a tab." << std::endl;

    // std::cout << "\x1B[0m";
}