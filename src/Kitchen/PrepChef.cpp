#include "PrepChef.h"

PrepChef::PrepChef(Kitchen* thisKitchen) {
    this->nextChef = new CookingChef();
    this->kitchen = thisKitchen;
}

PrepChef::~PrepChef() {
    delete this->kitchen;
    delete this->nextChef;
}

void PrepChef::handleOrder() {
    FoodOrder* currentOrder = kitchen->getNextOrder();
    while (currentOrder) {
        handleStock(currentOrder);
        this->nextChef->handleOrder();
        currentOrder = kitchen->getNextOrder();
    }
    delete currentOrder;
}

void PrepChef::handleStock(FoodOrder* order) {
    int stockMissing = 0;
    int stockNeeded = 0;
    //Get the list of ingredients in order and handle the stock
    //Pointer reference had it stop complaining about segfaults...
    std::vector<std::string> * ingredients = order->getIngredients();
    std::vector<std::string> cookingMethods = order->getCookingMethod();
    Shelf* currentShelf = kitchen->getShelf();
    //changing algorithm to accomidate for pointer
    int counter = 0;
    for (const std::string& ingredient : *ingredients) {
        stockNeeded++;
        Ingredient* takenIngredient = (Ingredient*)currentShelf->deductStock(ingredient);
        takenIngredient->setChoice(cookingMethods[counter]);
        counter++;
        if (takenIngredient == NULL) {
            stockMissing++;
            double cost = takenIngredient->getCostPerUnit();
            order->removeFromBill(takenIngredient->getName(), cost);
        } else {
            kitchen->addUncookedIngredient(takenIngredient);
        }
    }

    //condition set to intial zero so it has a value
    //if guard to prevent division by zero.
    int condition = 0;
    if(stockNeeded != 0)
    {
        condition = (stockNeeded - stockMissing) / stockNeeded;
    }

    kitchen->setCurrentDish(condition);
}
