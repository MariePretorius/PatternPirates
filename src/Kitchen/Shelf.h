//
// Created by Tristan on 2023/10/23.
//
/**
 * @file Shelf.h
 * @brief The declaration of the Shelf class
 */
#ifndef PROJ_SHELF_H
#define PROJ_SHELF_H

#include "Stock.h"
#include <list>
#include <vector>
class Stock;

/**
 * @class Shelf
 * @brief Manages all of the stock items
 */

class Shelf
{
public:
    Shelf();
    void addStock(Stock * newStock);
    void removeStock(std::string stock);
    void clearStock();
    Stock * deductStock(std::string stock);
    int getCurrentCapacity();
    int getMaxCapacity();
    std::string getStockList();
    std::vector<Stock*> getStockListVector();
private:

    std::vector<Stock*> stockList; ///< Stores the list of all stock items
    int currentCapacity; ///< the current capacity of the shelf
    int maxCapacity;///< the maximum capacity of the shelf
};


#endif //PROJ_SHELF_H
