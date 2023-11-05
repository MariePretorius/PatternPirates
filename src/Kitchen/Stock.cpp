//
// Created by Tristan on 2023/10/23.
//

#include "Stock.h"

#include <string>
#include <iostream>

/**
 * @brief The constructor for the Stock object
 * @param name The name of the item
 * @param initialQuantity The intial amount of the item
 * @param costPerUnit The cost per unit of the item
 * @param key The key for the item
 */
Stock::Stock(std::string name, int initialQuantity, double costPerUnit, int key)
{
    this->name = name;
    this->quantity = initialQuantity;
    this->costPerUnit = costPerUnit;
    this->key = key;
}

/**
 * @brief returns the cost per unit for the stock item
 * @return a double for the cost
 */
double Stock::getCostPerUnit()
{
    return costPerUnit;
}

/**
 * @brief Adds the given quantity to the stock
 * @param quantity an int
 */
void Stock::addStock(int quantity)
{
    this->quantity += quantity;
}

/**
 * @brief Removes stock of the given quantity
 * @param quantity an int
 */
void Stock::removeStock(int quantity)
{
    this->quantity -= quantity;
}

/**
 * @brief returns the name of the stock item
 * @return
 */
std::string Stock::getName() {
    return this->name;
}

/**
 * @brief returns a string represent ation of this stock item
 * @return a string
 */
std::string Stock::toString() {
    std::string temp = "Key: "+ std::to_string(key) +"\tName: " + name + "\t\tQuantity: " + std::to_string(quantity) +
    "\tCost Per Unit: " + std::to_string(costPerUnit);

    //std::cout << "temp" << std::endl;
    return temp;
}

Stock::~Stock() {

}

int Stock::getQuantity() {
    return this->quantity;
}
