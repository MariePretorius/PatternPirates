#include "PrepChef.h"

void PrepChef::handleOrder() {
    FoodOrder* currentOrder = kitchen->getNextOrder();
    handleStock(currentOrder);
}

void PrepChef::handleStock(FoodOrder* order) {
    //Get the list of ingredients in order and handle the stock
    std::list<std::string> ingredients = order->getIngredients();
    for (const auto& item : ingredients) {
        
    }
}