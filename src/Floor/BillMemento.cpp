#include "BillMemento.h"

BillMemento :: BillMemento(const std::vector<std::string>& billItems, double cost) : items(billItems), totalCost(cost) {}

const std::vector<std::string>& BillMemento :: getItems() const
{
    return items;
}

double BillMemento :: getTotalCost() const
{
    return totalCost;
}