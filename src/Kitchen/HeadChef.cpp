#include "HeadChef.h"

void HeadChef::handleOrder() {
    cout << "\033[1;36mThe head chef is assembling the dish!\033[0m" << endl;
    for (int i = 0; i < kitchen->getIngredientAmt(); i++) {
        Dish* dish = kitchen->getCurrentDish();
        dish->addIngredient(kitchen->getCookedIngredient());
    }
    cout << "\033[1;36mThe head chef just assembled a dish and it's now ready for collection!\033[0m" << endl;
}