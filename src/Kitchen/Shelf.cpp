//
// Created by Tristan on 2023/10/23.
//

#include "Shelf.h"

void Shelf::addStock(Stock newStock)
{
    this->stockList;
}

void Shelf::removeStock(std::string stock)
{
    std::list<Stock>::iterator it = stockList.begin();
    while(it != stockList.end() || it->getName() != stock)
    {
        it++;
    }

    if(it != stockList.end())
    {
        stockList.erase(it);
    }
}

void Shelf::clearStock()
{
    for(int i = 0; i < this->stockList.size(); i++)
    {
        stockList.pop_front();
    }
}
