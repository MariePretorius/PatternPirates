//Added by Franco
//Note to self:  PLEASE DELETE THIS FILE BEFORE COMMIT
#include "Dish.h"

Dish::Dish(double cond) {
    this->condition = cond;
}

int Dish::getId() {
    return id;
}

void Dish::addIngredient(Ingredient* ingredient) {
    ingredients.push_back(ingredient);
}