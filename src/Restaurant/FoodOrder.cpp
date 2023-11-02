//
// Created by Tristan on 2023/10/30.
//

#include "FoodOrder.h"
#include "../Floor/Customer.h"

FoodOrder::FoodOrder(std::string ingredients, std::string method, std::string tableNumber, Customer &customer) {
    this->customer = &customer;
}

FoodOrder::FoodOrder() {

}

void FoodOrder::execute() {

}

void FoodOrder::addToBill(std::string ingredient) {

}

std::string FoodOrder::getIngredients() {
    return std::string();
}