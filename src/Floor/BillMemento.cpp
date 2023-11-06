#include "BillMemento.h"

//comment added somewhere

/**
 * @brief Parameterized constructor for the BillMemento class.
 * @param billItems Menu items to be initialized on the bill.
 * @param cost Joined cost of the menu items that are being added onto the bill.
*/
BillMemento :: BillMemento(const std::vector<std::string>& billItems, double cost) : items(billItems), totalCost(cost) {}

/**
 * @brief Returns the vector containing the items on the bill.
 * @return Returns a vector of strings containing the items on the bill.
*/
const std::vector<std::string>& BillMemento :: getItems() const
{
    return items;
}

/**
 * @brief Returns the current total cost of the bill.
 * @return Returns a double representing the current total price of the bill.
*/
double BillMemento :: getTotalCost() const
{
    return totalCost;
}