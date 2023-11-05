
//
// Created by Tristan on 2023/11/01.
//

#ifndef PROJFINAL_INGREDIENT_H
#define PROJFINAL_INGREDIENT_H

#include "Stock.h"

class Ingredient : public Stock
{
public:
    Ingredient(std::string name, int initialQuantity, double costPerUnit, int key);
    std::string getName() override;
    std::string getCondition();
    std::string getChoice();
    void setCondition(std::string condition);

private:
    std::string name;
    std::string condition;
    std::string cookingChoice;
};


#endif //PROJFINAL_INGREDIENT_H

