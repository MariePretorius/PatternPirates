/**
 * @file PrepChef.h
 * @brief This file contains the implementation of the PrepChef class.
 */
#include "PrepChef.h"

/**
 * @brief Constructor for the PrepChef class.
 * @param thisKitchen A pointer to the Kitchen object.
 */
PrepChef::PrepChef(Kitchen* thisKitchen) {
    this->nextChef = new CookingChef();
    this->kitchen = thisKitchen;
}

/**
 * @brief Handle an order from the kitchen.
 * Gets the next order from the kitchen and handles its stock.
 */
void PrepChef::handleOrder() {
    FoodOrder* currentOrder = kitchen->getNextOrder();
    handleStock(currentOrder);
}

/**
 * @brief Handle the stock for a given food order.
 * Deducts the required ingredients from the shelf and adds uncooked ingredients to the kitchen.
 * @param order A pointer to the FoodOrder object.
 */
void PrepChef::handleStock(FoodOrder* order) {
    int stockMissing = 0;
    int stockNeeded = 0;
    //Get the list of ingredients in order and handle the stock
    std::vector<std::string> ingredients = order->getIngredients();
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