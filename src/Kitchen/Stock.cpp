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

double Stock::getCostPerUnit()
{
    return costPerUnit;
}

void Stock::addStock(int quantity)
{
    this->quantity += quantity;
}

void Stock::removeStock(int quantity)
{
    this->quantity -= quantity;
}

std::string Stock::getName() {
    return this->name;
}
