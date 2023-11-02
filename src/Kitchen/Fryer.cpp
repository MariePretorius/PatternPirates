#include "Fryer.h"

void Fryer::prepareStation() {
    cout << "\033[1;36mThe fryer is filling the fryer with oil...\033[0m" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); //Main thread used to timeout program for one second
    cout << "\033[1;36mThe fryer is heating the oil...\033[0m" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); //Main thread used to timeout program for one second 
    cout << "\033[1;36mThe fryer is ready to fry some food!\033[0m" << endl;
}

Ingredient* Fryer::cookIngredient(Ingredient* ingredient) { //This method takes the Ingredient and changes it condition to fried
    cout << "\033[1;36mThe fryer is frying a \033[0m" << ingredient->getName() << "\033[1;36m...\033[0m"  << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); //Main thread used to timeout program for one second
    ingredient->setCondition("Fried");
    cout << "\033[1;36mA \033[0m" << ingredient->getName() << "\033[1;36m is fried and ready...\033[0m"  << endl;
    return ingredient;
}