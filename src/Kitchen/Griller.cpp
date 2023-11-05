#include "Griller.h"
#include <iostream>
using namespace std;

void Griller::prepareStation() {
    cout << "\033[1;36mThe griller is heating up the stove...\033[0m" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20)); //Main thread used to timeout program for two seconds
    cout << "\033[1;36mThe griller is ready to grill some food!\033[0m" << endl;
}

Ingredient* Griller::cookIngredient(Ingredient* ingredient) { //This method takes the Ingredient and changes it condition to fried
    cout << "\033[1;36mThe griller is grilling a \033[0m" << ingredient->getName() << "\033[1;36m...\033[0m"  << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); //Main thread used to timeout program for one second
    ingredient->setCondition("Grilled");
    cout << "\033[1;36mA \033[0m" << ingredient->getName() << "\033[1;36m is grilled and ready...\033[0m"  << endl;
    return ingredient;
}