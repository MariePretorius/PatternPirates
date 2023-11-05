//
// Created by Tristan on 2023/10/23.
//

#include "Shelf.h"
#include <string>
#include <iostream>

/**
 * @brief Adds the passed in stock item to the list of stock
 * @param newStock A Stock pointer
 */
void Shelf::addStock(Stock * newStock)
{
    this->stockList.push_back(newStock);
}

/**
 * @brief Removes stock items from the shelf
 * @param stock name of the stock item
 */
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

/**
 * @brief deletes all stock items
 */
void Shelf::clearStock()
{
    for(int i = 0; i < this->stockList.size(); i++)
    {
        stockList.pop_back();
    }
}

/**
 * @brief returns a printable list of all the items in the shelf
 * @return string representation of the list
 */
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

/**
 * @brief returns the pointer to a the stock item so it's amount can be manipulated
 * @param stock The name of the item
 * @return The stock item requested
 */
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

/**
 * @brief Constructor for the shelf
 */
Shelf::Shelf() {
    stockList = std::vector<Stock*>();
    currentCapacity = 0;
    maxCapacity = 0;
}

/**
 * @brief returns a traversable vector of all the items in the shelf
 * @return a stock pointer vector
 */
std::vector<Stock *> Shelf::getStockListVector() {
    return stockList;
}
