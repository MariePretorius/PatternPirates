#include "Ingredient.h"

std::string Ingredient::getName() {
    return name;
}

std::string Ingredient::getCondition() {
    return condition;
}

std::string Ingredient::getChoice() {
    return cookingChoice;
}

void Ingredient::setCondition(std::string condition) {
    this->condition = condition;
}