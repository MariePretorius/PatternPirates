//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_SHELF_H
#define PROJ_SHELF_H

#include "Stock.h"
#include <list>

class Shelf
{
public:

private:
    std::list<Stock> stockList;
    int currentCapacity;
    int maxCapacity;
};


#endif //PROJ_SHELF_H
