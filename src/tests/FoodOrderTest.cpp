#include "FoodOrderTest.h"
#include <iostream>
#include <cassert>

FoodOrderTest::FoodOrderTest() 
{
    // Initialize a FoodOrder instance for testing
    std::vector<std::string> ingredients = {"Ingredient1", "Ingredient2"};
    std::vector<double> prices = {5.0, 3.0};
    int numIngredients = ingredients.size();
    std::string cookingMethod = "Grill";
    int tableNumber = 1;
    Customer* customer;
    Kitchen* kitchen;
    Bill* bill;

    //foodOrder = new FoodOrder(ingredients, prices, numIngredients, cookingMethod, tableNumber, customer, bill);
}

FoodOrderTest::~FoodOrderTest()
{
    delete foodOrder;
}

void FoodOrderTest::testExecute() 
{
    // Test the execute function (you can customize this test)
    foodOrder->execute();
    // ASSERT_TRUE(some_condition);
}

void FoodOrderTest::testAddToBill() 
{
    // Test the addToBill function (you can customize this test)
    foodOrder->addToBill("NewIngredient", 2.5);
    // ASSERT_TRUE(some_condition);
}

void FoodOrderTest::testGetters() 
{
    // Test getter functions
    std::vector<std::string> ingr = {"Ingredient1", "Ingredient2"};
    //assert(foodOrder->getIngredients() == ingr);
    assert(foodOrder->getCookingMethod() == "Grill");
    assert(foodOrder->getTableNumber() == 1);
    // Add more getter tests as needed
}

void FoodOrderTest::testRandomID() 
{
    // Test the getRandomID function
    int randomID = foodOrder->getRandomID();
    assert(randomID >= 1000 && randomID <= 9999);
    // You can add more tests for getRandomID if necessary
}

void FoodOrderTest::runTests() 
{
    testExecute();
    testAddToBill();
    testGetters();
    testRandomID();
}

