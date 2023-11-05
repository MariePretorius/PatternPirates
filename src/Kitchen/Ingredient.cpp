
//
// Created by Tristan on 2023/11/01.
//

#include "Ingredient.h"

/**
 * @brief Returns the name of the ingredient
 * @return a name
 */
std::string Ingredient::getName()
{
    return name;
}

/**
 * @brief returns the cooking choice for this ingrdient.
 * @return a cookingChoice
 */
std::string Ingredient::getChoice()
{
    return cookingChoice;
}

std::string Ingredient::getCondition()
{
    return condition;
}

/**
 * Sets the condition of the ingredient
 * @param condition
 */
void Ingredient::setCondition(std::string condition)
{

    this->condition = condition;
}

/**
 * @brief Constructor for the ingredient object
 * @param name Name of the ingredient
 * @param initialQuantity Amount of ingredient
 * @param costPerUnit Cost of each ingredient
 * @param key key for the ingredient
 */
Ingredient::Ingredient(std::string name, int initialQuantity, double costPerUnit, int key) : Stock(name, initialQuantity, costPerUnit, key)
{
    this->condition = "Uncooked";
}
