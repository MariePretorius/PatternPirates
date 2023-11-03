//
// Created by Tristan on 2023/10/30.
//

#include "FoodOrder.h"
#include "../Floor/Customer.h"
#include <list>

FoodOrder::FoodOrder(std::string ingredients, std::string method, std::string tableNumber, Customer &customer) {
    this->customer = &customer;
}

FoodOrder::FoodOrder() {

}

void FoodOrder::execute() {

}

void FoodOrder::addToBill(std::string ingredient) {

}

std::list<std::string> FoodOrder::getIngredients() {
    return ingredients;
}