#include "Dish.h"

Dish::Dish(double cond, Customer* customer, int tableId, Bill* bill) {
    this->condition = cond;
    this->customer = customer;
    this->tableId = tableId;
    this->bill = bill;
}

int Dish::getTableId() {
    return tableId;
}

void Dish::addIngredient(Ingredient* ingredient) {
    ingredients.push_back(ingredient);
}