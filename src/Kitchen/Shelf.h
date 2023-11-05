//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_SHELF_H
#define PROJ_SHELF_H

#include "Stock.h"
#include <list>
#include <vector>
class Stock;

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

    std::vector<Stock*> stockList;
    int currentCapacity;
    int maxCapacity;
};


#endif //PROJ_SHELF_H
