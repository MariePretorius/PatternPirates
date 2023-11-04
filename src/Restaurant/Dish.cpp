//Added by Franco
//Note to self:  PLEASE DELETE THIS FILE BEFORE COMMIT
#include "Dish.h"

Dish::Dish(double cond, Customer* customer, int tableId) {
    this->condition = cond;
    this->customer = customer;
    this->tableId = tableId;
}

int Dish::getId() {
    return tableId;
}

void Dish::addIngredient(Ingredient* ingredient) {
    ingredients.push_back(ingredient);
}