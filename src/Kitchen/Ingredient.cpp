
//
// Created by Tristan on 2023/11/01.
//

#include "Ingredient.h"

std::string Ingredient::getName()
{
    return name;
}

std::string Ingredient::getChoice()
{
    return cookingChoice;
}

std::string Ingredient::getCondition()
{
    return condition;
}

void Ingredient::setCondition(std::string condition)
{

    this->condition = condition;
}

Ingredient::Ingredient(std::string name, int initialQuantity, double costPerUnit, int key) : Stock(name, initialQuantity, costPerUnit, key)
{
    this->condition = "Uncooked";
}
