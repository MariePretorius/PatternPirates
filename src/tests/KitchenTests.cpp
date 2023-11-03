#include "KitchenTests.h"
#include "../Restaurant/FoodOrder.h"

KitchenTests::KitchenTests() {

}

void KitchenTests::runTests() {
    Kitchen* kitchen = new Kitchen(new Finance());

    FoodOrder* food1 = new FoodOrder();
    FoodOrder* food2 = new FoodOrder();
    FoodOrder* food3 = new FoodOrder();
    FoodOrder* food4 = new FoodOrder();
    FoodOrder* food5 = new FoodOrder();
    FoodOrder* food6 = new FoodOrder();
}