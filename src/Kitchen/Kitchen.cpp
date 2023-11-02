#include "Kitchen.h"
using namespace std;

Kitchen::Kitchen(){

};

Kitchen::~Kitchen() {

}

FoodOrder* Kitchen::getNextOrder() {
    if (!orders.empty()) {
        FoodOrder* nextOrder = orders.front();
        orders.erase(orders.begin());
        currentOrder = nextOrder;
        return nextOrder;
    } else {
        cout << "\033[1;36mAll orders are handled,  for now...\033[0m" << endl;
    }
}

Shelf* Kitchen::getShelf() {
    return shelf;
}

void Kitchen::addCookedIngredient(Ingredient* ingredient) {
    cookedIngredients.push_back(ingredient);
}

void Kitchen::addUncookedIngredient(Ingredient* ingredient) {
    uncookedIngredients.push_back(ingredient);
}

void Kitchen::addNewOrder(FoodOrder* newOrder) {
    orders.push_back(newOrder);
    cout << "\033[1;36mA new order was just added to the kitchen!\033[0m" << endl;
}

void Kitchen::notifyWaiter() {
    //Notify waiter that dish is ready
}

void Kitchen::addDish(Dish* dish) {
    completedOrders.push_back(dish);
    cout << "\033[1;36mA new order was just completed!  Order up!\033[0m" << endl;
}

Dish* Kitchen::takeDish(int id) {
    if (!completedOrders.empty()) {
        auto it = std::find_if(completedOrders.begin(), completedOrders.end(), [id](const Dish& dish) {
            return dish;   
        });
         if (it != completedOrders.end()) {
            //Dish is in the list
            std::cout << "Order " << id << "was succesfully collected by a waiter :)" << std::endl;
        } else {
            //If for some reason, the dish is not ready, notify
            std::cout << "Order " << id << "is not yet ready to be collected." << std::endl;
        }
    }
}
