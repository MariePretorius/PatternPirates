
//
// Created by Tristan on 2023/11/01.
//
/**
 * @file Stock.h
 * @brief The declaration of the stock class
 */
#ifndef PROJFINAL_INGREDIENT_H
#define PROJFINAL_INGREDIENT_H

#include "Stock.h"
/**
 * @class Ingredient
 * @brief is the concrete class of the Template method design pattern
 */
class Ingredient : public Stock
{
public:
    Ingredient(std::string name, int initialQuantity, double costPerUnit, int key);
    ~Ingredient();
    std::string getCondition();
    void setChoice(std::string newCookingChoice);
    std::string getChoice();
    void setCondition(std::string condition);

private:
    std::string condition; ///< The condition of this ingredient
    std::string cookingChoice; ///< The cooking choice for this ingredient
};


#endif //PROJFINAL_INGREDIENT_H

