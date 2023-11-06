#include "FoodOrderTest.h"
#include <iostream>

FoodOrderTest::FoodOrderTest() 
{
    // Initialize FoodOrderTest instance for testing
    std::vector<std::string> ingredients = {"Ingredient1", "Ingredient2"};
    std::vector<double> prices = {5.0, 3.0};
    int numIngredients = ingredients.size();
    std::vector<std::string> cookingMethod = {"Grill", "Grill"};
    int tableNumber = 1;


    Stock* s1 = new Stock("Ingredient1", 20, 5.0, 1);
    Stock* s2 = new Stock("Ingredient2", 20, 3.0, 2);
    std::vector<Stock*> stock = {s1, s2};

    this->customer = new Customer("Bill", false, stock);
    Finance* finance = new Finance();
    Table* table =  new Table(1, 4);
    Bill* bill = new Bill(customer, finance, table);
    this->kitchen = new Kitchen(finance);

    this->foodOrder = new FoodOrder(ingredients, prices, numIngredients, cookingMethod, tableNumber, *customer, bill);
    foodOrder->setKitchen(kitchen);
}


void FoodOrderTest::testFoodOrder() 
{
    // Test FoodOrder operations
    std::vector<std::string> cM = {"Grill", "Grill"};
    assert(foodOrder->getCookingMethod() == cM);
    assert(foodOrder->getTableNumber() == 1);

    std::vector<std::string>* order = foodOrder->getIngredients();

    std::vector<std::string> orderIngredients = *order;   //foodOrder.getIngredients();
    assert(orderIngredients.size() == 2);
    assert(orderIngredients[0] == "Ingredient1");
    assert(orderIngredients[1] == "Ingredient2");

    // Test execution
    foodOrder->execute();

    // Check if the order has been added to the kitchen
    //assert(kitchen.getNumOrders() == 1);
    //assert(kitchen.getOrder(0) == &foodOrder);
}

void FoodOrderTest::runTests() 
{
    testFoodOrder();
    std::cout << "\x1B[33m";
    std::cout << "FoodOrder tests successful!" << std::endl;
    std::cout << "\x1B[0m";
}

