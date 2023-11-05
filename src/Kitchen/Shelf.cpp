//
// Created by Tristan on 2023/10/23.
//

#include "Shelf.h"
#include <string>
#include <iostream>

void Shelf::addStock(Stock * newStock)
{
    this->stockList.push_back(newStock);
}

void Shelf::removeStock(std::string stock)
{
    std::vector<Stock*>::iterator it = stockList.begin();
    while(it != stockList.end() && (*it)->getName() != stock)
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
        stockList.pop_back();
    }
}

std::string Shelf::getStockList() {
    //std::cout <<"start"<< std::endl;
    std::string temp = "";

    for(Stock* i: stockList)
    {
        temp += i->toString() + "\n";
    }
    //std::cout << temp << std::endl;
    return temp;
}

Stock * Shelf::deductStock(std::string stock)
{
    std::vector<Stock*>::iterator it = stockList.begin();
    while(it != stockList.end() && (*it)->getName() != stock)
    {
        it++;
    }

    if(it != stockList.end())
    {
        return (*it);
    }
    return nullptr;
}

Shelf::Shelf() {
    stockList = std::vector<Stock*>();
    currentCapacity = 0;
    maxCapacity = 0;
}

std::vector<Stock *> Shelf::getStockListVector() {
    return stockList;
}
