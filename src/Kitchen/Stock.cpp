//
// Created by Tristan on 2023/10/23.
//

#include "Stock.h"

Stock::Stock(std::string name, int initialQuantity, double costPerUnit, int key)
{
    this->name = name;
    this->quantity = initialQuantity;
    this->costPerUnit = costPerUnit;
    this->key = key;
}

void Stock::addStock()
{

}

void Stock::removeStock()
{

}

double Stock::getCostPerUnit()
{
    return costPerUnit;
}