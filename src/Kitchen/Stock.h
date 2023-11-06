//
// Created by Tristan on 2023/10/23.
//
/**
 * @file Stock.h
 * @brief The declaration of the Stock class
 */
#ifndef PROJ_STOCK_H
#define PROJ_STOCK_H

#include <string>

/**
 * @class Stock
 * @brief The Abstract class of the template design pattern
 */
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
    std::string name; ///< The name of the stock item
    int quantity; ///< The quantity of the stock item
    int key; ///< The key of this item within the list
    double costPerUnit; ///< The cost per unit of this stock item

};


#endif //PROJ_STOCK_H
