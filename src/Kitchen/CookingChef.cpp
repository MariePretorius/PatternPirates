#include "CookingChef.h"

CookingChef::CookingChef() {
    this->nextChef = new HeadChef();
}

CookingChef::~CookingChef() {
    delete this->cook;
}

void CookingChef::changeCook(Cook* cook) {
    this->cook = cook;
}

void CookingChef::handleOrder() {
    Cook* fryer = new Fryer();
    Cook* griller = new Griller();
    for (int i = 0; i < kitchen->getIngredientAmt(); i++) {
        Ingredient* ingredient = kitchen->getUncookedIngredient();
        if (ingredient->getChoice() == "Fried") {
            this->changeCook(fryer);
        } else {
            this->changeCook(griller);
        }
        cook->prepareStation();
        kitchen->addCookedIngredient(cook->cookIngredient(ingredient));
    } 
    delete fryer;
    delete griller;
    this->nextChef->handleOrder();
}
