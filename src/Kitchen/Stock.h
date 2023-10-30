//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_STOCK_H
#define PROJ_STOCK_H

#include <string>

class Stock {
public:
    Stock(std::string name, int initialQuantity, double costPerUnit, int key);
    void addStock(int quantity);
    void removeStock(int quantity);
    double getCostPerUnit();

private:
    std::string name;
    int quantity;
    int key;
    double costPerUnit;

};


#endif //PROJ_STOCK_H
