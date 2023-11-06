//
// Created by Tristan on 2023/10/23.
//

#ifndef PROJ_STOCK_H
#define PROJ_STOCK_H

#include <string>

class Stock {
public:
    Stock(std::string name, int initialQuantity, double costPerUnit, int key);
    ~Stock();
    virtual void addStock(int quantity);
    virtual void removeStock(int quantity);
    virtual double getCostPerUnit();

    virtual std::string getName();

    virtual std::string toString();

    int getQuantity();

private:
    std::string name;
    int quantity;
    int key;
    double costPerUnit;

};


#endif //PROJ_STOCK_H
