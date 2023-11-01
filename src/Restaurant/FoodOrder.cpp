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
    }
}

FoodOrder :: ~FoodOrder()
{
    delete ingredients;
    delete prices;
}

void FoodOrder :: execute()
{

}

void FoodOrder :: addToBill(std::string ingredient, double cost)
{

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