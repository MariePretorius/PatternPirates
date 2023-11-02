//
// Created by Tristan on 2023/10/23.
//

#include "Stock.h"

#include <string>
#include <iostream>

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

std::string Stock::toString() {
    std::string temp = "Key: "+ std::to_string(key) +"\tName: " + name + "\t\tQuantity: " + std::to_string(quantity) +
    "\tCost Per Unit: " + std::to_string(costPerUnit);

    //std::cout << "temp" << std::endl;
    return temp;
}
