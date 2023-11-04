#include "HeadChef.h"

void HeadChef::handleOrder() {
    cout << "\033[1;36mThe head chef is assembling the dish!\033[0m" << endl;
    Dish* dish = kitchen->getCurrentDish();
    for (int i = 0; i < kitchen->getIngredientAmt(); i++) {
        dish->addIngredient(kitchen->getCookedIngredient());
    }
    kitchen->addDish(dish);
    cout << "\033[1;36mThe head chef just assembled a dish and it's now ready for collection!\033[0m" << endl;
}