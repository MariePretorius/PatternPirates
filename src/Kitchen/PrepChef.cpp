#include "PrepChef.h"

PrepChef::PrepChef() {
    this->nextChef = new CookingChef();
}

void PrepChef::handleOrder() {
    FoodOrder* currentOrder = kitchen->getNextOrder();
    handleStock(currentOrder);
}

void PrepChef::handleStock(FoodOrder* order) {
    int stockMissing = 0;
    int stockNeeded = 0;
    //Get the list of ingredients in order and handle the stock
    std::list<std::string> ingredients = order->getIngredients();
    Shelf* currentShelf = kitchen->getShelf();
    for (const std::string& ingredient : ingredients) {
        stockNeeded++;
        Ingredient* takenIngredient = (Ingredient*)currentShelf->deductStock(ingredient);
        if (takenIngredient == NULL) {
            stockMissing++;
        } else {
            kitchen->addUncookedIngredient(takenIngredient);
        }
    }

    int condition = (stockNeeded - stockMissing) / stockNeeded;
    kitchen->setCurrentDish(condition);
    this->nextChef->handleOrder();
}