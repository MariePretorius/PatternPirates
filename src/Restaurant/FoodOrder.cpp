#include "FoodOrder.h"
#include "../Floor/Customer.h"
#include "../Kitchen/Kitchen.h"
#include "../Floor/Bill.h"

FoodOrder :: FoodOrder(std::string* ingredients, double* prices, int num, std::string method, int tableNumber, Customer& customer, Kitchen& k, Bill& bill) : kitchen{k}, bill(bill)
{
    this->customer = &customer;
    //this->kitchen = &k;
    //this->bill = &bill;
    this->numberOfIngredients = num;
    this->cookingMethod = method;
    this->tableNumber = tableNumber;
    this->ingredients = new std::string[numberOfIngredients];
    this->prices = new double[numberOfIngredients];
    for (int i = 0; i < numberOfIngredients; i++)
    {
        this->ingredients[i] = ingredients[i];
        this->prices[i] = prices[i];
        addToBill(ingredients[i], prices[i]);
    }
}

FoodOrder :: ~FoodOrder()
{
    delete ingredients;
    delete prices;
}

void FoodOrder :: execute()
{
    //kitchen.prepareFood(ingredients, cookingMethod);
}

void FoodOrder :: addToBill(std::string ingredient, double cost)
{
    bill.addItem(ingredient, cost);
}

std::string* FoodOrder :: getIngredients()
{
    return this->ingredients;
}

std::string FoodOrder :: getCookingMethod()
{
    return this->cookingMethod;
}

int FoodOrder :: getTableNumber()
{
    return this->tableNumber;
}

Customer* FoodOrder :: getCustomer()
{
    return this->customer;
}

// In Waiter: 
// void takeOrder()
// {
//     // order parameters : 
//     // std::string* ingredients : array of ingredients
//     // double* prices : array of prices corresponding to the array of ingredients
//     // int num : number of ingredients/prices
//     // std::string method : cooking method
//     // int tableNumber : table number corresponding to the order
//     // Customer& customer : customer whose order it is
//     // Kitchen& k : reference to the kitchen
//     // Bill& bill : reference to the bill [used to add the order onto the bill]

//     // contents of function
//     FoodOrder order(ingredients, prices, num, method, tableNumber, customer, kitchen, bill);

//     order.execute();
// }

// In Kitchen
// void prepareFood(const std::string* ingredients, std::string cookingMethod) 
// {
//     // set cooking method
//     // add ingredients
    
//     // start process basically
//     // add to queue
// }